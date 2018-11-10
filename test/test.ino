#include <Servo.h>
Servo servo;

int diff = 1;
int ang = 0;

int timer,ntimer;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  servo.attach(3);
  servo.write(ang);
  timer = millis();
}


void loop() {
//  if(Serial.available()){
//    int SerialValue;
//    SerialValue = Serial.parseInt();
//    Serial.print(SerialValue);Serial.print("\t");
//    servo.write(SerialValue);
//    
//    int readValue;
//    readValue = pulseIn(9,HIGH);
//    Serial.println(readValue);
//    }

//    int readValue;
//    readValue = pulseIn(9,HIGH);
//    if(readValue != 0)Serial.println(readValue);
switch (timer / 4){
  case 0:
    diff = 6;break;
  case 1:
    diff = -2;break;
  case 2:
    diff = -3;
  }

if (ang < 6) diff = 10;
else if (ang > 174) diff = -10;


ang = ang + diff;
//Serial.println( ang);
servo.write(ang);
ntimer = millis();
Serial.println(ntimer - timer);
timer = ntimer;
delay(47);
}
