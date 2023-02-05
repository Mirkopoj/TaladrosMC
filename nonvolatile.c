#include "nonvolatile.h"
#include "mcc_generated_files/memory.h"
#include "constantes.h"

void save_to_nonvolatile(){
	uint16_t bloque[16] = {[0 ... 15] = 0x3FFF};
	
	bloque[0] = DATOS_VALIDOS;
	bloque[1] = BOTON1_MAX;
	bloque[2] = BOTON1_MIN;
	bloque[3] = BOTON2_MAX;
	bloque[4] = BOTON2_MIN;

	FLASH_WriteBlock(HIGH_ENDURANCE_ADDR, bloque);
}

int8_t read_from_nonvolatile(){
	if (FLASH_ReadWord(HIGH_ENDURANCE_ADDR)&DATOS_DEFAULT==DATOS_DEFAULT) {
		return 1;
	}

	BOTON1_MAX = FLASH_ReadWord(HIGH_ENDURANCE_ADDR+1);
	BOTON1_MIN = FLASH_ReadWord(HIGH_ENDURANCE_ADDR+2);
	BOTON2_MAX = FLASH_ReadWord(HIGH_ENDURANCE_ADDR+3);
	BOTON2_MIN = FLASH_ReadWord(HIGH_ENDURANCE_ADDR+4);

	return 0;
}
