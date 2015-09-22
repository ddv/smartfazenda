// Do not remove the include below
#include "testProMini2.h"

int led = 13;

//The setup function is called once at startup of the sketch
void setup() {
	pinMode(led, OUTPUT);
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop() {
	digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(300);               // wait for a second
	digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
	delay(300);
//	digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//	delay(300);
//Add your repeated code here
}
