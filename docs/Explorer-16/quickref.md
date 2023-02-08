 
# Quick reference for the Explorer 16 board
Development board for Microchip 16-bit microcontrollers. It includes the families:
- _PIC24_: PIC24FJ128GA010
- _dsPIC33_: dsPIC33FJ256GP710

## Pin names
The pin names are named with a capitalized letter indicating the port and a number indicating the pin. For example `B12` indicates de pin 12 of port B.
That pin definition is done in `aixt-project/api/Explorer-16-xxxxx/ports.h`.

### Pins names for PIC24FJ
| port |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |
|:----:|--|--|--|--|--|--|--|--|--|--|---|---|---|---|---|---| 
|**A** |A0|A1|a2|A3|A4|A5|A6|A7|- |A9|A10|-  |-  |-  |A14|A15|
|**B** |B0|B1|B2|B3|B4|b5|B6|B7|B8|B9|B10|B11|B12|B13|B14|B15|
|**C** |C0|C1|C2|C3|C4|- |- |- |- |- |-  |-  |C12|C13|C14|C15|
|**D** |D0|D1|D2|D3|D4|D5|D6|D7|D8|D9|D10|D11|D12|D13|D14|D15|
|**E** |E0|E1|E2|E3|E4|E5|E6|E7|E8|E9|-  |-  |-  |-  |-  |-  |
|**F** |F0|F1|F2|F3|F4|F5|F6|F7|F8|- |-  |-  |F12|F13|-  |-  |
|**G** |G0|G1|G2|G3|G4|G5|G6|G7|G8|G9|-  |-  |G12|G13|G14|G15|

### Pins names for dsPIC33
| port |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |
|:----:|--|--|--|--|--|--|--|--|--|--|---|---|---|---|---|---| 
|**A** |A0|A1|a2|A3|A4|A5|A6|A7|- |A9|A10|-  |-  |-  |A14|A15|
|**B** |B0|B1|B2|B3|B4|b5|B6|B7|B8|B9|B10|B11|B12|B13|B14|B15|
|**C** |C0|C1|C2|C3|C4|- |- |- |- |- |-  |-  |C12|C13|C14|C15|
|**D** |D0|D1|D2|D3|D4|D5|D6|D7|D8|D9|D10|D11|D12|D13|D14|D15|
|**E** |E0|E1|E2|E3|E4|E5|E6|E7|E8|E9|-  |-  |-  |-  |-  |-  |
|**F** |F0|F1|F2|F3|F4|F5|F6|F7|F8|- |-  |-  |F12|F13|-  |-  |
|**G** |G0|G1|G2|G3|G4|G5|G6|G7|G8|G9|-  |-  |G12|G13|G14|G15|

## Delay and timing
```go
import time {
	sleep,
	sleep_ms,
	sleep_us,
}

sleep(2)	// sleep for 2 seconds
sleep_us(1)     // sleep for 1 microsecond
sleep_ms(500)   // sleep for 500 milliseconds
```

## Pin and GPIO
```go
import machine { pin }

pin(b5, pin_out)
pin(a2, pin_in)

pin_high(b5)
pin_low(b5)
pin_toogle(b5)

pin_value(a2)
```

## UART
```go
import machine { uart }

uart1(9600)

uart1_put(`x`)
y := uart1_get()

uart1_write('Hello...')
msg := uart1_read()
```
