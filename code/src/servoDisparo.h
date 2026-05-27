#ifndef SERVODISPARO_H
#define SERVODISPARO_H

#include <Servo.h>   // En Arduino clásico se usa Servo.h

extern Servo servoDisparo;
extern int pinServoDisparo;
extern const int anguloReposo;
extern const int anguloDisparo;
extern const int tiempoDeDisparo;

void disparar();

#endif