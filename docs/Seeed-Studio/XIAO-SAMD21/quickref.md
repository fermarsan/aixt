# **Guia Rápida Seeeduino Xiao**
Esta implementación de Aixt para dae soporte a la tarjeta SAMD21.

## Resumen
* *SAMD21, tiene 14 PIN, que se pueden usar para 11 interfaces digitales, 11 interfaces simuladas, 10 interfaces PWM (d1-d10), 1 pin de salida DAC D0, 1 interfaz de pad SWD, 1 interfaz I2C, 1 interfaz SPI, 1 Interfaz UART, Indicador de comunicación serial (T/R), Luz parpadeante (L) mediante multiplexación de pines. Los colores de los LED (Power,L,RX,TX) son verde, amarillo, azul y azul. Además, Seeed Studio XIAO SAMD21 tiene una interfaz tipo C que puede suministrar energía y descargar código. Hay dos botones de reinicio, puedes conectarlos brevemente para reiniciar la placa.La definición de pines esta descrita en la tabla de* Identificación de Pines.

![Alt text](Picture/Seeeduino_XIAO_SAMD21.jpg)

## Datasheet
[Seeeduino Xiao SAMD21G18A-MU](https://files.seeedstudio.com/wiki/XIAO/Seeed-Studio-XIAO-Series-SOM-Datasheet.pdf)

## Identificación de Pines
Below are the ports used and their proper designations for programming:

Pin No. |Nombre                | Función 
--      |-----                 | ---
0       |D0-A0-DAC-QT0         | Análogo; Digital; Convertidor Análogo Digital;            Circuito integrado para botón capacitivo 
1       |D1-A1-QT1             | Análogo; Digital;                                         Circuito integrado para botón capacitivo  
2       |D2-A2                 | Análogo; Digital; 
3       |D3-A3                 | Análogo; Digital; 
4       |D4-A4-SDA(I2C)        | Análogo; Digital; Protocolo control de dispositivos(Transmisión de datos)
5       |D5-A5-SCL(I2C)        | Análogo; Digital; Protocolo control de dispositivos(Envió sincronismos de reloj) 
6       |D6-A6-TX-QT2          | Análogo; Digital; Comunicación Serial(Transmisor);        Circuito integrado para botón capacitivo
7       |D7-A7-RX-QT3          | Análogo; Digital; Comunicación Serial(Receptor);          Circuito integrado para botón capacitivo
8       |D8-A8-SCK(SPI)-QT4    | Análogo; Digital; Reloj serial;                           Circuito integrado para botón capacitivo
9       |D9-A9-MISO(SPI)-QT5   | Análogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
10      |D10-A10-MOSI(SPI)-QT6 | Análogo; Digital; Protocolo de comunicación 4 hilos;      Circuito integrado para botón capacitivo 
11      |3.3V                  | Alimentación de Microcontrolador 
12      |GND                   | Tierra Común
13      |5V                    | Alimentación de la Placa 

## Programación en Lenguaje V

Las funciones que contiene la API entradas o salidas digitales y para realizar una conversión analógico a digital.

Nombre                  | Descripción                                    |Ejemplos
------------------------|------------------------------------------------|------------
`pin.setup(pin, mode)`  | Configura `pin`como `mode` (input, out)        |<pre><code>**pin.setup**(5, pin.in) // Configura el pin 5 como entrada
`pin.out`               | Parámetro `mode` configuración de salida       |<pre><code>pin.setup(3, **pin.out**) // Configura el pin 3 como salida
`pin.in`                | Parámetro `mode` configuración de entrada      |<pre><code>pin.setup(7, **pin.in**) // Configura el pin 7 como entrada
`pin.high(pin)`         | Salida Digital en alto `pin`                   |<pre><code>**pin.high**(3) // Salida en alto pin 3
`pin.low(pin)`          | Salida Digital en bajo `pin`                   |<pre><code>**pin.low**(3) // Salida en bajo pin 3
`pin.write(pin, val)`   | Escribe `val` en `pin`                         |<pre><code>**pin.write**(3, 1) // Escribe 1 en el pin 3
`pin.read(pin)`         | Lectura digital `pin`                          |<pre><code>val=**pin.read**(3) // Almacena en **val** la lectura del pin 3
`adc.read(pin)`         | Lectura analógica `pin` para el `adc`          |<pre><code>val=**adc.read**(3) // Almacena en **val** la lectura analógica del pin 3
`pwm.write(pin, val)`   | Salida PWM `pin` y un ciclo util de `val`      |<pre><code>**pwm.write**(4, 125) // Escribe en el pin 3 una señal PWM con un ciclo util de aproximadamente el 50%
`uart.setup(baud_rate)` | Iniciación Comunicación Serial a `Baud.rate`  |<pre><code>**uart.setup**( 9600 ) // Inicia la comunicación del puerto serial a una velocidad de 9600 baudios
`uart.ready()`          | Obtiene el número de bytes a leer              |<pre><code>val=**uart.ready()** // Almacena en **val** el número de bytes a leer del puerto serial
`uart.read()`           | Lectura de Comunicación Serial                 |<pre><code>lec=**uart.read()** // Almacena en **lec** la lectura del puerto serial
`uart.println("message")` | Imprime  `message` a través Comunicación Serial|<pre><code>**uart.println**("Hola mundo") // Imprime **Hola mundo** en el puerto serial
`time.sleep(time)`      | Retardo en `seg`                               |<pre><code>**time.sleep**(5) // Retardo de **5** segundos    
`time.sleep_us(time)`   | Retardo en `microseg`                          |<pre><code>**time.sleep_us**(250) // Retardo de **250** microsegundos
`time.sleep_ms(time)`   | Retardo en `miliseg`                           |<pre><code>**time.sleep_ms**(250) // Retardo de **250** milisegundos


## EJEMPLOS
### Parpadeo de un LED
A continuación se encenderá y apagara un led 10 veces.

```go
import time {sleep_ms}   //importa la función sleep_ms del modulo time 
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

### Secuencia de 3 LED
A continuación se una secuencia de 3 led. 

```go
import time {sleep_ms} // importa la función sleep_ms
import pin  // importa el modulo pin

pin.setup(3, pin.out)    // Configura el pin #3 como salida
pin.setup(4, pin.out)    // Configura el pin #4 como salida
pin.setup(5, pin.out)    // Configura el pin #5 como salida

for{
    pin.high(3)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.high(4)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.high(5)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(3)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(4)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(5)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
}
```

### Encender un LED con pulsador
A continuación se condicionara el encendido de un led a un pulsador.

```go
import pin  // importa el modulo pin

__global (
    lectura = 0      //Crea una variable global para almacenar la lectura digital
)    

pin.setup(3, pin.input)     // Configura el pin #3 como entrada
pin.setup(5, pin.out)       // Configura el pin #5 como salida

for{        // For infinito
    lectura=pin.read(3)     //Almacena la lectura digital del pin #3
    if lectura==1{         //Condición si el valor de lectura es 1 (Alto)
        pin.high(5);        // Salida en Alto
    }
    pin.low(5)              // Salida en Bajo 
}
```

### Lectura análoga
A continuación se condicionara el encendido de 3 led a un potenciómetro y su lectura analógica.

```go
import pin  // importa el modulo pin
import adc  // importa el modulo adc

__global (
    val = 0      //Crea una variable global para almacenar la lectura analógica
)     
pin.setup(2, pin.out)   // Configura el pin #2 como salida
pin.setup(3, pin.out)   // Configura el pin #3 como salida
pin.setup(4, pin.out)   // Configura el pin #4 como salida


for {       // For infinito
    val=adc.read(8)     //Almacena la lectura analógica del pin #8
    if val>=1000 {      //Condición de la lectura analógica
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
A continuación se variara la intensidad lumínica de un led en un periodo de tiempo.

```go

import time {sleep_ms}  // importa la función sleep_ms
import pin              // importa el modulo pin
import pwm              // importa el modulo pwm

__global (
    val = 0        //Crea una variable global para almacenar un valor el cual corresponde a la intensidad lumínica
)      

pin.setup(5, pin.out)   // Configura el pin #5 como salida


for {
    pwm.write(5, val)   // Salida pwm a un ciclo util de val
    sleep_ms(250)       // Retardo de 250ms
    val=val+10          // Suma 10 a val
    if val==250{        // Condición si val=250
		val=0  
    }
} 
```
### Comunicación Serial
A continuación se encenderá o apagara un del dependiendo de la lectura del puerto serial.

```go

import pin
import uart
 
 __global (
    num = 0    //Crea una variable global para almacenar el número de bytes a leer del puerto serial
    lec = 0    //Crea una variable global para almacenar la lectura del puerto serial
 )
 pin.setup(3, pin.out)      // Configura el pin #5 como salida


for{
    num = uart.ready()      // Almacena el número de bytes a leer del puerto serial
    if  num>0  {
        lec = uart.read()   // Almacena la lectura del puerto serial
    }
    if lec==1 {           // Condición si la lectura es 'on'
        pin.high(3)         // Salida en Alto
    }
    if lec==2 {          // Condición si la lectura es 'off'
        pin.low(3)          // Salida en Bajo
    }
}

```
 