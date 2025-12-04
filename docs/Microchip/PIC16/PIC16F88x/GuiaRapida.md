# Guia Rápida para PIC16F886
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F886 (PIC16F882, PIC16F883, PIC16F884 y PIC16F887) 

**NOTA:** Este microcontrolador PIC16F cuenta con salidas digitales, entradas digitales, ADC, PWM y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a6` indica el pin 6 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir. [V variable naming rules.] (https://github.com/vlang/v/blob/master/doc/docs.md#variables).

### Nombres de los pines del PIC16F886
| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4| a5| a6| a7|
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|
| **C**  | c0| c1| c2| c3| c4| c5| c6| c7|
| **E**  | - | - | - | e3| - | - | - | - |

![alt text](image-1.png) Fuente: (https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001291H.pdf)

- `MCLR` significa Master Clear/Reset, es decir, un pin de reinicio del controlador y se conecta a Vcc (+5 V), mediante resistencias pull-up de 10k,
opcional capacitor RC para reset suave.
- `VDD` Alimentación positiva y referencia de tierra para los pines lógicos y de E/S, respectivamente. Estos pines cuentan con protección de diodo.
- `VSS` significa Fuente de Voltaje, Fuente o Fuente de Suministro de Voltaje y es el pin de tierra (GND), también conocido como referencia de voltaje, 0 voltios para todo el circuito.

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas, bidireccionales.

Tiene un pin de entrada y ocho de salida al dispositivo digital, el cual recibe el valor converdido del circuito analógico para mostrar el comportamiento ciclico programado de encendido del LED.

| Port | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
|:----:|-----|-----|-----|-----|-----|-----|-----|-----|
| **A**| `a0`| ----| ----| ----| ----|----|----|----|
| **B**| `b0`| `b1`| `b2`| `b3`| `b4`| `b5`| `b6`| `b7`|

### Componentes Integrados 
Este microcontrolador cuenta con 24 pines de entrada/salida digital (GPIO) distribuidos en los puertos A, B y C. Dentro de estos pines, 11 pueden funcionar como entradas analógicas para el módulo ADC de 10 bits.
  - PORTA (RA0–RA7): pines de E/S digitales; algunos incluyen funciones analógicas (AN0–AN4) y pines especiales como VREF+/VREF–.
  - PORTB (RB0–RB7): pines de E/S digitales, compatibles con interrupción por cambio de estado; varios de ellos también son entradas ADC (AN8–AN13).
  - PORTC (RC0–RC7): pines de E/S digitales con funciones periféricas como UART, I²C/SPI y PWM (CCP/ECCP), pero sin entradas analógicas.

Además, el microcontrolador posee los pines de alimentación VDD (5 V) y VSS (GND), y el pin MCLR/VPP utilizado para reinicio y programación, el cual requiere una resistencia ‘pull-up’ externa.

Por defecto, tras un reinicio, todos los pines se configuran como entrada (TRISx = 0xFF).
Los pines con función analógica deben configurarse explícitamente como digitales deshabilitando ANSEL y ANSELH

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales, conversor analogico a digital, modulación pwm y comunicación serial.

## Configuración del Reloj (Clock System)

Puede usar reloj externo o el oscilador interno/externo.
Esto afecta la velocidad real del microcontrolador y el funcionamiento de temporizadores, ADC, PWM y UART.

 - El registro OSCCON selecciona la frecuencia interna (31 kHz a 8 MHz).
 - El fusible FOSC define si el PIC usará:
 - osilador externo (HS/XT/LP)
 - reloj externo (EC)
 - oscilador interno (INTOSC) -Si el oscilador es 8 MHz → el PIC ejecuta 2 MIPS-

 ## Configuración de Fusibles (Configuration Bits)

 Los fusibles definen el comportamiento básico del microcontrolador al arrancar.

**FOSC** – Fuente de reloj
**WDTE** – Watchdog Timer
**PWRTE** – Power-Up Timer
**MCLRE** – Habilita el pin **MCLR** como reset externo
**BOREN** – Brown-out Reset (protección por bajo voltaje)
**LVP** – Low Voltage Programming

Si LVP está ON, el pin RB3 queda bloqueado como entrada PGM.
En proyectos normales

```v
#pragma config LVP = OFF
```
*Si LVP está ON, el pin RB3 queda bloqueado como entrada PGM, para proyectos normales.

## Limitaciones del Hardware y Pines Especiales

**RA4 (Open Drain / Open Collector)**
 - No puede entregar un ‘1’ alto por sí solo
 - Requiere pull-up externo si se usa como salida alta

**RB0/INT – Interrupción externa**

 - Soporta interrupción por flanco ascendente/descendente

**RB4–RB7 – Interrupt-on-Change (IOC)**

 - Interrupción automática si cambia el estado del pin
 - Útil para botones, teclados, encoders

**ANSEL y ANSELH**

Para usar RA0–RA4 y RB0–RB5 como pines digitales, primero debes desactivar los canales analógicos:
```v
ANSEL = 0;
ANSELH = 0; // Si no se hace esto → digitalWrite/digitalRead fallarán
```
**Estado inicial tras reset**

 - Todos los pines se configuran como entrada.
 - Debes configurar TRISx manualmente.

 ## Tabla de Pines Especiales

 | Pin Físico | Nombre | Digital I/O | Analógico | PWM / CCP | UART | I2C / SPI | Interrupciones | Notas Especiales |
|-----------:|--------|-------------|-----------|-----------|-------|-----------|----------------|------------------|
| 1          | RA2    | Sí          | AN2       | No        | No    | No        | No             | VREF– opcional   |
| 2          | RA3    | Sí          | AN3       | No        | No    | No        | No             | VREF+ opcional   |
| 3          | RA4    | Sí          | No        | No        | No    | No        | No             | **Open-Drain**, requiere pull-up |
| 4          | RA5    | Sí          | AN4       | No        | No    | No        | No             | Puede ser MCLR si fusible lo permite |
| 5          | RE0    | Sí          | AN5       | No        | No    | No        | No             | Función digital limitada |
| 6          | RE1    | Sí          | AN6       | No        | No    | No        | No             | Función digital limitada |
| 7          | RE2    | Sí          | AN7       | No        | No    | No        | No             | Función digital limitada |
| 8          | VDD    | –           | –         | –         | –     | –         | –              | Alimentación 5V |
| 9          | VSS    | –           | –         | –         | –     | –         | –              | Tierra GND |
| 10         | RA0    | Sí          | AN0       | No        | No    | No        | No             | – |
| 11         | RA1    | Sí          | AN1       | No        | No    | No        | No             | – |
| 12         | RC0    | Sí          | No        | No        | No    | Sí (T1OSO) | No            | Puede ser reloj del TMR1 |
| 13         | RC1    | Sí          | No        | CCP2      | No    | Sí        | No             | PWM / CCP2 |
| 14         | RC2    | Sí          | No        | CCP1      | No    | Sí        | No             | PWM / CCP1 |
| 15         | RC3    | Sí          | No        | No        | No    | SCK/SCL   | No             | SPI/I2C reloj |
| 16         | RC4    | Sí          | No        | No        | No    | SDI/SDA   | No             | SPI/I2C datos |
| 17         | RC5    | Sí          | No        | No        | No    | SDO       | No             | SPI dato salida |
| 18         | RC6    | Sí          | No        | No        | TX    | No        | No             | UART TX |
| 19         | RC7    | Sí          | No        | No        | RX    | No        | No             | UART RX |
| 20         | RB0    | Sí          | AN12      | No        | No    | No        | **INT**        | Interrupción externa |
| 21         | RB1    | Sí          | AN10      | No        | No    | No        | IOC           | Interrupt‐on‐change |
| 22         | RB2    | Sí          | AN8       | No        | No    | No        | IOC           | Interrupt‐on‐change |
| 23         | RB3    | Sí          | AN9       | No        | No    | No        | IOC           | **PGM si LVP=ON (bloqueado)** |
| 24         | RB4    | Sí          | AN11      | No        | No    | No        | IOC           | Interrupt-on-change |
| 25         | RB5    | Sí          | AN13      | No        | No    | No        | IOC           | Interrupt-on-change |
| 26         | RB6    | Sí          | No        | No        | No    | No        | IOC           | También PGC programación |
| 27         | RB7    | Sí          | No        | No        | No    | No        | IOC           | También PGD programación |
| 28         | MCLR   | No          | No        | No        | No    | No        | No            | Reset / VPP |

#### Entradas y Salidas Digitales (GPIO)
Nombre                                | Descripcion
------------------------------------|------------------------------------------------------
`pinMode(pin, modo)`   | Configura un pin como entrada o salida digital.
`digitalWrite(pin, valor)`               | Envía un nivel lógico alto o bajo (1 o 0) a un pin configurado como salida.
`digitalRead(pin)`                | Lee el estado lógico (1 o 0) de un pin configurado como entrada.
`portWrite(puerto, valor)`          | Envía un valor binario (0–255) a un puerto completo (ej. PORTB).
`portRead(puerto)`               | Lee el valor binario presente en un puerto completo.

```v
import port //Configuracion

