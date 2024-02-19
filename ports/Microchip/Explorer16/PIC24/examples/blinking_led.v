/* Blinking LED on the Explorer16 board with 
a PIC24FJ microcontroller (XC16 compiler)*/
import pin
import time

for {   //infinite loop
    pin.high(led10)     // LED 10 blinking
    time.sleep_ms(500)
    pin.low(led10)
    time.sleep_ms(500)
}