#include <Servo.h> // includes servo library
Servo ServoMotor;
int sensorAValue;
int sensorZValue;
int sensorA = 9;
int sensorZ = 10;
int LDR = A0; 
int LED = 2;
int WS = A3;
int ledPin = 13;
int ldrPin = A0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(sensorA, INPUT);
  pinMode(sensorZ, INPUT);
  ServoMotor.attach(11);
  ServoMotor.write(0);

}

void loop() 
{
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <=50) 
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite (ledPin, LOW);
  }
  sensorAValue = digitalRead(sensorA);
  sensorZValue = digitalRead(sensorZ);
  if(sensorAValue == LOW)
  {
    Serial.println("CLOSE");
    ServoMotor.write(140);
  }
  if(sensorZValue == LOW)
  {
    Serial.println("OPEN");
    ServoMotor.write(30);
  }
}
