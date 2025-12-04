# Guìa Rápida para PIC16F873A
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F873A

**NOTA:** Esta guía NO incluye el **datasheet completo**, únicamente presenta la información esencial necesaria para la configuración del microcontrolador, el uso de sus pines, el **ADC**, los periféricos principales y los parámetros iniciales más importantes, para su implementacion.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `b6` indica el pin 6 del puerto `b`. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

| Parámetro                              | Valor |
|----------------------------------------|-------|
| Tamaño de la memoria del programa (KB) | 7     |
| RAM                                    | 192   |
| Datos EEPROM (bytes)                   | 128   |
| Número de pines                        | 28    |
| Voltaje máximo de operación (V)        | 5.5   |
| Voltaje de operación mín. (V)          | 2     |


![alt text](image.png) Fuente: (https://www.microchip.com/en-us/product/pic16f873a)

### Nombres de los pines del PIC16F873A

Los pines del microcontrolador pueden funcionar como entradas o salidas digitales, entradas analógicas para el **ADC** o desempeñar funciones especiales como **PWM**, **UART**, interrupciones, comparadores y reloj. Conocer su nomenclatura permite configurarlos correctamente y evita conflictos entre funciones digitales y analógicas

| Puerto | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| :----: | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | -    | -    |
|  **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5` | `b6` | `b7` |
|  **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | `c6` | `c7` |

## Funciones Especiales

| Función                      | Pin         |
| ---------------------------- | ----------- |
| `ADC (AN0–AN4)`            | a0–a4     |
| `PWM CCP1`                 | c2         |
| `PWM CCP2`                 | c1         |
| `UART TX/RX`*               | c6 / c7   |
| `Interrupción externa INT` | b0         |
| `I²C SDA/SCL`              | c4 / c3   |
| `SPI`                      | c3/c4/c5 |

## Caracterìsticas

| Característica  | Valor     |
| --------------- | --------- |
| Memoria Flash   | 4 KB      |
| RAM             | 192 bytes |
| EEPROM          | 128 bytes |
| Número de pines | 28        |
| Voltaje máximo  | 5.5 V     |
| Voltaje mínimo  | 2 V       |

## Especificaciones Generales

| Categoría                | Especificación                                     |
| ------------------------ | -------------------------------------------------- |
| **Arquitectura**         | 8 bits, núcleo Mid-Range RISC (35 instrucciones)   |
| **Flash**                | 4K palabras                                        |
| **RAM**                  | 192 bytes                                          |
| **EEPROM**               | 128 bytes                                          |
| **Puertos I/O**          | 22 pines digitales                                 |
| **Canales ADC**          | 5 canales (AN0–AN4), resolución 10 bits            |
| **Comparadores**         | No posee comparador integrado                      |
| **PWM**                  | CCP1 y CCP2                                        |
| **Timers**               | TMR0 (8 bits), TMR1 (16 bits), TMR2 (8 bits)       |
| **USART**                | TX/RX en RC6/RC7                                   |
| **I²C / SPI**            | MSSP integrado                                     |
| **Voltaje de operación** | 2.0 – 5.5 V                                        |
| **Oscilador interno**    | No posee (requiere cristal o externo)              |
| **Interrupciones**       | INT, PORTB IOC, ADC, TMR0, TMR1, TMR2, USART, MSSP |
| **Programación**         | ICSP®                                              |

## Configuracion General

```V
import pin
import port
import adc
import time

pin.setup(pin.b0, pin.output)
pin.setup(pin.a1, pin.input)
pin.setup(pin.c2, pin.output)
pin.setup(pin.c7, pin.input)
pin.setup(pin.a5, pin.output)

port.setup(port.b, 0b00000000) // Puerto B como salida
port.setup(port.c, 0b11000000) // RC6/RC7 entradas UART

adc.setup()
adc.read(0) // AN0 como primera lectura
```

## Lìmites Elèctricos

| Parámetro                | Valor / Rango      | Descripción             |
| ------------------------ | ------------------ | ----------------------- |
| Voltaje de operación     | **2.0–5.5 V**      | Rango normal            |
| Voltaje máximo por pin   | −0.3 a VDD + 0.3 V | Límite absoluto         |
| Corriente máxima por pin | **25 mA**          | No exceder              |
| Corriente por puerto     | **200 mA total**   | Suma de todos los pines |
| Frecuencia máxima        | **20 MHz**         | Para cristal externo    |
| Corriente en Sleep       | µA                 | Ultra bajo consumo      |
| R resistencia MCLR       | 10 kΩ              | Pull-up recomendado     |

## Registros Claves

| Registro           | Función            | Uso                         |
| ------------------ | ------------------ | --------------------------- |
| **TRISx**          | Dirección de pines | 1=entrada, 0=salida         |
| **PORTx**          | Estado del puerto  | Lectura/escritura digital   |
| **ADCON0**         | Control del ADC    | Canal, inicio de conversión |
| **ADCON1**         | Config ADC         | Referencias, justificado    |
| **CCP1/CCP2**      | PWM                | Control de ciclo útil       |
| **TXSTA/RCSTA**    | UART               | Control de TX/RX            |
| **SSPCON/SSPSTAT** | I²C/SPI            | Config MSSP                 |

## Temporizadores

| **Timer** | **Resolución** | **Fuente de reloj**                | **Características principales**                     |
|----------|----------------|------------------------------------|----------------------------------------------------|
| **Timer0** | 8 bits         | Interna o RA4/T0CKI                | Prescaler 1:2 a 1:256                              |
| **Timer1** | 16 bits        | Interna o externa (T1CKI)          | Ideal para temporización precisa                   |
| **Timer2** | 8 bits         | Interna                            | Controla PWM automáticamente (módulo CCP)          |

## Interrupciones

| Registro                | Función                            |
| ----------------------- | ---------------------------------- |
| **INTCON**              | GIE, PEIE, T0IE, INTE, RBIE        |
| **PIE1 / PIR1**         | ADC, TMR1, TMR2, USART, PSP        |
| **PIE2 / PIR2**         | MSSP, comparador                   |
| **RBIF (PORTB cambio)** | Interrupción por cambio en RB4–RB7 |

## Oscilador (No posee oscilador interno)

| Modo             | Descripción       |
| ---------------- | ----------------- |
| **XT / HS / LP** | Requiere oscilador  |
| **EC**           | Fuente externa    |
| **CLKOUT (RA6)** | Salida del reloj  |
| **CLKIN (RA7)**  | Entrada del reloj |

## Modos de Reset y WDT

| Modo      | Descripción           |
| --------- | --------------------- |
| **POR**   | Reset por encendido   |
| **MCLR**  | Reset externo         |
| **BOR**   | Por bajo voltaje      |
| **WDT**   | Reinicio por watchdog |
| **SLEEP** | Modo de bajo consumo  |

## Ejemplo simple: uso de pines

```v
pin.high(pin.b1)
pin.low(pin.c2)

val := pin.read(pin.a0)

pin.write(pin.b0, pin.read(pin.c7))
```

## Ejemplo de ADC

```v
adc_val := adc.read(0)

if adc_val > 512 {
    pin.high(pin.c2)
} else {
    pin.low(pin.c2)
}
```

## Ejemplo de tiempo

```v
time.sleep_ms(500)
```

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `b5_s` Nombre del bit para configurar el `b5` pin como entrada o salida 
- `b5`   Nombre del bit para leer el pin como entrada o salida `b5`

### Componentes Integrados 
- Cuenta con cinco pines analogos que se encuentran distribuidas en el puerto A.

| Puerto | 0   | 1   | 2   | 3   | 4   | 5 | 6 | 7 |
| :----: | --- | --- | --- | --- | --- | - | - | - |
|  **A** | AN0 | AN1 | AN2 | AN3 | AN4 | – | – | – |
|  **B** | –   | –   | –   | –   | –   | – | – | – |
|  **C** | –   | –   | –   | –   | –   | – | – | – |


- Cuenta con dos pines para la modulacion del PWM.

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | CCP2 (c1)  | CCP1 (c2)  | -   | -   | -   | -   | -   |

- Cuenta con dos pines para la cominicación serial (UART).   

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | -   | -   | -   | -   | -   | c6 (TX) | c7 (RX) |

### Funciones soportadas
La API Aixt proporciona funciones para manejar entradas/salidas digitales, puertos completos, el conversor **ADC**, la modulación **PWM**, comunicación serial **UART** y temporización.

| Función                      | Descripción                                                                       |
| ---------------------------- | --------------------------------------------------------------------------------- |
| `pin.setup(pin_name, mode)`  | Configura un pin como entrada (`pin.input`) o salida (`pin.output`).              |
| `pin.high(pin_name)`         | Coloca el pin en nivel alto (1).                                                  |
| `pin.low(pin_name)`          | Coloca el pin en nivel bajo (0).                                                  |
| `pin.write(pin_name, value)` | Escribe un valor digital (0/1) en un pin.                                         |
| `pin.read(pin_name)`         | Lee el estado digital de un pin.                                                  |
| `pin.digital()`              | Configura **todos los pines** en modo digital (deshabilita funciones analógicas). |


### Ejemplos de las diferentes funciones de la API en lenguaje _Aixt_v 

## Tiempo

```v

time.sleep(5)        // Retardo de 5 segundos
time.sleep_us(10)    // Retardo de 10 microsegundos
time.sleep_ms(500)   // Retardo de 500 milisegundos


```

## Configuración de pines 

```v

pin.setup(pin.a5, pin.output)   // A5 como salida
pin.setup(pin.b7, pin.output)   // B7 como salida
pin.setup(pin.a0, pin.input)    // A0 como entrada
pin.setup(pin.c4, pin.input)    // C4 como entrada

pin.high(pin.a5)                // Encender A5
pin.low(pin.a5)                 // Apagar A5

pin.write(pin.a2, 0)            // Escribir 0 en A2
pin.write(pin.a2, 1)            // Escribir 1 en A2

pin.read(pin.b4)                // Leer B4
pin.read(pin.c7)                // Leer C7


```

Ejemplo de prender y apagar un led:

```v
      
for {
    pin.high(pin.c7)
    time.sleep_us(500)
    pin.low(pin.c7)
    time.sleep_us(500)
}


```
Ejemplo de prender y apagar un led con una entrada digital:

```v

pin.digital()   // Fuerza todos los pines a modo digital

for {
    if b4 == 1 {        // Si el pin B4 está en alto
        pin.high(pin.a4)
        pin.high(pin.a5)
    }
    else if b5 == 1 {   // Si el pin B5 está en alto
        pin.low(pin.a4)
        pin.low(pin.a5)
    }
}

        
```
## Configuración del port

```v

port.setup(port.b, 0b00000000)   // Todo el puerto B como salida


```

Ejemplo de prender y apagar el puerto del microcontrolador:

```v
      
for {
    port.write(port.b, 0b01010101)
    time.sleep_ms(500)
    port.write(port.b, 0b10101010)
    time.sleep_ms(500)
}


```

## Configuración del ADC

```v

adc.setup()    // Inicializa el ADC
adc.read(0)    // Lee AN0


```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:

```v

unsigned int adc_result   // Variable para almacenar la lectura

for {
    adc_result = adc.read(0)

    if adc_result >= 1020 {
        pin.high(pin.b0)
        pin.high(pin.b1)
        pin.high(pin.b2)
    }
    else if adc_result >= 820 {
        pin.high(pin.b0)
        pin.high(pin.b1)
        pin.low(pin.b2)
    }
    else if adc_result >= 620 {
        pin.high(pin.b0)
        pin.low(pin.b1)
        pin.low(pin.b2)
    }
    else {
        pin.low(pin.b0)
        pin.low(pin.b1)
        pin.low(pin.b2)
    }
}


```

## Configuración del PWM

```v

pwm.setup()        // Inicializa PWM
pwm.write(512)     // Duty de 50% (ejemplo)


```
Ejemplo de variar la intensidad de un led:

```v

for {
    adc_value := adc.read(0)   // Leer AN0
    pwm.write(adc_value)       // Aplicar al PWM (0–1023)
}


```

## Configuración del UART Transmisión

```v

uart.setup()   // Inicializa UART


```
Ejemplo enviar un caracter y visualizarlo en un mensaje:

```v

for {
    uart.write(0x33)
    time.sleep_ms(500)
    uart.write(0x99)
    time.sleep_ms(500)
}


```

## Configuración del UART Recepción

```v

uart.setup()                // Inicializa UART
port.setup(port.b, 0x00)    // Puerto B como salida
pin.setup(pin.c7, pin.input) // RX en C7


```
Ejemplo escribir en PORTB lo que llega por UART:

```v

for {
    value := uart.read()         // Leer byte recibido
    port.write(port.b, value)    // Enviar directamente al puerto B
}


```