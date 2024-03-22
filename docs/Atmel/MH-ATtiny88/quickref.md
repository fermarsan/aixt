#  **QUICK GUIDE MH-ATTINY88**

Implementation of Aixt to support the ATtiny88 card.

## SUMMARY 

* The ATtiny88 microcontroller is a small, high performance AVR microcontroller using a RISC processor. This microcontroller comes in two packages that are mainly used for interfacing and control between different sensors and devices.

* This microcontroller is available with low power consumption through MSSP and 10-bit ADC. The instruction code of this microcontroller can be stored through SRAM - 512 bytes and EEPROM - 64 bytes, manufactured by Micro Ship Tecnologic.

## THE FUNCTIONS:

* The ATtiny88 microcontroller performs several functions on a single integrated circuit. Some pins of the microcontroller are available with the ability to use the above function. Some of the main functions of this microcontroller include timers, SPI communication, I2C communication, BOD (Brown Out Reset), interrupt and ADC. This ATtiny88 microcontroller includes different memories such as FLASH, EEPROM and SRAM.
  
* The Atmel® ATtiny88 is a low-power 8-bit CMOS microcontroller based on the AVR® enhanced RISC architecture. By executing powerful instructions in a single clock cycle, the Atmel ATtiny88 achieves performances close to 1MIPS per MHz, allowing the system designer to optimize power consumption versus processing speed.


## FEATURES:

Características:  

* Velocidad de reloj: 16Mhz (Número de ciclos que ejecuta la CPU por segundo). 
* Voltaje de alimentación: 5V por micro USB, 7-12V pin VIN. 
* 26 pines de entrada/salida (2 exclusivamente para USB).  
* 26 pines de input/output para PWM por software/ 2 de ellas PWM(modulación por ancho de pulsos) por hardware (D9-D10). 
* 8 entradas analógicas (Las entradas analógicas son terminales o pines en un microcontrolador que permiten la entrada de
  señales analógicas, un rango de señal de varios valores). 
*Interfaz 12c y SPI (La Interfaz de Comunicación en Serie (SPI) y el Inter-Integrated Circuit (I2C) son dos protocolos de comunicación en 
 serie comunes utilizados en la electrónica. Ambos protocolos permiten que varios dispositivos se comuniquen entre sí y con un 
 microcontrolador o procesador.). 
* Led de PWR y led Builtin o prueba “Pin 0”. 
* Botón reset.  
* Microcontrolador AVR® de 8 bits de alto rendimiento y bajo consumo. 
* Grado de velocidad: 0 a 8Mhz a 2.7-5.5V, 0 a 16 Mhz en 4.5-5.5V.
* Bajo consumo de energía: modo activo: 8Mhz en 5V-4.4mA, modo suspendido: en 5V-6microA. 
* Arquitectura RISC avanzada. 
* 123 potentes instrucciones - la mayoría de ejecución en un solo ciclo de reloj. 
* 32 x 8 registros de trabajo de propósito general. 
* Funcionamiento totalmente estático. 
* Segmentos de memoria no volátil de alta resistencia. 
* 8K bytes de memoria de programa flash autoprogramable en el sistema(ATtiny88) se refiere a la capacidad de almacenamiento de la memoria 
  de programa flash en un dispositivo electrónico. 
* 64 bytes de EEPROM(Electrically Erasable Programmable Read-Only Memory). 
* 512 bytes de SRAM interna (Static Random-Access Memory o Memoria de Acceso Aleatorio Estático). 
* Ciclos de escritura/borrado: 10.000 Flash/100.000 EEPROM. 
* Bloqueo de programación para seguridad del software. 
* Características periféricas. 
* Un temporizador/contador de 8 bits con preescalador independiente y modo de comparación. 
* Un temporizador/contador de 16 bits con preescalador y modos de comparación y captura. 
* ADC de 8 canales y 10 bits en encapsulado TQFP de 32 terminales y QFN de 32 terminales. 
* Interfaz serie SPI maestro/esclavo. 
* Interfaz serie de 2 hilos orientada a bytes (Phillips I2C compatible). 
* Temporizador de vigilancia programable con oscilador independiente en chip. 
* Comparador analógico en chip. 
* Interrupción y activación por cambio de pin.
* Características especiales del microcontrolador. 
* Sistema de depuración en chip debugWIRE. 
* Programable en el sistema a través del puerto SPI. 
* Restablecimiento de encendido y detección de caída de tensión programable. 
* Oscilador interno calibrado. 
* Fuentes de interrupción externas e internas. 
*Tres modos de suspensión: Reposo, reducción de ruido ADC y apagado. 
* E/S y paquetes. 
* 28 líneas de E/S programables en encapsulado TQFP de 32 terminales y QFN de 32 terminales. 
* Tensión de funcionamiento: 2.7- 5.5V. 
* Rango de temperatura de automoción: -40°C a +125°C. 


