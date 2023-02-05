#ifndef MATCH_H
#define MATCH_H

#include <stdint.h>
extern uint16_t BOTON1_MIN;
extern uint16_t BOTON2_MIN;
extern const uint16_t DCHumbral;

#define match(X,Y) switch(enumerate(X,Y))

enum botones{
	NingunBoton,
	Boton1,
	Boton2,
	AmbosBotones
};

enum botones enumerate(uint16_t boton1, uint16_t boton2); 

#endif // !MATCH_H
