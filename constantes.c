#include "constantes.h"
 
uint16_t BOTON1_MAX = 656; //3,202v
uint16_t BOTON1_MIN = 542; //2,646v
uint16_t BOTON2_MAX = 656; //3,202v
uint16_t BOTON2_MIN = 542; //2,646v

const uint16_t DCidle = 375;

//Taladro = Cw,  Sierra = Rapido
const uint16_t DCminBoton1 = 
#ifdef SYSTEM_5
	375
#else
	375
#endif 
;

const uint16_t DCmaxBoton1 = 
#ifdef SYSTEM_5
	500
#else
	250
#endif 
;

//Taladro = CCw,  Sierra = Rapido
const uint16_t DCminBoton2 = 375 ;
const uint16_t DCmaxBoton2 = 
#ifdef SYSTEM_5
	480
#else
	500
#endif 
;

//Taladro = 10, Sierra = 3
const uint16_t DCHumbral = 
#ifdef SYSTEM_5
	2
#else
	2
#endif 
;

const uint16_t DCHisteresis = 20;
