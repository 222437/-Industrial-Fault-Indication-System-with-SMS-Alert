#include<LPC21xx.h>
#include"types.h"
//#include"pin_connect_block.h"
#include"delay.h"
#include"adc_defines.h"
void Init_adc(void)
{
          int CLKDIR_BITS,CLKDIR,PDN_BIT,ADIR;
        //cfg p0.27 as ANO pin
        //cfgportpin(0,27,AND_INPUT_PIN);
        PINSEL1=0x15400000;
        //cfg ADCR sf
        ADIR=(1<<PDN_BIT)|(CLKDIR<<CLKDIR_BITS);
 }
 void Read_ADC(u8 chND,f32*eAR,u32*dual)
 {
     int *dval,*CAR,ADCLR,DONE_BIT,chNo,ADC_START_BIT,ADCRL,RESUIT_BITS;
        //clear any prev channel selection
        ADCR&=0xFFFFFF00;
        //select analog channel,start conv
        ADCRL=(1<<ADC_START_BIT)|(1<<chNo);
        //conversion time
    delay_us(3);
        //int RESULT_BITS;
        //unit until conv completion 8 status
        while(((ADDR>>DONE_BIT)&1)==0);
        //stop adc conversion
        ADCLR&=~(1<<ADC_START_BIT);
        //reading the 10 bit digital data.
        *dval=((ADDR>>RESUIT_BITS)&1023);
        //representing in float/real number
        *CAR=(*dual* 13.31/1024);
}
