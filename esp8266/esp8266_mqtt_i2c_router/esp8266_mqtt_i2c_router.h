// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _esp8266_mqtt_i2c_router_H_
#define _esp8266_mqtt_i2c_router_H_
#include "Arduino.h"
//add your includes for the project esp8266_mqtt_i2c_router here


//end of add your includes here


//add your function definitions for the project esp8266_mqtt_i2c_router here
void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);



//Do not add code below this line
#endif /* _esp8266_mqtt_i2c_router_H_ */
