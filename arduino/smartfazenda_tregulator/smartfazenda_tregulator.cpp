// Проект регулятора температуры в доме
#include "smartfazenda_tregulator.h"
#include <Wire.h>
#include <dht11.h>

#define I2C_ADDR 2

dht11 DHT11;

int dht11_status = 0;
float dht11_temterature = -99;
float dht11_humidity = -99;

int last_send = 0;

void setup()
{
  DHT11.attach(2);
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);

  Wire.begin(I2C_ADDR);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{

  Serial.println("\n");

  dht11_status = DHT11.read();



  Serial.print("!!Read sensor: ");
  switch (dht11_status)
  {
    case 0: Serial.println("OK");
      dht11_temterature=DHT11.temperature;
      dht11_humidity=DHT11.humidity;
          break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, DEC);

  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, DEC);

  Serial.print("Temperature (°F): ");
  Serial.println(DHT11.fahrenheit(), DEC);

  Serial.print("Temperature (°K): ");
  Serial.println(DHT11.kelvin(), DEC);

  Serial.print("Dew Point (°C): ");
  Serial.println(DHT11.dewPoint(), DEC);

  Serial.print("Dew PointFast (°C): ");
  Serial.println(DHT11.dewPointFast(), DEC);

  delay(2000);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{

  Serial.print("I2C Req from Master:");
  Serial.println(dht11_status);
  char str_temp[16];
  char str_hum[16];

  dtostrf(dht11_temterature, 4, 2, str_temp);
  dtostrf(dht11_humidity, 4, 2, str_hum);



  switch (dht11_status)
  {
    case 0:
        if(last_send==0) {

          Serial.print("dht11 T:");
          Serial.println(str_temp);
          Serial.println("\n");

//          String s = "T/";
//           s = s + dht11_temterature;
        //s.getBytes(str_temp,12);
//          Wire.write());
          Wire.write(str_temp);


          last_send=1;
        } else {

          Serial.print("dht11 H:");
          Serial.println(str_hum);
          Serial.println("\n");

          Wire.write(str_hum);
          last_send=0;
        }

        break;
    case -1: Wire.write("crcerr"); break;
    case -2: Wire.write("tm_err"); break;
    default: Wire.write("un_err"); break;
  }
  //Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master
}
