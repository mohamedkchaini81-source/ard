#include <Arduino.h>
#include <NewPing.h>

#include "ultrasonic.h"
#include "pins.h"

// Maximum distance we want to measure (in cm)
#define MAX_DISTANCE    200

NewPing entrySensor(ENTRY_TRIG_PIN, ENTRY_ECHO_PIN, MAX_DISTANCE);
NewPing exitSensor(EXIT_TRIG_PIN, EXIT_ECHO_PIN, MAX_DISTANCE);

void ultrasonic_init() {
  Serial.println("Ultrasonic sensors test");
}

int ultrasonic_entry_distance() {
  return entrySensor.ping_cm();
}

int ultrasonic_exit_distance() {
  return exitSensor.ping_cm();
}

void ultrasonic_test() {
  int entryDistance = ultrasonic_entry_distance();
  delay(50);  // wait between the two sensors so their echoes don't mix
  int exitDistance = ultrasonic_exit_distance();

  Serial.print("Entry: ");
  Serial.print(entryDistance);
  Serial.print(" cm\tExit: ");
  Serial.print(exitDistance);
  Serial.println(" cm");

  delay(500);
}
