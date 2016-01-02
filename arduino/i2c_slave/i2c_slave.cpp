// Do not remove the include below
#include "i2c_slave.h"
#include <Wire.h>

// размер CRC
#define CRC_SIZE 3
// Размер тела ответа
#define MSG_BODY_SIZE 20

// This table comes from Dallas sample code where it is freely reusable,
// though Copyright (C) 2000 Dallas Semiconductor Corporation
static const uint8_t PROGMEM dscrc_table[] = { 0, 94, 188, 226, 97, 63, 221,
		131, 194, 156, 126, 32, 163, 253, 31, 65, 157, 195, 33, 127, 252, 162,
		64, 30, 95, 1, 227, 189, 62, 96, 130, 220, 35, 125, 159, 193, 66, 28,
		254, 160, 225, 191, 93, 3, 128, 222, 60, 98, 190, 224, 2, 92, 223, 129,
		99, 61, 124, 34, 192, 158, 29, 67, 161, 255, 70, 24, 250, 164, 39, 121,
		155, 197, 132, 218, 56, 102, 229, 187, 89, 7, 219, 133, 103, 57, 186,
		228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154, 101, 59, 217, 135, 4,
		90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36, 248, 166, 68, 26,
		153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185, 140, 210, 48,
		110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205, 17, 79, 173,
		243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80, 175, 241,
		19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238, 50, 108,
		142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115, 202,
		148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139, 87,
		9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,
		233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246,
		168, 116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137,
		107, 53 };

// Items
//const char item1[] PROGMEM = "item1";
//const char item2[] PROGMEM = "item2";
//const char item3[] PROGMEM = "item3";
//const char item4[] PROGMEM = "item4";
//const char item5[] PROGMEM = "item5";

const char ITEM1[] = "item1";
const char ITEM2[] = "item2";
const char ITEM3[] = "item3";
const char ITEM4[] = "item4";
const char ITEM5[] = "item5";

const char* ITEMS[] = { ITEM1, ITEM2, ITEM3, ITEM4, ITEM5 };

float item1_val = 1.1;
float item2_val = 2.1;
float item3_val = 3.1;
float item4_val = 4.1;
float item5_val = 5.1;

const String ANS_MASTER = "RESP[";
const String REQ_MASTER = "REQ[";

//const char* const ITEMS[] PROGMEM = { item1, item2, item3, item4, item5 };

// Последний запрошенный итем (номер в массиве ITEMS)
int last_requested_item = -1;

//String last_requested_item = "";
// Подготовленные данные для ответа
char last_responce_data[MSG_BODY_SIZE + CRC_SIZE];

void setup() {
	Serial.begin(115200);
	Serial.println("start");
	Wire.begin(2);                // join i2c bus with address #2
	Wire.onRequest(requestEvent); // register event
	Wire.onReceive(receiveEvent); // register event
}

void loop() {

	yield();

}

// Получение значения итема по его индексу
String get_item_value_by_index(int index) {

//	String data = get_item_name_by_index(last_requested_item);
//	String data = String(ITEMS[last_requested_item]);

//	data.concat(",");

	float val = 0;
	switch (index) {
	case 0:
		val = item1_val;
		break;
	case 1:
		val = item2_val;
		break;
	case 2:
		val = item3_val;
		break;
	case 3:
		val = item4_val;
		break;
	case 4:
		val = item5_val;
		break;
	default:
		val = NAN;
	}

	char str_temp[10];

	/* 4 is mininum width, 2 is precision; float value is copied onto str_temp*/
	dtostrf(val, 7, 3, str_temp);

	String s = String(str_temp);
	s.trim();

//	return String(val, DEC);
	return s;
}

// Задание значение итема
void set_item_value_by_name(String name, String val) {

	//Убираем мусор
	val.trim();

//	Serial.print("ATCMD[");
//	Serial.print(name);
//	Serial.print("=");
//	Serial.print(val);
//	Serial.print("]");

	if (name.equals("item1")) {
		float v = val.toFloat();
		item1_val = v;
	} else if (name.equals("item2")) {
		float v = val.toFloat();
		item2_val = v;
	} else if (name.equals("item3")) {
		float v = val.toFloat();
		item3_val = v;

//		Serial.print("!!!!!!!");
//		Serial.println(item3_val);

	} else if (name.equals("item4")) {
		float v = val.toFloat();
		item4_val = v;
	} else if (name.equals("item5")) {
		float v = val.toFloat();
		item5_val = v;
	}
}

// Ответ мастеру
void requestEvent() {
	//TODO проверка на длинну
	Wire.write(last_responce_data);
}

// Проверка CRC коммманды от мастера
boolean check_i2c_command_crc(const String& cmd) {
	//проверка CRC
	String cmd_in = cmd.substring(0, cmd.lastIndexOf(","));
	String crc_in = cmd.substring(cmd.lastIndexOf(",") + 1, cmd.length() - 1);
	String item_in = cmd_in.substring(cmd_in.indexOf(",") + 1, cmd_in.length());
	byte cmd_in_b[cmd_in.length() + 1];
	cmd.getBytes(cmd_in_b, cmd_in.length() + 1);
	uint8_t crc = crc8(cmd_in_b, cmd_in.length() + 1); //считаем crc
	String crc_str = String(crc, HEX);
	crc_str.toUpperCase();
	//CRC совпало
	if (crc_str.compareTo(crc_in) == 0) {
//		Serial.print("[");
//		Serial.print(last_requested_item);
//		Serial.print("]");
//		Serial.print("CRC:");
//		Serial.print(crc_in);
//		Serial.println("[OK]");
		return true;
	} else
		return false;
}

