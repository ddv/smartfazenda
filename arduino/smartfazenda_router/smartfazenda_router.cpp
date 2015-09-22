// Do not remove the include below
#include "smartfazenda_router.h"
#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <cc3000_PubSubClient.h>
#include <avr/wdt.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))

#define aref_voltage 3.3

// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!

// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10

// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11
Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS,
		ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT, SPI_CLOCK_DIVIDER);

#define WLAN_SSID       "JY-S3"
#define WLAN_PASS       "1234567890"

// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

// Это сокет
Adafruit_CC3000_Client client;

uint32_t ip;

// Флаг первого старта
boolean first_flag = true;


cc3000_PubSubClient mqttclient(ip, 1883, topic_callback, client, cc3000);

// Функция обработки данных из топика
void topic_callback(char* topic, byte* payload, unsigned int length) {

	Serial.print(F("TOPIC ["));
	Serial.print(topic);
	Serial.print(F("] LENGTH ["));
	Serial.print(length);
	Serial.print(" DATA [");
	Serial.write(payload, length);
	Serial.println("]\n");
}

byte x = 0;

void i2cchat() {
	Serial.println(F("I2C"));

	Wire.beginTransmission(4); // transmit to device #4
	Wire.write("x is ");        // sends five bytes
	Wire.write(x);              // sends one byte
	Wire.endTransmission();    // stop transmitting

	//x++;
	if (x == 0) {
		x = 1;
	} else {
		x = 0;
	}
	Serial.println(x);
	//delay(500);

	Wire.requestFrom(4, 6);    // request 6 bytes from slave device #2

	while (Wire.available())   // slave may send less than requested
	{
		char c = Wire.read(); // receive a byte as character
		Serial.print(c);         // print the character
	}
	//delay(500);
}

void setup(void) {

	wdt_disable();
	// Выключаем wtachdog
	delay(2000); // Даем на всякий случай время на инициализацию
	wdt_enable(WDTO_8S); //Включаем wtachdog (8 секунд)

	Wire.begin(); // join i2c bus (address optional for master)

	if (first_flag) {
		first_start();
	}

	Serial.println(F("Setup"));
	restartWiFI();
}

//
void first_start(void) {
	first_flag = false;
	Serial.begin(9600);
	Serial.println(F("Board restarted"));

}

void restartWiFI(void) {

	Serial.println(F("Hello, CC3000!\n"));

	cc3000.reboot();

	wdt_reset();
	//Сброс watchdog

	// If you want to set the aref to something other than 5v
	analogReference(EXTERNAL);

	displayDriverMode();

	Serial.println(F("\nInitialising the CC3000 ..."));
	if (!cc3000.begin()) {
		Serial.println(
				F("Unable to initialise the CC3000! Check your wiring?"));
		for (;;)
			;
	}

	wdt_reset();
	//Сброс watchdog

	uint16_t firmware = checkFirmwareVersion();
	if ((firmware != 0x113) && (firmware != 0x118)) {
		Serial.println(F("Wrong firmware version!"));
		for (;;)
			;
	}

	wdt_reset();
	//Сброс watchdog

	displayMACAddress();

	Serial.println(F("\nDeleting old connection profiles"));
	if (!cc3000.deleteProfiles()) {
		Serial.println(F("Failed!"));
		while (1)
			;
	}

	wdt_reset();
	//Сброс watchdog

	/* Attempt to connect to an access point */
	char *ssid = WLAN_SSID; /* Max 32 chars */
	Serial.print(F("\nAttempting to connect to "));
	Serial.println(ssid);
	Serial.print(F("\nto connect timeout "));
	Serial.println(WLAN_CONNECT_TIMEOUT);

	wdt_disable();
	// Выключаем wtachdog

	/* NOTE: Secure connections are not available in 'Tiny' mode! */
	if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY, 1)) {
		Serial.println(F("Failed!"));
		wdt_enable(WDTO_8S); //Включаем wtachdog (8 секунд)
		while (1)
			;

	}

	wdt_enable(WDTO_8S); //Включаем wtachdog (8 секунд)

	wdt_reset();
	//Сброс watchdog

	Serial.println(F("Connected!"));

	/* Wait for DHCP to complete */
	Serial.println(F("Request DHCP"));
	while (!cc3000.checkDHCP()) {
		delay(100); // ToDo: Insert a DHCP timeout!
	}

	wdt_reset();
	//Сброс watchdog

	/* Display the IP address DNS, Gateway, etc. */
	while (!displayConnectionDetails()) {
		delay(1000);
	}

	wdt_reset();
	//Сброс watchdog

	Serial.println(F("getHostByName..."));
	while (!cc3000.getHostByName("v.psystems.org", &ip)) {
		delay(1000);
	}

	wdt_reset();
	//Сброс watchdog

	Serial.println(F("BROCKER IP"));
	Serial.println(ip);

	// connect to the broker
	//if (!client.connected()) {
	client = cc3000.connectTCP(ip, 1883);
	//}

	Serial.println(F("Connected to Broker"));

	// did that last thing work? sweet, let's do something
	if (client.connected()) {
		Serial.println(F("client connected"));
		if (mqttclient.connect("ArduinoUnoClient-CC3000-A4", "test", "test")) {
			Serial.println(F("Publish A4 is now online"));
			mqttclient.publish("sensors/a4/out/debug", "A4 is now online");

			// Подписка
			Serial.println(F("Subscribe #"));
			mqttclient.subscribe("/smartfazenda/i2c/#");
		}
	}

	wdt_reset();
	//Сброс watchdog
}

