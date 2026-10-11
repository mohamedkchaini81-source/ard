#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

// =============================================================================
// Servo motor module
// Opens and closes the parking gate.
// =============================================================================

void servo_motor_init();

void servo_motor_open_gate();
void servo_motor_close_gate();

// Test: opens and closes the gate, printing on the Serial monitor
void servo_motor_test();

#endif // SERVO_MOTOR_H
