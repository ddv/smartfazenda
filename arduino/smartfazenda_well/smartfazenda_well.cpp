// Do not remove the include below
#include "smartfazenda_well.h"

// Датчик уровня
#define WELL_LOW_LVL_PIN  8

// Датчик уровня в бочке
#define TANK_MAX_LVL_PIN  9

// Канал управления включения-выключения
#define PUMP_RUN_PIN     7
// Лампочка
#define PUMP_STATUS_PIN     13

// Таймаут включения насоса после появления в кважине воды
#define PUMP_START_TIMEOUT     10000l
//#define PUMP_START_TIMEOUT     360000l

// Максимальное допустимое время работы мотора
#define PUMP_MAX_WORK_TIME     10000l

// статус работы мотора
boolean motor_run_status = false;

boolean motor_run_status_prev = false;
boolean well_min_lvl_status_prev = false;

boolean start = true;
//boolean tank_max_lvl_status_prev = false;

// статус "мало воды в скважине. true - мало воды. не включать
//boolean well_low_lvl_status = true;

// время последнего отключения насоса
//long pump_last_time__work = 0;

// Время последнего переключения режима
long pump_last_time_on_off = 0;

// Время старта работы мотора
long pump_start_time_work = 0;

// the setup routine runs once when you press reset:
void setup() {
	Serial.begin(9600);
	Serial.println(F("\nSmartFAZENDA/Well/Pump"));
	pinMode(PUMP_RUN_PIN, OUTPUT);
	pinMode(PUMP_STATUS_PIN, OUTPUT);

	// Датчик минимального уровня в скважине
	pinMode(WELL_LOW_LVL_PIN, INPUT_PULLUP);

	// Датчик максимального уровня в бочке
	pinMode(TANK_MAX_LVL_PIN, INPUT_PULLUP);

	// Сразу выключаем насос
	wellMotorStop();

//	// Уравниваем статусы
//	well_min_lvl_status_prev = getWellLowLvlStatus();
}

// the loop routine runs over and over again forever:
void loop() {

	//digitalWrite(PUMP_STATUS_PIN, HIGH);

	// Если в бочке есть место и в скважине есть вода - включаем насос
	if (!getTankMaxLvlStatus() && !getWellLowLvlStatus()) {

		wellMotorStart();

//		if (millis() - pump_start_time_work < PUMP_MAX_WORK_TIME)
//			wellMotorStart();
//		else
//			wellMotorStop();
	} else {
		wellMotorStop();
	}

	// Сбрвсываем время изменения статуса
	if (motor_run_status_prev != motor_run_status) {

		pump_last_time_on_off = millis();
		motor_run_status_prev = motor_run_status;
		Serial.print(F("CHANGE status. "));

	}

	// Запоминаем статус
	well_min_lvl_status_prev = getWellLowLvlStatus();

	Serial.print(F("\nPump run status: "));
	Serial.println(motor_run_status);

	Serial.print(F("\nPump start work time: "));
	Serial.println(pump_start_time_work);

	Serial.print(F("Well Low Level status: "));
	Serial.println(getWellLowLvlStatus());

	Serial.print(F("Tank max Level status: "));
	Serial.println(getTankMaxLvlStatus());

	Serial.print(F("last time on off: "));
	Serial.println(pump_last_time_on_off);

	delay(2000);
}

// Запуск мотора
void wellMotorStart() {

	//проверка таймаута для старта

	if (((millis() - pump_last_time_on_off) > PUMP_START_TIMEOUT) || start) {

//		if (millis() - pump_start_time_work > PUMP_MAX_WORK_TIME) {
//			motor_run_status = false;
//			start = false;
//			digitalWrite(PUMP_RUN_PIN, LOW);   // Включили насосос
//			Serial.println(F("\nERROR MOTOR WORK TIME!!!\n!"));
//			return;
//		}

		motor_run_status = true;
		digitalWrite(PUMP_RUN_PIN, HIGH);   // Включили насосос

		// Если мотор включился - делаем засечку времени
//		if (pump_start_time_work == 0) {
//			pump_start_time_work = millis();
//		}

//		pump_last_time__work = 0;
		start = false;
		Serial.println(F("Start!"));
	} else {

		Serial.print(F("Wait... "));
		Serial.println((millis() - pump_last_time_on_off));

		// Запоминаем время работы
//		pump_last_time__work = millis();
	}
}

// Останов мотора
void wellMotorStop() {
	motor_run_status = false;
//	pump_last_time__work = 0;
	pump_start_time_work = 0;
	digitalWrite(PUMP_RUN_PIN, LOW);   // Выключили насосос
}

// Статус - нет воды.
boolean getWellLowLvlStatus() {
	return !digitalRead(WELL_LOW_LVL_PIN);
}

// Статус - много воды (перелив)
boolean getTankMaxLvlStatus() {
	return !digitalRead(TANK_MAX_LVL_PIN);
}
