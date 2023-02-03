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
#include "match.h"

uint16_t BOTON1MIN;
uint16_t BOTON2MIN;
uint16_t HUMBRAL;


const uint16_t DCmin = 375;
const uint16_t DCmaxCW = 250;
const uint16_t DCmaxCCW = 500;

int main(void) {

	SYSTEM_Initialize();
	__delay_ms(200);

	uint16_t dc;
	uint16_t C1, C2, C1i, C2i;
	uint16_t C1s = 0;
	uint16_t C2s = 0;

   for(int i=0;i<5;i++)
   {
      C1i = ADC_GetConversion(hallC1);
      C1s = C1s + C1i;
      __delay_ms(1);
      C2i = ADC_GetConversion(hallC2);
      C2s = C2s + C2i;
      __delay_ms(1);
   }
   C1i = (C1s/5);
   C2i = (C2s/5);
   C1s = 0;
   C2s = 0;
   
   __delay_ms(200);

	while (1) {
      C1 = ADC_GetConversion(hallC1);
      C2 = ADC_GetConversion(hallC2);
      
      if(C1 > (C1i + 3)) {
         while(C1 > (C1i + 10)) {
            C1 = ADC_GetConversion(hallC1);
            dc = 895 - C1;
            __delay_us(25);
            if (dc<DCmaxCW){dc=DCmaxCW;}
            if (dc>DCmin){dc=DCmin;}
            PWM1_LoadDutyValue(dc);
         }
      }
      else if(C2 > (C2i + 10)) {

         while(C2 > (C2i + 3)) {
            C2 = ADC_GetConversion(hallC2);
            dc = C2 - 145;
            __delay_us(25);
            if (dc<DCmin) {dc=DCmin;}
            if (dc>DCmaxCCW) {dc=DCmaxCCW;}
            PWM1_LoadDutyValue(dc);
         }
      }
      else {
         dc = 375;
      }
      PWM1_LoadDutyValue(dc);
	  
	}
}
