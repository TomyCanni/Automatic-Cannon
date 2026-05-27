#include "servoDisparo.h"
#include <Arduino.h>

Servo servoDisparo;
int pinServoDisparo = 10;
const int anguloReposo = 0;
const int anguloDisparo = 45;   // Ajustar según tu mecánica
const int tiempoDeDisparo = 500; // Tiempo en ms

// --- Función de disparo automático ---
void disparar() {
  servoDisparo.write(anguloDisparo);
  delay(tiempoDeDisparo);
  servoDisparo.write(anguloReposo);
  Serial.println("Disparo manual ejecutado.");
}