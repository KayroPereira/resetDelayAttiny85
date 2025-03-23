#include "interruption.h"

unsigned char regDelayOutputIROn = REG_DELAY_OUTPUT_IR_SEC;

unsigned int regDelayTurnOnSensorIR = REG_DELAY_TURN_ON_SENSOR_IR_SEC;
unsigned int regDelay1s = REG_DELAY_1S;
unsigned int regDelay1Min = REG_DELAY_1MIN;


typedef union{
	struct{

		unsigned flgSinalDisparo				: 1;
		unsigned flgTurnOnSensorIR				: 1;
		unsigned flgToggleOutput				: 1;
	}flgsInterruptionBits;

	unsigned int flgsInterruptionByte;
}FlgsInterruption;

FlgsInterruption flgsInterruption;


unsigned long millisDelayPeriod = millis();

//ISR(TIMER1_COMPA_vect) {
void timerInterrupt() {

	if(--regDelay1s <= 0){

		softwareSerial.printf("\nDelay timer1 1s: %d\n", millis() - millisDelayPeriod);

		millisDelayPeriod = millis();

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

	callBackTimer1(timerInterrupt);
	configTimer1(TIM_DIV256, TIM_EDGE, TIM_LOOP);
//	configTimer1(TIM_DIV16, TIM_EDGE, TIM_LOOP);
	setSpeedTimer();
//	setSpeedTimerBase_uS(BASE_TIME);

	turnOnInterrupts();
}

void setSpeedTimer(){
	setSpeedTimer1((BASE_TIME * BASE_TIME_CLOCK) / DIVISOR_TIMER); // 1ms (80 MHz / 256)
//	setSpeedTimer1(66); // 1ms (80 MHz / 256)
}

void setSpeedTimerBase_uS(unsigned int base){

	double baseClock = (1.0 / (BASE_TIME_CLOCK / DIVISOR_TIMER)) / 0.000001;

	setSpeedTimer1(base / baseClock); // 1ms (80 MHz / 256)
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

bool getFlgToggleOutput(){
	return flgsInterruption.flgsInterruptionBits.flgToggleOutput;
}

void setFlgToggleOutput(bool value){
	flgsInterruption.flgsInterruptionBits.flgToggleOutput = value;
}
