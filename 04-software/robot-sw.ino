#include <Servo.h>

Servo headServo;
Servo tailServo;

int headServoPosn = 0;
int tailServoPosn = 0;

void setup() {
  headServo.attach(3);
  tailServo.attach(11);
  delay(1000);
  headServo.write(90);
  delay(1000);
  tailServo.write(90);
  delay(1000);
}

void loop() {
  while(tailServo.read()<95) {
    tailServo.write(tailServo.read()+1);
    delay(33);
  }
  delay(100);
  while(headServo.read()<100) {
    headServo.write(headServo.read()+1);
    delay(33);
  }
  delay(100);
  while(tailServo.read()>85) {
    tailServo.write(tailServo.read()-1);
    delay(33);
  }
  delay(100);
  while(headServo.read()>80) {
    headServo.write(headServo.read()-1);
    delay(33);
  }
  delay(100);
}
