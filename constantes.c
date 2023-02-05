#include "constantes.h"
 
uint16_t BOTON1_MAX = 656; //3,202v
uint16_t BOTON1_MIN = 542; //2,646v
uint16_t BOTON2_MAX = 656; //3,202v
uint16_t BOTON2_MIN = 542; //2,646v

const int16_t DCmin = 374;
const int16_t DCmaxBoton1 = //Taladro = Cw,  Sierra = Rapido
#ifdef SYSTEM_5
	250
#else
	500
#endif 
;

const int16_t DCmaxBoton2 = //Taladro = CCw, Sierra = Lento
#ifdef SYSTEM_5
	500
#else
	417
#endif 
;
const int16_t DCHumbral = //Taladro = 10, Sierra = 3
#ifdef SYSTEM_5
	10
#else
	3
#endif 
;
