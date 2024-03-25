# GUÍA RÁPIDA MH-ATTINY88
Implementación de Aixt para soportar la tarjeta MH-ATtiny88.

## RESUMEN
* El microcontrolador ATtiny88 es un microcontrolador AVR de alto rendimiento y tamaño reducido que utiliza un procesador RISC. Este microcontrolador viene en dos paquetes que se utilizan principalmente para la interfaz y el control entre diferentes sensores y dispositivos.

* Este microcontrolador está disponible con bajo consumo de energía a través de MSSP y ADC de 10 bits. El código de instrucción de este microcontrolador puede almacenarse a través de SRAM - 512 bytes y EEPROM - 64 bytes, fabricado por Micro Ship Tecnologic.

* Dispositivo diseñado para aplicaciones integradas. Está basado en la arquitectura AVR de 8 bits y cuenta con una amplia gama de periféricos integrados, incluidos puertos GPIO, interfaces de comunicación serial, temporizadores y convertidores analógico-digital. El MH-AT-tiny88 es adecuado para una variedad de aplicaciones, desde sistemas de control básicos hasta dispositivos portátiles y sensores IoT debido a su combinación de tamaño compacto, bajo consumo de energía y funcionalidad versátil.

## LAS FUNCIONES:
* El microcontrolador ATtiny88 realiza varias funciones en un solo circuito integrado. Algunos pines del microcontrolador están disponibles con la capacidad de utilizar la función mencionada anteriormente. Algunas de las principales funciones de este microcontrolador incluyen temporizadores, comunicación SPI, comunicación I2C, BOD (Restablecimiento por caída de voltaje), interrupción y ADC. Este microcontrolador ATtiny88 incluye diferentes memorias como FLASH, EEPROM y SRAM.

* El Atmel® ATtiny88 es un microcontrolador CMOS de 8 bits de bajo consumo de energía basado en la arquitectura RISC mejorada AVR®. Al ejecutar instrucciones potentes en un solo ciclo de reloj, el Atmel ATtiny88 logra un rendimiento cercano a 1MIPS por MHz, lo que permite al diseñador del sistema optimizar el consumo de energía versus la velocidad de procesamiento.

## CARACTERÍSTICAS:
* Velocidad de reloj: 16 MHz (Número de ciclos que la CPU ejecuta por segundo).
* Voltaje de alimentación: 5V a través de micro USB, 7-12V en el pin VIN.
* 26 pines de entrada/salida (2 exclusivamente para USB).
* 26 pines de entrada/salida para PWM de software / 2 de ellos PWM (modulación de ancho de pulso) por hardware (D9-D10).
* 8 entradas analógicas (Las entradas analógicas son terminales o pines en un microcontrolador que permiten la entrada de señales analógicas, un rango de señal de varios valores).
* Interfaz I2C y SPI (La Interfaz de Comunicación Serial (SPI) y el Circuito Integrado Inter-Interfaz (I2C) son dos protocolos de comunicación serial comunes utilizados en electrónica. Ambos protocolos permiten que múltiples dispositivos se comuniquen entre sí y con un microcontrolador o procesador).
* PWR LED de alimentación y LED incorporado o prueba "Pin 0".
* Botón de reinicio.
* Microcontrolador AVR® de 8 bits con alto rendimiento y bajo consumo de energía.
* Rango de velocidad: 0 a 8 MHz a 2.7-5.5V, 0 a 16 MHz a 4.5-5.5V.
* Bajo consumo de energía: modo activo: 8MHz a 5V-4.4mA, modo de suspensión: a 5V-6 microA.
* Arquitectura RISC avanzada.
* 123 instrucciones potentes, la mayoría se ejecutan en un solo ciclo de reloj.
* 32 x 8 registros de trabajo de propósito general.
* Operación totalmente estática.
* Segmentos de memoria no volátil de alta resistencia.
* 8K bytes de memoria de programa de flash auto-programable en el sistema (ATtiny88) se refiere a la capacidad de almacenamiento de la memoria de programa de flash en un dispositivo electrónico.
* 64 bytes de EEPROM (Memoria de solo lectura programable eléctricamente).
* 512 bytes de SRAM interna (Memoria de acceso aleatorio estática).
Ciclos de escritura/borrado: 10,000 Flash/100,000 EEPROM.
* Bloqueo de programación para seguridad de software.
Características periféricas.
* Un temporizador/contador de 8 bits con preescalador independiente y modo de comparación.
* Un temporizador/contador de 16 bits con preescalador y modos de comparación y captura.
* Un ADC de 8 canales y 10 bits en paquetes TQFP de 32 terminales y QFN de 32 terminales.
* Interfaz maestro/esclavo serial SPI.
* Interfaz serial de 2 cables orientada a bytes (compatible con Phillips I2C).
* Temporizador de vigilancia programable con oscilador independiente en el chip.
* Comparador analógico en el chip.
* Interrupción y activación por cambio de pin.
* Características especiales del microcontrolador.
* Sistema de depuración en chip debugWIRE.
* Programable en el sistema a través del puerto SPI.
* Restablecimiento de encendido programable y detección de caída de voltaje.
* Oscilador interno calibrado.
* Fuentes de interrupción externas e internas.
* Tres modos de suspensión: Suspensión, reducción de ruido del ADC y apagado.
* E/S y paquetes.
* 28 líneas de E/S programables en paquetes TQFP de 32 pines y QFN de 32 pines.
* Voltaje de funcionamiento: 2.7-5.5V.
Rango de temperatura automotriz: -40°C a +125°C.

