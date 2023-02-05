#ifndef MATCH_H
#define MATCH_H

#include "constantes.h"
#include <stdint.h>

#define match(X,Y) switch(enumerate(X,Y))

enum botones{
	NingunBoton,
	Boton1,
	Boton2,
	AmbosBotones
};

enum botones enumerate(uint16_t boton1, uint16_t boton2); 

#endif // !MATCH_H
