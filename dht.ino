
#include <dht11.h>
#define dht_apin 11
dht11 dhtObject;






void setup() {
  Serial.begin(9600); 
  // put your setup code here, to run once:

}

void loop() {
dhtObject.read(dht_apin);
int temp = dhtObject.temperature;
dhtObject.read(dht_apin);
int humidity = dhtObject.humidity;
Serial.println("temp=");
Serial.println(temp);
delay(1000);
Serial.println("humidity=");
Serial.println(humidity);
delay(1000);

}
