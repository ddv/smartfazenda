// Do not remove the include below
#include "smartfazenda_tregulator.h"

#include <Wire.h>
#include "DHT.h"

#define DHTPIN 2     // what pin we're conne

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)cted to

DHT dht(DHTPIN, DHTTYPE);
float h;
float t;
char recive_data[50];

int send_mode = 0;
volatile boolean led = false;

String event = "";

void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
	Wire.begin(4);                // join i2c bus with address #4
	Wire.onRequest(requestEvent); // register event
	Wire.onReceive(receiveEvent); // register event

	dht.begin();
}

void loop() {

	if (led) {
		digitalWrite(13, HIGH);
	} else {
		digitalWrite(13, LOW);
	}

//  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(2000);              // wait for a second
//   digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//   delay(100);              // wait for a second

	h = dht.readHumidity();
	// Read temperature as Celsius (the default)
	t = dht.readTemperature();

	// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t)) {
		return;
	}

	// Compute heat index in Celsius (isFahreheit = false)
	float hic = dht.computeHeatIndex(t, h, false);


}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
	if (send_mode == 0) {

		char t_str[15];
		dtostrf(t, 4, 1, t_str);
		char mqtt_t[] = "/smarthome/t\n";
		strcat(mqtt_t, t_str);
		strcat(mqtt_t, "\n");
		Wire.write(mqtt_t); // respond with message of 6 bytes
		send_mode = 1;
	} else if (send_mode == 1) {

		char h_str[15];
		dtostrf(h, 4, 1, h_str);
		char mqtt_h[] = "/smarthome/h\n";
		strcat(mqtt_h, h_str);
		strcat(mqtt_h, "\n");
		Wire.write(mqtt_h); // respond with message of 6 bytes
		send_mode = 2;
	} else {

		char out[50];
		event.toCharArray(out, 50);
		Wire.write(out); // respond with message of 6 bytes
		send_mode = 0;

	}
//  Wire.write(t_str); // respond with message of 6 bytes

//  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
//     delay(100);              // wait for a second
//     digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//     delay(100);              // wait for a second
	// as expected by master
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {


//	while (0 < Wire.available())	// loop through all but the last
//	{
//		char c = Wire.read(); // receive byte as a character
//	}

//	digitalWrite(13, HIGH);
//	delay(200);
//	digitalWrite(13, LOW);
//
//	if (true)
//		return;


//	String event2 = "/";
//	while (1 < Wire.available())// loop through all but the last
//	{
//		char c = Wire.read(); // receive byte as a character
//		event2.concat(c);
//	}
//
//	String stringVar =  String(howMany, DEC);
//	event2 += stringVar;
//	event2 += "\n";
//	event = event2;

	String tag = "/arduinopromini/";
	String val = "";
	boolean tag_end = false;
	boolean val_end = false;

//	for (int i = 0; i < howMany; i++) {
	while (0 < Wire.available()) {
		char c = Wire.read(); // receive byte as a character

		//find end of tag
		if (c == '\n' && !tag_end) {
			tag_end = true;
			continue;
		}
		//find end of value
		if (c == '\n' && tag_end) {
			val_end = true;
			continue;
		}

		if (val_end) {
			continue;
		}

		if (!tag_end) {
			tag.concat(c);
		} else {
			val.concat(c);
		}
	}

	if(val.equals("1")) {
		led=true;
	} else {
		led=false;
	}



	tag += "\n";
	tag += val;
	tag += "\n";
	event = tag;







}
