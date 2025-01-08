#define	t_on	500
#define t_off	100

import time
import machine

pin(B0,out)

pin.high(pin.B0)
time.sleep_ms(t_on)

pin.low(pin.B0)
time.sleep_ms(t_off)
