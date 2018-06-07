#pragma config(Sensor, in1,    marbleColorSensor, sensorLineFollower)
#pragma config(Sensor, dgtl1,  yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  green,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  red,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           shooter,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           servo,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          dispenser,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Light blue
const int aLower = 2000; //TODO
const int aUpper = 2600; //TODO

// Green
const int bLower = 2200; //TODO
const int bUpper = 2400; //TODO

// White
const int cLower = 0; //TODO
const int cUpper = 1300; //TODO

int getMarbleColor() {
	return SensorValue[marbleColorSensor];
}

bool marblePresent() {
	int color = getMarbleColor();
	return (aLower < color && color < aUpper) || (bLower < color && color < bUpper) || (cLower < color && color < cUpper);
}

void dispense() {
	motor[servo] = 127; //TODO maybe change
	delay(1000)
	motor[servo] = -127;
	delay(1000)
	motor[servo] = 0;
	/*while (marblePresent()) {}
	int lastVal = getMarbleColor();
	while(!marblePresent()) {}*/
	/*while (getMarbleColor() > aUpper || getMarbleColor() < (lastVal + 25)) {
		lastVal = getMarbleColor();
		SensorValue[green] = true;
	}
	SensorValue[green] = false;*/
	// delay(1);
	motor[dispenser] = 0;
}

const int lowSpeed = -45; //TODO
const int medSpeed = -80; //TODO
const int highSpeed = -80; //TODO

task main() {
	for (;;) {
		if (marblePresent()) {
			int color = getMarbleColor();
			SensorValue[red] = false;
			SensorValue[yellow] = false;
			SensorValue[green] = false;
			if (aLower < color && color < aUpper) {
				SensorValue[red] = true;
				motor[shooter] = highSpeed;
				delay(1000);
			} else if (/*cLower < color &&*/ color < aLower) {
				SensorValue[yellow] = true;
				motor[shooter] = lowSpeed;
				delay(1000);
			}
			// delay(1500);
			motor[servo] = 127; //TODO maybe change
			delay(1000)

		}
		motor[servo] = -127;
		delay(1000);
		motor[servo] = 0;
		delay(1000);
	}
}
