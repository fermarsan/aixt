# Quick guide to PIC16F886
## Reference of the PIC16 used by the brand MICROCHIP 
- PIC16F886  

**NOTE:** This PIC16F microcontroller has digital outputs, digital inputs, ADC, PWM and serial communication.

## Pin Names
Pin names are designated by a letter indicating the port and a number indicating the pin. For example, `a6` indicates pin 6 of port A. All names in **Aixt** are written in lowercase, as follows. [V variable naming rules.] (https://github.com/vlang/v/blob/master/doc/docs.md#variables).

### PIC16F886 pin names
| PORT   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4| a5| - | - |
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|
| **C**  | c0| c1| c2| c3| c4| c5| c6| c7|

![alt text](image-1.png) (https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001291H.pdf)

- `MCLR` stands for Master Clear/Reset, a controller reset pin, and is connected to Vcc (+5 V).
- `VDD` is the positive power supply and ground reference for the logic and I/O pins, respectively. These pins have diode protection.
- `VSS` stands for Voltage Source, Source, or Voltage Supply, and is the ground (GND) pin, also known as the voltage reference, 0 volts for the entire circuit.

In the PIC16 microcontroller families, the port registers are divided into:

- `TRIS` is used to configure each port pin.
- `PORT` is used to manage pins as inputs or outputs.

It has one input pin and eight output pins for the digital device, which receives the converted value from the analog circuit to display the programmed cyclical LED lighting behavior.

| Port | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
|:----:|-----|-----|-----|-----|-----|-----|-----|-----|
| **A**| `a0`| ----| ----| ----| ----|----|----|----|
| **B**| `b0`| `b1`| `b2`| `b3`| `b4`| `b5`| `b6`| `b7`|

### Integrated Components
- It has 24 analog-digital pins located between `A0–A7` (inputs/outputs); `B0–B7` (digital outputs, connected to data); `C0–C7` (additional input/output pins) can be specially programmed with specific functions; `Vdd` and ``ss` (inputs/outputs) are 0V to 5V and GND supplies; and we finish with the `MCLR/Vpp` pin, which is the reset pin and can be configured externally.

### Supported Functions
The functions contained in the API include digital inputs or outputs, analog-to-digital converters, PWM modulation, and serial communication.

#### Digital Inputs and Outputs (GPIO)
Name | Description
----------------------------------------|-------------------------------------------------------
`pinMode(pin, mode)` | Configures a pin as a digital input or output.
`digitalWrite(pin, value)` | Sends a high or low logic level (1 or 0) to a pin configured as an output.
`digitalRead(pin)` | Reads the logic state (1 or 0) of a pin configured as an input.
`portWrite(port, value)` | Sends a binary value (0–255) to an entire port (e.g., PORTB).
`portRead(port)` | Reads the binary value present on an entire port.

```v
import port //Configuration

// Configure RB0 as an output and RB1 as an input
port.setup(port.b0, port.output)
port.setup(port.b1, port.input)

for {
if port.read(port.b1) == 1 { // If input RB1 is high
port.write(port.b0, 1) // Turn on output RB0
} else {
port.write(port.b0, 0) // Turn off output RB0
}
}
```

#### Analog-to-Digital Converter (ADC)
Name | Description
--------------------------------------------|-----------------------------------------------------
`adcInit(channel)` | Initializes the ADC and selects the analog channel to read.
`adcRead(channel)` | Performs the conversion and returns the digital value (0–1023 for 10 bits).

```v
import adc //Configuration
import port
import time

adc.setup(0) // Channel AN0

for {
value := adc.read(0) // Read ADC value (0-1023)
port.write(port.b, value >> 2) // Scale to 8 bits and display on PORTB
time.sleep_ms(100)
}
```

#### Pulse Width Modulation (PWM)
Name | Description
----------------------------------------|-------------------------------------------------------
`pwmWrite(channel, cycle` | Sets the duty cycle between 0 and 1023 (for 10 bits).
`pwmInit(channel, frequency` | Sets a PWM channel to the desired frequency.
`pwmStop(channel)` | Stops PWM signal generation on the specified channel.

```v
import pwm //configuration
import time

pwm.setup(1, 500) // Channel 1, frequency 500 Hz

for duty := 0; duty < 1024; duty += 10 {
pwm.write(1, duty) // Set duty cycle (0-1023)
time.sleep_ms(10)
}
```

#### Serial Communications (USART)
Name | Description
----------------------------------------|-------------------------------------------------------
`serialBegin(baudrate` | Initializes serial communication with the specified baud rate (for example, 9600 bps).
`serialWrite(data)` | Sends a byte of data through the serial port.
`serialRead()` | Reads a byte of data received through the serial port.
`serialAvailable()` | Indicates whether data is available to read.

```v
import serial //Configuration
import time

serial.begin(9600) // Communication speed: 9600 bps

for {
serial.write("Hello PIC16F886!\n")
time.sleep_ms(1000)
}
```

### Example of API functions in _Aixt_v language

```v

#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define _XTAL_FREQ 10000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF		// Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#define time__sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory
#define time__sleep_us(TIME)    __delay_us(TIME)  // implementing by a macro for saving memory
#define time__sleep(TIME)    __delay_ms(TIME*1024)  // implementing by a macro for saving memory
#define pin__output 0	// pin mode direction
#define pin__input  1
#define pin__a0      A, 0	// pin names
#define pin__a1      A, 1
#define pin__a2      A, 2
#define pin__a3      A, 3
#define pin__a4      A, 4
#define pin__a5      A, 5
#define pin__a6      A, 6
#define pin__a7      A, 7
#define pin__b0      B, 0
#define pin__b1      B, 1
#define pin__b2      B, 2
#define pin__b3      B, 3
#define pin__b4      B, 4
#define pin__b5      B, 5
#define pin__b6      B, 6
#define pin__b7      B, 7
#define pin__c0      C, 0
#define pin__c1      C, 1
#define pin__c2      C, 2
#define pin__c3      C, 3
#define pin__c4      C, 4
#define pin__c5      C, 5
#define pin__c6      C, 6
#define pin__c7      C, 7
#define pin__e3      E, 3
#define pin__write_(PORT_NAME, PIN, VALUE)   PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN = VALUE
#define pin__write(PIN_NAME, VALUE)  pin__write_(PIN_NAME, VALUE)
#define pin__high_(PORT_NAME, PIN)   PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN = 1
#define pin__high(PIN_NAME)  pin__high_(PIN_NAME)
#define pin__setup_(PORT_NAME, PIN, MODE)   TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE
#define pin__setup(PIN_NAME, PIN_MODE)  pin__setup_(PIN_NAME, PIN_MODE)
#define pin__toggle_(PORT_NAME, PIN)   PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN ^= 1
#define pin__toggle(PIN_NAME)  pin__toggle_(PIN_NAME)
#define pin__read_(PORT_NAME, PIN)	PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN
#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)
#define pin__low_(PORT_NAME, PIN)   PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN = 0
#define pin__low(PIN_NAME)  pin__low_(PIN_NAME)
#define port__a		A	// port name constants
#define port__b		B
#define port__c		C
#define port__e		E
#define	port__all_inputs	0xFF	// port mode constants
#define	port__all_outputs	0x00
#define TRISport__a		TRISA	// port setup name equivalents
#define TRISport__b		TRISB
#define TRISport__c		TRISC
#define TRISport__e		TRISE
#define PORTport__a		PORTA	// port name equivalents
#define PORTport__b		PORTB
#define PORTport__c		PORTC
#define PORTport__e		PORTE
#define port__write(PORT_NAME, VALUE)  PORT ## PORT_NAME = (uint8_t)VALUE
#define port__setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE
#define port__read(PORT_NAME)  PORT ## PORT_NAME
#define	adc__in0 	0b1111111111111110
#define	adc__in1 	0b1111111111111101
#define	adc__in2 	0b1111111111111011
#define	adc__in3 	0b1111111111110111
#define	adc__in4 	0b1111111111101111
#define	adc__in5 	0b1111111111011111
#define	adc__in6 	0b1111111110111111
#define	adc__in7 	0b1111111101111111
#define	adc__in8 	0b1111111011111111
#define	adc__in9 	0b1111110111111111
#define	adc__in10	0b1111101111111111
#define adc__f_30ksps_1mhz	0	// VREF 3.0v
#define adc__f_30ksps_4mhz	1	// VREF 3.0v
#define adc__f_18ksps_8mhz	2	// VREF full range
#define adc__f_21ksps_10mhz	2	// VREF full range
#define adc__f_24ksps_12mhz	2	// VREF 3.0v
#define adc__f_30ksps_16mhz	2	// VREF 3.0v
#define adc__f_34ksps_20mhz	2	// VREF 3.0v
#define adc__f_18ksps_irc	3	// sleep mode FOSC > 1Mhz
#define	adc__bits_8		0
#define	adc__bits_10	1
#define	adc__ch0 	0
#define	adc__ch1 	1
#define	adc__ch2 	2
#define	adc__ch3 	3
#define	adc__ch4 	4
#define	adc__ch5 	5
#define	adc__ch6 	6
#define	adc__ch7 	7
#define	adc__ch8 	8
#define	adc__ch9 	9
#define	adc__ch10	10

uint8_t adc__read_byte(uint8_t channel) ;
uint16_t adc__read(uint8_t channel) ;



uint8_t adc__read_byte(uint8_t channel) {    
    ADCON0bits.CHS = channel;   /* assign the ADC channel */    
    ADCON0bits.GO_DONE = 1;     /* start conversion */  
    while(ADCON0bits.GO_DONE == 1) {}   /* wait for the end of conversion */    
    return ADRESH;              /* return the ADC value (8 bits) */  
}



#define adc__setup(PINS, FAD, NBITS) \
    /* analog pins setup */ \
    ANSEL = (uint8_t)~PINS;         \
    ANSELH = (uint8_t)(~PINS>>8);   \
    /* ADC setup */ \
    ADCON1 = 0b00000000;    /*VSS, VDD*/\
    ADCON1bits.ADFM = NBITS;    \
    ADCON0bits.ADCS = FAD;  \
    ADCON0bits.ADON = 1;



uint16_t adc__read(uint8_t channel) {    
    ADCON0bits.CHS = channel;   /* assign the ADC channel */    
    ADCON0bits.GO_DONE = 1;     /* start conversion */  
    while(ADCON0bits.GO_DONE == 1) {}   /* wait for the end of conversion */    
    return (ADRESH << 8) | ADRESL;     /* return the ADC value */  
}


void main(void) {

pin__setup(pin__a0, pin__input);
adc__setup(adc__in0, adc__f_21ksps_10mhz, adc__bits_8);
port__setup(port__b, port__all_outputs);
unsigned char muestra = 0;
while(true) {
muestra = adc__read_byte(adc__ch0);
port__write(port__b, muestra);
}
}

```

## Configuring an Individual Pin

```v

import port

// Configure RB0 as an output
port.setup(port.b0, port.output)

// Configure RB1 as an input
port.setup(port.b1, port.input)
```

Configuring a Full Port

```v
import port

// Configure all pins on port B as outputs
port.setup(port.b, port.all_outputs)

```
## Combined Bit Configuration

```v
import port

// 1 = output, 0 = input
// Example: 0b11110000 -> RB7..RB4 outputs, RB3..RB0 inputs
port.setup_mask(port.b, 0b11110000)

```