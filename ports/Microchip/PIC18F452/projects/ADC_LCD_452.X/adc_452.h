#include <xc.h>
#define _XTAL_FREQ 8000000

#define AN0_ANALOG          0xCE  // 1100 1110
#define AN0_AN1_AN3_ANALOG  0xC4  // 1100 0100
#define AN0_TO_AN4_ANALOG   0xC2  // 1100 0010
#define AN0_TO_AN5_ANALOG   0xC9  // 1100 1001
#define ALL_ANALOG          0xC0  // 1100 0000

void ADC_Init(unsigned char p_ang);
unsigned int ADC_Read(unsigned char ch);