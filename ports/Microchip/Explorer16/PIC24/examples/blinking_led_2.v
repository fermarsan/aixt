/* Blinking LED on the Explorer16 board with 
a PIC24FJ microcontroller (XC16 compiler)*/
import pin
import time

pin.setup(a3, pin.out)

for {   //infinite loop
    pin.high(a3)     // LED 10 blinking
    time.sleep_ms(500)
    pin.low(a3)
    time.sleep_ms(500)
}