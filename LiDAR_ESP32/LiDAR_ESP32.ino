#include <Wire.h>
#include <VL53L0X.h>
#include <ESP32Servo.h>

#include <WiFi.h>
#define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <sensor_msgs/LaserScan.h>

VL53L0X sensor;
Servo myservo;

// Set the WiFi's username and password
const char* ssid = "WiFi's username";
const char* password = "password";

// Set the rosserial socket server IP address
IPAddress server(192, 168, 1, 76);

// Set the rosserial socket server port
const uint16_t serverPort = 11411;

#define ang_incr 5 // Incremento do ângulo [graus]
#define n_pont 30 // Número máximo de leituras (Os testes mostram que *50* é o número máximo suportado pelo rosserial)
float ranges[n_pont] = {0};
float intensities[n_pont] = {0};
int ang_varr = ang_incr * n_pont; // Varredura em graus
int ang_min = (180 - ang_varr) / 2; // Ângulo mínimo [graus]
int ang_max = ang_varr + ang_min; // Ângulo máximo [graus]

int count, p, s;
int servoPin = 13; int pos = ang_min;
float dist, time_Now, time_Later, Scan_time;

ros::NodeHandle nh;

sensor_msgs::LaserScan msg_lidar;
ros::Publisher pub_lidar("/laser_scan", &msg_lidar);

void setup()
{
  Serial.begin(57600);

  myservo.setPeriodHertz(60);    // standard 60 hz servo
  myservo.attach(servoPin, 500, 2500);

  Wire.begin();

  //********************************************************************
  sensor.setTimeout(500);
  sensor.init();

  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);

  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(20000);

  //*********************************************************************
  // Trecho de conexão com WiFi
  Serial.print("Connecting to : ");
  Serial.println(ssid);

  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);

  WiFi.disconnect();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WifiOK");
  }

  Serial.println("Connection established!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  //Trecho ROS
  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Montando a mensagem laser_scan
  msg_lidar.header.frame_id = "LiDar";
  msg_lidar.angle_min = ang_min * (3.14 / 180); // Mínimo ãngulo de varredura [rad]
  msg_lidar.angle_max = ang_max * (3.14 / 180); // Máximo ângulo de varredura [rad]
  msg_lidar.angle_increment = ang_incr * 3.14 / 180; // Incremento angular [rad]
  msg_lidar.range_min = 0.01; // Distãncia mínima de leitura do laser [m]
  msg_lidar.range_max = 2.0; // Distância máxima de leitura do laser [m]
  msg_lidar.time_increment = 0.001; // Tempo entre cada leitura [seg]
  msg_lidar.ranges_length = n_pont;
  msg_lidar.intensities_length = n_pont;

  nh.advertise(pub_lidar);

  myservo.write(ang_min);
  delay(1000);
}

void loop()
{
  if (nh.connected()) {
    myservo.write(pos);
    time_Later = millis();
    dist = sensor.readRangeSingleMillimeters();
    //Serial.println(dist);
    ranges[count] = dist * 0.001;
    time_Now = millis();
    Scan_time = time_Now - time_Later;
  }
  // Atualiza os valores da msg e publica
  msg_lidar.scan_time = Scan_time / 100000;
  msg_lidar.ranges = ranges;
  msg_lidar.intensities = intensities;

  pub_lidar.publish( &msg_lidar);

  nh.spinOnce();

  count = count + p;
  pos = pos + s;
  //Serial.println(pos);
  if (count == 0) {
    p  = 1;
    s = ang_incr;
  }
  else if (count == n_pont) {
    p = -1;
    s = -1*ang_incr;
  }
}
