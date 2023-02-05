#ifndef CONSTS_H
#define CONSTS_H

#include <stdint.h>

extern uint16_t BOTON1_MAX;
extern uint16_t BOTON1_MIN;
extern uint16_t BOTON2_MAX;
extern uint16_t BOTON2_MIN;

extern const int16_t DCmin;
extern const int16_t DCmaxBoton1; //Taladro = Cw,  Sierra = Rapido
extern const int16_t DCmaxBoton2; //Taladro = CCw, Sierra = Lento
extern const int16_t DCHumbral; //Taladro = 10, Sierra = 3

#endif // !CONSTS_H
