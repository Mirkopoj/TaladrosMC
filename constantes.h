#ifndef CONSTS_H
#define CONSTS_H

#include <stdint.h>

struct botones_t {
	int16_t boton1;
	int16_t boton2;
};

extern uint16_t BOTON1_MAX;
extern uint16_t BOTON1_MIN;
extern uint16_t BOTON2_MAX;
extern uint16_t BOTON2_MIN;

extern const int16_t DCidle;
//Taladro = Cw,  Sierra = Rapido
extern const int16_t DCmaxBoton1; 
extern const int16_t DCminBoton1; 
//Taladro = CCw, Sierra = Lento
extern const int16_t DCmaxBoton2; 
extern const int16_t DCminBoton2; 
//Taladro = 10, Sierra = 3
extern const int16_t DCHumbral; 
extern const int16_t DCHisteresis; 

#endif // !CONSTS_H
