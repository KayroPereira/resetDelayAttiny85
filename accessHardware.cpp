#include "accessHardware.h"

typedef union{
	struct{

	}flgsAccessHardwareBits;

	unsigned int flgsAccessHardwareByte;
}FlgsAccessHardware;

FlgsAccessHardware flgsAccessHardware;


void inicializaVariaveisHardware(){

	setFlgsAccessHardware(0);
	setFlgsInterruption(0);
}

void initializeHardware(){

	//Define pinagem

	pinConfiguration(TRIGGER_SENSOR_IR, INPUT);

	pinConfiguration(OUTPUT_IR, OUTPUT);

	inicializaVariaveisHardware();

	timer1Configuration();

	//Inicialização padrão hardware

	definesInitialConditions();
}

//funções acesso ao hardware

//Interrupt

void turnOffInterrupts(){
	noInterrupts();
}

void turnOnInterrupts(){
	interrupts();
}

//IN_OUT

void pinConfiguration(uint8_t pin, uint8_t mode){
	pinMode(pin, mode);
}

void pinWrite(uint8_t pin, uint8_t val, bool modeHighLow){
	digitalWrite(pin, modeHighLow ? val : !val);
}

void pinWrite(uint8_t pin, uint8_t val){
	digitalWrite(pin, val);
}

int pinRead(uint8_t pin){
	return digitalRead(pin);
}

void setPin(uint8_t pin){
	pinWrite(pin, HIGH);
}

void clearPin(uint8_t pin){
	pinWrite(pin, LOW);
}

void togglePin(uint8_t pin){
	pinWrite(pin, !pinRead(pin));
}

//Timer1


void configTimer1(){

    // Configura o prescaler para 1024
    TCCR1 = (1 << CS13) | (1 << CS12) | (1 << CS11) | (1 << CS10);

    // Configura o modo CTC (Clear Timer on Compare Match)
    GTCCR |= (1 << PWM1B) | (1 << COM1B1);

    // Configura o valor de comparação para 5 ms
    OCR1C = 5;

    // Habilita a interrupção de comparação
    TIMSK |= (1 << OCIE1A);
}

//Delay

unsigned long getMillis(){
	return millis();
}

void delayMilliSeconds(unsigned long ms){
	delay(ms);
}


//gets e sets

void setFlgsAccessHardware(unsigned int value){
	flgsAccessHardware.flgsAccessHardwareByte = value;
}
