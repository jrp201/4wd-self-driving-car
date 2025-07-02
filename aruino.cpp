#include <AFMotor.h>

// Define motors
AF_DCMotor motor1(1);  // Left Front
AF_DCMotor motor2(2);  // Left Rear
AF_DCMotor motor3(3);  // Right Front
AF_DCMotor motor4(4);  // Right Rear

// Ultrasonic Pins
#define trigFront 8
#define echoFront 9
#define trigLeft 10
#define echoLeft 11
#define trigRight 12
#define echoRight 13

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void moveForward() {
  motor1.setSpeed(150); motor1.run(FORWARD);
  motor2.setSpeed(150); motor2.run(FORWARD);
  motor3.setSpeed(150); motor3.run(FORWARD);
  motor4.setSpeed(150); motor4.run(FORWARD);
}

void moveBackward() {
  motor1.setSpeed(150); motor1.run(BACKWARD);
  motor2.setSpeed(150); motor2.run(BACKWARD);
  motor3.setSpeed(150); motor3.run(BACKWARD);
  motor4.setSpeed(150); motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.setSpeed(100); motor1.run(BACKWARD);
  motor2.setSpeed(255); motor2.run(FORWARD);
  motor3.setSpeed(255); motor3.run(FORWARD);
  motor4.setSpeed(100); motor4.run(BACKWARD);
}

void turnRight() {
  motor1.setSpeed(255); motor1.run(FORWARD);
  motor2.setSpeed(100); motor2.run(BACKWARD);
  motor3.setSpeed(100); motor3.run(BACKWARD);
  motor4.setSpeed(225); motor4.run(FORWARD);
}

void setup() {
  pinMode(trigFront, OUTPUT);
  pinMode(echoFront, INPUT);
  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  long front = readDistance(trigFront, echoFront);
  long left = readDistance(trigLeft, echoLeft);
  long right = readDistance(trigRight, echoRight);

  Serial.print("Front: "); Serial.print(front);
  Serial.print(" Left: "); Serial.print(left);
  Serial.print(" Right: "); Serial.println(right);

  if (front < 20) {
    stopMotors();
    delay(300);
    if (left > right) {
      turnLeft();
    } else {
      turnRight();
    }
    delay(500);
  } else {
    moveForward();
  }

  delay(100);
}
