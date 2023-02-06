#ifndef CONSTS_H
#define CONSTS_H

#include <stdint.h>

struct botones_t {
	uint16_t boton1;
	uint16_t boton2;
};

extern uint16_t BOTON1_MAX;
extern uint16_t BOTON1_MIN;
extern uint16_t BOTON2_MAX;
extern uint16_t BOTON2_MIN;

extern const uint16_t DCmin;
extern const uint16_t DCmaxBoton1; //Taladro = Cw,  Sierra = Rapido
extern const uint16_t DCmaxBoton2; //Taladro = CCw, Sierra = Lento
extern const uint16_t DCHumbral; //Taladro = 10, Sierra = 3

#endif // !CONSTS_H
