// Do not remove the include below
#include "smartfazenda.h"
#include <avr/pgmspace.h>
#include <Adafruit_CC3000.h>
#include <SPI.h>
#include <Wire.h>
#include "utility/debug.h"
#include "utility/socket.h"

#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))

//Номер слэйва
#define REALAY_MODULE_SLAVE_ID   4  // MUST be an interrupt pin!

// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!
// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10
// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11

Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS,
ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
SPI_CLOCK_DIVIDER); // you can change this clock speed

#define WLAN_SSID       "JY-G5"   // cannot be longer than 32 characters!
#define WLAN_PASS       "1234567890"
// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

#define LISTEN_PORT           80      // What TCP port to listen on for connections.
// The HTTP protocol uses port 80 by default.

#define MAX_ACTION            10      // Maximum length of the HTTP action that can be parsed.

#define MAX_PATH              64      // Maximum length of the HTTP request path that can be parsed.
// There isn't much memory available so keep this short!

#define BUFFER_SIZE           MAX_ACTION + MAX_PATH + 20  // Size of buffer for incoming request data.
// Since only the first line is parsed this
// needs to be as large as the maximum action
// and path plus a little for whitespace and
// HTTP version.

#define TIMEOUT_MS            500    // Amount of time in milliseconds to wait for
// an incoming request to finish.  Don't set this
// too high or your server could be slow to respond.

Adafruit_CC3000_Server httpServer(LISTEN_PORT);
uint8_t buffer[BUFFER_SIZE + 1];
int bufindex = 0;
char action[MAX_ACTION + 1];
char path[MAX_PATH + 1];


#define TZ_SIZE 16 //Размер телезоны

// состояния клапанов
boolean valve_1_state = false;
boolean valve_2_state = false;
boolean valve_3_state = false;
boolean valve_4_state = false;

// состояния насоса в скважине
boolean pump_well_work_state = false;
// состояния датчика минимального уровня воды в скважине
boolean well_level_min_state = false;

// состояния насоса в бочке
boolean pump_tank_work_state = false;

// Уровень воды в бочке (верхний)
boolean tank_level_high = false;

// Уровень воды в бочке (средний)
boolean tank_level_middle = false;

// Расход воды
uint32_t water_out_flow_rate = -1; // 0x01020304; //16909060

// Приход воды
uint32_t water_in_flow_rate = -1; // 0x01020304; //16909060

boolean pump1_on = false;
unsigned long pump1_start_time = 0;

uint16_t input_water_flow = 0;

void setup(void) {
	Serial.begin(115200);
	Serial.println(F("Project 'Smart Fazenda'"));

	Wire.begin(); // join i2c bus (address optional for master)

	//Запрос телезоны
	requestSlaveTelezone();

	Serial.print(F("Free RAM: "));
	Serial.println(getFreeRam(), DEC);

	// Initialise the module
	Serial.println(F("\nInitializing..."));
	if (!cc3000.begin()) {
		Serial.println(F("Couldn't begin()! Check your wiring?"));
		while (1)
			;
	}

	Serial.print(F("\nAttempting to connect to "));
	Serial.println(WLAN_SSID);
	if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
		Serial.println(F("Failed!"));
		while (1)
			;
	}

	Serial.println(F("Connected!"));

	Serial.println(F("Request DHCP"));
	while (!cc3000.checkDHCP()) {
		delay(100); // ToDo: Insert a DHCP timeout!
	}

	// Display the IP address DNS, Gateway, etc.
	while (!displayConnectionDetails()) {
		delay(1000);
	}

	// Start listening for connections
	httpServer.begin();

	Serial.println(F("Listen..."));
}

