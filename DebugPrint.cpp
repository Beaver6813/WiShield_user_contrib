//	DebugPrint

#include "Arduino.h"

extern "C" {
	void DebugPrint(char *msg);
	void DebugPrintF(const char *msg);
	void DebugPrintFO(const char *msg);
	void PrintTime(void);
    void debug_print_flash(const char *s);
}

void PrintTime(void){
  unsigned long second, minute, hour, day;
  unsigned long currtime;
  unsigned int seconds, minutes, hours, days;
  unsigned long fraction;
  char timeStamp[30];

  second = 1000L;
  minute = 60L * second;
  hour = 60L * minute;
  day = 24L * hour;

  currtime = millis();
  days = currtime / day;
  currtime -= (days * day);
  hours = currtime / hour;
  currtime -= (hours * hour);
  minutes = currtime / minute;
  currtime -= (minutes * minute);
  seconds = currtime / second;
  currtime -= (seconds * second);
  fraction = currtime;

  sprintf(timeStamp,", %d-%d:%d:%d.%03ld\n",days,hours,minutes,seconds,(long)fraction);
  Serial.print(timeStamp);
}

void DebugPrint(char *msg){
	Serial.print (msg);
	PrintTime();
}

void debug_print_flash(const char *s)
{
	char c;
	while (c = pgm_read_byte(s++)){
	  Serial.print(c);
	}
} 	

void DebugPrintF (const char *s)
{
	debug_print_flash(s);
	PrintTime();
}

void DebugPrintFO (const char *s)
{
	debug_print_flash(s);
}
