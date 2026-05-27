#include "procesarComandos.h"
#include "servoAlza.h"
#include "stepperDeriva.h"
#include "motoresDC.h"
#include "servoDisparo.h"
#include "apuntadoAutomatico.h"
#include "volverAlOrigen.h"
#include <Arduino.h>

String buffer = ""; // acumulador de caracteres

// --- Función para procesar comandos por Serial ---
void procesarComando() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      buffer.trim();   // limpiar espacios
      if (buffer.length() > 0) {
        ejecutarComando(buffer); // procesar la línea completa
      }
      buffer = ""; // limpiar para el próximo comando
    } else {
      buffer += c; // acumular caracteres
    }
  }
}

// --- Función auxiliar para ejecutar el comando ---
void ejecutarComando(String comando) {
  int anguloAlza, anguloDeriva;
  float x, y, d;

  if (sscanf(comando.c_str(), "ALZA %d", &anguloAlza) == 1) {
    if (anguloAlza >= 0 && anguloAlza <= 180) {
      moverAlza(anguloAlza);
    } else {
      Serial.println("Ángulo inválido para ALZA. Debe estar entre 0 y 180.");
    }

  } else if (sscanf(comando.c_str(), "DERIVA %d", &anguloDeriva) == 1) {
    if (anguloDeriva >= 0 && anguloDeriva <= 360) {
      moverStepper(anguloDeriva);
    } else {
      Serial.println("Ángulo inválido para DERIVA. Debe estar entre 0 y 360.");
    }

  } else if (comando.equalsIgnoreCase("ACTIVAR")) {
    activarMotoresDC(velMotor);

  } else if (comando.equalsIgnoreCase("DETENER")) {
    detenerMotoresDC();

  } else if (comando.equalsIgnoreCase("DISPARAR")) {
    disparar();

  } else if (sscanf(comando.c_str(), "AUTO %f %f %f", &x, &y, &d) == 3) {
    if (x >= 0 && y >= 0 && d >= 0) {
      float anguloDeriva = atan2(y, x) * 180.0 / PI;
      if (anguloDeriva < 0) anguloDeriva += 360;
      float distanciaPlano = sqrt(x*x + y*y);
      float anguloElevacion = atan2(d, distanciaPlano) * 180.0 / PI;

      if (anguloDeriva >= 0 && anguloDeriva <= 360 && anguloElevacion >= 0 && anguloElevacion <= 180) {
        apuntarAutomatico(x, y, d);
      } else {
        Serial.println("Ángulos calculados fuera de rango. Verificar coordenadas.");
      }
    } else {
      Serial.println("Coordenadas inválidas para AUTO. No se aceptan valores negativos.");
    }

  } else if (comando.equalsIgnoreCase("ORIGEN")) {
    volverAlOrigen();

  } else {
    Serial.println("Comando inválido. Usa: ALZA <angulo>, DERIVA <angulo>, ACTIVAR, DETENER, DISPARAR, AUTO <x> <y> <d> u ORIGEN.");
  }
}