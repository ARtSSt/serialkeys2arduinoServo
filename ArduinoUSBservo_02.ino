#include <Servo.h>

Servo myServo; 
const int servoPin = 9; 

int pos = 90;    // Initial position

void setup() {
  myServo.attach(servoPin);
  myServo.write(pos);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read(); 

    if (command == 'l') { 
      pos -= 15; 
    } else if (command == 'r') { 
      pos += 15; 
    }

    // Limit to the 0-180 range
    pos = constrain(pos, 0, 180); 
    myServo.write(pos); 
  }
}
