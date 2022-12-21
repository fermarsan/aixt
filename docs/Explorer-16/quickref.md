 
# Quick reference for the Explorer 16 board

Development board for Microchip 16-bit microcontrollers. It includes the families:
- PIC24
- dsPIC33

## Pin names
| port |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |
|:----:|--|--|--|--|--|--|--|--|--|--|---|---|---|---|---|---|                          
|**A** |A0|A1|A2|A3|A4|A5|A6|A7|AAAAAAAA
|**B** |B0|B1|B2|B3|B4|B5|B6|B7|BBBBBBBB
|**C** |C0|C1|C2|C3|C4|C5|C6|C7|CCCCCCCC
|**D** |D0|D1|D2|D3|D4|D5|D6|D7|DDDDDDDD
|**E** |E0|E1|E2|E3|E4|E5|E6|E7|EEEEEEEE
|**F** |F0|F1|F2|F3|F4|F5|F6|F7|FFFFFFFF
## Delay and timing

```go
import time {
	sleep,
	sleep_ms,
	sleep_us
}

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
