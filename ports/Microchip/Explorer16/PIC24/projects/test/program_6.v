#define	t_on	500
#define t_off	100

import time
import machine

pin(B0,out)

pin.high(B0)
sleep_ms(t_on)

pin.low(B0)
sleep_ms(t_off)
