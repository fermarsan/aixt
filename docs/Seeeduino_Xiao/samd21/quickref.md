# **Guia Rapida Seeeduino Xiao**
Esta implementación de Aixt para dae soporte a la tarjeta SAMD21.

## Resumen
* *SAMD21, tiene 14 PIN, que se pueden usar para 11 interfaces digitales, 11 interfaces simuladas, 10 interfaces PWM (d1-d10), 1 pin de salida DAC D0, 1 interfaz de pad SWD, 1 interfaz I2C, 1 interfaz SPI, 1 Interfaz UART, Indicador de comunicación serial (T/R), Luz parpadeante (L) mediante multiplexación de pines. Los colores de los LED (Power,L,RX,TX) son verde, amarillo, azul y azul. Además, Seeed Studio XIAO SAMD21 tiene una interfaz tipo C que puede suministrar energía y descargar código. Hay dos botones de reinicio, puedes conectarlos brevemente para reiniciar la placa.La definició de pines esta descrita en la tala de* Identificación de Pines.
 
![Alt text](Picture/Seeeduino_XIAO_SAMD21.jpg)

## Datasheet
[Seeeduino Xiao SAMD21](https://files.seeedstudio.com/wiki/XIAO/Seeed-Studio-XIAO-Series-SOM-Datasheet.pdf)

## Identificación de Pines
Below are the ports used and their proper designations for programming:

Pin No. |Nombre                  | Función 
--      |-----                   |---
0       |D0-A0-DAC-QT0           | Analogo; Digital; Convertidor Analogo Digital;            Circuito integrado para botón capacitivo 
1       |D1-A1-QT1               | Analogo; Digital;                                         Circuito integrado para botón capacitivo  
2       |D2-A2                   | Analogo; Digital; 
3       |D3-A3                   | Analogo; Digital; 
4       |D4-A4-SDA(I2C)          | Analogo; Digital; Protocolo control de dispositivos(Transmisión de datos)
5       |D5-A5-SCL(I2C)          | Analogo; Digital; Protocolo control de dispositivos(Envio sincronismos de reloj) 
6       |D6-A6-TX-QT2            | Analogo; Digital; Comunicación Serial(Transmisor);        Circuito integrado para botón capacitivo
7       |D7-A7-RX-QT3            | Analogo; Digital; Comunicación Serial(Receptor);          Circuito integrado para botón capacitivo
8       |D8-A8-SCK(SPI)-QT4      | Analogo; Digital; Reloj serial;                           Circuito integrado para botón capacitivo
9       |D9-A9-MISO(SPI)-QT5     | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
10      |D10-A10-MOSI(SPI)-QT6   | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
11      |3.3V                    | Alimentación de Microcontrolador 
12      |GND                     | Tierra Común
13      |5V                      | Alimentación de la Placa 

## Programación en Lenguaje V

Las funciones que contiene la API entradas o salidas digitales y para realizar una conversión analogico a digital.

Nombre                  | Descripción
------------------------|------------------------------
`pin_setup(pin, mode)`  | Configura `pin`como `mode` (input, out)
`pin_high(pin)`         | Salida Digital en alto `pin`
`pin_low(pin)`          | Salida Digital en bajo `pin`
`pin_write(pin, val)`   | Escribe `val` en `pin`
`pin_read(pin)`         | Entrada digital `pin`
`adc_read(pin)`         | Lectura analogica `pin` para el `adc`
`pwm_write(pin, val)`   | Salida `pin` y un ciclo util de `val`
`uart_setup(baund_rate)`| Iniciación Comunicacón Serial a `Baund_rate`
`uart_read()`           | Lectura de Comunicacón Serial a ``
`println(message)`      | Imprime  `message` a traves Comunicacón Serial
`sleep(time)`           | Retardo en `seg`
`sleep_us(time)`        | Retardo en `microseg`
`sleep_ms(time)`        | Retardo en `miliseg`

### EJEMPLOS
#### Parpadeo de un LED
```go
pin_mode(5, out)

for i in 0..10{   //10 veces
    pin_high(5)
    sleep_ms(500)
    pin_low(5)
    sleep_ms(500)
}
```

#### Ejemplo lectura analoga

```go

pin_setup(2, out)
pin_setup(3, out)
pin_setup(4, out)
for {
    if( adc_read(8)>=1017 ){

        pin_high(2)
        pin_high(3)
        pin_high(4)

    }
    else if( adc_read(8)>=750 ){

        pin_high(2)
        pin_high(3)
        pin_low(4)
        
    }
    else if( adc_read(8)>=480 ){

        pin_high(2)
        pin_low(3)
        pin_low(4)
        
    }
    else {

        pin_low(2)
        pin_low(3)
        pin_low(4)
        
    }
    } 
```

#### Ejemplo salida PWM
```go

pin_setup(5, out)
int util=0

for {
    pwm_write(5, util)
    sleep_ms(250)
    util=util+10
    if (util==250){

        util=0
        
    }
    } 
```

#### Encender un LED con u pulsador
```go
pin_mode(3, out)

for {   //infinite loop
    pin_high(5)
    sleep_ms(500)
    pin_low(5)
    sleep_ms(500)
}
```

### Configuración Pines de Salida

To activate the port to use
```go
pin_high(pin_name)
```
* *Example: If you want to activate the port IO17;  `pin_high(IO17)`.*

To disable the port being used
```go
pin_low(pin_name)
```
* *Example: If you want to disable the port IO17;  `pin_low(O17I)`.*

To disable or enable the port to be used

```go
pin_write(pin_name, value)
```
* *Example: If you want to disable port IO17 `pin_write(IO17, 1)`, and if you want to activate  `pin_write(IO17, 0)`.*

### Input port detection

If you need to know what state an entry port is in:
```go
x = pin_read(pin_name)
```

* *Example: If you want to detect the value of port IO3; `x = pin_read(IO17)`, and `x` will take the value of 0 or 1, depending on which port is active or disabled.*

### Analog to digital ports (ADC)

To configure one of the analog ports
```go
adc_setup(channel, setup_value_1, ... )
```
* *In channel the name of the analog port is entered, in setup_value_1 the value that will be given is said port.*

To detect the analog port value
```go
x = adc_read(channel)
```
* *In `channel` the name of the analog port is entered, and `x` takes the value of said port..*

### Pulse Width Modulation (PWM outputs)

To configure some PWM
```go
pwm_setup(setup_value_1, setup_value_2, ... )
```
* *In pwm you set the PWM to use, and in setup_value_1 the value to which you want to configure said pwm.*


To configure the duty cycle of a modulator
```go
pwm_duty(duty)
```
* *In PWM the pwm to be used is set, and in `duty` the value of the cycle (from 0 to 100) in percentage.*

### Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

#### UART setup

```v
uart_setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

### Serial transmitting
```v
print(message)      // print a string to the default UART
```
```v
println(message)    // print a string plus a line-new character to the default UART
```
```v
uart2_print(message)    // print a string to the UART2
```
```v
uart1_println(message)  // print a string plus a line-new character to the UART1
```
```v
uart2_write(message)    // send binary data (in Bytes) to UART2
```

### Retardos

* Use of times

    * In each expression, the time value is put inside the parentheses.
```go
sleep(s) //Seconds
```
```go
sleep_ms(ms) //Milliseconds
```
```go
sleep_us(us) //Microseconds
```

* Example flashing LED

```go
import machine { pin }
import time { sleep_ms }

pin_mode(IO14, out)

for {   //infinite loop
    pin_high(IO14)
    sleep_ms(500)
    pin_low(IO14)
    sleep_ms(500)
}
```