![Alt text](picture/MH-ATtiny88.jpg)


Retrieved from: [ATtiny88 data sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/atmel-9157-automotive-microcontrollers-attiny88_datasheet.pdf)

## DATA SHEET
[ATtiny88](https://ww1.microchip.com/downloads/en/DeviceDoc/atmel-9157-automotive-microcontrollers-attiny88_datasheet.pdf)

## PIN IDENTIFICATION

Description of pins and their designation:

|PIN NO.  | NAME | FUNCTION |
|---------|--------|---------|
|0        |D0      |DIGITAL PIN, LED 0|
|1        |D1      |DIGITAL PIN|
|2        |D2      |DIGITAL PIN|
|3        |D3      |DIGITAL PIN|
|4        |D4      |DIGITAL PIN|
|5        |D5      |DIGITAL PIN|
|6        |D6      |DIGITAL PIN|
|7        |D7      |DIGITAL PIN|
|8        |D8      |DIGITAL PIN|
|9        |D9      |DIGITAL PIN|
|10       |D10     |DIGITAL PIN,SS|
|11       |D11     |DIGITAL PIN,MOSI|
|12       |D12     |DIGITAL PIN,MISO|
|13       |D13     |DIGITAL PIN,SCK|
|14       |D14     |DIGITAL PIN|
|15       |D15     |DIGITAL PIN|
|16       |D16     |DIGITAL PIN|
|17       |D17,A6  |DIGITAL PIN, analog-to-digital converter|
|18       |D18,A7  |DIGITAL PIN, analog-to-digital converter|
|19       |D19,A0  |DIGITAL PIN, analog-to-digital converter|
|20       |D20,A1  |DIGITAL PIN, analog-to-digital converter|
|21       |D21,A2  |DIGITAL PIN, analog-to-digital converter|
|22       |D22,A3  |DIGITAL PIN, analog-to-digital converter|
|23       |D23,A4  |DIGITAL PIN, analog-to-digital converter,SDA|
|24       |D24,A5  |DIGITAL PIN, analog-to-digital converter,SCL|
|25       |D25     |DIGITAL PIN|
|         |RST     |RESET|
|         |VIN     |POWER SUPPLY: VIN 7-12V|
|         |5V      |POWER SUPPLY: 5V|
|         |GND     | GROUND |

         
## ANALOG READOUT PORT CONFIGURATION

|PIN NO.  | NOMBRE | DECLARACION |
|---------|--------|-------------|
|17       |A6      | 1|
|18       |A7      | 2|
|19       |A0      |-5|
|20       |A1      |-4|
|21       |A2      |-3|
|22       |A3      |-2|
|23       |A4      |-1|
|24       |A5      | 0|

## PROGRAMMING LANGUAGE V

The descriptive functions contained in the API as inputs or outputs that perform analog-to-digital conversion:


NAME               | DESCRIPTION
------------------------|------------------------------
`pin.setup(pin, mode)`    | Configure pin like `mode (input, out)`
`pin.high(pin)`           | Digital output on `high pin`
`pin.low(pin)`           | Digital output on `low pin`
`pin.write(pin, val)`     | Type val in `pin`
`pin.read(pin)`           | Digital input `pin`
`adc.read(pin)`           | Analog pin readout for adc
`pwm.write(pin, val)`     | Output pin and a useful val cycle
`uart.setup(baund_rate)`  | Initiation Serial Communication to Baund_rate
`uart.read()`             | Serial Communication Reading
`println(message)`        | Print message via Serial Communication
`time.sleep(time)`             | delay in `S`
`time.sleep_us(time)`          | delay in `uS`
`time.sleep_ms(time)`          | delay in `mS`
`pin.input`    | Parameter `mode` input configuration 
`pin.output`    | Parameter `mode` output configuration 
`uart.any()` |	Get the number of bytes to read



## The following table will present equivalences between the native functions of the compiler in contrast to those implemented in the Aixt project, with the central idea being to redefine these functions and offer standardized support.


DEFINITION AIXT	 | DEFINITION ARDUINO
-----------------|-----------------------------
`adc__read(PIN_NAME)`|    	analogRead(PIN_NAME)
`pin__high(PIN_NAME)`| 		digitalWrite(PIN_NAME, HIGH)
`pin__low(PIN_NAME)`|        	digitalWrite(PIN_NAME, LOW)
`pin__output`| 				OUTPUT
`pin__input`|	INPUT
`pin__input_pullup	INPUT_PULLUP`|
`pin__read(PIN_NAME)`|   	digitalRead(PIN_NAME)
`pin__setup(PIN_NAME, MODE)`|        	pinMode(PIN_NAME, MODE)
`pin__write(PIN_NAME, VALUE)`|  	digitalWrite(PIN_NAME, VALUE)
`pwm__write(PIN, VALUE)`|   	analogWrite(PIN, VALUE)
`time__sleep_ms(MS)`|  	delay(MS)
`time__sleep_us(US) `|  	delayMicroseconds(US)
`time__sleep(S)`|	delay(S*1000)
`uart__any_0()`|		Serial.available()
`uart__any_1()`|		Serial1.available()
`uart__any_x(UART_NUMBER)	uart__any ## UART_NUMBER ##`| serial.available()
`uart__print_0(MESSAGE)`|		Serial.print(MESSAGE)
`uart__print_1(MESSAGE)`|		Serial1.print(MESSAGE)
`uart__println_0(MESSAGE)`|		Serial.println(MESSAGE)
`uart__println_1(MESSAGE)`|		Serial1.println(MESSAGE)
`uart__read_0()`|		Serial.read()
`uart__read_1()`|		Serial1.read()
`uart__setup(BAUD_RATE)`|   	Serial.begin(BAUD_RATE)
    *Table of equivalences between functions




## CODE SAMPLES

Addition of V language examples which can be implemented in the Aixt project for testing and translation:

### BLINK OF LED

Flashing of one LED in an infinite cycle with time delay:

```go
import time { sleep_ms }  // import the time module from the API
import pin				        // import the pin module from the API

pin.setup(1, pin.output)  // configures pin number 1 as output 

for {                     //main loop of the code 
	pin.high(1)			        //pin high
	sleep_ms(500)	  	      //delay in seconds 
	pin.low(1)			        //pin low
	sleep_ms(500)		        //delay in seconds
}
```
### DIGITAL READOUT

Example of digital readout, led sequence:

```go
import time {sleep_ms}          // import the sleep_ms function of the time module 
import pin 			                // Import the pin module in its entirety

pin.setup(14, pin.output)    	// Set pin #14 as output
pin.setup(15, pin.output)    	// Set pin #15 as output
pin.setup(16, pin.output)    	// Set pin #16 as output

for{
    pin.high(14)  		  // output 14 high   
    sleep_ms(2000) 		  // delay of 2000 ms
    pin.low(14)   		  // output 14 low
    pin.high(15)     		// output 15 high
    sleep_ms(2000) 		  // delay of 2000 ms 	
    pin.low(15)   	  	// output 15 low
    pin.high(16)     		// output 16 high 
    sleep_ms(2000)   		// retardo de 2000 ms
    pin.low(16) 		    // output 15 baja
}
```
### ANALOG AND DIGITAL READOUT

In this example we will test the analog and digital readings through the flashing of a LED that depends on the variation of a variable resistor:
```go
import pin                            // Importa el módulo pin en su totalidad
import adc                            // Importa el módulo adc en su totalidad
import pwm                            // Importa el módulo pwm en su totalidad

__global (
    brillo = 0                        // crea una variable global
    )
   


for{                                    // crea el ciclo
  brillo=adc.read(-5)                    //lee la entrada anologa digital
    pwm.write(3,brillo)                   //escribe la salida pwm
}

```


### SERIAL COMMUNICATION

Test UART communication with counter increasing if switch is pressed:

```go

import pin             //import the module pin from API
import uart            //import the module uart from API
  
__global(
button:=0              //defined global variable initialized to 0
        )


for {                   //for loop that executes the main code

	if pin.read(3) == 1  
	{ 
		button=button+1 
		uart.print(button)
	}
}
