//
// Leg Class
// This is a class created to hold three servos, their poistions, and methods for controlling them
//

// for this class, there are three servos
// to establish order, the servos repesnt the following this order
// shoulder
// arm
// forarm

//  prevents problems if someone accidently #include's your library twice
#ifndef Leg_h
#define Leg_h

// we need the servo libaray for the servo objects
#include <Servo.h>

class Leg
{
private:
	// will hold this leg object's servo objects
	Servo servos[3];

public:
	// constructor
	Leg() {}

	// constuctor with parameteres will attach a pin to servos
	void attach(int servoPins[3])
	{
		// run through all of pins to attach
		for (int i = 0; i < 3; i++)
		{
			// attatch each servo to a pin
			servos[i].attach(servoPins[i]);
		}
	}

	// method that writes servo positions
	// designed to move all servos
	// param of array needed, an element per servo
	void write(int values[3])
	{
		// run through array of write values
		for (int i = 0; i < 3; i++)
		{
			// write servo value
			servos[i].write(values[i]);
		}
	}

	// method that writes a single servo
	// designed to move a single servo
	// params needed is the index of the servo, and the poistion
	void write(int index, int value)
	{
		servos[index].write(value);
	}

	// method that returns positions of all servos
	// returns pointer to array of values
	int *read()
	{
		static int readValues[3];

		// get all servo readings
		for (int i = 0; i < 3; i++)
		{
			readValues[i] = servos[i].read();
		}

		return readValues;
	}
};

#endif