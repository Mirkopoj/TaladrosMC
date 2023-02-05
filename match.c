#include "match.h"
#include "constantes.h"

enum botones enumerate(struct botones_t bots) {
	enum botones apretados = NingunBoton;
	if (bots.boton1 > BOTON1_MIN+DCHumbral) apretados+=Boton1;
	if (bots.boton2 > BOTON2_MIN+DCHumbral) apretados+=Boton2;
	return apretados;
}
