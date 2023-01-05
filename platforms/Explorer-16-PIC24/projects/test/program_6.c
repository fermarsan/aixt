//Generated C file for:  Device = PIC24FJ128GA010  Board = Explorer 16

#include "settings.h"

#define t_on 500
#define t_off 100

// 
#include "time.h"
#include "machine.h"


int main(void) {
//AD1PCFG = 0xFFFF; // set all I/O digital

	pin(B0, out);
	pin_high(B0);
	sleep_ms(t_on);
	pin_low(B0);
	sleep_ms(t_off);
	
	return 0;
}