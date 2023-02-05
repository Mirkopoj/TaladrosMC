#include "match.h"

enum botones enumerate(uint16_t boton1, uint16_t boton2) {
	enum botones apretados = NingunBoton;
	if (boton1 > BOTON1_MIN+DCHumbral) apretados+=Boton1;
	if (boton2 > BOTON2_MIN+DCHumbral) apretados+=Boton2;
	return apretados;
}
