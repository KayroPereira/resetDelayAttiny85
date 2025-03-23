#include "controller.h"

union{
	struct{

		unsigned flgDebounceInput			: 1;
	}flgsControllerBits;

	unsigned int flgsController;
}flgsController;

// debounce inputs

//Define o estado anterior do pino
bool triggerSensorIROld;

//Define o estado do pino
bool triggerSensorIR;

//Utilizado para debounce, define a quantidade de leitura para determinar o estado
byte triggerSensorIRReadInput;

const MapByteBool mapInputs[] = {
	{TRIGGER_SENSOR_IR, &triggerSensorIR},
};

const MapByteByte mapInputsLeitura[] = {
	{TRIGGER_SENSOR_IR, &triggerSensorIRReadInput},
};

void variableInitialize(){
}

void setOutputIR(){

	pinWrite(OUTPUT_IR, HIGH);
}

void clearOutputIR(){

	pinWrite(OUTPUT_IR, LOW);
}

void definesInitialConditions(){

	setFlgToggleOutput(false);

//	clearOutputIR();
	setOutputIR();
}

void verificaTriggerIR(){

	if(getTriggerSensorIR() != getTriggerSensorIROld()){

		if(!getTriggerSensorIR()){

			loadFlgSinalDisparo();
		}else{
			setFlgSinalDisparo(false);
		}

		setTriggerSensorIROld(getTriggerSensorIR());
	}
}

void defineStatusInput(){

	setFlgDebounceInput(false);

	bool readInputs[NUMERO_INPUTS];

	for(char i = 0; i < NUMERO_INPUTS; i++){

		bool statusPinAtual = pinRead((mapInputs+i)->key);

		if(statusPinAtual != *(mapInputs+i)->value){

			(*(mapInputsLeitura+i)->value)++;

			if(*(mapInputsLeitura+i)->value >= DEBOUNCE_INPUTS){

				*(mapInputs+i)->value = statusPinAtual;
				*(mapInputsLeitura+i)->value = 0;
			}
		}else{
			*(mapInputsLeitura+i)->value = 0;
		}
	}
}

//gets e sets

// padrão

void setFlgsController(unsigned int value){
	flgsController.flgsController = value;
}

void setFlgDebounceInput(bool value){
	flgsController.flgsControllerBits.flgDebounceInput = value;
}

bool getFlgDebounceInput(){
	return flgsController.flgsControllerBits.flgDebounceInput;
}


// específico


bool getTriggerSensorIR(){
	return triggerSensorIR;
}

void setTriggerSensorIR(bool value){
	triggerSensorIR = value;
}

bool getTriggerSensorIROld(){
	return triggerSensorIROld;
}

void setTriggerSensorIROld(bool value){
	triggerSensorIROld = value;
}
