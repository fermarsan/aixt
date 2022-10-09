#include "../settings.h"
#include "../ports.h"

#define IN      1
#define OUT     0

unsigned int *addr; //PORT address pointer
int port_bit;       //specific bit of PORT

//The PORT address are computed as  "(int)(PIN / n)*s + init" 
//and the individual bit is computed as  "PIN % n"
//where "n" is the number of bit of each port (16 for this case) 
//"s" is the address separation between each PORT (6 for this case)
//and "init" is the PORTA address
//the same applies to TRIS and LAT registers 

#define Pin(PIN,TYPE)   addr = (int)(PIN/16)*6 + &TRISA; \
                        port_bit = PIN%16; \
                        if(TYPE==IN) *addr |=   0x0001<<port_bit; \
                        else         *addr &= ~(0x0001<<port_bit)

#define PinHigh(PIN)    *((int)(PIN/16)*6 + &LATA)  |=   0x0001<<(PIN%16)
#define PinLow(PIN)     *((int)(PIN/16)*6 + &LATA)  &= ~(0x0001<<(PIN%16))

#define PinWrite(PIN,VAL)   addr = (int)(PIN/16)*6 + &LATA; \
                            port_bit = PIN%16; \
                            *addr &= (~((0x0001)<<port_bit)); \
                            *addr |= (VAL<<port_bit)  

#define PinRead(PIN)    (*((int)(PIN/16)*6 + &PORTA) >> (PIN%16)) & 0x0001
         


