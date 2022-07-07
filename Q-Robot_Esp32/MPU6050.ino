

void MPU6050()
{
  Wire.beginTransmission(MPU);      //transmite
  Wire.write(0x3B);                 // Endereço 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);     //Finaliza transmissão
  Wire.requestFrom(MPU, 14, true); //requisita bytes
  acelX = Wire.read() << 8 | Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  acelY = Wire.read() << 8 | Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  acelZ = Wire.read() << 8 | Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  giroX = Wire.read() << 8 | Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  giroY = Wire.read() << 8 | Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  giroZ = Wire.read() << 8 | Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  //  ang_accel = atan2(-acelY, acelX) * 180 / PI;
  //  vang_gyro = giroZ / 131;

  //Serial.println(ang_accel); //Serial.print(",");
//  Serial.print(acelX); Serial.print(",");
//  Serial.print(acelY); Serial.print(",");
//  Serial.println(acelZ);
  //    Serial.println(ang_Kalman);

  //if (nh.connected()) {
//      msg_acel_x.data = acelX;
//      msg_acel_y.data = acelY;
//      msg_acel_z.data = acelZ;
//      pub_acelx.publish( &msg_acel_x );
//      pub_acely.publish( &msg_acel_y );
//      pub_acelz.publish( &msg_acel_z ); 
 // }
  //nh.spinOnce();
}
