#include <Carbonara_DRV8874.h>

// Define as much motors you want here: VVV
Carbonara_DRV8874 myMotor(1, 2, 3); // Replace these values with the pins you end up wiring!
/*
1: Enable || PWM (Must support PWM!)
2. Phase || Direction
3. Sleep || On or Off
*/

void setup() {
  myMotor.begin(); // Initializes the motor
}

void loop() {
  // This basic script turns on the motor for 3 seconds then turns it off for 3 seconds repeatedly.
  myMotor.set(1);
  delay(3000);
  myMotor.set(0);
  delay(3000);
}
