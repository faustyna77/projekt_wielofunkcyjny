
#include <Arduino.h>

#include <Servo.h>
#define analog A0
#define ledy 10
#define motor 11
#define dc 6
#define pwmdc 7
#define btn 2
#define btnstop 3

int var;
int var2;
long int start=millis();
long int start2=millis();

long int now;
Servo myservo;
 void rotateServo();
 void on();



void setup()
{
  Serial.begin(9600);
  pinMode(analog,INPUT);
  pinMode(ledy,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(12,OUTPUT);
   pinMode(8,OUTPUT);
    pinMode(4,OUTPUT);
     pinMode(5,OUTPUT);
     pinMode(7,OUTPUT);
     pinMode(6,OUTPUT);
     pinMode(btn,INPUT_PULLUP);
     pinMode(btnstop,INPUT_PULLUP);
     start=millis();
     Serial.println(start);
     
     myservo.attach(9);
     delay(500);
    
    
   

}

void writeled();
void motors();
void motorDC();
void servowrite();
void on();
void offFUNC();


void loop()

{
  var= analogRead(analog);
  
  now=millis();
  
  writeled();
  motorDC();
  if(millis()-start>=200)
  {

    motors();
    start=millis();
    
  }

  if(millis()-start2>=5000)
  {
     on();
     offFUNC();
    start2=millis();
    
  }
 

  

}
void on()
{
  
  for(int s=0;s<=180;s++)
  {
    myservo.write(s);
    delay(10);

  }
}
void offFUNC()
{
  for(int k=180;k>=0;k--)
  {
    myservo.write(k);
    delay(10);
  }
}
void writeled()
{
  var2=map(var,0,1023,0,255);
  analogWrite(ledy,var2);
}

void motors()
{

   for(int i=0;i<100;i++)
   {
    digitalWrite(12,HIGH);
    delay(3);
    digitalWrite(12,LOW);
  
    digitalWrite(8,HIGH);
    delay(3);
    digitalWrite(8,LOW);
     digitalWrite(4,HIGH);
    delay(3);
    digitalWrite(4,LOW);
     digitalWrite(5,HIGH);
    delay(3);
    digitalWrite(5,LOW);
   }


}


void motorDC()
{
  digitalWrite(dc,var2);
  analogWrite(pwmdc,LOW);

}

void servowrite()
{
  for(int s=0;s<=180;s++)
  {
    myservo.write(s);
    delay(10);
    

  }
  for(int k=180;k>=0;k--)
  {
    myservo.write(k);
    delay(10);
    
  }
}


