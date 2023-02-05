#ifndef AUX_H
#define AUX_H

#include <stdint.h>

enum boton{
	Boton_1,
	Boton_2,
};

void clamp(int16_t *var, enum boton bot);

void linear_map_init(int16_t *a, int16_t *b, enum boton bot);
int16_t linear_map(int16_t *a, int16_t *b, int16_t x);

#endif // !AUX_H
