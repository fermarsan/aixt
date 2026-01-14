# Guìa Rápida para PIC16F87x
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F87x (Incluye PIC16F873, PIC16F873A, PIC16F874, PIC16F874A, PIC16F876, PIC16F876A, PIC16F877 y PIC16F877A)

**NOTA:** Esta guía NO incluye el **datasheet completo**, únicamente presenta la información esencial necesaria para la configuración del microcontrolador, el uso de sus pines, el **ADC**, los periféricos principales y los parámetros iniciales más importantes, para su implementacion.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `b6` indica el pin 6 del puerto `b`. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

| Categoría           | Parámetro                   | Valor común para PIC16F87x               |
| ------------------- | --------------------------- | ---------------------------------------- |
| **Arquitectura**    | Núcleo                      | 8 bits – RISC Mid-Range                  |
|                     | Conjunto de instrucciones   | 35 instrucciones                         |
|                     | Ciclo de instrucción        | Fosc / 4                                 |
|                     | Stack                       | 8 niveles                                |
| **Voltaje**         | Voltaje de operación (VDD)  | **2.0 – 5.5 V**                          |
|                     | Voltaje máximo por pin      | −0.3 V a VDD + 0.3 V                     |
| **Corriente**       | Corriente máxima por pin    | **25 mA**                                |
|                     | Corriente total por puerto  | **≤ 200 mA**                             |
| **Frecuencia**      | Frecuencia máxima de reloj  | **20 MHz**                               |
| **Memoria**         | Arquitectura de Flash       | Palabras de 14 bits                      |
|                     | Organización de RAM         | Bancada (Banked RAM)                     |
|                     | EEPROM                      | Integrada, acceso byte a byte            |
| **Puertos I/O**     | Puertos disponibles         | PORTA, PORTB, PORTC                      |
|                     | Configuración de pines      | Registros **TRISx**                      |
|                     | Lectura / escritura digital | Registros **PORTx**                      |
|                     | Interrupción externa        | RB0 / INT                                |
|                     | Interrupción por cambio     | RB4–RB7                                  |
| **ADC**             | Resolución                  | **10 bits**                              |
|                     | Tipo                        | SAR                                      |
|                     | Referencias                 | VDD/VSS o externas                       |
|                     | Justificación de resultado  | Izquierda o derecha                      |
| **Temporizadores**  | Timer0                      | 8 bits, prescaler 1:2–1:256              |
|                     | Timer1                      | 16 bits, reloj interno o externo         |
|                     | Timer2                      | 8 bits, base para PWM                    |
| **PWM (CCP)**       | Módulos disponibles         | CCP1 y CCP2                              |
|                     | Resolución PWM              | Hasta 10 bits                            |
|                     | Fuente de reloj PWM         | Timer2                                   |
| **Comunicación**    | USART                       | Full duplex, síncrono/asíncrono          |
|                     | SPI / I²C                   | MSSP Master / Slave                      |
| **Interrupciones**  | Fuentes soportadas          | INT, IOC PORTB, ADC, Timers, USART, MSSP |
| **Oscilador**       | Oscilador interno           | No posee                               |
|                     | Modos soportados            | LP / XT / HS / EC                        |
|                     | Pines de reloj              | RA7 (CLKIN) / RA6 (CLKOUT)               |
| **Reset y control** | Power-On Reset (POR)        | Aplica                                        |
|                     | Brown-Out Reset (BOR)       | Aplica                                        |
|                     | Watchdog Timer (WDT)        | Aplica                                        |
|                     | Reset externo               | MCLR                                     |
| **Programación**    | Método                      | **ICSP®**                                |
| **Consumo**         | Modo Sleep                  | µA                                       |
| **MCLR**            | Resistencia recomendada     | 10 kΩ pull-up                            |

| Parámetro / Característica        | 873 | 873A | 874 | 874A | 876 | 876A | 877 | 877A |
| --------------------------------- | :-: | :--: | :-: | :--: | :-: | :--: | :-: | :--: |
| **Arquitectura 8-bit RISC**       |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **35 instrucciones**              |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Voltaje 2.0–5.5 V**             |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Frecuencia máx. 20 MHz**        |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Oscilador interno**             |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |
| **PORTA, PORTB, PORTC**           |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Interrupción RB0 / INT**        |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **IOC RB4–RB7**                   |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **ADC 10 bits**                   |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **ADC hasta 5 canales (AN0–AN4)** |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |
| **ADC hasta 8 canales (AN0–AN7)** |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Timer0 (8 bits)**               |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Timer1 (16 bits)**              |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Timer2 (8 bits)**               |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Timer3 (16 bits)**              |  No Aplica  |   No Aplica  |  No Aplica  |   No Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **PWM CCP1 (RC2)**                |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **PWM CCP2 (RC1)**                |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **USART (RC6/RC7)**               |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **SPI / I²C (MSSP)**              |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Comparadores internos**         |  No Aplica  |   No Aplica  |  No Aplica  |   Aplica  |  No Aplica  |   No Aplica  |  No Aplica  |   Aplica  |
| **EEPROM interna**                |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **ICSP®**                         |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Watchdog Timer (WDT)**          |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Brown-Out Reset (BOR)**         |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |
| **Modo Sleep**                    |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |  Aplica  |   Aplica  |

