#include "stepperDeriva.h"
#include <Arduino.h>

// Pines para el driver del stepper
#define pinStep 2
#define pinDir  4

// Objeto AccelStepper configurado como DRIVER (step/dir)
AccelStepper stepper(AccelStepper::DRIVER, pinStep, pinDir);

const int pasosPorVuelta = 200;

// --- Función de posicionamiento de deriva ---
void moverStepper(int angulo) {
  if (angulo >= 0 && angulo <= 360) {
    long pasosObjetivo = (angulo / 360.0) * pasosPorVuelta;
    stepper.moveTo(pasosObjetivo);
    stepper.runToPosition();
    Serial.print("Deriva objetivo: ");
    Serial.println(angulo);
  } else {
    Serial.println("Ángulo inválido. Ingresar un valor entre 0 y 360.");
  }
}