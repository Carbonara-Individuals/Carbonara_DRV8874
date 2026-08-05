Advanced Features
==================

Welcome to the advanced features section of the Carbonara_DRV8874 library! This section will cover some of the extra features as well as some advance features of this library. If you haven't alraedy, please visit the :ref:`Getting Started <getting_started>` section!


Additional Features
-------------------

These are features that are not required to use in the library, but also do not require any extra wiring or hardware to use.

.. cpp:function:: void setBrakeMode(bool isBrakeMode)

		Sets the brake mode of the motor. When enabled, the motor would stop immediately. When not enabled, the motor would coast to a stop.
		
		:param bool isBrakeMode: The input boolean value to set the brake mode.

		**Example usage:**

		::

			myMotor.setBrakeMode(true);
			
		Enables the brake mode of the motor.
		   

.. cpp:function:: void setInverted(bool isInverted)

		Sets the inverted state of the motor. When enabled, the motor would rotate in the opposite direction.
		
		:param bool isInverted: The input boolean value to set the inverted state.

		**Example usage:**

		::

			myMotor.setInverted(true);
			
		Sets the motor to inverted mode.


Sensing Features
----------------

One of the neat parts of this library/IC is the built in ability to sense issues with the IC! This is done via 2 extra pins on the IC, the **nFAULT** pin and the **IPROPI** pin. This allows for the sensing features below!

.. important::
    The sensing pins must also be connected to your microcontroller. These are reading pins unlike the other pins. However, one thing to note is to wire the **nFAULT** pin to a digital pin and the **IPROPI** pin to a PWM pin!

.. cpp:function:: void beginSensing(int faultPin, int iPropIPin)

		Sets up the sensing pins for the motor driver.

		:param int faultPin: The pin connected to the nFAULT pin of the IC.
		:param int iPropIPin: The pin connected to the IPROPI pin of the IC.

		**Example usage:**

		::

			myMotor.beginSensing(10, 11);
			
		Sets up the sensing pins for the motor driver.
		**Example usage:**

		::

			myMotor.setBrakeMode(true);
			
		Enables the brake mode of the motor.

.. cpp:function:: bool isFault()

		Checks if the motor driver is in a fault state. When an issue happens such as overcurrent, thermal shutdown, undervoltage lockout, etc, this function returns true. Otherwise, it returns false.

		**Example usage:**

		::

			float myVariable = myMotor.isFault();
			
		Sets the fault state of the IC to a variable.

.. cpp:function:: float getCurrent()

		This checks the current input in the motor driver and returns a value based on the input.

        .. important::
            Typically the returned value and value range is different based on microcontrollers, so please check what that is for your microcontroller!

		**Example usage:**

		::

			float myVariable = myMotor.getCurrent();
			
		Sets the current input of the IC to a variable.

Pin Recongifuration
-------------------

These are some functions that allow you to change an pin at any time during runtime. They include all 5 pins shown in this documentation.

- :cpp:func:`configEnablePin()`
- :cpp:func:`configPhasePin()`
- :cpp:func:`configSleepPin()`
- :cpp:func:`configFaultPin()`
- :cpp:func:`configIPropIPin()`

.. note::
    For more information on pins, please visit the :ref:`API Reference <api_reference>`!