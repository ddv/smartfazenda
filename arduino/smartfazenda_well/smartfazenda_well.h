// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _smartfazenda_well_H_
#define _smartfazenda_well_H_
#include "Arduino.h"
//add your includes for the project smartfazenda_well here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project smartfazenda_well here
void wellMotorRun();
void wellMotorStop();
boolean getWellLowLvlStatus();
boolean getTankMaxLvlStatus();
boolean checkWellMotorIsReadyToStart();
boolean checkWellMotorNeedToStop();
void blinkEror();
void blinkStatus();
void blinkWellMinLvl();
void blinkTankllMaxLvl();


//Do not add code below this line
#endif /* _smartfazenda_well_H_ */
