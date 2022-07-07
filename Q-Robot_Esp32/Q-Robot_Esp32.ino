
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include <WiFi.h>
#define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <std_msgs/Float32.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <std_msgs/Float64.h>

float serv[12];

// Set the WiFi's username and password
const char* ssid = "WiFi's username";
const char* password = "Password";

// Set the rosserial socket server IP address
IPAddress server(192, 168, 1, 76);

// Set the rosserial socket server port
const uint16_t serverPort = 11411;

ros::NodeHandle nh;
// Make a chatter publisher
//std_msgs::String str_msg;
//ros::Publisher chatter("chatter", &str_msg);

// Ros Publishers
//std_msgs::Float32 msg_acel_x;
//ros::Publisher pub_acelx("/AcelX", &msg_acel_x);
//
//std_msgs::Float32 msg_acel_y;
//ros::Publisher pub_acely("/AcelY", &msg_acel_y);
//
//std_msgs::Float32 msg_acel_z;
//ros::Publisher pub_acelz("/AcelZ", &msg_acel_z);

//ros::Subscriber <geometry_msgs::Twist> sub("/cmd_vel", Callback);
void Callback0(const trajectory_msgs::JointTrajectory& Tr_msg) {
  for (int i = 0; i < 12; i++) {
    serv[i] = Tr_msg.points[0].positions[i];
    serv[i] = serv[i] * 57.3;
  }
}

ros::Subscriber <trajectory_msgs::JointTrajectory> sub0("/joint_group_position_controller/command", Callback0);

//Endereco I2C do MPU6050
const int MPU = 0x68; //pino aberto 0X68 , pino ligado em 3,3V 0x69
int acelX, acelY, acelZ, giroX, giroY, giroZ;
//float ang_accel, vang_gyro;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

int pos;

void setup() {
  Serial.begin(57600);

  // Trecho de inicialização dos motores
  pwm.begin();
  pwm.setPWMFreq(60);

  // Trecho de inicialização do MPU6050
  Wire.begin();                 //inicia I2C
  Wire.beginTransmission(MPU);  //Inicia transmissão para o endereço do MPU
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Trecho de conexão com a Internet
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

//  nh.advertise(pub_acelx);
//  nh.advertise(pub_acely);
//  nh.advertise(pub_acelz);

  nh.subscribe(sub0);
}

void loop() {
  //delay(20);
  nh.spinOnce();
  if (nh.connected()) {
    //MPU6050(); // Aquisição dos dados do Acelerometro e Giroscópio.
    Motors_ON(serv[0], serv[1], serv[2], serv[3], serv[4], serv[5], serv[6], serv[7], serv[8], serv[9], serv[10], serv[11]);
  }
}
