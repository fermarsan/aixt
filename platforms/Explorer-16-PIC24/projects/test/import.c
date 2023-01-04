//Generated C file for:  Device = PIC24FJ128GA010  Board = Explorer 16

#include "settings.h"

//User defined headers files
#include "machine.h"
#include "time.h"

int main(void) {

	//AD1PCFG = 0xFFFF; // set all I/O digital
	time(1000);
	pin(B0, out);
	
	return 0;
}