void loop(void) {
	// Try to get a client which is connected.
	Adafruit_CC3000_ClientRef client = httpServer.available();
	if (client) {
		Serial.println(F("Client connected."));
		// Process this request until it completes or times out.
		// Note that this is explicitly limited to handling one request at a time!

		// Clear the incoming data buffer and point to the beginning of it.
		bufindex = 0;
		memset(&buffer, 0, sizeof(buffer));

		// Clear action and path strings.
		memset(&action, 0, sizeof(action));
		memset(&path, 0, sizeof(path));

		// Set a timeout for reading all the incoming data.
		unsigned long endtime = millis() + TIMEOUT_MS;

		// Read all the incoming data until it can be parsed or the timeout expires.
		bool parsed = false;
		while (!parsed && (millis() < endtime) && (bufindex < BUFFER_SIZE)) {
			if (client.available()) {
				buffer[bufindex++] = client.read();
			}
			parsed = parseRequest(buffer, bufindex, action, path);
		}

		// Handle the request if it was parsed.
		if (parsed) {
			Serial.println(F("Processing request"));
			Serial.print(F("Action: "));
			Serial.println(action);
			Serial.print(F("Path: "));
			Serial.println(path);

			//
			String s = String(path);
//			Serial.println(F("test: "));

			int i = s.indexOf("?");
			String mode = s.substring(0, i);
//			Serial.print(F("mode["));
//			Serial.print(mode);
//			Serial.println(F("]"));

			if (mode.compareTo(F("/rest")) == 0) {

				while (i > 0) {
					int prev = i + 1;
					i = s.indexOf("&", i + 1);

					//Serial.println(i);
					String keyval = s.substring(prev, i);
					//Serial.println(keyval);

					int k = keyval.indexOf("=");
					String key = keyval.substring(0, k);
					String val = keyval.substring(k + 1);

					//Serial.println(key);
					//Serial.println(val);

					runcmd(key, val);
				}
			}

			//��������� ������
			char *tmp;
			tmp = strtok(path, ",");
			while (tmp) {
				// ArrayKey[i++] = atoi(tmp);
				tmp = strtok(0, "?");
				Serial.println(tmp);
			}

			// Check the action to see if it was a GET request.
			if (strcmp(action, "GET") == 0) {
				// Respond with the path that was accessed.
				// First send the success response code.
				client.fastrprintln(F("HTTP/1.1 200 OK"));
				// Then send a few headers to identify the type of data returned and that
				// the connection will not be held open.
				client.fastrprintln(
						F("Content-Type: text/html; charset=utf-8"));

				client.fastrprintln(F("Connection: close"));
				client.fastrprintln(F("Server: Smart Fazenda"));
				// Send an empty line to signal start of body.

				showForm(client);
			} else {
				// Unsupported action, respond with an HTTP 405 method not allowed error.
				client.fastrprintln(F("HTTP/1.1 405 Method Not Allowed"));
				client.fastrprintln(F(""));
			}
		}

		// Wait a short period to make sure the response had time to send before
		// the connection is closed (the CC3000 sends data asyncronously).
		delay(100);

		// Close the connection when done.
		Serial.println(F("Client disconnected"));
		client.close();
	}

}

// Запрос телезоны у слейва
void requestSlaveTelezone() {


//	uint32_t water_in_flow_rate = -1;
//	uint32_t water_out_flow_rate = -1;

	Serial.println("TZ");
	// Запрос телезоны
	Wire.requestFrom(REALAY_MODULE_SLAVE_ID, TZ_SIZE);

	int respVals[4];
	uint8_t respIoIndex = 0;



//	if (Wire.available()) {
//		//Читаем состояния клапанов
//		for (byte r = 0; r < 8; r++) {
//			if (Wire.available()) {
//				uint8_t data = (uint8_t) Wire.read();
//				respVals[respIoIndex] = data;
//				respIoIndex++;
//				Serial.print("v=");
//				Serial.println(data);
//			} else {
//				// log or handle error: "missing read"; if you are not going to do so use r index instead of respIoIndex and delete respoIoIndex from this for loop
//				Serial.println("ERROR");
//				break;
//			}
//		}
//
//	}

	// Телевостояния
	if (Wire.available()>=8) {
		valve_1_state = (uint8_t) Wire.read();
		valve_2_state = (uint8_t) Wire.read();
		valve_3_state = (uint8_t) Wire.read();
		valve_4_state = (uint8_t) Wire.read();

		pump_well_work_state = (uint8_t) Wire.read();
		well_level_min_state = (uint8_t) Wire.read();
		tank_level_high = (uint8_t) Wire.read();
		tank_level_middle = (uint8_t) Wire.read();
	}

//	Serial.println("TS:");
	Serial.println(valve_1_state);
	Serial.println(valve_2_state);
	Serial.println(valve_3_state);
	Serial.println(valve_4_state);
//
//	Serial.println(pump_well_work_state);
//	Serial.println(well_level_min_state);
//	Serial.println(tank_level_high);
//	Serial.println(tank_level_middle);

	//Читаем приход воды
	if (Wire.available()>=4) {
		water_in_flow_rate = (uint32_t) Wire.read();
		water_in_flow_rate += ((uint32_t) Wire.read()) << 8;
		water_in_flow_rate += ((uint32_t) Wire.read()) << 16;
		water_in_flow_rate += ((uint32_t) Wire.read()) << 24;
	} else {
		Serial.println("ERROR");
	}


//	Serial.println("IN");
//	Serial.println(water_in_flow_rate);

	//Читаем расход воды
	if (Wire.available()>=4) {
		water_out_flow_rate = (uint32_t) Wire.read();
		water_out_flow_rate += ((uint32_t) Wire.read()) << 8;
		water_out_flow_rate += ((uint32_t) Wire.read()) << 16;
		water_out_flow_rate += ((uint32_t) Wire.read()) << 24;
	} else {
		Serial.println("ERROR");
	}


//	Serial.println("OUT");
//	Serial.println(water_out_flow_rate);


}

