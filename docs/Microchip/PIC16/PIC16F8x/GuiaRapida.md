# Guía rápida de P16F8X
## Referencia del PIC16 utilizado por la marca MICROCHIP
- PIC16F8X (PIC16F83, PIC16F84, PIC16CR83, PIC16CR84)

**NOTA** Esta guía **NO** incluye módulos **ADC**, **PWM** o **UART**, ya que el PIC16F8x no tiene estos módulos.

## Nombres de los pines
Los nombres de los pines se componen de una letra que indica el puerto y un número que indica el pin. Por ejemplo, **a2** indica el pin **2** del puerto **A**. Todos los nombres en Aixt se escriben en minúsculas [Reglas de nomenclatura de variables V]. (https://github.com/vlang/v/blob/master/doc/docs.md#variables)

Cuenta con dos pines de entrada y salida de circuito digital para mostrar el comportamiento programado de encendido y apagado del LED.

| Puerto  | 0    | 1    | 2    | 3    | 4    | 5     | 6     | 7     |
| :---: | ---- | ---- | ---- | ---- | ---- | ----- | ----- | ----- |
| **A** | `a0` | `a1` | `a2` | `a3` | `a4` | ----- | ----- | ----- |
| **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5`  | `b6`  | `b7`  |

En **a4** la salida es tipo open-drain, entrada normal y ningún pin soporta voltaje analógico continuo en modo ADC, por ser digital.

**Aixt utiliza nombres de pines en minúsculas, sin el prefijo “R”: a0, a1, b3, b7…**

| Nº | Especificación                     | Valor  |
|:--:|------------------------------------|--------|
|  1 | Memoria de programa (KB)           | 0.875  |
|  2 | RAM (bytes)                        | 36     |
|  3 | EEPROM (bytes)                     | 64     |
|  4 | Número de pines                    | 18     |
|  5 | Voltaje mínimo de operación (V)    | 2      |
|  6 | Voltaje máximo de operación (V)    | 6      |

Fuente: (https://www.microchip.com/en-us/product/pic16f83)

| Nº | Característica                           | Descripción / Valor                              |
|:--:|-------------------------------------------|--------------------------------------------------|
|  1 | Arquitectura                               | Microcontrolador RISC de 8 bits                  |
|  2 | Pines de E/S digitales                     | 13 (PORTA + PORTB)                               |
|  3 | Memoria Flash (programa)                   | 512–1K instrucciones                             |
|  4 | Memoria EEPROM                             | 64 bytes                                         |
|  5 | RAM                                        | 36 a 68 bytes (según variante)                   |
|  6 | Temporizador                               | TMR0 de 8 bits                                   |
|  7 | Tipo de interrupciones disponibles         | 4                                               |

```v
import pin

// Configuración
pin.setup(pin.b0, pin.output)
pin.setup(pin.a1, pin.input)

// Escribir pines
pin.high(pin.b0)
pin.low(pin.a3)

// Alternar un pin
pin.toggle(pin.b7)

// Leer un pin
value := pin.read(pin.a1)

// Eco (entrada → salida)
pin.write(pin.b2, pin.read(pin.a1))
```
![texto alternativo](image.png) Fuente: (https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/30430D.pdf)

Es un microcontrolador sencillo y orientado al aprendizaje básico. Debido a que no incorpora periféricos avanzados como **ADC**, **PWM** o **UART**, su uso principal es digital.

- Solo es adecuado para probar **E/S**, **TMR0**, **interrupciones** y **EEPROM**.
- Es ideal para ejercicios introductorios, simulación y comprensión de la arquitectura **PIC**.
- Permite estudiar con claridad:
  - Operaciones de **Lectura–Modificación–Escritura (R–M–W)** en puertos
  - Configuración de direcciones mediante **TRIS**
  - Uso del **prescaler**
  - Funcionamiento del **temporizador TMR0**
  - Latencias y manejo de **interrupciones**
  - Lectura y escritura de **EEPROM**

Gracias a su simplicidad, este microcontrolador es perfecto para desarrollar bases sólidas antes de pasar a dispositivos más completos.

Es ideal para ejercicios de simulación introductorios y para comprender los fundamentos de la arquitectura PIC.

Permite estudiar con claridad conceptos como:

- Lectura–Modificación–Escritura **(R-M-W)**
 - Configuración de **TRIS**
 - Latencias de interrupciones
 - Uso del prescaler
 - Manejo de **EEPROM** de datos

**`MCLR`** significa Master Clear/Reset, es decir, un pin de reinicio del controlador que se conecta a Vcc (+5 V).
**`OSC`** significa Oscillator Pins, que controla el reloj del sistema y determina la velocidad de ejecución del programa. En el PIC16F83-1, es una salida interna, en modo cristal, que se conecta al segundo pin (tiene una entrada y una salida, OSC1 y OSC2).
**`VDD`** Potencia positiva y referencia de tierra para los pines lógicos y de E/S, respectivamente. Estos pines cuentan con protección de diodo.
**`VSS`** significa Voltage Source, Source o Voltage Supply Source y es el pin de tierra (GND), también conocido como referencia de voltaje, 0 voltios para todo el circuito.

## Control general de $\mu C$
```v
// Frecuencia del oscilador del microcontrolador
// Ajustar según el cristal usado en el hardware o simulación.
@[as_macro]
pub const CPU_FREQ: u32 = 4_000_000; // 4 MHz
```

| Hardware | Valor para CPU_FREQ |
|---------------------|---------------------|
| 4 MHz               | 4_000_000           |
| 8 MHz               | 8_000_000           |
| 10 MHz              | 10_000_000          |
| 20 MHz              | 20_000_000          |

## Retardo

El módulo **`time`** permite generar retardos en segundos, milisegundos o microsegundos.

```v
import time

time.sleep(2)        // Retardo de 2 segundos
time.sleep_ms(50)    // Retardo de 50 ms
time.sleep_us(100)   // Retardo de 100 µs
```

## Funciones

| Nº | Registro        | Función principal                                   |
|:--:|-----------------|------------------------------------------------------|
|  1 | PORTA           | Lectura/escritura de pines RA0–RA4                  |
|  2 | PORTB           | Lectura/escritura de pines RB0–RB7                  |
|  3 | TRISA           | Configuración de dirección del puerto A             |
|  4 | TRISB           | Configuración de dirección del puerto B             |
|  5 | TMR0            | Temporizador/contador de 8 bits                     |
|  6 | OPTION_REG      | Prescaler, flanco INT, configuración TMR0           |
|  7 | INTCON          | Gestión de interrupciones (GIE, INTE, T0IE, RBIE)   |
|  8 | EECON1          | Control de EEPROM                                   |
|  9 | EECON2          | Secuencia de escritura EEPROM                       |