/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1503
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set hallC1 aliases
#define hallC1_TRIS                 TRISCbits.TRISC1
#define hallC1_LAT                  LATCbits.LATC1
#define hallC1_PORT                 PORTCbits.RC1
#define hallC1_ANS                  ANSELCbits.ANSC1
#define hallC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define hallC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define hallC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define hallC1_GetValue()           PORTCbits.RC1
#define hallC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define hallC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define hallC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define hallC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set hallC2 aliases
#define hallC2_TRIS                 TRISCbits.TRISC2
#define hallC2_LAT                  LATCbits.LATC2
#define hallC2_PORT                 PORTCbits.RC2
#define hallC2_ANS                  ANSELCbits.ANSC2
#define hallC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define hallC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define hallC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define hallC2_GetValue()           PORTCbits.RC2
#define hallC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define hallC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define hallC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define hallC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/