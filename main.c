/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1503
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "calibracion.h"
#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include "constantes.h"
#include "nonvolatile.h"
#include "match.h"
#include "auxiliares.h"


int main(void) {

	SYSTEM_Initialize();
	read_from_nonvolatile();
	__delay_ms(T_PARA_SOLTAR_BOTONES);

	struct botones_t botones = leer_botones();

	calibrar(botones);

	int16_t a1, a2;
	int32_t b1, b2;
	linear_map_init(&a1, &b1, Boton_1);
	linear_map_init(&a2, &b2, Boton_2);
   
   __delay_ms(200);

	while (1) {

		botones = leer_botones();
      
		match(botones) {
			case NingunBoton:
			case AmbosBotones:
				parar_motor();
				break;

			case Boton1: 
				boton_loop(Boton_1, a1, b1);
				break;

			case Boton2:
				boton_loop(Boton_2, a2, b2);
				break;
		}

	  
	}
}
