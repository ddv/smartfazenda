// Do not remove the include below
#include "smartfazenda.h"




/***************************************************
  Adafruit CC3000 Breakout/Shield Simple HTTP Server

  This is a simple implementation of a bare bones
  HTTP server that can respond to very simple requests.
  Note that this server is not meant to handle high
  load, concurrent connections, SSL, etc.  A 16mhz Arduino
  with 2K of memory can only handle so much complexity!
  This server example is best for very simple status messages
  or REST APIs.

  See the CC3000 tutorial on Adafruit's learning system
  for more information on setting up and using the
  CC3000:
    http://learn.adafruit.com/adafruit-cc3000-wifi

  Requirements:

  This sketch requires the Adafruit CC3000 library.  You can
  download the library from:
    https://github.com/adafruit/Adafruit_CC3000_Library

  For information on installing libraries in the Arduino IDE
  see this page:
    http://arduino.cc/en/Guide/Libraries

  Usage:

  Update the SSID and, if necessary, the CC3000 hardware pin
  information below, then run the sketch and check the
  output of the serial port.  After connecting to the
  wireless network successfully the sketch will output
  the IP address of the server and start listening for
  connections.  Once listening for connections, connect
  to the server IP from a web browser.  For example if your
  server is listening on IP 192.168.1.130 you would access
  http://192.168.1.130/ from your web browser.

  Created by Tony DiCola and adapted from HTTP server code created by Eric Friedrich.

  This code was adapted from Adafruit CC3000 library example
  code which has the following license:

  Designed specifically to work with the Adafruit WiFi products:
  ----> https://www.adafruit.com/products/1469

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#include <Adafruit_CC3000.h>
#include <SPI.h>
#include "utility/debug.h"
#include "utility/socket.h"


// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!
// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10
// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11

Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
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
uint8_t buffer[BUFFER_SIZE+1];
int bufindex = 0;
char action[MAX_ACTION+1];
char path[MAX_PATH+1];

boolean valve1_on = false;
boolean valve2_on = false;
boolean valve3_on = false;
boolean valve4_on = false;

boolean pump1_on = false;
unsigned long pump1_start_time = 0;

uint16_t input_water_flow = 0;

void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("Hello, CC3000!\n"));

  Serial.print("Free RAM: "); Serial.println(getFreeRam(), DEC);

  // Initialise the module
  Serial.println(F("\nInitializing..."));
  if (!cc3000.begin())
  {
    Serial.println(F("Couldn't begin()! Check your wiring?"));
    while(1);
  }

  Serial.print(F("\nAttempting to connect to ")); Serial.println(WLAN_SSID);
  if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println(F("Failed!"));
    while(1);
  }

  Serial.println(F("Connected!"));

  Serial.println(F("Request DHCP"));
  while (!cc3000.checkDHCP())
  {
    delay(100); // ToDo: Insert a DHCP timeout!
  }

  // Display the IP address DNS, Gateway, etc.
  while (! displayConnectionDetails()) {
    delay(1000);
  }

  // ******************************************************
  // You can safely remove this to save some flash memory!
  // ******************************************************
  Serial.println(F("\r\nNOTE: This sketch may cause problems with other sketches"));
  Serial.println(F("since the .disconnect() function is never called, so the"));
  Serial.println(F("AP may refuse connection requests from the CC3000 until a"));
  Serial.println(F("timeout period passes.  This is normal behaviour since"));
  Serial.println(F("there isn't an obvious moment to disconnect with a server.\r\n"));

  // Start listening for connections
  httpServer.begin();

  Serial.println(F("Listening for connections..."));
}

void loop(void)
{
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
    memset(&path,   0, sizeof(path));

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
      Serial.print(F("Action: ")); Serial.println(action);
      Serial.print(F("Path: ")); Serial.println(path);

      //
      String s = String(path);
      Serial.println(F("test: "));

      int i=s.indexOf("?");
      String mode = s.substring(0,i);
      Serial.print(F("mode["));
      Serial.print(mode);
      Serial.println(F("]"));

      if (mode.compareTo(F("/rest"))==0) {

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
        client.fastrprintln(F("Content-Type: text/html; charset=utf-8"));


        client.fastrprintln(F("Connection: close"));
        client.fastrprintln(F("Server: Smart Fazenda"));
        // Send an empty line to signal start of body.





        showForm(client);
      }
      else {
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

// Form
void showForm(Adafruit_CC3000_ClientRef client) {

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

	//Valve 1

	client.fastrprintln(F("<tr><td colspan=2> Клапан №1 </td></tr>"));

	client.fastrprintln(F("<tr>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"valve_1\" value=\"on\">"));


	if(valve1_on==true)
		client.fastrprint(F("<input type=\"submit\" value=\"Открыть\" disabled>"));
	else
		client.fastrprint(F("<input type=\"submit\" value=\"Открыть\">"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"valve_1\" value=\"off\">"));

	if(valve1_on==true)
		client.fastrprint(F("<input type=\"submit\" value=\"Закрыть\">"));
	else
		client.fastrprint(F("<input type=\"submit\" value=\"Закрыть\" disabled>"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("</tr>"));

	//Valve 2

	client.fastrprintln(F("<tr><td colspan=2> Клапан №2 </td></tr>"));

	client.fastrprintln(F("<tr>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"valve_2\" value=\"on\">"));

	if(valve2_on==true)
			client.fastrprint(F("<input type=\"submit\" value=\"Открыть\" disabled>"));
		else
			client.fastrprint(F("<input type=\"submit\" value=\"Открыть\">"));


	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"valve_2\" value=\"off\">"));

	if(valve2_on==true)
			client.fastrprint(F("<input type=\"submit\" value=\"Закрыть\">"));
		else
			client.fastrprint(F("<input type=\"submit\" value=\"Закрыть\" disabled>"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("</tr>"));


	//Pump 1



	if(pump1_start_time>0) {
		client.fastrprintln(F("<tr><td colspan=2> Насос №1 (работает "));
		client.println(( (millis()-pump1_start_time)/1000));
		client.fastrprintln(F(" сек.)</td></tr>"));
	} else {
		client.fastrprintln(F("<tr><td colspan=2> Насос №1 </td></tr>"));
	}

	client.fastrprintln(F("<tr>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"pump_1\" value=\"on\">"));

	if(pump1_on==true)
			client.fastrprint(F("<input type=\"submit\" value=\"Включить\" disabled>"));
		else
			client.fastrprint(F("<input type=\"submit\" value=\"Включить\">"));


	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("<td>"));

	client.fastrprint(F("<form action=\"rest\">"));
	client.fastrprint(
			F("<input type=\"hidden\" name=\"pump_1\" value=\"off\">"));

	if(pump1_on==true)
			client.fastrprint(F("<input type=\"submit\" value=\"Выключить\">"));
		else
			client.fastrprint(F("<input type=\"submit\" value=\"Выключить\" disabled>"));

	client.fastrprint(F("</form>"));

	client.fastrprintln(F("</td>"));
	client.fastrprintln(F("</tr>"));

	client.fastrprintln(F("</table>"));




}


void runcmd(String cmd, String val) {
	Serial.print(F("CMD: ["));
	Serial.print(cmd);
	Serial.print(F("]=["));
	Serial.print(val);
	Serial.println(F("]"));

	if (cmd.compareTo(F("valve_1")) == 0 && val.compareTo(F("on")) == 0) {
		valve1_on = true;
		Serial.println(F("valve1_on"));
	} else
	if (cmd.compareTo(F("valve_1")) == 0 && val.compareTo(F("off")) == 0) {
		valve1_on = false;
		Serial.println(F("valve1_off"));
	} else
	if (cmd.compareTo(F("valve_2")) == 0 && val.compareTo(F("on")) == 0) {
		valve2_on = true;
		Serial.println(F("valve2_on"));
	} else
	if (cmd.compareTo(F("valve_2")) == 0 && val.compareTo(F("off")) == 0) {
		valve2_on = false;
		Serial.println(F("valve2_off"));
	} else
	if (cmd.compareTo(F("pump_1")) == 0 && val.compareTo(F("on")) == 0) {
		pump1_on = true;
		pump1_start_time = millis();
		Serial.println(F("pump1_on"));
	} else
	if (cmd.compareTo(F("pump_1")) == 0 && val.compareTo(F("off")) == 0) {
		pump1_on = false;
		pump1_start_time = 0;
		Serial.println(F("pump1_off"));
	}

	Serial.print(F("out:"));

	Serial.print(F("valve1="));
	Serial.println(valve1_on);

	Serial.print(F("valve2="));
	Serial.println(valve2_on);

	Serial.print(F("pump1="));
	Serial.println(pump1_on);
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
  if (buf[bufSize-2] == '\r' && buf[bufSize-1] == '\n') {
    parseFirstLine((char*)buf, action, path);
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
bool displayConnectionDetails(void)
{
  uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;

  if(!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv, &dnsserv))
  {
    Serial.println(F("Unable to retrieve the IP Address!\r\n"));
    return false;
  }
  else
  {
    Serial.print(F("\nIP Addr: ")); cc3000.printIPdotsRev(ipAddress);
    Serial.print(F("\nNetmask: ")); cc3000.printIPdotsRev(netmask);
    Serial.print(F("\nGateway: ")); cc3000.printIPdotsRev(gateway);
    Serial.print(F("\nDHCPsrv: ")); cc3000.printIPdotsRev(dhcpserv);
    Serial.print(F("\nDNSserv: ")); cc3000.printIPdotsRev(dnsserv);
    Serial.println();
    return true;
  }
}