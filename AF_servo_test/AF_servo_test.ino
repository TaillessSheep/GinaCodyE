#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  servo.attach(10);
}
int a;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Waiting for input...");
  do{
    a = Serial.parseInt();
    }while(a==0);
  
  Serial.println(a);
  servo.writeMicroseconds(a);
//  servo.write(100);
//  delay(2000);
//  servo.writeMicroseconds(2000);
//  delay(1000);


  
}
