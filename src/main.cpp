#include <Arduino.h>

#include "ultrasonic.h"
#include "servo_motor.h"

// A car is in front of a sensor if it is closer than this distance (in cm)
#define CAR_DISTANCE  15

bool car_at_entry() {
  int distance = ultrasonic_entry_distance();
  delay(50);  // wait between two measures so the echoes don't mix

  // 0 means "nothing detected"
  return distance > 0 && distance < CAR_DISTANCE;
}

bool car_at_exit() {
  int distance = ultrasonic_exit_distance();
  delay(50);  // wait between two measures so the echoes don't mix

  return distance > 0 && distance < CAR_DISTANCE;
}

void setup() {
  Serial.begin(9600);
  ultrasonic_init();
  servo_motor_init();
}

void loop() {
  // A car wants to enter
  if (car_at_entry()) {
    Serial.println("Car at entry -> opening the gate");
    servo_motor_open_gate();

    // Wait until the car reaches the exit sensor...
    while (!car_at_exit()) {
    }
    Serial.println("Car at exit");

    // ...then wait until it has passed it
    while (car_at_exit()) {
    }

    delay(1000);
    Serial.println("Car passed -> closing the gate");
    servo_motor_close_gate();
  }

  // A car wants to leave
  if (car_at_exit()) {
    Serial.println("Car at exit -> opening the gate");
    servo_motor_open_gate();

    // Wait until the car reaches the entry sensor...
    while (!car_at_entry()) {
    }
    Serial.println("Car at entry");

    // ...then wait until it has passed it
    while (car_at_entry()) {
    }

    delay(1000);
    Serial.println("Car passed -> closing the gate");
    servo_motor_close_gate();
  }
}
