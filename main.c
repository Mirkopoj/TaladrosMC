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

#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include "constantes.h"
#include "nonvolatile.h"
#include "match.h"
#include "auxiliares.h"


int main(void) {

	SYSTEM_Initialize();
      read_from_nonvolatile();
	__delay_ms(200);

	int16_t C1, C2;

   C1 = ADC_GetConversion(hallC1);
   C2 = ADC_GetConversion(hallC2);
   
   if (C1 > 575 && C2 > 575) {
      int16_t C1p = 0;
      int16_t C2p = 0;
      for (int i=0;i<5;i++){
         C1p += ADC_GetConversion(hallC1);
         C2p += ADC_GetConversion(hallC2);
      }
      BOTON1_MAX = C1p/5;
      BOTON2_MAX = C2p/5;
      
      PWM1_LoadDutyValue(DCmaxBoton1);
      __delay_ms(2000);
      PWM1_LoadDutyValue(DCmaxBoton2);
      __delay_ms(2000);
      PWM1_LoadDutyValue(DCmin);
      
      C1p = 0;
      C2p = 0;
       
      while (C1 > 550 || C2 > 550) {
         C1 = ADC_GetConversion(hallC1);
         C2 = ADC_GetConversion(hallC2);
      }
      __delay_ms(2000);
      
      for (int i=0;i<5;i++){
         C1p += ADC_GetConversion(hallC1);
         C2p += ADC_GetConversion(hallC2);
      }
      BOTON1_MIN = C1p/5;
      BOTON2_MIN = C2p/5;
      
      PWM1_LoadDutyValue(DCmaxBoton1);
      __delay_ms(2000);
      PWM1_LoadDutyValue(DCmaxBoton2);
      __delay_ms(2000);
      PWM1_LoadDutyValue(DCmin);
      
      save_to_nonvolatile();
      
   }
   
	int16_t dc;

	int16_t a1;
	int16_t b1;
	int16_t a2;
	int16_t b2;

	linear_map_init(&a1, &b1, Boton_1);
	linear_map_init(&a2, &b2, Boton_2);
   
   __delay_ms(200);

	while (1) {

      C1 = ADC_GetConversion(hallC1);
      C2 = ADC_GetConversion(hallC2);
      
		match(C1, C2) {
			case NingunBoton:
			case AmbosBotones:
				dc = 375;
				break;

			case Boton1: 
				while(C1 > (BOTON1_MIN + DCHumbral)) {
					C1 = ADC_GetConversion(hallC1);
					dc = ((int32_t)C1 * a1 + b1)>>5;
					clamp(&dc, Boton_1);
					PWM1_LoadDutyValue(dc);
				}
				break;

			case Boton2:
				while(C2 > (BOTON2_MIN + DCHumbral)) {
					C2 = ADC_GetConversion(hallC2);
					dc = ((int32_t)C2 * a2 + b2)>>5;
					clamp(&dc, Boton_2);
					PWM1_LoadDutyValue(dc);
				}
				break;
		}

      PWM1_LoadDutyValue(dc);
	  
	}
}