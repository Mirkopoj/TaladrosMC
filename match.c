#include "match.h"

enum botones enumerate(uint16_t boton1, uint16_t boton2) {
	enum botones apretados = NingunBoton;
	if (boton1 > BOTON1MIN+HUMBRAL) apretados+=SentidoHorario;
	if (boton2 > BOTON2MIN+HUMBRAL) apretados+=SentidoAntiHorario;
	return apretados;
}
