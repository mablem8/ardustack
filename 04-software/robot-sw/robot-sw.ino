#include <Servo.h>

Servo headServo;
Servo tailServo;

int headServoPosn = 0;
int tailServoPosn = 0;

void setup() {
  headServo.attach(3);
  tailServo.attach(11);
  delay(1000);
  headServo.write(100);
  delay(1000);
  tailServo.write(100);
  delay(1000);
}

void loop() {
  while(tailServo.read()<115) {
    tailServo.write(tailServo.read()+1);
    delay(50);
  }
  delay(200);
  while(headServo.read()<110) {
    headServo.write(headServo.read()+1);
    delay(50);
  }
  delay(200);
  while(tailServo.read()>85) {
    tailServo.write(tailServo.read()-1);
    delay(50);
  }
  delay(200);
  while(headServo.read()>90) {
    headServo.write(headServo.read()-1);
    delay(50);
  }
  delay(200);
}
