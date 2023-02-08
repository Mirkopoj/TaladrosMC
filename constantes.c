#include "constantes.h"
 
uint16_t BOTON1_MAX = 656; //3,202v
uint16_t BOTON1_MIN = 542; //2,646v
uint16_t BOTON2_MAX = 656; //3,202v
uint16_t BOTON2_MIN = 542; //2,646v

const int16_t DCidle = 374;

//Taladro = Cw,  Sierra = Rapido
const int16_t DCminBoton1 = 
#ifdef SYSTEM_5
	398
#else
	342
#endif 
;
const int16_t DCmaxBoton1 = 
#ifdef SYSTEM_5
	500
#else
	250
#endif 
;

//Taladro = CCw,  Sierra = Rapido
const int16_t DCminBoton2 = 398 ;
const int16_t DCmaxBoton2 = 
#ifdef SYSTEM_5
	417
#else
	500
#endif 
;

//Taladro = 10, Sierra = 3
const int16_t DCHumbral = 
#ifdef SYSTEM_5
	3
#else
	10
#endif 
;

const int16_t DCHisteresis = 10;
