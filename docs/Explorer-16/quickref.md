 
# Quick reference for the Explorer 16 board

Development board for Microchip 16-bit microcontrollers. It includes the families:
- PIC24
- dsPIC33

## Pin names
| port | |
|:----:|
|A	|A0	
|B
|C
|D
|E
|F
## Delay and timing

```go
import time

sleep(2)	// sleep for 2 seconds
sleep_us(1)     // sleep for 1 microsecond
sleep_ms(500)   // sleep for 500 milliseconds
```

## Pin and GPIO

```go
import machine { pin }

pin(B5, pin_out)
pin(A2, pin_in)

pin_high(B5)
pin_low(B5)
pin_toogle(B5)

pin_value(A2)
```

## UART
```go
import machine { uart }

uart_1(9600)

uart_1_put(`x`)
y := uart_1_get()

uart_1_write('Hello...')
msg := uart_1_read()
```
