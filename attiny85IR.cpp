#include "attiny85IR.h"

void setup() {

	initializeHardware();
}


void loop() {

	if(getFlgDebounceInput()){
		defineStatusInput();
	}

	verificaTriggerIR();
}
