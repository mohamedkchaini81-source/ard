#include <Arduino.h>
#include <Servo.h>

#include "servo_motor.h"
#include "pins.h"

Servo gateServo;

void servo_motor_init() {
  Serial.println("Servo motor test");

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);
}

void servo_motor_open_gate() {
  // Open the gate slowly: from 0 to 90 degrees, one degree at a time
  for (int angle = 0; angle <= 90; angle++) {
    gateServo.write(angle);
    delay(15);
  }
}

void servo_motor_close_gate() {
  // Close the gate slowly: from 90 back to 0 degrees
  for (int angle = 90; angle >= 0; angle--) {
    gateServo.write(angle);
    delay(15);
  }
}

void servo_motor_test() {
  Serial.println("Opening");
  servo_motor_open_gate();
  delay(1000);

  Serial.println("Closing");
  servo_motor_close_gate();
  delay(1000);
}
