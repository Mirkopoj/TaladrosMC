#ifndef CALIBRAR_H
#define CALIBRAR_H

#include "constantes.h"

#define T_GIRO_MOTOR				2000	//[ms]
#define T_PARA_SOLTAR_BOTONES 2000	//[ms]

#define V_MODO_CALIBRACION		575	//[V/1024]
#define V_SALIR_CALIBRACION	550	//[V/1024]
											
#define N_SAMPLES_AVERAGE		5
								  
void calibrar(struct botones_t botones);

#endif // !CALIBRAR_H


