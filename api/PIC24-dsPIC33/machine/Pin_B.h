#include "../settings.h"

#define PIN_IN(TRIS,PIN)            TRIS |= ((0x0001)<<PIN)
#define PIN_OUT(TRIS,PIN)           TRIS &= (~((0x0001)<<PIN))
#define PIN_ON(LAT,PIN)             LAT  |= ((0x0001)<<PIN)
#define PIN_OFF(LAT,PIN)            LAT  &= (~((0x0001)<<PIN))
#define PIN_VALUE_IN(LAT,PIN)       (LAT>>PIN) & 0x0001
#define PIN_VALUE_OUT(LAT,PIN,VAL)  LAT &= (~((0x0001)<<PIN)); LAT |= (VAL<<PIN)