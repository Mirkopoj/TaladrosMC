# 1 "nonvolatile.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/mplabx/v6.05/packs/Microchip/PIC12-16F1xxx_DFP/1.3.90/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "nonvolatile.c" 2
# 1 "./nonvolatile.h" 1


# 1 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 1 3



# 1 "/opt/microchip/xc8/v2.40/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 2 3
# 22 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 1 3
# 127 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 3
typedef long intptr_t;
# 158 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.40/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 145 "/opt/microchip/xc8/v2.40/pic/include/c99/stdint.h" 2 3
# 4 "./nonvolatile.h" 2



enum {
 DATOS_VALIDOS,
 DATOS_DEFAULT=0xFF
};




void save_to_nonvolatile();
# 30 "./nonvolatile.h"
int8_t read_from_nonvolatile();
# 2 "nonvolatile.c" 2
# 1 "./mcc_generated_files/memory.h" 1
# 54 "./mcc_generated_files/memory.h"
# 1 "/opt/microchip/xc8/v2.40/pic/include/c99/stdbool.h" 1 3
# 54 "./mcc_generated_files/memory.h" 2
# 99 "./mcc_generated_files/memory.h"
uint16_t FLASH_ReadWord(uint16_t flashAddr);
# 128 "./mcc_generated_files/memory.h"
void FLASH_WriteWord(uint16_t flashAddr, uint16_t *ramBuf, uint16_t word);
# 164 "./mcc_generated_files/memory.h"
int8_t FLASH_WriteBlock(uint16_t writeAddr, uint16_t *flashWordArray);
# 189 "./mcc_generated_files/memory.h"
void FLASH_EraseBlock(uint16_t startAddr);
# 3 "nonvolatile.c" 2
# 1 "./constantes.h" 1





extern uint16_t BOTON1_MAX;
extern uint16_t BOTON1_MIN;
extern uint16_t BOTON2_MAX;
extern uint16_t BOTON2_MIN;
# 4 "nonvolatile.c" 2

void save_to_nonvolatile(){
 uint16_t bloque[16] = {[0 ... 15] = 0xFF};

 bloque[0] = DATOS_VALIDOS;
 bloque[1] = BOTON1_MAX;
 bloque[2] = BOTON1_MIN;
 bloque[3] = BOTON2_MAX;
 bloque[4] = BOTON2_MIN;

 FLASH_WriteBlock(0x0780, bloque);
}

int8_t read_from_nonvolatile(){
 if (FLASH_ReadWord(0x0780)==DATOS_DEFAULT) {
  return 1;
 }

 BOTON1_MAX = FLASH_ReadWord(0x0780 +1);
 BOTON1_MIN = FLASH_ReadWord(0x0780 +2);
 BOTON2_MAX = FLASH_ReadWord(0x0780 +3);
 BOTON2_MIN = FLASH_ReadWord(0x0780 +4);

 return 0;
}
