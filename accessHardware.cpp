#include "accessHardware.h"

typedef union{
	struct{

	}flgsAccessHardwareBits;

	unsigned int flgsAccessHardwareByte;
}FlgsAccessHardware;

FlgsAccessHardware flgsAccessHardware;


SoftwareSerial softwareSerial(RX_SOFT, TX_SOFT);

void inicializaVariaveisHardware(){

	setFlgsAccessHardware(0);
	setFlgsInterruption(0);
}

void initializeHardware(){

	softwareSerial.begin(9600);

	//Define pinagem

	pinConfiguration(TRIGGER_SENSOR_IR, INPUT);

	pinConfiguration(OUTPUT_IR, OUTPUT);
	pinConfiguration(OUTPUT_TEST_FREQUENCE, OUTPUT);


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

void setSpeedTimer1(uint32_t ticks){
	timer1_write(ticks);
}

void callBackTimer1(timercallback userFunc){
	timer1_attachInterrupt(userFunc);
}

void configTimer1(uint8_t divider, uint8_t int_type, uint8_t reload){
	timer1_enable(divider, int_type, reload);
}

void configTimer1(){

	// Configura Timer1 no modo Clear Timer on Compare Match (CTC)
//	TCCR1 = (1 << CTC1) | (1 << CS11);  // Prescaler de 8 e modo CTC
//	TCCR1 = (1 << CTC1) | (1 << CS10);  // Prescaler de 8 e modo CTC

//	OCR1C = 41;  // Conta de 0 a 3 → 4 ciclos → 2 µs
//	OCR1C = 16;  // Conta de 0 a 3 → 4 ciclos → 2 µs


//	TIMSK |= (1 << OCIE1A);  // Habilita interrupção de compare match A


//    cli(); // Desativa interrupções globais

//    GTCCR = 0;  // Garante que o prescaler não está travado
//
//    // Configura o Timer1 no modo CTC (Clear Timer on Compare Match) e prescaler 1
//    TCCR1 = (1 << CTC1) | (1 << CS10);  // CS10 = Prescaler 1		-> 57.5KHz
////    TCCR1 = (1 << CTC1) | (1 << CS11);  // Teste com prescaler 2	-> 57.5KHz
////    TCCR1 = (1 << CTC1) | (1 << CS12);  // Teste com prescaler 4	-> 24.44KHz
//
//    OCR1C = 15;  // Define o valor de comparação para ajustar a frequência
//
//    TIMSK |= (1 << OCIE1A);  // Ativa interrupção de comparação A



    // Configura Timer1 para gerar PWM de 1 MHz
//    TCCR1 = (1 << CTC1) | (1 << CS10);
//    OCR1A = 213;  // Deve gerar um sinal de 1 MHz se F_CPU estiver correto
//    OCR1C = OCR1A;
//    TIMSK |= (1 << OCIE1A);  // Ativa interrupção de comparação A

//    GTCCR |= (1 << COM1B0); // Ativa saída no pino OCR1B

//    sei(); // Ativa interrupções globais
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
