
//int last_ang0, last_ang1, last_ang2, last_ang3, last_ang4, last_ang5, last_ang6, last_ang7, last_ang8, last_ang9, last_ang10, last_ang11;
//int pos;
void Motors_ON(int ang0, int ang1, int ang2, int ang3, int ang4, int ang5, int ang6, int ang7, int ang8, int ang9, int ang10, int ang11) {

//
      ang0 = abs(68 - ang0);
//      if ((ang0 == 0 || ang0 == 180 || abs(ang0 - last_ang0) >= 20) && (last_ang0 > 0)) {
//        ang0 = last_ang0;
//      }
//      else{
//        last_ang0 = ang0;
//      }
      pos = map(ang0, 0, 165, 500, 2600);
      pwm.writeMicroseconds(2, pos);


      ang1 = abs(83 + ang1); // Correção
//      if ((ang1 == 0 || ang1 == 180 || abs(ang1 - last_ang1) >= 20) && (last_ang1 > 0)) {
//        ang1 = last_ang1;
//      }
//      else{
//        last_ang1 = ang1;
//      }
      pos = map(ang1, 0, 165, 500, 2600);
      pwm.writeMicroseconds(1, pos);

      ang2 = abs(115 + ang2);
//      if ((ang2 == 0 || ang2 == 180 || abs(ang2 - last_ang2) >= 20) && (last_ang2 > 0)) {
//        ang2 = last_ang2;
//      }
//      else{
//        last_ang2 = ang2;
//      }
      pos = map(ang2, 0, 165, 500, 2600);
      pwm.writeMicroseconds(0, pos);
      
      ang3 = abs(78 - ang3);
//      if ((ang3 == 0 || ang3 == 180 || abs(ang3 - last_ang3) >= 20) && (last_ang3 > 0)) {
//        ang3 = last_ang3;
//      }
//      else{
//        last_ang3 = ang3;
//      }
      pos = map(ang3, 0, 165, 500, 2600);
      pwm.writeMicroseconds(3, pos);
//
      ang4 = abs(72 - ang4);
//      if ((ang4 == 0 || ang4 == 180 || abs(ang4 - last_ang4) >= 20) && (last_ang4 > 0)) {
//        ang4 = last_ang4;
//      }
//      else{
//        last_ang4 = ang4;
//      }
      pos = map(ang4, 0, 165, 500, 2600);
      pwm.writeMicroseconds(4, pos);
//
      ang5 = abs(54 - ang5);
//      if ((ang5 == 0 || ang5 == 180 || abs(ang5 - last_ang5) >= 20) && (last_ang5 > 0)) {
//        ang5 = last_ang5;
//      }
//      else{
//        last_ang5 = ang5;
//      }
      pos = map(ang5, 0, 165, 500, 2600);
      pwm.writeMicroseconds(5, pos);
//
      ang6 = abs(92 - ang6);
//      if ((ang6 == 0 || ang6 == 180 || abs(ang6 - last_ang6) >= 20) && (last_ang6 > 0)) {
//        ang6 = last_ang6 + 1;
//      }
//      else{
//        last_ang6 = ang6;
//      }
      pos = map(ang6, 0, 180, 500, 2500);
      pwm.writeMicroseconds(12, pos);
//
      ang7 = abs(58 + ang7); // ><
//      if ((ang7 == 0 || ang7 == 180 || abs(ang7 - last_ang7) >= 20) && (last_ang7 > 0)) {
//        ang7 = last_ang7;
//      }
//      else{
//        last_ang7 = ang7;
//      }
      pos = map(ang7, 0, 165, 500, 2600);
      pwm.writeMicroseconds(11, pos);
//
      ang8 = abs(48 + ang8);
//      if ((ang8 == 0 || ang8 == 180 || abs(ang8 - last_ang8) >= 20) && (last_ang8 > 0)) {
//        ang8 = last_ang8;
//      }
//      else{
//        last_ang8 = ang8;
//      }
      pos = map(ang8, 0, 165, 500, 2600);
      pwm.writeMicroseconds(10, pos);
//
      ang9 = abs(102 - ang9);
//      if ((ang9 == 0 || ang9 == 180 || abs(ang9 - last_ang9) >= 20) && (last_ang9 > 0)) {
//        ang9 = last_ang9;
//      }
//      else{
//        last_ang9 = ang9;
//      }
      pos = map(ang9, 0, 180, 500, 2500);
      pwm.writeMicroseconds(13, pos);
//
      ang10 = abs(79 - ang10);
//      if ((ang10 == 0 || ang10 == 180 || abs(ang10 - last_ang10) >= 20) && (last_ang10 > 0)) {
//        ang10 = last_ang10;
//      }
//      else{
//        last_ang10 = ang10;
//      }
      pos = map(ang10, 0, 165, 500, 2600);
      pwm.writeMicroseconds(14, pos);
//
      ang11 = abs(112 - ang11);
//      if ((ang11 == 0 || ang11 == 180 || abs(ang11 - last_ang11) >= 20) && (last_ang11 > 0)) {
//        ang11 = last_ang11;
//      }
//      else{
//        last_ang11 = ang11;
//      }
      pos = map(ang11, 0, 165, 500, 2600);
      pwm.writeMicroseconds(15, pos);

//  Serial.print(ang0); Serial.print(", ");
//  Serial.print(ang1); Serial.print(", ");
//  Serial.print(ang2); Serial.print(", ");
//  Serial.print(ang3); Serial.print(", ");
//  Serial.print(ang4); Serial.print(", ");
//  Serial.print(ang5); Serial.print(", ");
//  Serial.print(ang6); Serial.print(", ");
//  Serial.print(ang7); Serial.print(", ");
//  Serial.print(ang8); Serial.print(", ");
//  Serial.print(ang9); Serial.print(", ");
//  Serial.print(ang10); Serial.print(", ");
//  Serial.println(ang11);
}
