#include "auxiliares.h"
#include "constantes.h"

void clamp(int16_t *var, enum boton bot){
	switch (bot) {
		case Boton_1:
#ifdef SYSTEM_5
			if (*var<DCmaxBoton1){*var=DCmaxBoton1;}
			if (*var>DCmin){*var=DCmin;}
#else
			if (*var>DCmaxBoton1){*var=DCmaxBoton1;}
			if (*var<DCmin){*var=DCmin;}
#endif 
			break;

		case Boton_2:
			if (*var<DCmin) {*var=DCmin;}
			if (*var>DCmaxBoton2) {*var=DCmaxBoton2;}
			break;

	}
}

void linear_map_init(int16_t *a, int16_t *b);
int16_t linear_map(int16_t *a, int16_t *b, int16_t x);
