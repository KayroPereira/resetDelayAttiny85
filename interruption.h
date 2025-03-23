
#ifndef INTERRUPTION_H_
#define INTERRUPTION_H_

#include "Arduino.h"
#include "importUtils.h"


// Utilizando uma base de 5ms por interrupção

#define REG_DELAY_1S							200	// 1s

#define REG_DELAY_OUTPUT_IR_SEC					2		// 2s
#define REG_DELAY_TURN_ON_SENSOR_IR_SEC			1		// 1s

#define REG_DELAY_1MIN							60		// 1 minutos


//Declara constantes

const int BASE_TIME = 5;				// Base em ms
const int BASE_TIME_CLOCK = 80000;		// Não mexer
const int DIVISOR_TIMER = 256;			// Não mexer

//const int BASE_TIME = 13;				// Base em us
//const int BASE_TIME_CLOCK = 80000000;		// Não mexer
//const int DIVISOR_TIMER = 16;			// Não mexer

#define TIM_DIV256 3
#define TIM_DIV16 1
#define TIM_EDGE 0
#define TIM_LOOP 1


//interruption

bool getFlgToggleOutput();
void setFlgToggleOutput(bool value);

void loadFlgSinalDisparo();
void loadFlgTurnOnSensorIR();

void setSpeedTimerBase_uS(unsigned int base);

#endif /* INTERRUPTION_H_ */
