#include "volverAlOrigen.h"
#include "servoAlza.h"
#include "servoDisparo.h"
#include "stepperDeriva.h"
#include <Arduino.h>

void volverAlOrigen() {
  // Alza a 0°
  servoAlza.write(0);
  Serial.println("Alza a 0°");

  // Deriva a 0°
  stepper.moveTo(0);
  stepper.runToPosition();
  Serial.println("Deriva en movimiento hacia 0°");

  // Disparo en reposo
  servoDisparo.write(anguloReposo);
  Serial.println("Disparo en reposo");
}