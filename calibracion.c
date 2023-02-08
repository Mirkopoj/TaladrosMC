#include "calibracion.h"
#include "constantes.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/pwm1.h"
#include "auxiliares.h"
#include "nonvolatile.h"
#include <stdint.h>

void guardar_valor_actual(uint16_t *boton1, uint16_t *boton2){
      int16_t C1p = 0;
      int16_t C2p = 0;

      for (int i=0;i<N_SAMPLES_AVERAGE;i++){
         C1p += ADC_GetConversion(hallC1);
         C2p += ADC_GetConversion(hallC2);
      }
      *boton1 = C1p/N_SAMPLES_AVERAGE;
      *boton2 = C2p/N_SAMPLES_AVERAGE;
      
      PWM1_LoadDutyValue(DCmaxBoton1);
      __delay_ms(T_GIRO_MOTOR);
      PWM1_LoadDutyValue(DCmaxBoton2);
      __delay_ms(T_GIRO_MOTOR);
      PWM1_LoadDutyValue(DCidle);
}

void calibrar(struct botones_t botones){
   if (botones.boton1 > V_MODO_CALIBRACION && botones.boton2 > V_MODO_CALIBRACION) {

		guardar_valor_actual(&BOTON1_MAX, &BOTON2_MAX);
      
      while (botones.boton1 > V_SALIR_CALIBRACION || botones.boton2 > V_SALIR_CALIBRACION) {
			botones = leer_botones();
      }
      __delay_ms(T_PARA_SOLTAR_BOTONES);
      
		guardar_valor_actual(&BOTON1_MIN, &BOTON2_MIN);
      
      save_to_nonvolatile();
      
   }
}
