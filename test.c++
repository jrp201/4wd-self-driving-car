#include <AFMotor.h>

AF_DCMotor motor1(1); // Connect one motor to M1
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  motor1.setSpeed(255);
  motor2.setSpeed(180);
  motor3.setSpeed(150);
  motor4.setSpeed(255);    // Speed: 0 to 255
}

void loop() {
  motor1.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor4.run(FORWARD);      // Run the motor forward
  delay(100);
}
