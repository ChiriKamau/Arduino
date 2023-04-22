
#include<Servo.h>
Servo myServo;
int trigger=13;
int echo =12;
int A=5;
int B=6; //controls the right wheel, for backward movements
int C=9;
int D=10; //controls the right wheel, for forward movements


void test_motor();
void obstacle();
int read_dist();
void motor_forward();
void motor_reverse();
void motor_stop();
void obstacle();
void left_turn();
void right_turn();
void u_turn();


void setup() {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

  //configure the servo motors
  myServo.attach(11); //this one is for scanning with the ultrasonic sensor
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  //make sure all motors are off; i.e the robot is stationary
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  pinMode(left_led, OUTPUT);
  pinMode(right_led, OUTPUT);
  pinMode(uturn_led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //lets just test the motor
  test_motor();
}



void loop() {
  //test servo motor
  //test_motor();

  //read from ultrasonic sensor
  int cm = read_dist();
  
  motor_forward();
  motor_stop();

  //obstacle? Time to change course
  obstacle();
  
}
  

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2 ;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2 ;
}


void test_motor()
{

  /**
   * test_motor - chcek the working of the motors by asking it to momentarily move forward, then back
   */
  digitalWrite(A,HIGH);
  delay(500);
  // digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  delay(500);
  digitalWrite(D,HIGH);
  delay(500);
  digitalWrite(D,LOW);
  delay(500);
  digitalWrite(B,HIGH);
  delay(500);
  digitalWrite(B,LOW);
  delay(500);
}

int read_dist()
{
  /**
   * read_dist - code by the ultrasonic sensor to read the distance ahead
   * 
   * Return: the distance, in centimeters
   */
  long duration, inches,cm;
  digitalWrite(trigger,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  duration = pulseIn(echo, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print(" in ");
  Serial.print(cm);
  Serial.print(" cm ");  
  Serial.println();
  delay(1000);

  return (cm);
}

void motor_forward()
{
  /**
   * motor_forward - code to basically just drive the motor forward
   * 
   * Return: none
   */

   Serial.println("I am just moving on forward");
   while (read_dist() > 20)
   {
    digitalWrite(D, HIGH);
   }
}

void motor_reverse()
{
  /**
   * motor_reverse - code to basically drive the motor in reverse
   */

   digitalWrite(B, HIGH);
   myServo.write(360);
}

void motor_stop()
{
  /**
   * code to stop all movements of the robot
   */

   digitalWrite(D, LOW);
   digitalWrite(B, LOW);
}

void obstacle()
{
  digitalWrite(A,LOW);  
  myServo.write(180);//start by scanning the enviroment
  delay(1000);
  //I need to turn left, and close
  if (read_dist() > 20)
  {
    Serial.println("I am now trying to turn left");
    left_turn();
    return (NULL);
  }

  else
  {
    myServo.write(0);
    if (read_dist() > 20)
    {
      Serial.println("I am now trying to turn right");
      right_turn();
      return (NULL);
    }
    else
    {
      myServo.write(90);
      if (read_dist() > 20)
      {
        Serial.println("I am now trying to make a U-turn");
        u_turn();
        return (NULL);
      }
    }
  }
}

void left_turn()
{
  /**
   * left_turn - turn the bor to the left by 90 degrees
   */

   digitalWrite(LED_BUILTIN, HIGH);
   Serial.println("Is the blinker on, it should be, I'm turning left");
   //delay(1000);
}

void right_turn()
{
  /**
   * right_turn - turn the bot to the right by 90 degrees
   */

   digitalWrite(right_led, HIGH);
   Serial.println("Is my right blinker on? I am turning right");
   delay(1000);
   
}

void u_turn()
{
  /**
   * u_turn - turn the bot 180 degrees
   */

   digitalWrite(uturn_led, HIGH);
   Serial.println("Are you seeing this? I am making a U-turn");
   delay(1000);
}
