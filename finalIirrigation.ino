#include<Blynk.h>
#include<ESP8266WiFi.h>
#define LED 16
#define BLYNK_PRINT Serial
#include<BlynkSimpleEsp8266.h>
char auth[] = "YA3BfLCJkV0BdZJBS1_4iJUVyTodoHWA";
char ssid[] ="ocean";
char pass[] ="123go   ";
void setup() {
Serial.begin(115200);
Blynk.begin(auth,ssid,pass);
pinMode(LED,OUTPUT);
}
void loop(){
Blynk.run();
}