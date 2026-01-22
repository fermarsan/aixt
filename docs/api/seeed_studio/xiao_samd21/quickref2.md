# **Guia Rapida Seeeduino Xiao**
Esta implementación de Aixt para dae soporte a la tarjeta SAMD21.

## Resumen
* *SAMD21, tiene 14 PIN, que se pueden usar para 11 interfaces digitales, 11 interfaces simuladas, 10 interfaces PWM (d1-d10), 1 pin de salida DAC D0, 1 interfaz de pad SWD, 1 interfaz I2C, 1 interfaz SPI, 1 Interfaz UART, Indicador de comunicación serial (T/R), Luz parpadeante (L) mediante multiplexación de pines. Los colores de los LED (Power,L,RX,TX) son verde, amarillo, azul y azul. Además, Seeed Studio XIAO SAMD21 tiene una interfaz tipo C que puede suministrar energía y descargar código. Hay dos buttones de reinicio, puedes conectarlos brevemente para reiniciar la placa.La definició de pines esta descrita en la tala de* Identificación de Pines.
 
![Alt text](Picture/Seeeduino_XIAO_SAMD21.jpg)

## Datasheet
[Seeeduino Xiao SAMD21](https://files.seeedstudio.com/wiki/XIAO/Seeed-Studio-XIAO-Series-SOM-Datasheet.pdf)

## Identificación de Pines
Below are the ports used and their proper designations for programming:

| Pin No. | Nombre                | Función                                                                                            |
| ------- | --------------------- | -------------------------------------------------------------------------------------------------- |
| 0       | D0-A0-DAC-QT0         | Analogo; Digital; Convertidor Analogo Digital;            Circuito integrado para botón capacitivo |
| 1       | D1-A1-QT1             | Analogo; Digital;                                         Circuito integrado para botón capacitivo |
| 2       | D2-A2                 | Analogo; Digital;                                                                                  |
| 3       | D3-A3                 | Analogo; Digital;                                                                                  |
| 4       | D4-A4-SDA(I2C)        | Analogo; Digital; Protocolo control de dispositivos(Transmisión de datos)                          |
| 5       | D5-A5-SCL(I2C)        | Analogo; Digital; Protocolo control de dispositivos(Envio sincronismos de reloj)                   |
| 6       | D6-A6-TX-QT2          | Analogo; Digital; Comunicación Serial(Transmisor);        Circuito integrado para botón capacitivo |
| 7       | D7-A7-RX-QT3          | Analogo; Digital; Comunicación Serial(Receptor);          Circuito integrado para botón capacitivo |
| 8       | D8-A8-SCK(SPI)-QT4    | Analogo; Digital; Reloj serial;                           Circuito integrado para botón capacitivo |
| 9       | D9-A9-MISO(SPI)-QT5   | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo |
| 10      | D10-A10-MOSI(SPI)-QT6 | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo |
| 11      | 3.3V                  | Alimentación de Microcontrolador                                                                   |
| 12      | GND                   | Tierra Común                                                                                       |
| 13      | 5V                    | Alimentación de la Placa                                                                           |

## Programación en Lenguaje V

Las funciones que contiene la API entradas o salidas digitales y para realizar una conversión analogico a digital.

| Nombre                   | Descripción                                    |
| ------------------------ | ---------------------------------------------- |
| `pin.setup(pin, mode)`   | Configura `pin`como `mode` (input, out)        |
| `pin.high(pin)`          | Salida Digital en alto `pin`                   |
| `pin.low(pin)`           | Salida Digital en bajo `pin`                   |
| `pin.write(pin, val)`    | Escribe `val` en `pin`                         |
| `pin.read(pin)`          | Entrada digital `pin`                          |
| `adc.read(pin)`          | Lectura analogica `pin` para el `adc`          |
| `pwm.write(pin, val)`    | Salida `pin` y un ciclo util de `val`          |
| `uart.setup(baund_rate)` | Iniciación Comunicacón Serial a `Baund_rate`   |
| `uart.read()`            | Lectura de Comunicacón Serial a ``             |
| `println(message)`       | Imprime  `message` a traves Comunicacón Serial |
| `sleep(time)`            | Retardo en `seg`                               |
| `sleep_us(time)`         | Retardo en `microseg`                          |
| `sleep_ms(time)`         | Retardo en `miliseg`                           |

### EJEMPLOS
#### Parpadeo de un LED
```v
import pin
import time

pin.setup(5, output)

for i in 0..10{   //10 veces
    pin.high(5)
    time.sleep_ms(500)
    pin.low(5)
    time.sleep_ms(500)
}
```

#### Ejemplo lectura analoga

```v

pin.setup(2, out)
pin.setup(3, out)
pin.setup(4, out)
for {
    if( adc.read(8)>=1017 ){

        pin.high(2)
        pin.high(3)
        pin.high(4)

    }
    else if( adc.read(8)>=750 ){

        pin.high(2)
        pin.high(3)
        pin.low(4)
        
    }
    else if( adc.read(8)>=480 ){

        pin.high(2)
        pin.low(3)
        pin.low(4)
        
    }
    else {

        pin.low(2)
        pin.low(3)
        pin.low(4)
        
    }
    } 
```

#### Ejemplo salida PWM
```v

pin.setup(5, out)
int util=0

for {
    pwm.write(5, util)
    sleep_ms(250)
    util=util+10
    if (util==250){

        util=0
        
    }
    } 
```

#### Encender un LED con u pulsador
```v
pin_mode(3, out)

for {   //infinite loop
    pin.high(5)
    sleep_ms(500)
    pin.low(5)
    sleep_ms(500)
}
```

### Configuración Pines de Salida

To activate the port to use
```v
pin.high(pin_name)
```
* *Example: If you want to activate the port IO17;  `pin.high(IO17)`.*

To disable the port being used
```v
pin.low(pin_name)
```
* *Example: If you want to disable the port IO17;  `pin.low(O17I)`.*

To disable or enable the port to be used

```v
pin.write(pin_name, value)
```
* *Example: If you want to disable port IO17 `pin.write(IO17, 1)`, and if you want to activate  `pin.write(IO17, 0)`.*

### Input port detection

If you need to know what state an entry port is in:
```v
x = pin.read(pin_name)
```

* *Example: If you want to detect the value of port IO3; `x = pin.read(IO17)`, and `x` will take the value of 0 or 1, depending on which port is active or disabled.*

### Analog to digital ports (ADC)

To configure one of the analog ports
```v
adc.setup(channel, setup_value_1, ... )
```
* *In channel the name of the analog port is entered, in setup_value_1 the value that will be given is said port.*

To detect the analog port value
```v
x = adc.read(channel)
```
* *In `channel` the name of the analog port is entered, and `x` takes the value of said port..*

### Pulse Width Modulation (PWM outputs)

To configure some PWM
```v
pwm.setup(setup_value_1, setup_value_2, ... )
```
* *In pwm you set the PWM to use, and in setup_value_1 the value to which you want to configure said pwm.*


To configure the duty cycle of a modulator
```v
pwm_duty(duty)
```
* *In PWM the pwm to be used is set, and in `duty` the value of the cycle (from 0 to 100) in percentage.*

### Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

#### UART setup

```v
uart.setup(baud_rate)   // the same of uart1_setup(baud_rate)
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
```v
time.sleep(s) //Seconds
```
```v
time.sleep_ms(ms) //Milliseconds
```
```v
time.sleep_us(us) //Microseconds
```

* Example flashing LED

```v
import pin 
import time { sleep_ms }

pin_mode(IO14, out)

for {   //infinite loop
    pin.high(IO14)
    sleep_ms(500)
    pin.low(IO14)
    sleep_ms(500)
}
```