## CONFIGURACIÓN DE PINES Y SUS FUNCIONES RESPECTIVAS

![Alt text](picture/MH-ATtiny88.jpg)

Obtenido de: [ATtiny88 data sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/atmel-9157-automotive-microcontrollers-attiny88_datasheet.pdf)

## DATA SHEET
[MH-ATtiny88](https://ww1.microchip.com/downloads/en/DeviceDoc/atmel-9157-automotive-microcontrollers-attiny88_datasheet.pdf)

## IDENTICACION DE PINES

Descripción de los pines y su designación:

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
|17       |D17, A6  |DIGITAL PIN, analog-to-digital converter|
|18       |D18, A7  |DIGITAL PIN, analog-to-digital converter|
|19       |D19, A0  |DIGITAL PIN, analog-to-digital converter|
|20       |D20, A1  |DIGITAL PIN, analog-to-digital converter|
|21       |D21, A2  |DIGITAL PIN, analog-to-digital converter|
|22       |D22, A3  |DIGITAL PIN, analog-to-digital converter|
|23       |D23, A4  |DIGITAL PIN, analog-to-digital converter,SDA|
|24       |D24, A5  |DIGITAL PIN, analog-to-digital converter,SCL|
|25       |D25     |DIGITAL PIN|
|         |RST     |RESET|
|         |VIN     |POWER SUPPLY: VIN 7-12V|
|         |5V      |POWER SUPPLY: 5V|
|         |GND     | GROUND |

## Configuración de los Puerto de Lectura Analógica

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

## PROGRAMACION EN LENGUAJE V

Las funciones descriptivas contenidas en la API como entradas o salidas que realizan la conversión analógico a digital:

NAME               | DESCRIPTION
------------------------|------------------------------
`pin.setup(pin, mode)`    | Configurar pin como: `mode (input, out)`
`pin.high(pin)`           | Salida digital On `high pin`
`pin.low(pin)`           | Salida digital Off`low pin`
`pin.write(pin, val)`     | ingresar el valor en `pin`
`pin.read(pin)`           | Entrada digital `pin`
`adc.read(pin)`           | Lectura de pin analógico para ADC
`pwm.write(pin, val)`     | Pin de salida y un ciclo de valor útil
`uart.setup(baund_rate)`  | Inicio de comunicación serial
`uart.read()`             | Lectura de Comunicación Serial
`println(message)`        | Imprimir mensaje a través de la Comunicación Serial
`time.sleep(time)`             | retardo en `S`
`time.sleep_us(time)`          | retardo en `uS`
`time.sleep_ms(time)`          | retardo en `mS`
`pin.input`    | Parametros `mode` configuracion de entrada 
`pin.output`    | parametros `mode` configuracion de salida 
`uart.any()` |	Obtener el número de bytes para leer

* La siguiente tabla presentará las equivalencias entre las funciones nativas del compilador en contraste con aquellas implementadas en el proyecto Aixt, con la idea central de redefinir estas funciones y ofrecer soporte estandarizado.

DEFINITION AIXT	 | DEFINITION ARDUINO
-----------------|-----------------------------
`adc__read(PIN_NAME)`|    	`analogRead(PIN_NAME)`
`pin__high(PIN_NAME)`| 		`digitalWrite(PIN_NAME, HIGH)`
`pin__low(PIN_NAME)`|        	`digitalWrite(PIN_NAME, LOW)`
`pin__output`| 				`OUTPUT`
`pin__input`|	`INPUT`
`pin__input_pullup	INPUT_PULLUP`|
`pin__read(PIN_NAME)`|   	`digitalRead(PIN_NAME)`
`pin__setup(PIN_NAME, MODE)`|        	`pinMode(PIN_NAME, MODE)`
`pin__write(PIN_NAME, VALUE)`|  	`digitalWrite(PIN_NAME, VALUE)`
`pwm__write(PIN, VALUE)`|   	`analogWrite(PIN, VALUE)`
`time__sleep_ms(MS)`|  	`delay(MS)`
`time__sleep_us(US) `|  	`delayMicroseconds(US)`
`time__sleep(S)`|	`delay(S*1000)`
`uart__any_0()`|		`Serial.available()`
`uart__any_1()`|		`Serial1.available()`
`uart__any_x(UART_NUMBER)	uart__any ## UART_NUMBER ##`| `serial.available()`
`uart__print_0(MESSAGE)`|		`Serial.print(MESSAGE)`
`uart__print_1(MESSAGE)`|		`Serial1.print(MESSAGE)`
`uart__println_0(MESSAGE)`|		`Serial.println(MESSAGE)`
`uart__println_1(MESSAGE)`|		`Serial1.println(MESSAGE)`
`uart__read_0()`|		`Serial.read()`
`uart__read_1()`|		`Serial1.read()`
`uart__setup(BAUD_RATE)`|   	`Serial.begin(BAUD_RATE)`
  `  *Table of equivalences between functions`

## ejemplos

* Adición de ejemplos de código en el lenguaje V que pueden implementarse en el proyecto Aixt para pruebas y traducción:

### parpadeo led

Parpadeo de un LED en un ciclo infinito con retraso de tiempo:

```go
import time { sleep_ms }  			// importa (sleep_ms) del modulo time
import pin				        // importa el modulo pin en su totalidad

pin.setup(1, pin.output)  			// configura el pin 1 como salida
for {                     			//crea el void loob
	pin.high(1)			        //pin encendido
	sleep_ms(500)	  	      		//retardo en milisegundos 
	pin.low(1)			        //pin apagado
	sleep_ms(500)		       		 //retardo en milisegundos
}
```
### Secuencia tipo semaforo
```go
import time {sleep_ms}          //importa la funcion sleep_ms de el modulo time   
import pin 			// Importa el módulo pin en su totalidad

pin.setup(14, pin.output)    	// Establece el pin #14 como salida
pin.setup(15, pin.output)    	// Establece el pin #15 como salida
pin.setup(16, pin.output)    	// Establece el pin #16 como salida

for{
    pin.high(14)  		// salida 14 high   
    sleep_ms(2000) 		// retardo de 2000 ms
    pin.low(14)   		// salida 14 baja
    pin.high(15)     		// salida 15 high
    sleep_ms(2000) 		// retardo de 2000 ms 	
    pin.low(15)   		// salida 15 baja
    pin.high(16)     		// salida 16 high 
    sleep_ms(2000)   		// retardo de 2000 ms
    pin.low(16) 		// salida 15 baja
}
```
### LECTURA ANALÓGICA Y DIGITAL

En este ejemplo, probaremos las lecturas analógicas y digitales a través del destello de un LED que depende de la variación de un potenciómetro:
```go
import pin                            // Importa el módulo pin en su totalidad
import adc                            // Importa el módulo adc en su totalidad
import pwm                            // Importa el módulo pwm en su totalidad

__global (
    brillo = 0                        // crea una variable global
    )
   


for{                      // crea el ciclo
  brillo=adc.read(-5)     //lee la entrada anologa digital
    pwm.write(3,brillo)   //escribe la salida pwm
}
```

### comunicacion serial

Prueba de comunicación UART con contador incrementando si se presiona un interruptor:
```go

import pin             //importa en su totalidad el modulo PIN
import uart            //importa el modulo UART
  
__global(
button:=0              //define una variable global y la inicia en 0
        )


for {                   //crea el ciclo

	if pin.read(3) == 1  
	{ 
		button=button+1 
		uart.print(button)
	}
}
```
A continuación, puedes ver un video explicativo de la transcompilación o traducción del proyecto Aixt. Este video trata sobre la prueba de modulación de ancho de pulso o PWM, donde se varía el flujo luminoso de un LED (diodo emisor de luz) mediante la variación de un potenciómetro o resistor variable. Los pines se leen y escriben con función analógico-digital.
 Link Youtube : [ATtiny88 test PWM-ADC](https://youtu.be/aViNecpmvjw)
