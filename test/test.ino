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
  Serial.println("Waiting for input...");
  do{
    a = Serial.parseInt();
    }while(a==0);
  
  servo.write(a);



  
}
