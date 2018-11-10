#include <AFMotor.h>
#include <Servo.h>

Servo arm, bucket; // arm: ser1; bucket: ser2
AF_DCMotor Lmotor(3),Rmotor(4);

//int bucket_range[] = [150 60];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Let's get started!");

  bucket.attach(10); //
  
  Lmotor.setSpeed(200);
  Lmotor.run(RELEASE);
  Rmotor.setSpeed(200);
  Rmotor.run(RELEASE);
  
}
int c;
void loop() {
  do{
    c =  Serial.parseInt();
    
  }while(c==0);
  switch(c){
    case 1: // forward
      Serial.println("Forward");
      motorControl('F', 200, 200);
      break;

    case 2: // backward
      Serial.println("Backward");
      motorControl('B', 200, 200);
      break;

    case 3: // turn left
      Serial.println("Left");
      motorControl('L', 100, 100);
      break;

    case 4: // turn right
      Serial.println("Right");
      motorControl('R', 100, 100);
      break;

//    case 5: // bucket up
//      motorControl('S', 0, 0);
//      bucket.write(bucket_range[0]);
//      break;
//    case 6: // bucket down
//      motorControl('S', 0, 0);
//      bucket.write(bucket_range[1]);
//      break;
    default: // stops the motor
      motorControl('S', 0, 0);
    }
//  delay(1000);
  
}

// ----------------------------------------------------------------

//int command(){
//  unsigned long timer = millis();
//  int c = Serial.parseInt();
////  while(mills() - timer < 3000){}
//
//  return c;
//  
//  }


//-------------------------------------------------------------------
void motorControl(char dir, int ls, int rs){
  // dir: diresction; ls: speed of left wheel; rs: speed of right wheel
  
  Lmotor.setSpeed(ls);
  Rmotor.setSpeed(rs);

  switch(dir){
    case 'F':
      Lmotor.run(FORWARD);
      Rmotor.run(FORWARD);
      break;
    case 'B':
      Lmotor.run(BACKWARD);
      Rmotor.run(BACKWARD);
      break;
    case 'L':
      Lmotor.run(BACKWARD);
      Rmotor.run(FORWARD);
      break;
    case 'R':
      Lmotor.run(FORWARD);
      Rmotor.run(BACKWARD);
      break;
    default:
      Lmotor.run(RELEASE);
      Rmotor.run(RELEASE);
      break;
    }
  
  }
