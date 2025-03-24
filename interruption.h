
#ifndef INTERRUPTION_H_
#define INTERRUPTION_H_

#include "Arduino.h"
#include "importUtils.h"


// Utilizando uma base de 5ms por interrupção

#define REG_DELAY_1S							200	// 1s

#define REG_DELAY_OUTPUT_IR_SEC					2		// 2s
#define REG_DELAY_TURN_ON_SENSOR_IR_SEC			1		// 1s

#define REG_DELAY_1MIN							60		// 1 minutos


//interruption

bool getFlgToggleOutput();
void setFlgToggleOutput(bool value);

void loadFlgSinalDisparo();
void loadFlgTurnOnSensorIR();

void setSpeedTimerBase_uS(unsigned int base);

#endif /* INTERRUPTION_H_ */
