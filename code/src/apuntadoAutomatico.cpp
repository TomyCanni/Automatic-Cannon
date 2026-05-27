#include "apuntadoAutomatico.h"
#include "stepperDeriva.h"
#include "servoAlza.h"
#include "motoresDC.h"
#include "servoDisparo.h"
#include <Arduino.h>
#include <math.h>

const float g = 9.81;
const float velocidadInicial = 9.5;   // Ajustar según tu sistema
const int tiempoEspera = 1000;         // Tiempo de espera entre apuntado y disparo

// --- Función para calcular elevación balística ---
float calcularElevacionBalistica(float x, float y, float v) {
  float v2 = v * v;
  float discriminante = v2*v2 - g * (g*x*x + 2*y*v2);

  if (discriminante < 0) {
    Serial.println("Objetivo fuera de alcance balístico.");
    return -1;
  }

  float anguloRad = atan((v2 - sqrt(discriminante)) / (g * x));
  return anguloRad * 180.0 / PI;
}

// --- Función de apuntado automático ---
void apuntarAutomatico(float x, float y, float d) {
  float anguloDeriva = atan2(y, x) * 180.0 / PI;
  if (anguloDeriva < 0) anguloDeriva += 360;

  float distanciaPlano = sqrt(x*x + y*y);
  float anguloElevacion = calcularElevacionBalistica(distanciaPlano, d, velocidadInicial);

  if (anguloElevacion < 0) {
    Serial.println("No se puede apuntar: objetivo fuera de alcance.");
    return;
  }

  Serial.print("Apuntando a coordenada (");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(") a una distancia de ");
  Serial.println(d);

  moverStepper(anguloDeriva);
  moverAlza((int)anguloElevacion);
  activarMotoresDC(velMotor);
  delay(tiempoEspera);
  disparar();
}