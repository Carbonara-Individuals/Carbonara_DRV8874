Getting Started
===============

Include the library:

.. code-block:: cpp

   #include <Carbonara_DRV8874.h>

Create a motor:

.. code-block:: cpp

   Carbonara_DRV8874 motor(EN, PH, SLEEP);

Initialize:

.. code-block:: cpp

   motor.begin();

Control:

.. code-block:: cpp

   motor.set(0.5);
