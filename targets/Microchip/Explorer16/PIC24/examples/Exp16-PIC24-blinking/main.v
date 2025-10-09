/* Blinking LED on the Explorer16 board with 
a PIC24FJ microcontroller (XC16 compiler)*/
import pin
import time

pin.setup(pin.led6, pin.output)

for {   //infinite loop
    pin.high(pin.led6)     // LED 6 blinking
    time.sleep_ms(500)
    pin.low(pin.led6)
    time.sleep_ms(500)
}