// Smart Fazend Relay Module
#include "smartfazenda_rm.h"
#include <Wire.h>
#include <avr/pgmspace.h>
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))

#define VALVE_1_PIN   8  // Порт Клапана №1
#define VALVE_2_PIN   9  // Порт Клапана №1
#define VALVE_3_PIN   10  // Порт Клапана №1
#define VALVE_4_PIN   11  // Порт Клапана №1

#define STATUS_PIN   13  // Информационная лампочка

// состояния клапанов
boolean valve_1_state = false;
boolean valve_2_state = false;
boolean valve_3_state = false;
boolean valve_4_state = false;

// Результат для последнего опроса I2C мастером
uint32_t last_status_result = 100;

void setup() {

	pinMode(VALVE_1_PIN, OUTPUT);
	pinMode(VALVE_2_PIN, OUTPUT);
	pinMode(VALVE_3_PIN, OUTPUT);
	pinMode(VALVE_4_PIN, OUTPUT);
	pinMode(STATUS_PIN, OUTPUT);

	Wire.begin(4);                // join i2c bus with address #4
	Wire.onReceive(receiveEvent); // register event
	Wire.onRequest(requestEvent); // register event
	Serial.begin(9600);           // start serial for output
	Serial.println(F("Slave"));
}

void loop() {
//	delay(1000);
//	Serial.println(F("Slave OK"));

	//Морагие лампочкой
	if (valve_1_state)
		blink(1, true);
	if (valve_2_state)
		blink(2, true);
	if (valve_3_state)
		blink(3, true);
	if (valve_4_state)
		blink(4, true);

	delay(500);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

	String s;
	while (Wire.available()) // loop through all but the last
	{
		char c = Wire.read(); // receive byte as a character
		s.concat(c);
	}

	if (s.compareTo(F("VALVE_1_ON")) == 0) {
		cmdValve(1, true);
	} else if (s.compareTo(F("VALVE_1_OFF")) == 0) {
		cmdValve(1, false);
	} else if (s.compareTo(F("VALVE_2_ON")) == 0) {
		cmdValve(2, true);
	} else if (s.compareTo(F("VALVE_2_OFF")) == 0) {
		cmdValve(2, false);
	} else if (s.compareTo(F("VALVE_3_ON")) == 0) {
		cmdValve(3, true);
	} else if (s.compareTo(F("VALVE_3_OFF")) == 0) {
		cmdValve(3, false);
	} else if (s.compareTo(F("VALVE_4_ON")) == 0) {
		cmdValve(4, true);
	} else if (s.compareTo(F("VALVE_4_OFF")) == 0) {
		cmdValve(4, false);
	} else {
		Serial.print(F("UNKNOWN CMD["));
		Serial.print(s);
		Serial.println(F("]"));
	}

}

// Отправка данных I2C мастеру (4 байта)
void requestEvent() {
	Wire.write(last_status_result);
}

// Управление клапаном
void cmdValve(int valve, boolean state) {

	switch (valve) {
	case 1:
		valve_1_state = state;
		digitalWrite(VALVE_1_PIN, state);
		break;
	case 2:
		valve_2_state = state;
		digitalWrite(VALVE_2_PIN, state);
		break;
	case 3:
		valve_3_state = state;
		digitalWrite(VALVE_3_PIN, state);
		break;
	case 4:
		digitalWrite(VALVE_4_PIN, state);
		valve_4_state = state;
		break;
	}

	Serial.print(F("CMD_VALVE["));
	Serial.print(valve);
	Serial.print(F("]=["));
	Serial.print(state);
	Serial.println(F("]"));

}

//Моргание статусной лампочкой
void blink(int valve, boolean state) {
	int t = 100;
	for (int i = 0; i < valve; i++) {
		digitalWrite(STATUS_PIN, HIGH);
		delay(t);
		digitalWrite(STATUS_PIN, LOW);
		delay(t);
	}
	delay(t * 2 * (4 - valve));

}

// Запрос состояния клапана №1
void requestStatusValve(int valve) {
	switch (valve) {
	case 1:
		last_status_result = valve_1_state;
		break;
	case 2:
		last_status_result = valve_2_state;
		break;
	case 3:
		last_status_result = valve_3_state;
		break;
	case 4:
		last_status_result = valve_4_state;
		break;
	}

}