// Configurar RB0 como salida y RB1 como entrada
port.setup(port.b0, port.output)
port.setup(port.b1, port.input)

for {
    if port.read(port.b1) == 1 {      // Si la entrada RB1 está en alto
        port.write(port.b0, 1)       // Encender salida RB0
    } else {
        port.write(port.b0, 0)       // Apagar salida RB0
    }
}
```

#### Conversor Analógico a Digital (ADC)
Nombre                                | Descripcion
------------------------------------|------------------------------------------------------
`adcInit(canal)`                 | Inicializa el ADC y selecciona el canal analógico a leer.
`adcRead(canal)`                         | Realiza la conversión y devuelve el valor digital (0–1023 para 10 bits).

```v
import adc //Configuracion
import port
import time

adc.setup(0) // Canal AN0

for {
    value := adc.read(0)  // Leer valor ADC (0-1023)
    port.write(port.b, value >> 2)  // Escalar a 8 bits y mostrar en PORTB
    time.sleep_ms(100)
}
```

#### Modulación por Ancho de Pulso (PWM)
Nombre                                | Descripcion
------------------------------------|------------------------------------------------------
`pwmWrite(canal, ciclo`     | Ajusta el ciclo de trabajo (duty cycle) entre 0 y 1023 (para 10 bits).
`pwmInit(canal, frecuencia`                      |Configura un canal PWM con la frecuencia deseada. 
`pwmStop(canal)`                | Detiene la generación de señal PWM en el canal especificado.

```v
import pwm //configuracion
import time

pwm.setup(1, 500) // Canal 1, frecuencia 500 Hz

for duty := 0; duty < 1024; duty += 10 {
    pwm.write(1, duty)     // Ajustar ciclo de trabajo (0-1023)
    time.sleep_ms(10)
}
```

#### Comunicación Serial (USART)
Nombre                                | Descripcion
------------------------------------|------------------------------------------------------
`serialBegin(baudrate`                               | Inicializa la comunicación serial con la velocidad indicada (por ejemplo, 9600 bps).
`serialWrite(dato)`                      | Envía un byte de datos por el puerto serial.
`serialRead()`                  | Lee un byte de datos recibido por el puerto serial. 
`serialAvailable()`                               | Indica si hay datos disponibles para leer.


```v
import serial //Configuracion
import time

serial.begin(9600) // Velocidad de comunicación 9600 bps

for {
    serial.write("Hola PIC16F886!\n")
    time.sleep_ms(1000)
}
```

### Ejemplo de las funciones de la API en lenguaje _Aixt_v 

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

## Configuración de un pin individual 

```v

import port

// Configurar RB0 como salida
port.setup(port.b0, port.output)

// Configurar RB1 como entrada
port.setup(port.b1, port.input)
```
## Configuración de un Puerto Completo

```v
import port

// Configurar todos los pines del puerto B como salidas
port.setup(port.b, port.all_outputs)

```
## Configuración Combinada de Bits

```v
import port

// 1 = salida, 0 = entrada
// Ejemplo: 0b11110000 -> RB7..RB4 salidas, RB3..RB0 entradas
port.setup_mask(port.b, 0b11110000)

```