![alt text](image-1.png) 
![alt text](image-2.png) Fuente:(https://ww1.microchip.com/downloads/en/devicedoc/30292d.pdf)
![alt text](image.png) 
![alt text](image-3.png) Fuente: (https://ww1.microchip.com/downloads/en/devicedoc/39582b.pdf)

### Nombres de los pines del PIC16F87x

Los pines del microcontrolador pueden funcionar como entradas o salidas digitales, entradas analógicas para el **ADC** o desempeñar funciones especiales como **PWM**, **UART**, interrupciones, comparadores y reloj. Conocer su nomenclatura permite configurarlos correctamente y evita conflictos entre funciones digitales y analógicas

| Puerto | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| :----: | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | -    | -    |
|  **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5` | `b6` | `b7` |
|  **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | `c6` | `c7` |

Para PIC16F876/877 (33 pines), se agregan pines extras en el puerto C, que corresponden

| Puerto | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| :----: | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | -    | -    | -    |
|  **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5` | `b6` | `b7` | -    |
|  **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | `c6` | `c7` | `c8` |

## Funciones Especiales

| Función                              | PIC16F873/873A/874/874A | PIC16F876/876A/877/877A | Pines asignados                  |
| ------------------------------------ | ----------------------- | ----------------------- | -------------------------------- |
| **ADC (AN0–AN4)**                    | 5 canales               | 8 canales (AN0–AN7)     | A0–A5 (873/874), A0–A7 (876/877) |
| **PWM CCP1**                         | 1 módulo                | 1 módulo                | C2                               |
| **PWM CCP2**                         | 1 módulo                | 1 módulo                | C1                               |
| **UART TX/RX**                       | 1 módulo                | 1 módulo                | C6 / C7                          |
| **Interrupción externa INT**         | 1 pin                   | 1 pin                   | B0                               |
| **I²C SDA/SCL**                      | MSSP integrado          | MSSP integrado          | C4 / C3                          |
| **SPI (MOSI/MISO/SCK)**              | MSSP integrado          | MSSP integrado          | C3/C4/C5                         |
| **Timer0**                           | 8 bits                  | 8 bits                  | Interno / RA4/T0CKI              |
| **Timer1**                           | 16 bits                 | 16 bits                 | Interno / T1CKI                  |
| **Timer2**                           | 8 bits                  | 8 bits                  | Interno (para PWM)               |
| **Timer3**                           | No disponible           | 16 bits                 | T3CKI (876/877)                  |
| **Comparadores internos**            | No                      | Algunos modelos A       | AN0/AN1 (874A/877A)              |
| **Oscilador externo (CLKIN/CLKOUT)** | Todos los modelos       | Todos los modelos       | RA6/RA7                          |
| **Reset externo (MCLR)**             | Todos                   | Todos                   | MCLR pin                         |
| **Watchdog (WDT)**                   | Todos                   | Todos                   | Integrado                        |
| **Port Change Interrupt**            | B4–B7                   | B4–B7                   | PORTB                            |

## Especificaciones Generales

| Categoría                | Especificación             |
| ------------------------ | -------------------------------------------------- |
| **Arquitectura**         | 8 bits, núcleo Mid-Range RISC (35 instrucciones)   |
| **Flash**                | 4K palabras                                        |
| **RAM**                  | 192 bytes                                          |
| **EEPROM**               | 128 bytes                                          |
| **Puertos I/O**          | 22 pines digitales                                 |
| **Canales ADC**          | 5 canales (AN0–AN4), resolución 10 bits            |
| **Comparadores**         | No posee comparador integrado. No disponibles en versiones estándar. Disponibles (2) únicamente en versiones A, **PIC16F874A/877A**.                     |
| **PWM**                  | CCP1 y CCP2                                        |
| **Timers**               | TMR0 (8 bits), TMR1 (16 bits), TMR2 (8 bits)       |
| **USART**                | TX/RX en RC6/RC7                                   |
| **I²C / SPI**            | MSSP integrado                                     |
| **Voltaje de operación** | 2.0 – 5.5 V                                        |
| **Oscilador interno**    | No posee (requiere cristal o externo)              |
| **Interrupciones**       | INT, PORTB IOC, ADC, TMR0, TMR1, TMR2, USART, MSSP |
| **Programación**         | ICSP®                      |

## Diferencias dentro de la familia
| Característica         | Diferencias relevantes               |
| ---------------------- | ---------------------------------------------------------------------------------------------------- |
| **Memoria Flash**      | 873/873A: 4 KB, 874/874A: 4 KB, 876/876A/877/877A: 8 KB                                              |
| **Número de pines**    | 873/873A/874/874A: 28 pines, 876/876A/877/877A: 40 pines (33 I/O efectivos)               |
| **ADC**                | Todos tienen 10 bits, pero 876/877 tiene hasta 8 canales (AN0–AN7)                                   |
| **PWM (CCP)**          | 873/874: 2 módulos, 876/877: 2 módulos, algunas versiones soportan PWM en más pines                  |
| **USART / MSSP**       | 876/877 soporta master/slave SPI/I²C en los mismos pines, pero la configuración de TRIS puede variar |
| **Timers**             | 876/877 tiene Timer3 adicional (16 bits), ausente en 873/874                                         |
| **Comparador interno** | Algunas versiones (874A, 877A) incluyen comparadores en ciertos pines                                |
| **Oscilador**          | Todos requieren oscilador externo, pero los modos y pines CLKOUT/CLKIN pueden variar ligeramente     |

## Configuraciòn General

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

- Cuenta con cinco pines anàlogos que se encuentran distribuidas en el puerto A.

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

- Cuenta con dos pines para la comunicación serial (UART).   

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | -   | -   | -   | -   | -   | c6 (TX) | c7 (RX) |

### Funciones soportadas

La API Aixt proporciona funciones para manejar entradas/salidas digitales, puertos completos, el conversor **ADC**, la modulación **PWM**, comunicación serial **UART** y temporización.

| Función                      | Descripción                    |
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