#ifndef MATCH_H
#define MATCH_H

#include <stdint.h>
extern uint16_t BOTON1MIN;
extern uint16_t BOTON2MIN;
extern uint16_t HUMBRAL;

#define match(X,Y) switch(enumerate(X,Y))

enum botones{
	NingunBoton,
	SentidoHorario,
	SentidoAntiHorario,
	AmbosBotones
};

enum botones enumerate(uint16_t boton1, uint16_t boton2); 

#endif // !MATCH_H
