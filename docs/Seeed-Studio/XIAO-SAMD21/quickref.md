# **Guia Rápida Seeeduino Xiao**
Esta implementación de Aixt para dae soporte a la tarjeta SAMD21.

## Resumen
* *SAMD21, tiene 14 PIN, que se pueden usar para 11 interfaces digitales, 11 interfaces simuladas, 10 interfaces PWM (d1-d10), 1 pin de salida DAC D0, 1 interfaz de pad SWD, 1 interfaz I2C, 1 interfaz SPI, 1 Interfaz UART, Indicador de comunicación serial (T/R), Luz parpadeante (L) mediante multiplexación de pines. Los colores de los LED (Power,L,RX,TX) son verde, amarillo, azul y azul. Además, Seeed Studio XIAO SAMD21 tiene una interfaz tipo C que puede suministrar energía y descargar código. Hay dos botones de reinicio, puedes conectarl2os brevemente para reiniciar la placa.La definició de pines esta descrita en la tala de* Identificación de Pines.

![Alt text](Picture/Seeeduino_XIAO_SAMD21.jpg)

## Datasheet
[Seeeduino Xiao SAMD21G18A-MU](https://files.seeedstudio.com/wiki/XIAO/Seeed-Studio-XIAO-Series-SOM-Datasheet.pdf)

## Identificación de Pines
Below are the ports used and their proper designations for programming:

Pin No. |Nombre                | Función 
--      |-----                 | ---
0       |D0-A0-DAC-QT0         | Analogo; Digital; Convertidor Analogo Digital;            Circuito integrado para botón capacitivo 
1       |D1-A1-QT1             | Analogo; Digital;                                         Circuito integrado para botón capacitivo  
2       |D2-A2                 | Analogo; Digital; 
3       |D3-A3                 | Analogo; Digital; 
4       |D4-A4-SDA(I2C)        | Analogo; Digital; Protocolo control de dispositivos(Transmisión de datos)
5       |D5-A5-SCL(I2C)        | Analogo; Digital; Protocolo control de dispositivos(Envio sincronismos de reloj) 
6       |D6-A6-TX-QT2          | Analogo; Digital; Comunicación Serial(Transmisor);        Circuito integrado para botón capacitivo
7       |D7-A7-RX-QT3          | Analogo; Digital; Comunicación Serial(Receptor);          Circuito integrado para botón capacitivo
8       |D8-A8-SCK(SPI)-QT4    | Analogo; Digital; Reloj serial;                           Circuito integrado para botón capacitivo
9       |D9-A9-MISO(SPI)-QT5   | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
10      |D10-A10-MOSI(SPI)-QT6 | Analogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
11      |3.3V                  | Alimentación de Microcontrolador 
12      |GND                   | Tierra Común
13      |5V                    | Alimentación de la Placa 

## Programación en Lenguaje V

Las funciones que contiene la API entradas o salidas digitales y para realizar una conversión analogico a digital.

Nombre                  | Descripción
------------------------|------------------------------
`pin.setup(pin, mode)`  | Configura `pin`como `mode` (input, out)
`pin.out`               | Parametro `mode` configuración de salida
`pin.in`                | Parametro `mode` configuración de entrada
`pin.high(pin)`         | Salida Digital en alto `pin`
`pin.low(pin)`          | Salida Digital en bajo `pin`
`pin.write(pin, val)`   | Escribe `val` en `pin`
`pin.read(pin)`         | Lectrura digital `pin`
`adc.read(pin)`         | Lectura analogica `pin` para el `adc`
`pwm.write(pin, val)`   | Salida PWM `pin` y un ciclo util de `val`
`uart.setup(baud_rate)` | Iniciación Comunicacón Serial a `Baund.rate`
`uart.ready()`          | Obtiene el numero de bytes a leer
`uart.read()`           | Lectura de Comunicacón Serial
`uart.println(message)`      | Imprime  `message` a través Comunicacón Serial
`time.sleep(time)`           | Retardo en `seg`
`time.sleep_us(time)`        | Retardo en `microseg`
`time.sleep_ms(time)`        | Retardo en `miliseg`

## EJEMPLOS
### Parpadeo de un LED
A continuación se comprobara el funcionamiento de la salida digital y el retardo en milisegundos. Para esto se encendera y apagara un led 10 veces, en este ejemplo se importaran del modulo `time` la función `sleep_ms` (retardo en milisegundos), y el modulo `pin` en su totalidad. 
```go
import time {sleep_ms}   //impota la fución sleep_ms del modulo time 
import pin  // importa el modulo pin en su totalidad

pin.mode(5, pin.out)    // Configura el pin #5 como salida

for i in 0..10{   // 10 veces
    pin.high(5)     // Salida en Alto (Enciende el led)
    sleep_ms(500)   // Retardo de 0.5s
    pin.low(5)      // Salida en Bajo (Apaga el led)
    sleep_ms(500)   // Retardo de 0.5s
}
for{}       // For infinito necesario para la compilación
```
### Encender un LED con pulsador
A continuación se comprobara el funcionamiento de entrada y salida digital. Para esto se condicionara el encendido de un led a un pulsador, en este ejemplo se importara modulo `pin` en su totalidad. 

```go
import pin  // importa el modulo pin

__global Lectura = 0    //Crea una variable global para almacenar la lectura digital

pin.setup(3, pin.input)     // Configura el pin #3 como entrada
pin.setup(5, pin.out)       // Configura el pin #5 como salida

for{        // For infinito
    Lectura=pin.read(3)     //Almacena la lectura digital del pin #3
    if(Lectura==1){         //Condición si el valor de lectura es 1 (Alto)
        pin.high(5);        // Salida en Alto
    }
    pin.low(5)              // Salida en Bajo 
}

```
### Lectura analoga
A continuación se comprobara el funcionamiento de entrada analogica y salida digital. Para esto se condicionara el encendido de 3 led a un potencimetro, estos led encenderan dependiendo de la lectura analogica, en este ejemplo se importara modulo `pin` y el modulo `adc`en su totalidad. 
```go
import pin  // importa el modulo pin
import adc  // importa el modulo adc

__global val = 0    //Crea una variable global para almacenar la lectura analogica

pin.setup(2, pin.out)   // Configura el pin #2 como salida
pin.setup(3, pin.out)   // Configura el pin #3 como salida
pin.setup(4, pin.out)   // Configura el pin #4 como salida



for {       // For infinito
    val=adc.read(8)     //Almacena la lectura analogica del pin #8
    if val>=1000 {      //Condición de la lectura analogica
        pin.high(2)     // Salida en Alto
        pin.high(3)     // Salida en Alto
        pin.high(4)     // Salida en Alto
    }
    else if val>=750 {
        pin.high(2)     // Salida en Alto
        pin.high(3)     // Salida en Alto
        pin.low(4)      // Salida en Bajo 
    }
    else if val>=480 {
        pin.high(2)     // Salida en Alto
        pin.low(3)      // Salida en Bajo 
        pin.low(4)      // Salida en Bajo 
    }
    else {
        pin.low(2)      // Salida en Bajo 
        pin.low(3)      // Salida en Bajo 
        pin.low(4)      // Salida en Bajo  
    }   
    }
```
### Salida PWM
A continuación se comprobara el funcionamiento de la salida analogica (PWM). Para esto se variara la intensidad luminica de un led en un periodo de tiempo, en este ejemplo se importara modulo `pin` y el modulo `pwm`en su totalidad y la la función `sleep_ms` del modulo`time`.
```go

import time {sleep_ms}  // importa el función sleep_ms
import pin              // importa el modulo pin
import pwm              // importa el modulo pwm

__global val = 0        //Crea una variable global para almacenar un valor el cual corresponde a la intensidad luminica

pin.setup(5, pin.out)   // Configura el pin #5 como salida



for {
    pwm.write(5, val)   // Salida pwm a un ciclo util de val
    sleep_ms(250)       // Retardo de 250ms
    val=val+10          // Suma 10 a val
    if val==250{        // Condicion si val=250
		val=0  
    }
} 
```