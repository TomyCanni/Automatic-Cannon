#ifndef STEPPERDERIVA_H
#define STEPPERDERIVA_H

#include <AccelStepper.h>

extern AccelStepper stepper;
extern const int pasosPorVuelta;

void moverStepper(int angulo);

#endif