#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "accessHardware.h"
#include "importUtils.h"


//controller

bool getTriggerSensorIR();
void setTriggerSensorIR(bool value);
bool getTriggerSensorIROld();
void setTriggerSensorIROld(bool value);

#endif /* CONTROLLER_H_ */
