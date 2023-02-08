#include "match.h"
#include "constantes.h"
#include <stdint.h>

enum botones enumerate(struct botones_t bots) {
	enum botones apretados = NingunBoton;
	uint16_t Humbral = DCHumbral + DCHisteresis;
	if (bots.boton1 > BOTON1_MIN+Humbral) apretados+=Boton1;
	if (bots.boton2 > BOTON2_MIN+Humbral) apretados+=Boton2;
	return apretados;
}