void showFormValve(Adafruit_CC3000_ClientRef client, int valve, boolean state) {

	client.fastrprintln(F("<tr><td colspan=2> Клапан №1 </td></tr>"));

	client.fastrprintln(F("<tr>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(F("<input type=\"hidden\" name=\"valve_"));
	client.print(valve);
	client.fastrprint(F("\" value=\"on\">"));

	if (state == true)
		client.fastrprint(
				F("<input type=\"submit\" value=\"Открыть\" disabled>"));
	else
		client.fastrprint(F("<input type=\"submit\" value=\"Открыть\">"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(F("<input type=\"hidden\" name=\"valve_"));
	client.print(valve);
	client.fastrprint(F("\" value=\"off\">"));

	if (state == true)
		client.fastrprint(F("<input type=\"submit\" value=\"Закрыть\">"));
	else
		client.fastrprint(
				F("<input type=\"submit\" value=\"Закрыть\" disabled>"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("</tr>"));
}

// Form
void showForm(Adafruit_CC3000_ClientRef client) {

	//Запрос телезоны
	requestSlaveTelezone();

	client.fastrprintln(F(""));
	// Now send the response data.
	client.fastrprintln(
			F("<meta name=\"viewport\" content=\"width=device-width\">"));

	client.fastrprintln(
			F("<meta http-equiv=\"refresh\" content=\"10; url=/rest\">"));

	client.fastrprintln(F("<a href=\"rest\"><h1>Умная дача</h1></a>"));
	client.fastrprint(F("You accessed path: "));
	client.fastrprintln(path);

	client.fastrprintln(F("<table>"));

	showFormValve(client, 1, valve_1_state);
	showFormValve(client, 2, valve_2_state);
	showFormValve(client, 3, valve_3_state);
	showFormValve(client, 4, valve_4_state);

	//Pump 1

//	if (pump1_start_time > 0) {
//		client.fastrprintln(F("<tr><td colspan=2> Насос №1 (работает "));
//		client.println(((millis() - pump1_start_time) / 1000));
//		client.fastrprintln(F(" сек.)</td></tr>"));
//	} else {
//		client.fastrprintln(F("<tr><td colspan=2> Насос №1 </td></tr>"));
//	}
//
//	client.fastrprintln(F("<tr>"));
//	client.fastrprintln(F("<td>"));
//
//	client.fastrprint(F("<form action=\"rest\">"));
//	client.fastrprint(
//			F("<input type=\"hidden\" name=\"pump_1\" value=\"on\">"));
//
//	if (pump1_on == true)
//		client.fastrprint(
//				F("<input type=\"submit\" value=\"Включить\" disabled>"));
//	else
//		client.fastrprint(F("<input type=\"submit\" value=\"Включить\">"));
//
//	client.fastrprint(F("</form>"));
//
//	client.fastrprintln(F("</td>"));
//	client.fastrprintln(F("<td>"));
//
//	client.fastrprint(F("<form action=\"rest\">"));
//	client.fastrprint(
//			F("<input type=\"hidden\" name=\"pump_1\" value=\"off\">"));
//
//	if (pump1_on == true)
//		client.fastrprint(F("<input type=\"submit\" value=\"Выключить\">"));
//	else
//		client.fastrprint(
//				F("<input type=\"submit\" value=\"Выключить\" disabled>"));
//
//	client.fastrprint(F("</form>"));
//
//	client.fastrprintln(F("</td>"));
//	client.fastrprintln(F("</tr>"));

	client.fastrprintln(F("</table>"));

}

void runcmd(String cmd, String val) {

	if (cmd.compareTo(F("valve_1")) == 0 && val.compareTo(F("on")) == 0) {
		sendCommand2Slave(1, true);

	} else if (cmd.compareTo(F("valve_1")) == 0
			&& val.compareTo(F("off")) == 0) {
		sendCommand2Slave(1, false);

	} else if (cmd.compareTo(F("valve_2")) == 0
			&& val.compareTo(F("on")) == 0) {
		sendCommand2Slave(2, true);

	} else if (cmd.compareTo(F("valve_2")) == 0
			&& val.compareTo(F("off")) == 0) {
		sendCommand2Slave(2, false);

	} else if (cmd.compareTo(F("valve_3")) == 0
			&& val.compareTo(F("on")) == 0) {
		sendCommand2Slave(3, true);

	} else if (cmd.compareTo(F("valve_3")) == 0
			&& val.compareTo(F("off")) == 0) {
		sendCommand2Slave(3, false);

	} else if (cmd.compareTo(F("valve_4")) == 0
			&& val.compareTo(F("on")) == 0) {
		sendCommand2Slave(4, true);

	} else if (cmd.compareTo(F("valve_4")) == 0
			&& val.compareTo(F("off")) == 0) {
		sendCommand2Slave(4, false);

	}

	else if (cmd.compareTo(F("pump_1")) == 0 && val.compareTo(F("on")) == 0) {
		pump1_on = true;
		pump1_start_time = millis();
	} else if (cmd.compareTo(F("pump_1")) == 0
			&& val.compareTo(F("off")) == 0) {
		pump1_on = false;
		pump1_start_time = 0;
	}

}

// Посылка команды слейву
void sendCommand2Slave(int valve, boolean mode) {

	Wire.beginTransmission(REALAY_MODULE_SLAVE_ID); // transmit to device #4
	String s = String("VALVE_");
	s.concat(valve);
	s.concat('=');
	s.concat(mode);
//	Serial.println(s);
//	Serial.print("String[");
//	Serial.print("][");
//	Serial.print(s.c_str());
//	Serial.println("]");
	Wire.write(s.c_str());

	Wire.endTransmission();    // stop transmitting

}

// Return true if the buffer contains an HTTP request.  Also returns the request
// path and action strings if the request was parsed.  This does not attempt to
// parse any HTTP headers because there really isn't enough memory to process
// them all.
// HTTP request looks like:
//  [method] [path] [version] \r\n
//  Header_key_1: Header_value_1 \r\n
//  ...
//  Header_key_n: Header_value_n \r\n
//  \r\n
bool parseRequest(uint8_t* buf, int bufSize, char* action, char* path) {
	// Check if the request ends with \r\n to signal end of first line.
	if (bufSize < 2)
		return false;
	if (buf[bufSize - 2] == '\r' && buf[bufSize - 1] == '\n') {
		parseFirstLine((char*) buf, action, path);
		return true;
	}
	return false;
}

// Parse the action and path from the first line of an HTTP request.
void parseFirstLine(char* line, char* action, char* path) {
	// Parse first word up to whitespace as action.
	char* lineaction = strtok(line, " ");
	if (lineaction != NULL)
		strncpy(action, lineaction, MAX_ACTION);
	// Parse second word up to whitespace as path.
	char* linepath = strtok(NULL, " ");
	if (linepath != NULL)
		strncpy(path, linepath, MAX_PATH);
}

// Tries to read the IP address and other connection details
bool displayConnectionDetails(void) {
	uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;

	if (!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv,
			&dnsserv)) {
		Serial.println(F("Unable to retrieve the IP Address!\r\n"));
		return false;
	} else {
		Serial.print(F("\nIP: "));
		cc3000.printIPdotsRev(ipAddress);
		Serial.print(F("\nMask: "));
		cc3000.printIPdotsRev(netmask);
		Serial.print(F("\nGW: "));
		cc3000.printIPdotsRev(gateway);
		Serial.print(F("\nDHCP: "));
		cc3000.printIPdotsRev(dhcpserv);
		Serial.print(F("\nDNS: "));
		cc3000.printIPdotsRev(dnsserv);
		Serial.println();
		return true;
	}
}
