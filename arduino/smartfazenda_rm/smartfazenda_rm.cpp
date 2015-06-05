// Smart Fazend Relay Module
#include "smartfazenda_rm.h"
#include <Wire.h>
#include <avr/pgmspace.h>
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))

#define VALVE_1_PIN   8  // ���� ������� �1
#define VALVE_2_PIN   9  // ���� ������� �1
#define VALVE_3_PIN   10  // ���� ������� �1
#define VALVE_4_PIN   11  // ���� ������� �1

#define STATUS_PIN   13  // �������������� ��������

#define TZ_SIZE 16 //������ ��������

// ��������� ��������
boolean valve_1_state = false;
boolean valve_2_state = false;
boolean valve_3_state = false;
boolean valve_4_state = false;

// ��������� ������ � ��������
boolean pump_well_work_state = false;
// ��������� ������� ������������ ������ ���� � ��������
boolean well_level_min_state = false;

// ��������� ������ � �����
boolean pump_tank_work_state = false;

// ������� ���� � ����� (�������)
boolean tank_level_high = false;

// ������� ���� � ����� (�������)
boolean tank_level_middle = false;

// ������ ����
uint32_t water_out_flow_rate = 16909060; // 0x01020304; //16909060

// ������ ����
uint32_t water_in_flow_rate = 17908030; // 0x01020304; //16909060

void setup() {

	pinMode(VALVE_1_PIN, OUTPUT);
	pinMode(VALVE_2_PIN, OUTPUT);
	pinMode(VALVE_3_PIN, OUTPUT);
	pinMode(VALVE_4_PIN, OUTPUT);
	pinMode(STATUS_PIN, OUTPUT);

	Wire.begin(4);                // join i2c bus with address #4
	Wire.onReceive(receiveEvent); // register event
	// ����������� ����������� ��������� ��������
	Wire.onRequest(requestTeleZone);
	Serial.begin(9600);           // start serial for output
	Serial.println(F("Slave"));
}

void loop() {
//	delay(1000);
//	Serial.println(F("Slave OK"));

	//������� ���������
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

	if (s.compareTo(F("VALVE_1=1")) == 0) {
		cmdValve(1, true);
	} else if (s.compareTo(F("VALVE_1=0")) == 0) {
		cmdValve(1, false);
	} else if (s.compareTo(F("VALVE_2=1")) == 0) {
		cmdValve(2, true);
	} else if (s.compareTo(F("VALVE_2=0")) == 0) {
		cmdValve(2, false);
	} else if (s.compareTo(F("VALVE_3=1")) == 0) {
		cmdValve(3, true);
	} else if (s.compareTo(F("VALVE_3=0")) == 0) {
		cmdValve(3, false);
	} else if (s.compareTo(F("VALVE_4=1")) == 0) {
		cmdValve(4, true);
	} else if (s.compareTo(F("VALVE_4_0")) == 0) {
		cmdValve(4, false);
	} else {
		Serial.print(F("UNKNOWN CMD["));
		Serial.print(s);
		Serial.println(F("]"));
	}

}

// �������� ������ I2C ������� (4 �����)

void requestTeleZone() {

	uint8_t i2cResponse[TZ_SIZE];

	int tz_position = 0;

	//��������� ��������
	i2cResponse[tz_position++] = valve_1_state;
	i2cResponse[tz_position++] = valve_2_state;
	i2cResponse[tz_position++] = valve_3_state;
	i2cResponse[tz_position++] = valve_4_state;

	// ��������� ������ � ��������
	i2cResponse[tz_position++] = pump_well_work_state;

	// ��������� ������� ������������ ������ ���� � ��������
	i2cResponse[tz_position++] = well_level_min_state;

	// ������� ���� � ����� (�������)
	i2cResponse[tz_position++] = tank_level_high;

	// ������� ���� � ����� (�������)
	i2cResponse[tz_position++] = tank_level_middle;

	//������ ����
	i2cResponse[tz_position++] = water_in_flow_rate;
	i2cResponse[tz_position++] = water_in_flow_rate >> 8;
	i2cResponse[tz_position++] = water_in_flow_rate >> 16;
	i2cResponse[tz_position++] = water_in_flow_rate >> 24;

	//������ ����
	i2cResponse[tz_position++] = water_out_flow_rate;
	i2cResponse[tz_position++] = water_out_flow_rate >> 8;
	i2cResponse[tz_position++] = water_out_flow_rate >> 16;
	i2cResponse[tz_position++] = water_out_flow_rate >> 24;

	Wire.write(i2cResponse, tz_position);

}

// ���������� ��������
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

//�������� ��������� ���������
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



