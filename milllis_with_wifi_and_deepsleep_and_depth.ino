

#include <ESP32Servo.h>

unsigned long now;
unsigned long last = 0;
Servo myservo;
 const int trig = 18;
const int echo = 19;

int dist ;
long dur ;
int thresh[3] ={5,15,32};

RTC_DATA_ATTR const int pir = 12;
int distance;
int led = 13;
const int trigPin=2;
const int echoPin=5;

int servoPin=4;
long duration;


void setup()
{ 
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led,OUTPUT);
   pinMode(echo, INPUT);
 pinMode(trig,OUTPUT);
  Serial.begin(115200);

  

}

void loop()
{  
  

 
 Serial.println("just woke up ");
 digitalWrite(led,HIGH);
 
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration = pulseIn(echoPin,HIGH);
 distance=duration*(0.034/2);
 Serial.print("distance:");
 Serial.println(distance);
 last = millis();
 Serial.print("last");
 Serial.println(last);
 if (distance<65)
 {
  myservo.write(0);
  delay(2000);
 }
 if (distance>=65)
 {
  myservo.write(90);
  delay(2000);
 
  
  }
  digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);
 dur = pulseIn(echo,HIGH);
 dist=dur*(0.034/2);
 Serial.print("distance");
 Serial.println(dist);
 if (dist<thresh[0])
 {
  Serial.print("100%");
 }
 if(dist<thresh[1])
 {
  Serial.print("60%");
 }
 if (dist<thresh[2])
{
  
  Serial.print("20%");
}
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_12,HIGH);
  
 
 while((last - now )> (10000))
 {
  Serial.println("going to sleep");
   now = millis();
  Serial.print("now");
  Serial.println(now);
  esp_deep_sleep_start();
  delay(500);
 
  
}}
