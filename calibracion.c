#include "calibracion.h"
#include "constantes.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/pwm1.h"
#include "auxiliares.h"
#include "nonvolatile.h"
#include <stdint.h>

void guardar_valor_actual(uint16_t *boton, adc_channel_t hall){
      uint16_t Cp = 0;

      for (int i=0;i<N_SAMPLES_AVERAGE;i++){
         Cp += ADC_GetConversion(hall);
      }

      *boton = Cp/N_SAMPLES_AVERAGE;
}

void soltar_boton(){
      PWM1_LoadDutyValue(DCmaxBoton1);
      __delay_ms(T_GIRO_MOTOR);
      PWM1_LoadDutyValue(DCmaxBoton2);
      __delay_ms(T_GIRO_MOTOR);
      PWM1_LoadDutyValue(DCidle);
}

void calibrar(struct botones_t botones){
   if (botones.boton1 > V_MODO_CALIBRACION || botones.boton2 > V_MODO_CALIBRACION) {

		if (botones.boton1 > V_MODO_CALIBRACION) guardar_valor_actual(&BOTON1_MAX, hallC1);
		if (botones.boton2 > V_MODO_CALIBRACION) guardar_valor_actual(&BOTON2_MAX, hallC2);
		soltar_boton();
      
      while (botones.boton1 > V_SALIR_CALIBRACION || botones.boton2 > V_SALIR_CALIBRACION) {
			botones = leer_botones();
      }
      __delay_ms(T_PARA_SOLTAR_BOTONES);
      
		guardar_valor_actual(&BOTON1_MAX, hallC1);
		guardar_valor_actual(&BOTON2_MAX, hallC2);
		soltar_boton();
      
      save_to_nonvolatile();
      
   }
}