void loop(void) {

	//Сброс вачдога
	wdt_reset();

	//Обработка подписки
	mqttclient.loop();

	i2cchat();

	//Сброс вачдога
	wdt_reset();

	Serial.println(F("Loop"));

	//Сброс вачдога
	wdt_reset();

	//Проверка WIFI
	if (cc3000.getStatus() != STATUS_CONNECTED) {
		Serial.println(F("WIFI restarting"));
		restartWiFI();
		return;
	}

	Serial.println(F("WIFI OK"));

	//float temperatureReading = analogRead(tempPin);
	float temperatureReading = random(10, 40);

	float voltage = temperatureReading * aref_voltage;
	voltage /= 1024.0;

	float temperatureC = (voltage - 0.5) * 100;
	float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

	// cheap tricks I tell you
	char stringTemperatureF[10];
	dtostrf(temperatureF, 0, 3, stringTemperatureF);

	// are we still connected?
	if (!client.connected()) {
		Serial.println(F("make connectTCP"));
		client = cc3000.connectTCP(ip, 1883);

		if (client.connected()) {

			Serial.println(F("connectTCP"));

			if (mqttclient.connect("ArduinoUnoClient-Office-A4")) {
				Serial.println(F("publishing now online..."));
				mqttclient.publish("sensors/a4/out/debug",
						"A4 is now back online");
				Serial.println(F("publishing now online OK"));
			}
		}
	} else {
		// yep, publish that test
		Serial.println(F("publishing..."));
		mqttclient.publish("sensors/a4/out", stringTemperatureF);
		Serial.print(F("Publish temerature="));
		Serial.println(stringTemperatureF);

	}

	wdt_reset();
	//Сброс watchdog
	delay(500);
}

/**************************************************************************/
/*!
 @brief  Displays the driver mode (tiny of normal), and the buffer
 size if tiny mode is not being used

 @note   The buffer size and driver mode are defined in cc3000_common.h
 */
/**************************************************************************/
void displayDriverMode(void) {
#ifdef CC3000_TINY_DRIVER
	Serial.println(F("CC3000 is configure in 'Tiny' mode"));
#else
	Serial.print(F("RX Buffer : "));
	Serial.print(CC3000_RX_BUFFER_SIZE);
	Serial.println(F(" bytes"));
	Serial.print(F("TX Buffer : "));
	Serial.print(CC3000_TX_BUFFER_SIZE);
	Serial.println(F(" bytes"));
#endif
}

/**************************************************************************/
/*!
 @brief  Tries to read the CC3000's internal firmware patch ID
 */
/**************************************************************************/
uint16_t checkFirmwareVersion(void) {
	uint8_t major, minor;
	uint16_t version;

#ifndef CC3000_TINY_DRIVER
	if (!cc3000.getFirmwareVersion(&major, &minor)) {
		Serial.println(F("Unable to retrieve the firmware version!\r\n"));
		version = 0;
	} else {
		Serial.print(F("Firmware V. : "));
		Serial.print(major);
		Serial.print(F("."));
		Serial.println(minor);
		version = major;
		version <<= 8;
		version |= minor;
	}
#endif
	return version;
}

/**************************************************************************/
/*!
 @brief  Tries to read the 6-byte MAC address of the CC3000 module
 */
/**************************************************************************/
void displayMACAddress(void) {
	uint8_t macAddress[6];

	if (!cc3000.getMacAddress(macAddress)) {
		Serial.println(F("Unable to retrieve MAC Address!\r\n"));
	} else {
		Serial.print(F("MAC Address : "));
		cc3000.printHex((byte*) &macAddress, 6);
	}
}

/**************************************************************************/
/*!
 @brief  Tries to read the IP address and other connection details
 */
/**************************************************************************/
bool displayConnectionDetails(void) {
	uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;

	if (!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv,
			&dnsserv)) {
		Serial.println(F("Unable to retrieve the IP Address!\r\n"));
		return false;
	} else {
		Serial.print(F("\nIP Addr: "));
		cc3000.printIPdotsRev(ipAddress);
		Serial.print(F("\nNetmask: "));
		cc3000.printIPdotsRev(netmask);
		Serial.print(F("\nGateway: "));
		cc3000.printIPdotsRev(gateway);
		Serial.print(F("\nDHCPsrv: "));
		cc3000.printIPdotsRev(dhcpserv);
		Serial.print(F("\nDNSserv: "));
		cc3000.printIPdotsRev(dnsserv);
		Serial.println();
		return true;
	}
}

