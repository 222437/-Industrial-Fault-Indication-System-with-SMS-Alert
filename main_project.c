#include<lpc21xx.h>
//lcd header file inclusion
#include "lcd_func_declarations_project.h"
#include "lcd_defines_project.h"

//kpm header file inclusion
#include "kpm_declarations_project.h"
#include "kpm_defines_project.h"

//dht11 functions declarations
#include"dht11_declaratioons_project.h"
 
//delay function declarations
#include"delay_header.h"

//uart declarations
#include"uart_declarations_project.h"

//i2c declarations
#include"i2c_declarations.h"

//i2c eeprom declarations
//#include"i2c_eeprom_declarations.h"
//eeprom slave address
//#define I2C_EEPROM_SA 0x50 //7Bit Slave Addr

//led pin numbers
/*#define rLED 1<<16 //P1.16
#define gLED 1<<17 //P1.17*/
int t;
int h;
unsigned char humidity_integer,humidity_decimal,temp_integer,temp_decimal,check_sum;
int main()
{
	InitLCD();
	//Init_UART0();
	//init_i2c();
	//IODIR1=gLED|rLED;
	while(1)
	{
	   StrLCD("vector");
	   delay_s(10);		
	   CmdLCD(CLEAR_LCD);
       dht11_request();
   	   StrLCD("vector");
   	   delay_s(10);		
	   CmdLCD(CLEAR_LCD);
	   dht11_response();
   	   StrLCD("vector");
   	   delay_s(10);		
   	   CmdLCD(CLEAR_LCD);
	   humidity_integer=dht11_data()+1;
	   humidity_decimal=dht11_data();
	   temp_integer=dht11_data()+1;
	   temp_decimal=dht11_data();
	   check_sum=dht11_data();
	   CharLCD('f');
	   delay_s(1);
	   if((humidity_integer+humidity_decimal+temp_integer+temp_decimal)!=(check_sum+2))
	   {
	       StrLCD("checksum error");
		   delay_s(2);
	   }
	   else
	   {		
	       CmdLCD(CLEAR_LCD);		 
	       CmdLCD(GOTO_LINE1_POS0);
           StrLCD("H :");
		   S32LCD(humidity_integer);
		   CharLCD('.');
		   S32LCD(humidity_decimal);
		   CharLCD(37);
		   StrLCD("RH");
		   CmdLCD(GOTO_LINE2_POS0);
		   StrLCD("T :");
		   S32LCD(temp_integer);
		   CharLCD('.');
		   S32LCD(temp_decimal);
		   CharLCD(223);
		 //  delay_ms(2000);
	//	   i2c_eeprom_write(I2C_EEPROM_SA,0x0000,humidity_integer);
	 //      h=i2c_eeprom_read(I2C_EEPROM_SA,0x0000);
		   //delay_ms(2000);
	//	   i2c_eeprom_write(I2C_EEPROM_SA,0x0005,temp_integer);
	  //     t=i2c_eeprom_read(I2C_EEPROM_SA,0x0005);
		   //delay_ms(2000);
		   //U0_TXU32(1);
		   //U0_TXU32(2);
		   /*CmdLCD(CLEAR_LCD);
		   S32LCD(h);
		   CmdLCD(GOTO_LINE2_POS0);
		   S32LCD(t);
		   delay_s(5);*/
		   //goto label;
	   }			 
	}  
}


main project.c
