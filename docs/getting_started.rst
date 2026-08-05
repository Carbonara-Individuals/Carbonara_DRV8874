Getting Started
===============

Before we begin, make sure to have the `Arduino IDE <https://docs.arduino.cc/software/ide/>`_ installed as this tutorial will be based on it. Additionally, make sure you also have the IDE set up for your board.


Setup
-----

| 1. Go to the Arduino IDE and open the Library Manager (**Sketch** > **Include Library** > **Manage Libraries...**) 
| 2. Search for "Carbonara_DRV8874" and click the **Install** button.
| 3. Restart the Arduino IDE to ensure the library is properly loaded.
| 4. Create a new sketch (File > New) and save it.

Basics
------

With setup out of the way, let's get started with the basics. First, we are going to include the library in our sketch:

.. code-block:: cpp

   #include <Carbonara_DRV8874.h>

This gives us access to the library's functions and classes.

.. note::
   Make sure to include the library outside the :cpp:func:`setup()`and :cpp:func:`loop()` functions!

Currently, our script does not know what pins are used or if a motor exists. So to solve that, we can define the pins and create a motor driver instance.

.. code-block:: cpp

   Carbonara_DRV8874 motor(EN, PH, SLEEP);

Within the parentheses, there are three required pins: **EN**, **PH**, and **SLEEP**. **EN** is the enable pin which allows for the motor to have variable speed. **PH** is the phase pin that allows for the motor to turn backwards or forwards. Lastly, the **SLEEP** pin is used to turn off and on the driver.

Now with the motor driver instance defined, we can move to starting the motor. To do this, we need to call the :cpp:func:`begin` function.

.. code-block:: cpp

   motor.begin();


Finally, we can now control the motor! We can do this by simply calling:

.. code-block:: cpp

   motor.set(0.5);

This allows to control the motor on a -1 to 1 scale where -1 is full speed backwards, 0 is stopped, and 1 is full speed forwards.

Full Script
-----------

Now, if everything is done correctly, the full script should look like this:

.. code-block:: cpp

   #include <Carbonara_DRV8874.h>

   Carbonara_DRV8874 myMotor(1, 2, 3); // These are placeholder pins!

   void setup() {
      myMotor.begin();
   }

   void loop() {
      myMotor.set(0.5); // This will run the motor at half speed forwards
   }

Congratulations! You have successfully set up the library and are now able to control your motor. For more advanced features, check out the advance articles below! For a full reference guide, check out the :ref:`API Reference <api_reference>` section for more information!