#include "auxiliares.h"
#include "constantes.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/pwm1.h"
#include <stdint.h>

void clamp(int16_t *var, enum boton bot){
	switch (bot) {
		case Boton_1:
#ifdef SYSTEM_5
			if (*var>DCmaxBoton1){*var=DCmaxBoton1;}
			if (*var<DCmin){*var=DCmin;}
#else
			if (*var<DCmaxBoton1){*var=DCmaxBoton1;}
			if (*var>DCmin){*var=DCmin;}
#endif 
			break;

		case Boton_2:
			if (*var<DCmin) {*var=DCmin;}
			if (*var>DCmaxBoton2) {*var=DCmaxBoton2;}
			break;

	}
}

void linear_map_init(int16_t *a, int32_t *b, enum boton bot){
	int32_t DCmin_S = DCmin<<SHIFT_LINEAR_MAP;

	switch (bot) {
		case Boton_1: 
			*a = (((int32_t)DCmaxBoton1<<SHIFT_LINEAR_MAP) - DCmin_S)/(BOTON1_MAX - BOTON1_MIN);
			*b = DCmin_S - BOTON1_MIN * (int32_t)*a;
			break;
		case Boton_2:
			*a = (((int32_t)DCmaxBoton2<<SHIFT_LINEAR_MAP) - DCmin_S)/(BOTON2_MAX - BOTON2_MIN);
			*b = DCmin_S - BOTON2_MIN * (int32_t)*a;
			break;
	}
}

int16_t inline linear_map(int16_t a, int32_t b, int16_t x){
	return ((int32_t)x * a + b)>>SHIFT_LINEAR_MAP;
}

void boton_loop(enum boton bot, int16_t a, int32_t b){
	int16_t presion_minima = DCHumbral;
	adc_channel_t canal_adc;
	int16_t presion_en_el_boton;
	int16_t dc;

	switch (bot) {
		case Boton_1: 
			presion_minima += BOTON1_MIN;
			canal_adc = hallC1;
			break;
		case Boton_2:
			presion_minima += BOTON2_MIN;
			canal_adc = hallC2;
			break;
	}

	do {
		presion_en_el_boton = ADC_GetConversion(canal_adc);
		dc = linear_map(a, b, presion_en_el_boton);
		clamp(&dc, bot);
		PWM1_LoadDutyValue(dc);
	} while (presion_en_el_boton > presion_minima);
}

struct botones_t leer_botones(){
	struct botones_t ret = {
		.boton1 = ADC_GetConversion(hallC1),
		.boton2 = ADC_GetConversion(hallC2)
	};
	return ret;
}

void inline parar_motor(){
	PWM1_LoadDutyValue(DCmin);
}
