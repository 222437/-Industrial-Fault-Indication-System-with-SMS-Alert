#include <LPC21xX.H>


#include "lcd_defines.h"
#include "lcd.h"
#include "rtc_defines.h"

// Array to hold names of days of the week
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};


/*
Initialize the Real-Time Clock (RTC)
This function disables the RTC, sets the prescaler values,
and then enables the RTC.
*/
void RTC_Init(void)
{
  // Disable and reset the RTC
        CCR = RTC_RESET;

  // Set prescaler integer and fractional parts
        PREINT = PREINT_VAL;
  PREFRAC = PREFRAC_VAL;

  // Enable the RTC & select external clk source (for LPC2148)
        #ifndef _LPC2148_
                CCR = RTC_ENABLE;
        #else
                CCR = RTC_ENABLE | RTC_CLKSRC;
  #endif
}

/*
Get the current RTC time
hour Pointer to store the current hour
minute Pointer to store the current minute
second Pointer to store the current second
*/
void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
        *hour = HOUR;
        *minute = MIN;
        *second = SEC;
}
