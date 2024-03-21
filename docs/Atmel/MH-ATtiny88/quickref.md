#  **QUICK GUIDE MH-ATTINY88**

Implementation of Aixt to support the ATtiny88 card.

## Resumen 

* The ATtiny88 microcontroller is a small, high performance AVR microcontroller using a RISC processor. This microcontroller comes in two packages that are mainly used for interfacing and control between different sensors and devices.

* This microcontroller is available with low power consumption through MSSP and 10-bit ADC. The instruction code of this microcontroller can be stored through SRAM - 512 bytes and EEPROM - 64 bytes, manufactured by Micro Ship Tecnologic.

## Las funciones:

* El microcontrolador ATtiny88 realiza varias funciones en un solo circuito integrado. Algunos pines del microcontrolador están disponibles con la capacidad de usar la función anterior. Algunas de las funciones principales de este microcontrolador incluyen temporizadores, comunicación SPI, comunicación I2C, BOD (Brown Out Reset), interrupción y ADC. Este microcontrolador ATtiny88 incluye diferentes memorias como FLASH, EEPROM y SRAM.

* El Atmel® ATtiny88 es un microcontrolador CMOS de 8 bits de bajo consumo basado en la arquitectura RISC mejorada AVR®. Al ejecutar instrucciones potentes en un solo ciclo de reloj, el Atmel ATtiny88 alcanza rendimientos cercanos a 1MIPS por MHz, lo que permite al diseñador del sistema optimizar el consumo de energía frente a la velocidad de procesamiento.


## Caracteristicas:

------------------------------------------

![Alt text](picture/MH-ATtiny88.jpg)

## Hoja de datos
[ATtiny88](https://ww1.microchip.com/downloads/en/DeviceDoc/atmel-9157-automotive-microcontrollers-attiny88_datasheet.pdf)

## Identificación de pines 

Descripción de pines y su desiganación:

|PIN NO.  | NOMBRE | FUNCIÓN |
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
|17       |D17,A6  |DIGITAL PIN,convertidor analógico-digital|
|18       |D18,A7  |DIGITAL PIN,convertidor analógico-digital|
|19       |D19,A0  |DIGITAL PIN,convertidor analógico-digital|
|20       |D20,A1  |DIGITAL PIN,convertidor analógico-digital|
|21       |D21,A2  |DIGITAL PIN,convertidor analógico-digital|
|22       |D22,A3  |DIGITAL PIN,convertidor analógico-digital|
|23       |D23,A4  |DIGITAL PIN,convertidor analógico-digital,SDA|
|24       |D24,A5  |DIGITAL PIN,convertidor analógico-digital,SCL|
|25       |D25     |DIGITAL PIN|
|         |RST     |RESET|
|         |VIN     |ALIMENTACION: VIN 7-12V|
|         |5V      |ALIMENTACION: 5V|
|         |GND     |TIERRA |

         
## CONFIGURACION PUERTOS LECTURA ANALOGA

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

## PROGRAMACIÓN EL LENGUAJE V

Las funciones descriptivas que contiene la API como entradas o salidas que realizan una conversión analogíca y digital:


Nombre                  | Descripción
------------------------|------------------------------
pin_setup(pin, mode)    | Configura pin`como `mode (input, out)
pin_high(pin)           | Salida Digital en alto pin
pin_low(pin)            | Salida Digital en bajo pin
pin_write(pin, val)     | Escribe val en pin
pin_read(pin)           | Entrada digital pin
adc_read(pin)           | Lectura analogica pin para el adc
pwm_write(pin, val)     | Salida pin y un ciclo util de val
uart_setup(baund_rate)  | Iniciación Comunicacón Serial a Baund_rate
uart_read()             | Lectura de Comunicacón Serial a ``
println(message)        | Imprime  message a traves Comunicacón Serial
sleep(time)             | Retardo en seg
sleep_us(time)          | Retardo en microseg
sleep_ms(time)          | Retardo en miliseg

##EJEMPLOS DE CÓDIGO 

** PRUEBA PIN 3 Y 0, GENERAL PROPOUSE INPUT OUTPUT


## EJEMPLOS

### ENCENDER UN LED

### PARPADEO UN LED

### LECTURA DIGITAL 

### LECTURA ANALOGA

### SALIDA PWM

### COMUNICACION SERIAL
