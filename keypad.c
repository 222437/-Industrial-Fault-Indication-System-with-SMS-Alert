#include "types.h"
#include<lpc21xx.h>
#include "defines.h"
#include "kpm_defines.h"
#include "lcd.h"
#include "lcd_defines.h"
u32 KPMLUT[4][4]={
{1,2,3,4},
{5,6,7,8},
{9,10,11,12},
{13,14,15,16}
};
void InitKPM(void){
WRITTENIBBLE(IODIR1, ROW0,15);
}
u32 COLSCAN(void){
u32 t;
t= READNIBBLE(IOPIN1, COL0);
return (t<15) ? 0:1;
}

u32 ROWCHECK(void){
u32 r;
for(r=0;r<=3;r++){
WRITTENIBBLE(IOPIN1, ROW0, ~(1<<r));
if(COLSCAN()==0){
break;
}
}
IOCLR1=15<<ROW0;
return r;

}
u32 COLCHECK(void){
u32 c;
for(c=0;c<=3;c++){
if(READBIT(IOPIN1,COL0+c)==0)
break;
}
return c;
}
u32     KEYSCAN(void){
u32 r,c, keyv;
while(COLSCAN());
r=ROWCHECK();
c=COLCHECK();
keyv=KPMLUT[r][c];
return keyv;
}
u32 READNUM(void){
u32 sum=0, num=0;
while(1){
num=KEYSCAN();
delay_ms(1000);
while(COLSCAN()==0);
CMDLCD(GOTO_LINE2_POS0+8);
//CharLCD(num);
U32LCD(num);
if(num>=0 && num<=9){
sum=(sum*10)+(num);
CMDLCD(GOTO_LINE2_POS0);
                  while(COLSCAN()==0);
}
else{
//sum=(sum*10)+(num);
CMDLCD(GOTO_LINE2_POS0);
//StrLCD("                ");
//while(COLSCAN()==0);


break;
}
}
return sum;
}
