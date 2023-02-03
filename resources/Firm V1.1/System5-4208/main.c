#include <main.h>

int16 dc;
int16 C1, C2, C1i, C2i;
int16 C1s = 0;
int16 C2s = 0;

void main()
{
   setup_oscillator(OSC_16MHZ | OSC_INTRC);
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(sAN5 | sAN6 | VSS_VDD);      //AN5 es C1; AN6 es C2
      
   setup_timer_2(T2_DIV_BY_64,125,1);
   setup_pwm1(PWM_ENABLED | PWM_ACTIVE_HIGH | PWM_OUTPUT);
   
   set_pwm1_duty(375);
   delay_ms(200);
   
   for(int i=0;i<5;i++)
   {
      set_adc_channel(5);
      delay_ms(1);
      C1i = read_adc();
      C1s = C1s + C1i;
      delay_ms(1);
      set_adc_channel(6);
      delay_ms(1);
      C2i = read_adc();
      C2s = C2s + C2i;
      delay_ms(1);
   }
   C1i = (C1s/5);
   C2i = (C2s/5);
   C1s = 0;
   C2s = 0;

   delay_ms(200);

   while(TRUE)
   {
      set_adc_channel(5);
      delay_us(25);
      C1 = read_adc();
      set_adc_channel(6);
      delay_us(25);
      C2 = read_adc();
      
      if(C1 > (C1i + 3))
      {
         set_adc_channel(5);
         delay_us(25);
         while(C1 > (C1i + 3))
         {
            C1 = read_adc();
            dc = C1 - 145;
            delay_us(25);
            if (dc<375) {dc=375;}
            if (dc>500) {dc=500;}
            set_pwm1_duty(dc);
         }
      }
      else if(C2 > (C2i + 3))
      {
         set_adc_channel(6);
         delay_us(25);
         while(C2 > (C2i + 3))
         {
            C2 = read_adc();
            dc = C2 - 145;
            delay_us(25);
            if (dc<375) {dc=375;}
            if (dc>417) {dc=417;}
            set_pwm1_duty(dc);
         }
      }
      else
      {
         dc = 375;
      }
      set_pwm1_duty(dc);
   }
}
