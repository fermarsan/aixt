#include "../settings.h"

#define PIN_0_IN(TRIS)          TRIS |= 0x0001
#define PIN_0_OUT(TRIS)         TRIS &= 0xFFFE
#define PIN_0_ON(LAT)           LAT  |= 0x0001
#define PIN_0_OFF(LAT)          LAT  &= 0xFFFE
#define PIN_1_IN(TRIS)          TRIS |= 0x0002
#define PIN_1_OUT(TRIS)         TRIS &= 0xFFFD
#define PIN_1_ON(LAT)           LAT  |= 0x0002
#define PIN_1_OFF(LAT)          LAT  &= 0xFFFD
#define PIN_2_IN(TRIS)          TRIS |= 0x0004
#define PIN_2_OUT(TRIS)         TRIS &= 0xFFFB
#define PIN_2_ON(LAT)           LAT  |= 0x0004
#define PIN_2_OFF(LAT)          LAT  &= 0xFFFB
#define PIN_3_IN(TRIS)          TRIS |= 0x0008
#define PIN_3_OUT(TRIS)         TRIS &= 0xFFF7
#define PIN_3_ON(LAT)           LAT |= 0x0008
#define PIN_3_OFF(LAT)          LAT &= 0xFFF7 
#define PIN_4_IN(TRIS)          TRIS |= 0x0010
#define PIN_4_OUT(TRIS)         TRIS &= 0xFFEF
#define PIN_4_ON(LAT)           LAT |= 0x0010
#define PIN_4_OFF(LAT)          LAT &= 0xFFEF
#define PIN_5_IN(TRIS)          TRIS |= 0x0020
#define PIN_5_OUT(TRIS)         TRIS &= 0xFFDF
#define PIN_5_ON(LAT)           LAT |= 0x0020
#define PIN_5_OFF(LAT)          LAT &= 0xFFDF
#define PIN_6_IN(TRIS)          TRIS |= 0x0040
#define PIN_6_OUT(TRIS)         TRIS &= 0xFFBF
#define PIN_6_ON(LAT)           LAT |= 0x0040
#define PIN_6_OFF(LAT)          LAT &= 0xFFBF
#define PIN_7_IN(TRIS)          TRIS |= 0x0080
#define PIN_7_OUT(TRIS)         TRIS &= 0xFF7F
#define PIN_7_ON(LAT)           LAT |= 0x0080
#define PIN_7_OFF(LAT)          LAT &= 0xFF7F 
#define PIN_8_IN(TRIS)          TRIS |= 0x0100
#define PIN_8_OUT(TRIS)         TRIS &= 0xFEFF
#define PIN_8_ON(LAT)           LAT |= 0x0100
#define PIN_8_OFF(LAT)          LAT &= 0xFEFF
#define PIN_9_IN(TRIS)          TRIS |= 0x0200
#define PIN_9_OUT(TRIS)         TRIS &= 0xFDFF
#define PIN_9_ON(LAT)           LAT |= 0x0200
#define PIN_9_OFF(LAT)          LAT &= 0xFDFF
#define PIN_10_IN(TRIS)         TRIS |= 0x0400
#define PIN_10_OUT(TRIS)        TRIS &= 0xFBFF
#define PIN_10_ON(LAT)          LAT |= 0x0400
#define PIN_10_OFF(LAT)         LAT &= 0xFBFF
#define PIN_11_IN(TRIS)         TRIS |= 0x0800
#define PIN_11_OUT(TRIS)        TRIS &= 0xF7FF
#define PIN_11_ON(LAT)          LAT |= 0x0800
#define PIN_11_OFF(LAT)         LAT &= 0xF7FF 
#define PIN_12_IN(TRIS)         TRIS |= 0x1000
#define PIN_12_OUT(TRIS)        TRIS &= 0xEFFF
#define PIN_12_ON(LAT)          LAT |= 0x1000
#define PIN_12_OFF(LAT)         LAT &= 0xEFFF
#define PIN_13_IN(TRIS)         TRIS |= 0x2000
#define PIN_13_OUT(TRIS)        TRIS &= 0xDFFF
#define PIN_13_ON(LAT)          LAT |= 0x2000
#define PIN_13_OFF(LAT)         LAT &= 0xDFFF
#define PIN_14_IN(TRIS)         TRIS |= 0x4000
#define PIN_14_OUT(TRIS)        TRIS &= 0xBFFF
#define PIN_14_ON(LAT)          LAT |= 0x4000
#define PIN_14_OFF(LAT)         LAT &= 0xBFFF
#define PIN_15_IN(TRIS)         TRIS |= 0x8000
#define PIN_15_OUT(TRIS)        TRIS &= 0x7FFF
#define PIN_15_ON(LAT)          LAT |= 0x8000
#define PIN_15_OFF(LAT)         LAT &= 0x7FFF 

