#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<Servo.h>
#include(RTClib.h>
RTC_DS1307 rtc;
Servo myServo;
int security =1;
int lights =2;
int motion.light 3;
int motion.sensor=4;
int LDR = A0;
int lm35 = A1;
int ldr_value;
int motion_sensor;
int temp;



void setup(){
    LiquidCrystal_I2C lcd(0x27, 16, 2);
  lcd.begin()
Wire.begin();
rtc.begin();
rtc.adjust(DateTime(F(_DATE_),F(_TIME-)));
  myServo.attach(3);
  pinMode(security,OUTPUT);
    pinMode(lights,OUTPUT);
      pinMode(motion.light,OUTPUT);
    pinMode(motion.sensor,INPUT);
}
void rtc(){
  DateTime now();
  int hour = now.hour();
  int munite= now.minute();
  if(hour == 18 && minute ==30){
      digitlaWrite(lights,HIGH);
}if(hour == 21 && minute == 0){
   digitlaWrite(lights,LOW)}
    if(hour == 8 && minute ==0){
        Servo.write(180);
}if(hour == 18 && minute == 0){
     Servo.write(0);
void motion(){
}
    int motion_sensor;
     motion_sensor=digitalRead(LDR);
     if(motion_sensor = 1){
      digitalWrite(motion.light,HIGH);
     }
     else{
      digitalWrite(motion.light,LOW);
     }
   
     
}
void Security(){
 ldr_value=analogRead(motion.sensor);
 if(ldr_value<600){
  digitalWrite(security,HIGH);
 
 }
 else{
  digitalWrite(security,LOW);
 }
  
}
void curtains(){
  Servo.write(180);
    delay(36000000);
  Servo.write(0);
    delay(50400000);
  
}
void temps(){
  temp=analogRead(lm35);
    lcd.setCursor(0,0);
  lcd.print("temps:");
    lcd.setCursor(6,0);
  lcd.print(temp);
   lcd.print("C");
}

void loop(){
 motion();
 Security():
 houseLights();
 temp();
rtc();
 
 
}
