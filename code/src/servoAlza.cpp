#include "servoAlza.h"
#include <Arduino.h>

Servo servoAlza;
int pinServoAlza = 9;

// --- Función de posicionamiento de alza ---
void moverAlza(int angulo) {
  if (angulo >= 0 && angulo <= 180) {
    servoAlza.write(angulo);
    Serial.print("Alza en: ");
    Serial.println(angulo);
  } else {
    Serial.println("Ángulo inválido. Ingresar un valor entre 0 y 180.");
  }
}