#define PIN_0_VALUE_IN(LAT)         LAT & 0x0001
#define PIN_0_VALUE_OUT(LAT,VAL)    LAT &= 0xFFFE; LAT |= VAL
#define PIN_1_VALUE_IN(LAT)         LAT>>1 & 0x0001
#define PIN_1_VALUE_OUT(LAT,VAL)    LAT &= 0xFFFD; LAT |= VAL<<1
#define PIN_2_VALUE_IN(LAT)         LAT>>2 & 0x0001
#define PIN_2_VALUE_OUT(LAT,VAL)    LAT &= 0xFFFB; LAT |= VAL<<2
#define PIN_3_VALUE_IN(LAT)         LAT<<3 & 0x0001
#define PIN_3_VALUE_OUT(LAT,VAL)    LAT &= 0xFFF7; LAT |= VAL<<3
#define PIN_4_VALUE_IN(LAT)         LAT>>4 & 0x0001
#define PIN_4_VALUE_OUT(LAT,VAL)    LAT &= 0xFFEF; LAT |= VAL<<4
#define PIN_5_VALUE_IN(LAT)         LAT>>5 & 0x0001
#define PIN_5_VALUE_OUT(LAT,VAL)    LAT &= 0xFFDF; LAT |= VAL<<5
#define PIN_6_VALUE_IN(LAT)         LAT>>6 & 0x0001
#define PIN_6_VALUE_OUT(LAT,VAL)    LAT &= 0xFFBF; LAT |= VAL<<6
#define PIN_7_VALUE_IN(LAT)         LAT>>7 & 0x0001
#define PIN_7_VALUE_OUT(LAT,VAL)    LAT &= 0xFF7F; LAT |= VAL<<7
#define PIN_8_VALUE_IN(LAT)         LAT>>8 & 0x0001
#define PIN_8_VALUE_OUT(LAT,VAL)    LAT &= 0xFEFF; LAT |= VAL<<8
#define PIN_9_VALUE_IN(LAT)         LAT>>9 & 0x0001
#define PIN_9_VALUE_OUT(LAT,VAL)    LAT &= 0xFDFF; LAT |= VAL<<9
#define PIN_10_VALUE_IN(LAT)        LAT>>10 & 0x0001
#define PIN_10_VALUE_OUT(LAT,VAL)   LAT &= 0xFBFF; LAT |= VAL<<10
#define PIN_11_VALUE_IN(LAT)        LAT>>11 & 0x0001
#define PIN_11_VALUE_OUT(LAT,VAL)   LAT &= 0x7FFF; LAT |= VAL<<11
#define PIN_12_VALUE_IN(LAT)        LAT>>12 & 0x0001
#define PIN_12_VALUE_OUT(LAT,VAL)   LAT &= 0xEFFF; LAT |= VAL<<12
#define PIN_13_VALUE_IN(LAT)        LAT>>13 & 0x0001
#define PIN_13_VALUE_OUT(LAT,VAL)   LAT &= 0xDFFF; LAT |= VAL<<13
#define PIN_14_VALUE_IN(LAT)        LAT>>14 & 0x0001
#define PIN_14_VALUE_OUT(LAT,VAL)   LAT &= 0xBFFF; LAT |= VAL<<14
#define PIN_15_VALUE_IN(LAT)        LAT>>15 & 0x0001
#define PIN_15_VALUE_OUT(LAT,VAL)   LAT &= 0x7FFF; LAT |= VAL<<15
