#ifndef ULTRASONIC_H
#define ULTRASONIC_H

// =============================================================================
// Ultrasonic module
// Reads the two ultrasonic sensors (entry and exit).
// =============================================================================

void ultrasonic_init();

// Distance in cm (0 means nothing detected)
int ultrasonic_entry_distance();
int ultrasonic_exit_distance();

// Test: prints the two distances on the Serial monitor
void ultrasonic_test();

#endif // ULTRASONIC_H
