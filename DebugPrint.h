//	DebugPrint.h

//#include "Arduino.h"

extern "C" {
	void DebugPrint(char *msg);
	void DebugPrintF(const char *msg);
	void DebugPrintFO(const char *msg);
}

