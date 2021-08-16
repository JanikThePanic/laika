#include <Arduino.h>
#include <Leg.h>

// define pins for legs
// these dont change
int frontLeftPins[] = {9, 10, 11};
int frontRightPins[] = {1, 2, 3};
int backLeftPins[] = {1, 2, 3};
int backRightPins[] = {1, 2, 3};

Leg myLeg;

int pos = 20; // variable to store the servo position
int poses[] = {0, 0, 0};

void setup()
{
	myLeg.attach(frontLeftPins);
}

void loop()
{
	for (pos = 20; pos <= 180; pos += 2)
	{
		poses[2] = pos;
		poses[0] = pos;
		myLeg.write(poses);
		delay(15); // waits 15ms for the servo to reach the position
	}
	for (pos = 180; pos >= 20; pos -= 2)
	{
		poses[2] = pos;
		poses[0] = pos;
		myLeg.write(poses);
		delay(15); // waits 15ms for the servo to reach the position
	}
}