#define blynk serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
char auth[]= "";
int moisturePin = A0;
int humidityPin = 2; 
int pumpPin=1;
int moistureValue;
int humidityValue=0;

char auth[] = "***";
char ssid[] = "ocean";
char pass[] = "123go   ";
void setup(){
Blynk.begin(auth,ssid,pass);
pinMode(pumpPin,OUTPUT);
pinMode(humidityPin,INPUT);

}

void loop(){
Blynk.run();
moistureValue = analogRead(moisturePin);
moistureValue = constrain(moistureValue,0,1023);
moistureValue = map(moistureValue,0,1023,100,0);

humidityValue = digitalRead(humidityPin);

if(humidityValue ==1){
Blynk.notify(" enough Humidity");
lcd.setCursor(0,1);  
lcd.print("enough humidty");  

  
}
else{
 Blynk.notify("low Humidity ");   
lcd.setCursor(0,1);  
lcd.print("enough humidty"); 
}


lcd.setCursor(0,0);  
lcd.print("S.Moisture:");
lcd.setCursor(12,0);  
lcd.print(moistureValue);
lcd.print("%");

lcd.setCursor(0,1);  
lcd.print("enough humidty");


Blynk.notify("S.Moisture: \n");
Blynk.notify(moistureValue);

if(moistureValue<30){
digitalWrite(pumpPin,HIGH);
Blynk.notify("need water");

  } 
  else{
digitalWrite(pumpPin,LOW);

  }
}