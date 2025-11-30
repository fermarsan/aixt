
#include <p24FJ128GA010.h>

#define FCY _const_main__cpu_freq

#include <libpic30.h> 

// CONFIG2
#pragma config POSCMOD = XT		//Primary Oscillator Select->XT Oscillator mode selected
#pragma config OSCIOFNC = ON    //Primary Oscillator Output Function->OSC2/CLKO/RC15 functions as port I/O (RC15)
#pragma config FCKSM = CSDCMD   //Clock Switching and Monitor->Clock switching and Fail-Safe Clock Monitor are disabled
#pragma config FNOSC = PRIPLL   //Oscillator Select->Primary Oscillator with PLL module (HSPLL, ECPLL)
#pragma config IESO = ON    	//Internal External Switch Over Mode->IESO mode (Two-Speed Start-up) enabled

// CONFIG1
#pragma config WDTPS = PS32768	//Watchdog Timer Postscaler->1:32768
#pragma config FWPSA = PR128    //WDT Prescaler->Prescaler ratio of 1:128
#pragma config WINDIS = ON    	//Watchdog Timer Window->Standard Watchdog Timer enabled,(Windowed-mode is disabled)
#pragma config FWDTEN = OFF    	//Watchdog Timer Enable->Watchdog Timer is disabled
#pragma config ICS = PGx2    	//Comm Channel Select->Emulator/debugger uses EMUC2/EMUD2
#pragma config BKBUG = OFF    	//Background Debug->Device resets into Operational mode
#pragma config GWRP = OFF    	//General Code Segment Write Protect->Writes to program memory are allowed
#pragma config GCP = OFF    	//General Code Segment Code Protect->Code protection is disabled
#pragma config JTAGEN = OFF    	//JTAG Port Enable->JTAG port is disabled
