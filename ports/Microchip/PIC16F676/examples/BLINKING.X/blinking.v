import time {time__sleep_ms}
import pin

pin.setup(c0, pin.out)
pin.setup(c1, pin.out)
pin.setup(c2, pin.out)

fot{

    pin.hig(c0)
    time__sleep_ms(500)
    pin.hig(c1)
    time__sleep_ms(500)
    pin.hig(c2) 
    time__sleep_ms(500)

    pin.low(c0)
    pin.low(c1)
    pin.low(c2)
    time__sleep_ms(500)

}




