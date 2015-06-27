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
#define PUMP_START_TIMEOUT     1200000l // 2 часа
//#define PUMP_START_TIMEOUT     20000l

// Максимальное допустимое время работы мотора
#define PUMP_MAX_WORK_TIME     900000l // 15 минут

// статус работы мотора
boolean motor_run_status = false;

boolean motor_run_status_prev = false;

// Ошибка переработки мотора (датчик отвалился)
boolean motor_max_work_time_error = false;

// Время последнего выключения мотора
long pump_time_off = 0;

// Время старта работы мотора
long pump_start_time = 0;

// Время работы мотора (от старта мотора)
long pump_time_work = 0;

// Время неработы мотора (после останова мотора)
long pump_time_sleep = 0;

// Количество запусков моторов
long pump_starts_count = 0;

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

}

// the loop routine runs over and over again forever:
void loop() {

	//digitalWrite(PUMP_STATUS_PIN, HIGH);
	if (motor_max_work_time_error) {
		Serial.print(F("\n <<<< ERROR MOTOR MAX WORK TIME >>>>>>>>"));
		wellMotorStop();

		blinkEror();

		delay(1000);
		return;
	}

	if (getTankMaxLvlStatus())
		blinkTankllMaxLvl();
	else if (getWellLowLvlStatus())
		blinkWellMinLvl();
	else
		blinkStatus();

	// Если в бочке есть место и в скважине есть вода - включаем насос
	if (!getTankMaxLvlStatus() && !getWellLowLvlStatus()) {

		if (checkWellMotorIsReadyToStart()) {
			wellMotorRun();
		}

	} else {
		wellMotorStop();
	}

	// Проверка и принудительная остановка
	if (checkWellMotorNeedToStop()) {
		wellMotorStop();
	}

	// Сбрасываем время изменения статуса
	if (motor_run_status_prev != motor_run_status) {

		// выключился мотор
		if (!motor_run_status) {
			pump_time_off = millis();
		} else {
			pump_time_sleep = millis();
			pump_start_time = millis();
			pump_starts_count++;
		}

		motor_run_status_prev = motor_run_status;
		Serial.print(F("\nCHANGE status motor RUN="));
		Serial.print(motor_run_status);
		Serial.println(F("\n"));

	}

	// Если мотор работает
	if (motor_run_status)
		pump_time_work = millis() - pump_start_time;
	else
		pump_time_sleep = millis() - pump_time_off;

	if (motor_run_status) {
		Serial.print(F("Pump:RUN "));
		Serial.print(pump_time_work / 1000);
		Serial.print(F(" / "));
		Serial.print(PUMP_MAX_WORK_TIME / 1000);
		Serial.println(F(" sec."));

	} else {
		Serial.print(F("Pump:STOP "));
		Serial.print(pump_time_sleep / 1000);
		Serial.print(F(" / "));
		Serial.print(PUMP_START_TIMEOUT / 1000);
		Serial.println(F(" sec."));

		if (getWellLowLvlStatus())
			Serial.print(F("Well:LOW_LEVEL"));
		if (getTankMaxLvlStatus())
			Serial.print(F("Tank:MAX_LEVEL"));

		Serial.print(F("\n"));
	}

//	Serial.print(F("\nPump ["));
//	Serial.print(motor_run_status);
//
//	Serial.print(F("] Well ["));
//	Serial.print(getWellLowLvlStatus());
//
//	Serial.print(F("] Tank ["));
//	Serial.print(getTankMaxLvlStatus());
//
//	Serial.print(F("] start ["));
//	Serial.print(pump_start_time);
//
//	Serial.print(F("] work ["));
//	Serial.print(pump_time_work);
//
//	Serial.print(F("] sleep ["));
//	Serial.print(pump_time_sleep);
//
//	Serial.print(F("] off ["));
//	Serial.print(pump_time_off);
//
//	Serial.print(F("] count ["));
//	Serial.print(pump_starts_count);
//	Serial.println(F("]"));

	delay(2000);
}

// Проверка, готов ли мотор стартовать
// проверяем: остыл-ли он (как давно он был остановлен)
boolean checkWellMotorIsReadyToStart() {

//	Serial.println(F("start_check"));

// проверка что мотор остыл
	if (pump_time_off == 0
			|| ((millis() - pump_time_off) > PUMP_START_TIMEOUT)) {
		if (pump_time_off == 0) {
//			Serial.println(F("start_check:first_start"));
		}
		return true;
	}
	return false;
}

// Проверка, нужно ли мотор тормозить
// проверяем: как давно он включен
boolean checkWellMotorNeedToStop() {

//	Serial.println(F("stop_check"));

// Если мотор долго работает -
	if (pump_time_work > PUMP_MAX_WORK_TIME) {
		Serial.println(F("stop_check:max_time!"));
		// Выставляем ошибку
		motor_max_work_time_error = true;
		return true;
	}
	return false;
}

// Запуск мотора
void wellMotorRun() {
	pump_time_sleep = 0;
	motor_run_status = true;
	digitalWrite(PUMP_RUN_PIN, HIGH);   // Включили насосос

}

// Останов мотора
void wellMotorStop() {
	pump_time_work = 0;
	motor_run_status = false;
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

void blinkEror() {
	for (int i = 0; i < 20; i++) {
		digitalWrite(PUMP_STATUS_PIN, LOW);
		delay(100);
		digitalWrite(PUMP_STATUS_PIN, HIGH);
		delay(100);
	}
}

void blinkWellMinLvl() {
	for (int i = 0; i < 3; i++) {
		digitalWrite(PUMP_STATUS_PIN, HIGH);
		delay(500);
		digitalWrite(PUMP_STATUS_PIN, LOW);
		delay(100);
	}
}

void blinkTankllMaxLvl() {
	for (int i = 0; i < 5; i++) {
		digitalWrite(PUMP_STATUS_PIN, HIGH);
		delay(500);
		digitalWrite(PUMP_STATUS_PIN, LOW);
		delay(100);
	}
}

void blinkStatus() {
	long t = (PUMP_START_TIMEOUT - pump_time_sleep);
	long k = PUMP_START_TIMEOUT / 10;
	int v = 10 - (t / k) + 1;

//	Serial.print(F("v="));
//	Serial.println(v);

	for (int i = 0; i < v; i++) {
		digitalWrite(PUMP_STATUS_PIN, LOW);
		delay(50);
		digitalWrite(PUMP_STATUS_PIN, HIGH);
		delay(100);
	}
}
