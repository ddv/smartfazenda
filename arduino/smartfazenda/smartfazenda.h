// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _smartfazenda_H_
#define _smartfazenda_H_
#include "Arduino.h"
//add your includes for the project smartfazenda here

#include <Adafruit_CC3000.h>

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project testCC3000 here
void parseFirstLine(char* line, char* action, char* path);
bool displayConnectionDetails(void);
bool parseRequest(uint8_t* buf, int bufSize, char* action, char* path);
void runcmd(String cmd, String val);
void showForm(Adafruit_CC3000_ClientRef client);
void sendCommand2Slave(int valve, boolean mode);
void requestSlaveTelezone();

//Do not add code below this line
#endif /* _smartfazenda_H_ */
