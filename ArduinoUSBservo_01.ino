#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9); // Attach servo to pin 9
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'R') {
      myServo.write(90); // Move servo right
    } else if (command == 'L') {
      myServo.write(0); // Move servo left
    }
  }
}

