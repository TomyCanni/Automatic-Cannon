#ifndef MOTORESDC_H
#define MOTORESDC_H

// Pines compartidos
extern int AIN1;   // PWM Motor A
extern int AIN2;   // Dirección Motor A

extern int velMotor; // velocidad por defecto (0-255)

// Funciones
void activarMotoresDC(int velocidad);
void detenerMotoresDC();

#endif
