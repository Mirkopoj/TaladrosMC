#ifndef MATCH_H
#define MATCH_H

#include "auxiliares.h"
#include "constantes.h"
#include <stdint.h>

#define match(X) switch(enumerate(X))

enum botones{
	NingunBoton,
	Boton1,
	Boton2,
	AmbosBotones
};

enum botones enumerate(struct botones_t bots); 

#endif // !MATCH_H
