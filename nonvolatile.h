#ifndef NONVOLATILE_H
#define NONVOLATILE_H
#include <stdint.h>

#define HIGH_ENDURANCE_ADDR 0x07F0 //Ver el address real 

enum {
	DATOS_VALIDOS,
	DATOS_DEFAULT=0x3FFF
};

/*
 * Guarde el valor de las globales en memoria no volatil
*/
void save_to_nonvolatile(void);

/*
 * Actualiza el valor de las globales en funcion del de 
 * la memoria no volatil
 *
 * Devuelve 0 si el contenido de la memoria no volatil
 * fue escrito alguna vez, impliicando que son vlaores
 * valido.
 *
 * Devuelve 1 en caso de que la memoria no volatil nunca
 * haya sido escrita. En este caso la funcion aborta la 
 * escritura de las globales preservando su valor actual.
 *
*/
int8_t read_from_nonvolatile(void);

#endif

