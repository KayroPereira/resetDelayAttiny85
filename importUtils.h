#ifndef IMPORTUTILS_H_
#define IMPORTUTILS_H_

#include "SoftwareSerial.h"

extern SoftwareSerial softwareSerial;

//Declara pinos

#define RX_SOFT						3	//D9
#define TX_SOFT						5	//D1

//#define BUTTON_LED_CONFIG			D4

//#define INPUT_SENSOR_SUP			D6
#define TRIGGER_SENSOR_IR			14	//D5
//#define INPUT_CAIXA_3				D7

//#define OUTPUT_RELE_NIVEL_SUP		D3
//#define OUTPUT_RELE_NIVEL_INF		D1	//D8
//#define OUTPUT_RELE_PRINCIPAL		D2

//#define OUTPUT_IR					PB1
#define OUTPUT_IR					2	//D4
#define OUTPUT_TEST_FREQUENCE		4	//D2

#define NUMERO_INPUTS				1
#define DEBOUNCE_INPUTS				8


//IN_OUT

extern void turnOffInterrupts();
extern void turnOnInterrupts();
extern void pinConfiguration(uint8_t pin, uint8_t mode);
extern void pinWrite(uint8_t pin, uint8_t val, bool modeHighLow);
extern void pinWrite(uint8_t pin, uint8_t val);
extern int pinRead(uint8_t pin);
extern void setPin(uint8_t pin);
extern void clearPin(uint8_t pin);
extern void togglePin(uint8_t pin);


//Timer1

extern void setSpeedTimer1(uint32_t ticks);
extern void callBackTimer1(timercallback userFunc);
extern void configTimer1(uint8_t divider, uint8_t int_type, uint8_t reload);
extern void configTimer1();
//extern void removeCallbackTimer1();


//Delay

extern unsigned long getMillis();
extern void delayMilliSeconds(unsigned long ms);


//accessHardware

extern void initializeHardware();
extern void setInitializationOk(bool value);
extern void setFlgsAccessHardware(unsigned int value);


//interruption

extern void timer1Configuration();
extern void setFlgsInterruption(unsigned int value);
extern void setSpeedTimer();
extern void loadFlgSinalDisparo();


extern bool getFlgToggleOutput();
extern void setFlgToggleOutput(bool value);
extern bool getFlgSinalDisparo();
extern void setFlgSinalDisparo(bool value);
extern bool getFlgTurnOnSensorIR();
extern void setFlgTurnOnSensorIR(bool value);


//controller

extern bool localOnOff;
extern bool localAutoManual;

extern int e2promGravada;
extern int localUpdate;


extern void variableInitialize();
extern void definesInitialConditions();
extern void setFlgsController(unsigned int value);
extern void setFlgDebounceInput(bool value);
extern bool getFlgDebounceInput();
extern void defineStatusInput();
extern void verificaTriggerIR();


extern void setOutputIR();
extern void clearOutputIR();


#endif /* IMPORTUTILS_H_ */
