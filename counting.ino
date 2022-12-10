#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ir=1;
int count=0;
void setup()
{
	pinMode(ir,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
	lcd.begin();
  lcd.backlight();
}
void Display(){
  lcd.setCursor(0,0);
lcd.print(count);  
  
}
void loop(){
int val=digitalRead(ir);
if(val==1){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
}
else{
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  
}
  
}