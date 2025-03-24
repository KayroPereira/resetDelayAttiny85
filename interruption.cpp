#include "interruption.h"

unsigned char regDelayOutputIROn = REG_DELAY_OUTPUT_IR_SEC;

unsigned int regDelayTurnOnSensorIR = REG_DELAY_TURN_ON_SENSOR_IR_SEC;
unsigned int regDelay1s = REG_DELAY_1S;
unsigned int regDelay1Min = REG_DELAY_1MIN;


typedef union{
	struct{

		unsigned flgSinalDisparo				: 1;
		unsigned flgTurnOnSensorIR				: 1;
	}flgsInterruptionBits;

	unsigned int flgsInterruptionByte;
}FlgsInterruption;

FlgsInterruption flgsInterruption;


ISR(TIMER1_COMPA_vect) {

	if(--regDelay1s <= 0){

		regDelay1s = REG_DELAY_1S;

		if(getFlgTurnOnSensorIR()){

			if(--regDelayTurnOnSensorIR <= 0){

				setFlgTurnOnSensorIR(false);
				setOutputIR();
			}
		}

		if(getFlgSinalDisparo()){

			if(--regDelayOutputIROn <= 0){

				setFlgSinalDisparo(false);
				clearOutputIR();
				loadFlgTurnOnSensorIR();
			}
		}
	}

	setFlgDebounceInput(true);
}

void timer1Configuration(){

	//Configurações timer1

	turnOffInterrupts();

	configTimer1();

	turnOnInterrupts();
}

void loadFlgSinalDisparo(){

	regDelayOutputIROn = REG_DELAY_OUTPUT_IR_SEC;
	setFlgSinalDisparo(true);
}

void loadFlgTurnOnSensorIR(){

	regDelayTurnOnSensorIR = REG_DELAY_TURN_ON_SENSOR_IR_SEC;
	setFlgTurnOnSensorIR(true);
}

//gets e sets

void setFlgsInterruption(unsigned int value){
	flgsInterruption.flgsInterruptionByte = value;
}

bool getFlgSinalDisparo(){
	return flgsInterruption.flgsInterruptionBits.flgSinalDisparo;
}

void setFlgSinalDisparo(bool value){
	flgsInterruption.flgsInterruptionBits.flgSinalDisparo = value;
}

bool getFlgTurnOnSensorIR(){
	return flgsInterruption.flgsInterruptionBits.flgTurnOnSensorIR;
}

void setFlgTurnOnSensorIR(bool value){
	flgsInterruption.flgsInterruptionBits.flgTurnOnSensorIR = value;
}
