#include <Servo.h> 
Servo servo;
int eastLDR = A0;
int westLDR = A1;
int east = 0;
int west = 0;
int error = 0;
int LDR=A2;
int lvalue=0;
int servoposition=80;
void setup()
{
Serial.begin(9600);
pinMode(LDR,INPUT);
pinMode(eastLDR,INPUT);
pinMode(westLDR,INPUT);
// pinMode(servoposition,OUTPUT);
servo.attach(9);
servo.write(80);
delay(1000);
}
  
void loop ()
{
east =analogRead(eastLDR); 
west = analogRead(westLDR);
lvalue=analogRead(LDR);
error = abs(west-east);
Serial.println(servoposition);
Serial.println("and");
Serial.println(lvalue);
Serial.println("and");
Serial.println(east);
Serial.println("and");
Serial.println(west);
Serial.println("of");
Serial.println(error);
Serial.println("---");
if(lvalue<0)
{
    while(servoposition >80)
    {
      servoposition--;
      servo.write(servoposition);
      delay(100);
    }
}
else 
{
    if(error>10 && east > west)
    {
      if (servoposition >=80)
      {
        servoposition--;
      }
        servo.write(servoposition);
        
    }
    else if (error>10 && east < west)
    {
      if (servoposition <=180)
      {  
        servoposition++;
      }
        servo.write (servoposition);  
    }
    delay (100);
      
    
}
}
