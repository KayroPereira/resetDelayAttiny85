#ifndef IMPORTUTILS_H_
#define IMPORTUTILS_H_


//Declara pinos

#define TRIGGER_SENSOR_IR			PB2


#define OUTPUT_IR					PB1


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

extern void configTimer1();


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
extern void loadFlgSinalDisparo();


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