// Упаковка данных в выходной буффер (массив для отправки)
void pack_output_message(String data) {

	byte data_b[data.length() + 1];
	data.getBytes(data_b, data.length() + 1);
	uint8_t crc = crc8(data_b, data.length() + 1); //считаем crc
	String crc_str = String(crc, HEX);
	crc_str.toUpperCase();
	data += "," + crc_str + "\n";
	data.toCharArray(last_responce_data, MSG_BODY_SIZE + CRC_SIZE);
	Serial.print(ANS_MASTER);
	Serial.print(last_responce_data);
	Serial.println("]");
}

// Получение имени итема по его индексу
//String get_item_name_by_index(int index) {
//
//	return ITEMS[index];
////	char buffer[MSG_BODY_SIZE];
////	strcpy_P(buffer, (char*) pgm_read_word(&(ITEMS[index])));
////	return String(buffer);
//}

// Обработка запроса от мастера
void receiveEvent(int howMany) {

	//Длинные строки не парсим
	if (howMany > (MSG_BODY_SIZE + CRC_SIZE))
		return;

	String cmd = "";

	while (Wire.available()) { // loop through all but the last
		char c = Wire.read(); // receive byte as a character
		cmd.concat(c);
	}

	Serial.print(REQ_MASTER);
	Serial.print(cmd);
	Serial.println("]");

	// Проверка валидности запроса
	if (!cmd.startsWith("ATGET,") && !cmd.startsWith("ATCMD,"))
		return;



	//Не совпал CRC
	if (!check_i2c_command_crc(cmd)) {
		// Заполняем ответ
		String resp = "ERROR/CRC";
		pack_output_message(resp);

		Serial.print(ANS_MASTER);
		Serial.println("CRCERR");
		return;
	}




	// Запрос "следующего" item (ATGET,FF)
	if (cmd.startsWith("ATGET,") && cmd.length() == 9) {

		// Количество итемов

		int items_count = sizeof(ITEMS) / 2;
//		Serial.println(items_count);

		if ((last_requested_item++) >= items_count - 1) {
			last_requested_item = 0;
		}

//		Serial.print("size:");
//		Serial.print(items_count);
//		Serial.print("index:");
//		Serial.println(last_requested_item);

		//Выполняем подготовку данных для ответа

		String data = String(ITEMS[last_requested_item]);
//		String data = get_item_name_by_index(last_requested_item);

		data.concat(",");

		String val = get_item_value_by_index(last_requested_item);

		data.concat(val);

		pack_output_message(data);


		return;

	}
	if (cmd.startsWith("ATGET,")) { // Запрос конкретного item



		String item_name = cmd.substring(cmd.indexOf(",") + 1,
				cmd.lastIndexOf(","));


		// Количество итемов
		int items_count = sizeof(ITEMS) /2 ;


		for (int i = 0; i < items_count; i++) {

//			const char* item = ITEMS[i];
//			String item = get_item_name_by_index(last_requested_item);
			String item = String(ITEMS[i]);

			if (item.equals(item_name)) {

				String val = get_item_value_by_index(i);

				String data = item;
				data.concat(",");
				data.concat(val);

				pack_output_message(data);

//				Serial.print("[EQ]");
//				Serial.println(data);

				break;
			}

		}

		return;

	} else if (cmd.startsWith("ATCMD,")) { // Запрос команды



		String item_name_val = cmd.substring(cmd.indexOf(",") + 1,
				cmd.lastIndexOf(","));

		String item_name = item_name_val.substring(0,
				item_name_val.indexOf(","));
		String item_val = item_name_val.substring(
				item_name_val.indexOf(",") + 1);

		set_item_value_by_name(item_name, item_val);

		//Пакуем данные для отправки
		String data = String(item_name);
		data.concat(",");
		data.concat(item_val);

		pack_output_message(data);

//		Serial.print("!!! ATCMD [");
//		Serial.print(item_name);
//		Serial.print("=");
//		Serial.print(item_val);
//		Serial.println("]");

		return;
	}
}

//
// Compute a Dallas Semiconductor 8 bit CRC directly.
// this is much slower, but much smaller, than the lookup table.
//
uint8_t crc8(const uint8_t *addr, uint8_t len) {

	uint8_t crc = 0;

	while (len--) {
		crc = pgm_read_byte(dscrc_table + (crc ^ *addr++));
	}
	return crc;

}

//
// Compute a Dallas Semiconductor 8 bit CRC directly.
// this is much slower, but much smaller, than the lookup table.
//
uint8_t crc8_compute(const uint8_t *addr, uint8_t len) {
	uint8_t crc = 0;

	while (len--) {
		uint8_t inbyte = *addr++;
		for (uint8_t i = 8; i; i--) {
			uint8_t mix = (crc ^ inbyte) & 0x01;
			crc >>= 1;
			if (mix)
				crc ^= 0x8C;
			inbyte >>= 1;
		}
	}
	return crc;
}

