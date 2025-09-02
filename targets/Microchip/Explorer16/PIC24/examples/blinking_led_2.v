/* Blinking LED on the Explorer16 board with 
a PIC24FJ microcontroller (XC16 compiler)*/
import pin
import time

pin.setup(pin.a3, pin.output)

for {   //infinite loop
    pin.high(pin.a3)     // LED 10 blinking
    time.sleep_ms(500)
    pin.low(pin.a3)
    time.sleep_ms(500)
}