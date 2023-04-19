#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int IRsensor = 1;

void setup()
{
	// initialize the LCD
lcd.begin();
pinMode(IRsensor,INPUT);	
// pinMode(LED,OUTPUT);

}

void loop()
{
digitalRead(IRsensor);
int val=digitalRead(IRsensor);
if(val==0){
// digitalWrite(LED,HIGH);
lcd.setCursor(2,0);   
	lcd.print("Intruder");
	lcd.setCursor(2,1);
	lcd.print("Lights off");
}
else{
// digitalWrite(LED,LOW);
lcd.setCursor(2,0);
	lcd.print("NO Intruder");
	lcd.setCursor(2,1);
	lcd.print("Lights on");
}

}
