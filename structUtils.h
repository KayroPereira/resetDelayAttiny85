#ifndef STRUCTUTILS_H_
#define STRUCTUTILS_H_

#include "Arduino.h"

typedef struct{
	const String key;
	bool *value;
}MapStringBool;

typedef struct{
	const byte key;
	bool *value;
}MapByteBool;

typedef struct{
	const String key;
	int *value;
}MapStringInt;

typedef struct{
	const byte key;
	byte *value;
}MapByteByte;

typedef struct{
	word TOn;
	word TOff;
	char repeat;
	bool step;
}BeepConfig;

#endif /* STRUCTUTILS_H_ */
