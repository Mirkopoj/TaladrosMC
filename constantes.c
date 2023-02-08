#include "constantes.h"
 
uint16_t BOTON1_MAX = 656; //3,202v
uint16_t BOTON1_MIN = 542; //2,646v
uint16_t BOTON2_MAX = 656; //3,202v
uint16_t BOTON2_MIN = 542; //2,646v

const uint16_t DCmin = 374;
const uint16_t DCmaxBoton1 = //Taladro = Cw,  Sierra = Rapido
#ifdef SYSTEM_5
	500
#else
	250
#endif 
;

const uint16_t DCmaxBoton2 = //Taladro = CCw, Sierra = Lento
#ifdef SYSTEM_5
	417
#else
	500
#endif 
;
const uint16_t DCHumbral = //Taladro = 10, Sierra = 3
#ifdef SYSTEM_5
	3
#else
	10
#endif 
;
