// Do not remove the include below
#include "esp8266_mqtt_i2c_router.h"

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "DDVPOINT";
const char* password = "1234567890";
const char* mqtt_server = "v.psystems.org";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Wire.begin(0, 2);       // join i2c bus (address optional for master)
  //Wire.setClock(100000);
  Serial.begin(9600);  // start serial for output
  //Serial.println("ESP-MASTER");

  //pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  //Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

   String val = "";
  for (int i = 0; i < length; i++) {
    val.concat((char)payload[i]);
    Serial.print((char)payload[i]);
  }

  Serial.println();

  String tag = "led\n";
  tag += val;
  tag += "\n";

  Wire.beginTransmission(4); // transmit to device #4
  char out[50];
  tag.toCharArray(out,50);

  Serial.print("Transmit[");
  Serial.print(out);
  Serial.println("]");

  Wire.write(out);
//  Wire.write("led\n1\n");

  Wire.endTransmission();    // stop transmitting

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    //digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    //digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client", "test", "test")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic/#");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  //I2C

  Serial.println("READ:\n");
  Wire.requestFrom(4, 32);    // request 6 bytes from slave device #2

  Serial.print("[");
  String tag = "/esp8266";
  String val = "";
  boolean tag_end = false;
  boolean val_end = false;
  while (Wire.available())   // slave may send less than requested
  {
    char c = Wire.read(); // receive a byte as character
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
    //    Serial.print("[");
    //Serial.print(c);         // print the character
    //    Serial.print("]");
  }

  Serial.print(tag);
  Serial.print("]=[");
  Serial.print(val);
  Serial.print("]");

  Serial.println("\nEND\n");

  val.toCharArray(msg, 50);

  //MQTT

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //  long now = millis();
  //  if (now - lastMsg > 2000) {
  //    lastMsg = now;
  //    ++value;
  //    snprintf (msg, 75, "hello world #%ld", value);
  ;
  Serial.print("Publish message: ");
  Serial.println(msg);

  //  client.publish("outTopic", msg);

  char topic[50];
  tag.toCharArray(topic, 50);

  client.publish(topic, msg);

  delay(3000);
}



