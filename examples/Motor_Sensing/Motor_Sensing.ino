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
  myMotor.beginSensing(4, 5); // Initializes sensing pins (Must have sensing pins defined first!)
  /*
  4: Fault || Issue
  5. IpropI || Current (Must support ADC!)
  */
  
}

void loop() {
  // This basic script turns on the motor and checks the sensing pins.
  myMotor.set(1);

  myMotor.isFault(); // Checks fault pin if protection is active
  myMotor.getCurrent(); // Retrieves the active current in amps
}
