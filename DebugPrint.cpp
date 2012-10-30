//	DebugPrint

#include "Arduino.h"

extern "C" {
	void DebugPrint(char *msg);
	void DebugPrintF(const char *msg);
	void DebugPrintFO(const char *msg);
}

void DebugPrint(char *msg){
	Serial.print (msg);
}

void debug_print_flash(const char *s)
{
	char c;
	while (c = pgm_read_byte(s++)){
	  Serial.print(c);
	}
    Serial.print("\n");
} 	

void DebugPrintF (const char *s)
{
	debug_print_flash(s);
}

void DebugPrintFO (const char *s)
{
	debug_print_flash(s);
}
