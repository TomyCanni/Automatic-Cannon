#ifndef APUNTADOAUTOMATICO_H
#define APUNTADOAUTOMATICO_H

extern const float g;
extern const float velocidadInicial;

float calcularElevacionBalistica(float x, float y, float v);
void apuntarAutomatico(float x, float y, float d);

#endif