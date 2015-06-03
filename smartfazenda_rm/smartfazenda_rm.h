// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _smartfazenda_rm_H_
#define _smartfazenda_rm_H_
#include "Arduino.h"
//add your includes for the project smartfazenda_rm here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project smartfazenda_rm here

void receiveEvent(int howMany);
void requestEvent();
void cmdValve(int valve, boolean state);
void requestStatusValve(int valve);
void blink(int valve, boolean state);


//Do not add code below this line
#endif /* _smartfazenda_rm_H_ */
