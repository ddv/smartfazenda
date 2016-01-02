// Do not remove the include below

#include "i2c_master.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <HardwareSerial.h>
#include <include/wl_definitions.h>
#include <IPAddress.h>
#include <Print.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <WString.h>
#include <cstdbool>

char* wifi_ssid = "DDVPOINT";
//char* wifi_ssid = "JY-S3";
char* wifi_password = "1234567890";
const char* mqtt_server = "v.psystems.org";

String system_name = "ESP8266";
String system_id = "unknown";

// Максимальная длинна запроса
#define REQ_MAX_LENGTH 100

// Таймаут получения данных
#define ANSWER_DELAY 50
// размер CRC
#define CRC_SIZE 3
// Размер тела ответа
#define MSG_BODY_SIZE 20
// номер слейва
#define SLAVE_ID 2

// Перепосылка всег кэша
#define MQTT_POOL 10000

long last_time = millis();
long mqtt_rescan_time = 0;

#define CACHE_SIZE 20
String cache[CACHE_SIZE];
int cache_pointer = 0;

WiFiClient espClient;
PubSubClient client(espClient);

boolean wifi_ready = false; //wifi работает
// Инициалищаци WIFI
void setup_wifi() {

	delay(10);
	// We start by connecting to a WiFi network
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(wifi_ssid);

	WiFi.begin(wifi_ssid, wifi_password);
//	unsigned long int t =  millis();

	while (WiFi.status() != WL_CONNECTED) {
//			if(t+3000<millis())
//			break;

		delay(500);
		Serial.print(".");
//		Serial.print("wifistatus:");
//		Serial.print(WiFi.status());

	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
}
//The setup function is called once at startup of the sketch
void setup() {

	Serial.begin(115200);  // start serial for output
	Wire.begin(0, SLAVE_ID);       // join i2c bus (address optional for master)
	//Wire.setClock(100000);
//	t = millis();

	setup_wifi();
}


// Отправка данных в отладочный топик
void sendToMQTT_Topic_Debug(String dev, String msg) {

	if (msg.length() <= 0)
		return;

	if (!client.connected()) {
		setup_mqtt();
	}
	client.loop(); //MQTT chat

	String topic = "/" + system_name + "/" + system_id + "/debug/" + dev;

	char v[msg.length()];
	msg.toCharArray(v, msg.length() + 1);

	char t[topic.length()];
	topic.toCharArray(t, topic.length() + 1);

	client.publish(t, v);

}


void sendToMQTT_Topic_Debug_Master(String prefix, String msg) {
	if (prefix.length() <= 0)
		sendToMQTT_Topic_Debug("master" + prefix, msg);
	else
		sendToMQTT_Topic_Debug("master/" + prefix, msg);
}

// Отправка данных в топик
void sendToMQTT_Topic(String msg, String mode) {
	if (!client.connected()) {
		setup_mqtt();
	}
	client.loop(); //MQTT chat
	int index = msg.indexOf(",");
	String val = "";
	String item = "";
	String topic = "/" + system_name + "/" + system_id;

	if (index > 0) {
		item = msg.substring(0, index);
		val = msg.substring(index + 1, msg.length());
		topic += "/" + item + "/" + mode;

	} else { // Выводим в отладочный топик
		sendToMQTT_Topic_Debug_Master("error",
				"topic name is bad! mode=" + mode + " msg=" + msg);
	}

	if (val.length() <= 0) // Выводим в отладочный топик
		sendToMQTT_Topic_Debug_Master("error",
				"value is empty! mode=" + mode + " msg=" + msg);

	char v[val.length()];
	val.toCharArray(v, val.length() + 1);

	char t[topic.length()];
	topic.toCharArray(t, topic.length() + 1);

	client.publish(t, v);
}

// Отправка в топик STATE
void sendToMQTT_Topic_State(String msg) {
	sendToMQTT_Topic(msg, "state");
}


// Отправка в MQTT
void send_mqtt(String msg) {
	Serial.print("MQTT_SEND:[");
	Serial.print(msg);
	Serial.println("]");

	sendToMQTT_Topic_State(msg);
}

//Отправка команды слейву
void i2c_send_cmd(String cmd) {

	// Считаем CRC
	byte outdata[cmd.length() + 1];
	cmd.getBytes(outdata, cmd.length() + 1);
	uint8_t out_crc = crc8(outdata, cmd.length() + 1); //считаем crc
	// Формируем строку с командой
	String crc_str = String(out_crc, HEX);
	crc_str.toUpperCase();
	cmd += "," + crc_str;
	//Посылаем комманду слейву
	Wire.beginTransmission(SLAVE_ID); // transmit to device #2
	outdata[cmd.length() + 1];
	cmd.getBytes(outdata, cmd.length() + 1);
	Wire.write(outdata, cmd.length() + 1);
	Wire.endTransmission(); // stop transmitting

}

// Получение данных от слейва
String i2c_slave_responce() {
	//Запрос данных от слейва
	int size = Wire.requestFrom(SLAVE_ID, MSG_BODY_SIZE + CRC_SIZE);
//	Serial.print("size:");
//	Serial.println(size, DEC);
	String data = "";
	boolean end_cmd = false;
	while (Wire.available()) {
		char c = (char) (Wire.read());
		if (c == '\n')
			end_cmd = true;

		if (!end_cmd)
			data.concat(c);
	}
	Serial.print("data[");
	Serial.print(data);
	Serial.println("]");
	//считаем CRC
	String crc_str = data.substring(data.lastIndexOf(",") + 1, data.length());
//	Serial.print("crc_in[");
//	Serial.print(crc_str);
//	Serial.println("]");
	String msg = data.substring(0, data.lastIndexOf(","));
//	Serial.print("msg[");
//	Serial.print(msg);
//	Serial.println("]");
	byte b[msg.length() + 1];
	msg.getBytes(b, msg.length() + 1);
	uint8_t crc = crc8(b, msg.length() + 1); //считаем crc
	String crc_check_str = String(crc, HEX);
	crc_check_str.toUpperCase();
//	Serial.print("crc_str[");
//	Serial.print(crc_check_str);
//	Serial.print("]");
//	Serial.print("crc_in[");
//	Serial.print(crc_str);
//	Serial.print("]");
	if (crc_str.equals(crc_check_str)) {
//		Serial.println("CRCOK");

		String item_name = msg.substring(0,msg.indexOf(",")+1);
		Serial.print("!!!!item_name[");
		Serial.print(item_name);
		Serial.println("]");

		//Помещаем в кэш
		boolean find = false;
		for(int i=0; i<CACHE_SIZE; i++) {
			String s = cache[i];

			if(msg.equals(s)) { //есть в кэше 100%
				find=true;
				break;
			}else if(s.startsWith(item_name)) {
				// замещаем
				cache[i]=msg;
				Serial.print("CACHE_REPL[");
				Serial.print(i);
				Serial.print("]");
				Serial.println(msg);

				//TODO отправляем в MQTT
				send_mqtt(msg);

				find=true;
				break;
			}
		}
		// Абсолютно новый
		if(!find) {
			if(cache_pointer++>=CACHE_SIZE-1) {
				cache_pointer=0;
			}
			cache[cache_pointer]=msg;
			Serial.print("CACHE_NEW:");
			Serial.print(cache_pointer);
			Serial.print("]");
			Serial.println(msg);


			//TODO отправляем в MQTT
			send_mqtt(msg);

		}



		return msg;
	} else {
		Serial.print("CRCERR[");
		Serial.print(data);
		Serial.println("]");
		return "ERROR/CRCERROR[" + data + "]";
	}
	return "";
}

// Запрос конкретного итема
String request_item(String item) {

	String cmd = ("ATGET,");
	cmd.concat(item);

	i2c_send_cmd(cmd);

	//Пауза, чтобы slave успел отработать
	delay(ANSWER_DELAY);

	String resp = i2c_slave_responce();
	return resp;
}

// Запрос конкретного итема
String request_next_item() {

	String cmd = ("ATGET");

	i2c_send_cmd(cmd);

	//Пауза, чтобы slave успел отработать
	delay(ANSWER_DELAY);

	String resp = i2c_slave_responce();
	return resp;
}

// Отправка комманды
String send_command(String item, String value) {

	String cmd = String("ATCMD,");
	cmd.concat(item);
	cmd.concat(",");
	cmd.concat(value);
//	i2c_send_cmd("ATCMD,item2,34.123");
	i2c_send_cmd(cmd);

	//Пауза, чтобы slave успел отработать
	delay(ANSWER_DELAY);

	String resp = i2c_slave_responce();
	//	Serial.print("resp CMD:");
	//	Serial.println(resp);

	return resp;

}



// Инициализаци MQTT + подписка
void setup_mqtt() {
	// Loop until we're reconnected
	while (!client.connected()) {
		Serial.print("Attempting MQTT connection...");
		// Attempt to connect
		if (client.connect("ESP8266Client", "test", "test")) {
//    if (client.connect("ESP8266Client")) {
			Serial.println("connected");
			uint32_t id = ESP.getChipId();
			//Отправка отладки в MQ
			sendToMQTT_Topic_Debug_Master("", "started");
			sendToMQTT_Topic_Debug_Master("chip/id", String(id));

			// подписка только на топик "out"
			String topic = "/" + system_name + "/" + system_id + "/+/command";
			//String topic = "/in/#";
			char t[topic.length()];
			topic.toCharArray(t, topic.length() + 1);
			client.subscribe(t);
		} else {
			Serial.print("failed, rc=");
			Serial.print(client.state());
			Serial.println(" try again in 5 seconds");
			// Wait 5 seconds before retrying
			delay(5000);
		}
	}
}

// Получение названия итема
String getMQTTItemName(String topic) {
	///ESP8266/unknown/item1/command
	String sys = "/" + system_name + "/" + system_id + "/";
	if (topic.startsWith(sys)) {
		topic.remove(topic.lastIndexOf("/command"), topic.length());
		topic.lastIndexOf("/");
		topic.remove(0, topic.lastIndexOf("/") + 1);
//		sendToMQTT_Topic_Debug("master/parse/topic_item", topic);
		return topic;

	} else
		return "";
}


void callbackMQTT(char* topic, byte* payload, unsigned int length) {

	//проверка на длинну сообщения
	if (length > REQ_MAX_LENGTH) {
		sendToMQTT_Topic_Debug_Master("", "Request too long! " + length);
		return;
	}

	String val = "";
	for (int i = 0; i < length; i++) {
		val.concat((char) payload[i]);
	}
	String t(topic);

	sendToMQTT_Topic_Debug_Master("mqtt_callback",
			"topic:" + t + " value:" + val);

	String var_name = getMQTTItemName(t);

	send_command(var_name, val);

//	Serial.println(t);
//	Serial.println(val);
//	Serial.println("MQTTCALLBACK:"+var_name + "," + val);

}


// The loop function is called in an endless loop
void loop() {

	//TODO Проверять статус wifi у самого класса wifiClient
//	if (!wifi_ready) {
	if(!wifi_ready || WiFi.status() != WL_CONNECTED) {
			setup_wifi();
			client.setServer(mqtt_server, 1883);
			client.setCallback(callbackMQTT);
			wifi_ready = true;
		}

		if (!client.connected()) {
			setup_mqtt();
		}

		client.loop(); //MQTT pooling

	// Опрос слейва

	String resp = request_next_item();
	Serial.println(resp);

	//Отладка
//	if((t+2000)<millis()) {
//		long v = random(100);
//		String s = String(v);
//		s.trim();
//		String resp = send_command("item3", s);
//		Serial.println(resp);
//		t=millis();
//	}

	//TODO Учесть сброс счетчика
	if((mqtt_rescan_time+MQTT_POOL)<millis() || last_time>millis()) {

		for(int i=0; i<CACHE_SIZE; i++) {
			String s = cache[i];
			if(s.length()>0)
				send_mqtt(s);
		}

		mqtt_rescan_time=millis();
	}

	last_time=millis();
}

uint8_t crc8(const uint8_t *addr, uint8_t len) {
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
