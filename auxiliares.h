#ifndef AUX_H
#define AUX_H

#include <stdint.h>

enum boton {
	Boton_1,
	Boton_2
};

void clamp(int16_t *var, enum boton bot);

void linear_map_init(int16_t *a, int32_t *b, enum boton bot);
int16_t inline linear_map(int16_t a, int32_t b, int16_t x);

void boton_loop(enum boton bot, int16_t a, int32_t b);

struct botones_t leer_botones();

void inline parar_motor();

#endif // !AUX_H
