API Reference
=============

Basic Features
--------------

.. cpp:function:: void Carbonara_DRV8874 motor(int EN, int PH, int SLEEP)

		Initializes the motor instance and inital pins.
		
		:param int EN: The ADC pin connected to the EN pin of the IC.
        :param int PH: The digital pin connected to the PH pin of the IC.
        :param int SLEEP: The digital pin connected to the SLEEP pin of the IC.

		**Example usage:**

		::

			Carbonara_DRV8874 myMotor(1, 2, 3);
			
		Uses pins 1, 2, and 3 for initialization.


.. cpp:function:: void begin()

		Starts the IC driver.

		**Example usage:**

		::

			myMotor.begin();
			
		Starts the driver.

        .. note::
            This function must be in the :cpp:func:`setup()` function.



.. cpp:function:: void set(int motorSpeed)

		Sets the speed of the motor.
		
		:param int motorSpeed: The input speed value from -1 to 1.

		**Example usage:**

		::

			myMotor.set(0.5);
			
		Sets the speed of the motor at half speed forward.


Advanced Features
-----------------

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


Pin Recongifurations
--------------------

.. cpp:function:: void configEnablePin(int enablePin)

		Reconfigures the enable pin to a different pin.
		
		:param int enablePin: The new enable pin number.

		**Example usage:**

		::

			myMotor.configEnablePin(1);
			
		Sets the new enable pin to 1.


.. cpp:function:: void configPhasePin(int phasePin)

		Reconfigures the phase pin to a different pin.
		
		:param int phasePin: The new phase pin number.

		**Example usage:**

		::

			myMotor.configPhasePin(2);
			
		Sets the new phase pin to 2.


.. cpp:function:: void configSleepPin(int sleepPin)

		Reconfigures the sleep pin to a different pin.
		
		:param int sleepPin: The new sleep pin number.

		**Example usage:**

		::

			myMotor.configSleepPin(3);
			
		Sets the new sleep pin to 3.


.. cpp:function:: void configFaultPin(int faultPin)

		Reconfigures the fault pin to a different pin.
		
		:param int faultPin: The new fault pin number.

		**Example usage:**

		::

			myMotor.configFaultPin(4);
			
		Sets the new fault pin to 4.


.. cpp:function:: void configIpropIPin(int iPropIPin)

		Reconfigures the IpropI pin to a different pin.
		
		:param int iPropIPin: The new IpropI pin number.

		**Example usage:**

		::

			myMotor.configIpropIPin(5);
			
		Sets the new IpropI pin to 5.
