#include <Arduino.h>
#include <Servo.h>
#include <AccelStepper.h>

// --- Headers ---
#include "stepperDeriva.h"
#include "servoAlza.h"
#include "servoDisparo.h"
#include "motoresDC.h"
#include "apuntadoAutomatico.h"
#include "volverAlOrigen.h"
#include "procesarComandos.h"

void setup() {
  // Stepper
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);

  // Servo alza
  servoAlza.attach(pinServoAlza);   // en Arduino basta con attach(pin)

  // Servo disparo
  servoDisparo.attach(pinServoDisparo);

  // Motores DC → usar analogWrite en vez de ledcSetup/ledcAttachPin
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  // Serial
  Serial.begin(115200);
  
  Serial.println("Sistema listo.");
  Serial.println("Comandos:");
  Serial.println("ALZA <angulo 0-180>");
  Serial.println("DERIVA <angulo 0-360>");
  Serial.println("ACTIVAR (activar motores DC)");
  Serial.println("DETENER (detener motores DC)");
  Serial.println("DISPARAR (disparar manualmente)");
  Serial.println("AUTO <x> <y> <d> (apuntado automático)");
  Serial.println("ORIGEN (posicionamiento a 0°)");
  
  volverAlOrigen();
  Serial.println("Sistemas listos.");
}

void loop() {
  procesarComando();
}