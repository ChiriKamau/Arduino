int Soil_moisture = 28;
int LED =6;

void setup(){
pinMode(LED,OUTPUT);
Serial.begin(9600);
}
void loop(){
int moisture=analogRead(Soil_moisture);
Serial.println(moisture);
if(moisture<500){
digitalWrite(LED,HIGH);
}
else{
digitalWrite(LED,LOW);
}
}