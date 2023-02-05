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

void linear_map_init(int16_t *a, int16_t *b, enum boton bot){
	int32_t DCmin_S = DCmin<<5;

	switch (bot) {
		case Boton_1: 
			*a = (((int32_t)DCmaxBoton1<<5) - DCmin_S)/(BOTON1_MAX - BOTON1_MIN);
			*b = DCmin_S - BOTON1_MIN * *a;
			break;
		case Boton_2:
			*a = (((int32_t)DCmaxBoton2<<5) - DCmin_S)/(BOTON2_MAX - BOTON2_MIN);
			*b = DCmin_S - BOTON2_MIN * *a;
			break;
	}
}

int16_t inline linear_map(int16_t a, int16_t b, int16_t x){
	return ((int32_t)x * a + b)>>5;
}
