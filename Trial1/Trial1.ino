#include <AFMotor.h>
#include <Servo.h>

Servo door, bucket; // arm: ser1; bucket: ser2
AF_DCMotor Lmotor(3),Rmotor(4);

int Speed[]         = {200,170, 200,170}; 
// {Driving speed(L/R)  Turning speed(L/R)}

int door_range[]      = {0, 180};  // {open, close}
int door_pos          = door_range[1];
int door_closing_step = 10;

int bucket_range[]  = {50, 145}; // {up, down}
int bucket_pos      = bucket_range[0];
int bucket_down_step = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Let's get started!");

  bucket.attach(10); //
  bucket.write(bucket_range[0]);
  door.attach(9);
  door.write(door_pos);
  
  
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
      motorControl('F', Speed[0], Speed[1]);
      break;

    case 2: // backward
      Serial.println("Backward");
      motorControl('B', Speed[0], Speed[1]);
      break;

    case 3: // turn left
      Serial.println("Left");
      motorControl('L', Speed[2], Speed[3]);
      break;

    case 4: // turn right
      Serial.println("Right");
      motorControl('R', Speed[2], Speed[3]);
      break;

    case 5: // bucket up
      motorControl('S', 0, 0);
      bucket_pos = bucket_range[0];
      bucket.write(bucket_pos);
      break;
    case 6: // bucket down
      motorControl('S', 0, 0);
      if(bucket_pos != bucket_range[1])bucket_pos += bucket_down_step;
      bucket.write(bucket_pos);
      break;
    case 7: // door open
      motorControl('S', 0, 0);
      if(door_pos != door_range[0]) door_pos -= door_closing_step;
      door.write(door_pos);
      break;
    case 8: // door close
      motorControl('S', 0, 0);
      door_pos = door_range[1];
      door.write(door_pos);
      break;
    case 9: // forward left only
      Serial.println("Forward");
      motorControl('F', Speed[0], 0);
      break;
    case 10: // forward right only
      Serial.println("Forward");
      motorControl('F', 0, Speed[1]);
      break;

    case 11: // backward left only
      Serial.println("Backward");
      motorControl('B', Speed[0], 0);
      break;
    case 12: // backward right only
      Serial.println("Backward");
      motorControl('B', 0, Speed[1]);
      break;
      
      
    
    default: // stops the motor
      Serial.println("Stopping");
      motorControl('S', 0, 0);
    }
//  delay(200);
//  motorControl('S', 0, 0);
  
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
