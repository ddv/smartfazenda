// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _smartfazenda_router_H_
#define _smartfazenda_router_H_
#include "Arduino.h"
//add your includes for the project smartfazenda_router here

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project smartfazenda_router here
void restartWiFI(void);
void topic_callback(char* topic, byte* payload, unsigned int length);
void first_start(void);
void displayDriverMode(void);
uint16_t checkFirmwareVersion(void);
void displayMACAddress(void);
bool displayConnectionDetails(void);

//Do not add code below this line
#endif /* _smartfazenda_router_H_ */
