#include "motoresDC.h"
#include <Arduino.h>

// Pines de control
int AIN1 = 6;   // PWM Motor A
int AIN2 = 5;   // Dirección Motor A

int velMotor = 220; // Ajustar velocidad (0-255 en Arduino UNO)

// --- Función para activar motores DC ---
void activarMotoresDC(int velocidad) {
  analogWrite(AIN1, velMotor);       // 0-255
  digitalWrite(AIN2, LOW);      // LOW = adelante, HIGH = atrás
  Serial.println("Motores DC activados.");
}

// --- Función para detener motores DC ---
void detenerMotoresDC() {
  analogWrite(AIN1, 0);
  Serial.println("Motores DC detenidos.");
}