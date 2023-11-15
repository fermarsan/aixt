<!-- changes to snake_case -->
# Quick reference for the Exploer 16 boad
Development board for Microchip 16-bit microcontrollers. It includes the families:
- _PIC24_: PIC24FJ128GA010
- _dsPIC33_: dsPIC33FJ256GP710

## Pin names
The pin names are named with a letter indicating the port and a number indicating the pin. For example `b12` indicates de pin 12 of port B. All the names in **Aixt** are written in lower-case, to follow the [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

### Pin names for PIC24FJ
| port |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |
|:----:|--|--|--|--|--|--|--|--|--|--|---|---|---|---|---|---| 
|**A** |a0|a1|a2|a3|a4|a5|a6|a7|- |a9|a10|-  |-  |-  |a14|a15|
|**B** |b0|b1|b2|b3|b4|b5|b6|b7|b8|b9|b10|b11|b12|b13|b14|b15|
|**C** |c0|c1|c2|c3|c4|- |- |- |- |- |-  |-  |c12|c13|c14|c15|
|**D** |d0|d1|d2|d3|d4|d5|d6|d7|d8|d9|d10|d11|d12|d13|d14|d15|
|**E** |e0|e1|e2|e3|e4|e5|e6|e7|e8|e9|-  |-  |-  |-  |-  |-  |
|**F** |f0|f1|f2|f3|f4|f5|f6|f7|f8|- |-  |-  |f12|f13|-  |-  |
|**G** |g0|g1|g2|g3|g4|g5|g6|g7|g8|g9|-  |-  |g12|g13|g14|g15|

### Pins names for dsPIC33
| port |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |
|:----:|--|--|--|--|--|--|--|--|--|--|---|---|---|---|---|---| 
|**A** |a0|a1|a2|a3|a4|a5|a6|a7|- |a9|a10|-  |-  |-  |a14|a15|
|**B** |b0|b1|b2|b3|b4|b5|b6|b7|b8|b9|b10|b11|b12|b13|b14|b15|
|**C** |c0|c1|c2|c3|c4|- |- |- |- |- |-  |-  |c12|c13|c14|c15|
|**D** |d0|d1|d2|d3|d4|d5|d6|d7|d8|d9|d10|d11|d12|d13|d14|d15|
|**E** |e0|e1|e2|e3|e4|e5|e6|e7|e8|e9|-  |-  |-  |-  |-  |-  |
|**F** |f0|f1|f2|f3|f4|f5|f6|f7|f8|- |-  |-  |f12|f13|-  |-  |
|**G** |g0|g1|g2|g3|g4|g5|g6|g7|g8|g9|-  |-  |g12|g13|g14|g15|

In _dsPIC33_ and _PIC24_ microcontrollers families, the port's registers are divided in:
  - `TRIS` for setting up each pin of the port
  - `PORT` for managing the pins as inputs 
  - `LAT` for managing the pins as outputs

then, for making easy the implementation (and for avoiding to generate unnecessary code) of this _Aixt_ port, the name of each pin differ among its setup, input and output as the following example:
  - `c6_s` name of the bit for setting up the `c6` pin as input or output
  - `c6_i` name of the bit for reading the input pin `c6`
  - `c6` name of the bit for writing the output pin `c6`

### Explorer16 Onboard components

#### Onboard LEDs
LED	| name	| pin
----|-------|----
3	| led3 	| a0            
4 	| led4 	| a1        
5 	| led5 	| a2        
6 	| led6 	| a3       
7 	| led7 	| a4       
8 	| led8 	| a5        
9 	| led9 	| a6        
10 	| led10	| a7    

#### Onboard switchs
Switch	| name	| pin
--------|-------|------
3		| sw3   | d6_i  
4		| sw4   | d13_i  
5		| sw5   | a7_i  
6		| sw6   | d7_i  

#### Onboard potentiometer
Potentiometer	| name	| pin
----------------|-------|-----
1				| pot   | b5_i

## Delay and timing
```go
sleep(2)		// sleep for 2 seconds
sleep_us(1)		// sleep for 1 microsecond
sleep_ms(500)	// sleep for 500 milliseconds
```

## Pin and GPIO
```go
pin_setup(b5_s, out)
pin_setup(a2_s, out)
pin_setup(c10_s, input)

pin_high(b5)
pin_low(b5)

pin_write(a2)

x = pin_read(c10_i)
```

Blinking LED example:
```go
for {
	pin_high(led10)
	sleep_ms(500)
	pin_low(led10)
	sleep_ms(500)
}
```

## UART
```go
uart_setup(1, 9600)

uart_put(1, `x`)
y := uart_get(1)

uart_write(1, 'Hello...')
msg := uart_read(1)
```

