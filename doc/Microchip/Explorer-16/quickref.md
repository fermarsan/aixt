<!-- changes to snake_case -->
# Quick reference for the Explorer 16 board
Development board for Microchip 16-bit microcontrollers. It includes the families:
- _PIC24_: PIC24FJ128GA010
- _dsPIC33_: dsPIC33FJ256GP710

## Pin names
The pin names are named with a capitalized letter indicating the port and a number indicating the pin. For example `rb12` indicates de pin 12 of port B.

### Pin original names for PIC24FJ
| port |0  |1  |2  |3  |4  |5  |6  |7  |8  |9  |10  |11  |12  |13  |14  |15  |
|:----:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----| 
|**A** |ra0|ra1|ra2|ra3|ra4|ra5|ra6|ra7|-  |ra9|ra10|-   |-   |-   |ra14|ra15|
|**B** |rb0|rb1|rb2|rb3|rb4|rb5|rb6|rb7|rb8|rb9|rb10|rb11|rb12|rb13|rb14|rb15|
|**C** |rc0|rc1|rc2|rc3|rc4|-  |-  |-  |-  |-  |-   |-   |rc12|rc13|rc14|rc15|
|**D** |rd0|rd1|rd2|rd3|rd4|rd5|rd6|rd7|rd8|rd9|rd10|rd11|rd12|rd13|rd14|rd15|
|**E** |re0|re1|re2|re3|re4|re5|re6|re7|re8|re9|-   |-   |-   |-   |-   |-   |
|**F** |rf0|rf1|rf2|rf3|rf4|rf5|rf6|rf7|rf8|-  |-   |-   |rf12|rf13|-   |-   |
|**G** |rg0|rg1|rg2|rg3|rg4|rg5|rg6|rg7|rg8|rg9|-   |-   |rg12|rg13|rg14|rg15|

### Pins original names for dsPIC33
| port |0  |1  |2  |3  |4  |5  |6  |7  |8  |9  |10  |11  |12  |13  |14  |15  |
|:----:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----| 
|**A** |ra0|ra1|ra2|ra3|ra4|ra5|ra6|ra7|-  |ra9|ra10|-   |-   |-   |ra14|ra15|
|**B** |rb0|rb1|rb2|rb3|rb4|rb5|rb6|rb7|rb8|rb9|rb10|rb11|rb12|rb13|rb14|rb15|
|**C** |rc0|rc1|rc2|rc3|rc4|-  |-  |-  |-  |-  |-   |-   |rc12|rc13|rc14|rc15|
|**D** |rd0|rd1|rd2|rd3|rd4|rd5|rd6|rd7|rd8|rd9|rd10|rd11|rd12|rd13|rd14|rd15|
|**E** |re0|re1|re2|re3|re4|re5|re6|re7|re8|re9|-   |-   |-   |-   |-   |-   |
|**F** |rf0|rf1|rf2|rf3|rf4|rf5|rf6|rf7|rf8|-  |-   |-   |rf12|rf13|-   |-   |
|**G** |rg0|rg1|rg2|rg3|rg4|rg5|rg6|rg7|rg8|rg9|-   |-   |rg12|rg13|rg14|rg15|

### Pin names in **Aixt**
All the names in **Aixt** are written in lower-case, to follow the **V** variable naming rules.

## Delay and timing
```go
import time {
	sleep,
	sleep_ms,
	sleep_us,
}

sleep(2)	    // sleep for 2 seconds
sleep_us(1)     // sleep for 1 microsecond
sleep_ms(500)   // sleep for 500 milliseconds
```

## Pin and GPIO
```go
import machine { pin }

pin_mode(rb5, out)
pin_mode(ra2, in)

pin_high(rb5)
pin_low(rb5)

pin_write(ra2)
```

## UART
```go
import machine { uart }

uart_setup(1, 9600)

uart_put(1, `x`)
y := uart_get(1)

uart_write(1, 'Hello...')
msg := uart_read(1)
```