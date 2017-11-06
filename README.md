# hopper-metering-tool
Uses an Arduino to meter coins out of an Suzohapp MKII Cube Hopper at an exact interval. 

This works great and is used in production.

Tasks for next build:
  * Post a picture of the current build.
  * Test if the whole hopper can be turned off instead of just the motor. 
  * It would be nice to print a circuit board for this.

***

It gets input from the cube hopper's open-collector output time the power on the motor. 

A general page on an open-collector circuit details:  http://www.evilmadscientist.com/2012/basics-open-collector-outputs/

Hopper Wiring Notes:
* Only 5 wires need to connect to the hopper: (Pretend it does not have power like a Ryedale) 
* A	6# (Signal) 
* B 	8# (Ground) 
* C	9# (12V Positive) 
* D	Black from the motor (Positive: Hopper is wired backwards from the factory)
* E	Red from the motor (Ground: Hopper is wired backwards from the factory)
* The motor is no longer connected to the hopper control board. 

Arduino Takes 12V in with the Barrel jack 
* A	To Arduino Pin 0
* B 	Ground on the Arduino
* 	Solenoid NC
* 	Ground PIN on the Relay board
* 	E (Ground - Red on Motor) 
* C	VIN on the Arduino
* 	Solenoid NO	
* E	Solenoid COM

Wire:
* 5V Arduino To 4700 Ohm then Arduino Pin 0

Relay Module Board Controls:
* (The input pins must be pulled to ground for the relay to turn on. )
* VIN to 5V on the Arduino
* Input 2 to PIN 9 on the Arduino
* Ground to Ground
