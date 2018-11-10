#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  servo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.writeMicroseconds(1000);
  delay(2000);
  servo.writeMicroseconds(2000);
  delay(1000);


  
}
