# Guía rápida de PIC16F6xx_14p
## Referencia del PIC16 utilizado por la marca MICROCHIP
- PIC16F6xx_14p (Incluye PIC16F630, PIC16F676 y PIC16F684)

**NOTA** Una guía rápida **NO** incluye el **datasheet**, solo lo esencial que afecta la configuración, el uso de pines, el **ADC**, está disponible únicamente en los PIC16F676 y PIC16F684. El PIC16F630 no dispone de **ADC**.

## Nombres de los pines

Los nombres de los pines se componen de una letra que indica el puerto y un número que indica el pin. Por ejemplo, **c1** indica el pin **1** del puerto **c**. Todos los nombres en Aixt se escriben en minúsculas [Reglas de nomenclatura de variables V]. (https://github.com/vlang/v/blob/master/doc/docs.md#variables)

Estos pines pueden funcionar como entradas o salidas digitales, entradas analógicas para el **ADC** o desempeñar funciones especiales como reloj, interrupciones o comparadores. Conocer esta nomenclatura permite configurar correctamente cada pin y aprovechar todas las capacidades del microcontrolador sin conflictos entre sus funciones digitales y analógicas.

| Puerto | 0    | 1    | 2    | 3    | 4    | 5    | 6     | 7     |
| :----: | ---- | ---- | ---- | ---- | ---- | ---- | ----- | ----- |
|  **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | - | - |
|  **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | - | - |

Las funciones analógicas **ADC** solo están disponibles en los PIC16F676 y PIC16F684. El PIC16F630 utiliza todos los pines únicamente como E/S digitales.

#### 14-pin PDIP, SOIC, TSSOP
![alt text](image-2.png) Fuente: (https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40039F.pdf)

#### 14-Pin Diagram (PDIP, SOIC, TSSOP)
![alt text](image-3.png)
Fuente: https://ww1.microchip.com/downloads/en/DeviceDoc/41202F-print.pdf

## Caracteristicas

| **Característica**              | **Valor**                             |
| ------------------------------- | ------------------------------------- |
| **Familia**                     | PIC16F6xx_14p                         |
| **Arquitectura**                | 8 bits, núcleo Mid-Range RISC         |
| **Memoria de programa (Flash)** | ~1K palabras                          |
| **RAM (SRAM)**                  | 64 bytes                              |
| **EEPROM de datos**             | 128 bytes                             |
| **Número de pines**             | 14                                    |
| **Puertos de E/S**              | 2 (Puerto A y Puerto C)               |
| **Pines digitales**             | Hasta 12 pines I/O                    |
| **ADC**                         | Solo PIC16F676 y PIC16F684            |
| **Resolución ADC**              | 10 bits (cuando está disponible)      |
| **Comparadores**                | 1 comparador analógico                |
| **Timers**                      | Timer0 (8 bits), Timer1 (16 bits)     |
| **Oscilador interno**           | 4 MHz calibrado (OSCCAL)              |
| **Voltaje de operación**        | 2.0 V – 5.5 V                         |
| **Consumo**                     | Bajo consumo con modo Sleep           |
| **Interrupciones**              | INT, Timer0, Timer1, IOC              |
| **Programación**                | ICSP® (In-Circuit Serial Programming) |

Las características son comunes para los tres dispositivos de la familia **PIC16F6xx_14p**.

## Especificaciones Generales

- Las especificaciones son comunes para la familia **PIC16F6xx_14p**.
- Las funciones analógicas **ADC** no están presentes en el **PIC16F630**.

| **Categoría**                 | **Especificación**                                     |
| ----------------------------- | ------------------------------------------------------ |
| **Arquitectura**              | 8 bits, núcleo Mid-Range RISC (35 instrucciones)       |
| **Memoria de programa**       | ~1K palabras de Flash                                  |
| **RAM (SRAM)**                | 64 bytes                                               |
| **EEPROM**                    | 128 bytes                                              |
| **Puertos de E/S**            | Puerto A y Puerto C                                    |
| **Pines de E/S digitales**    | Hasta 12 pines (RA0–RA5, RC0–RC5)                      |
| **Entradas analógicas (ADC)** | Disponible solo en PIC16F676 y PIC16F684 (10 bits)     |
| **Comparadores**              | 1 comparador analógico                                 |
| **Timers**                    | Timer0 (8 bits), Timer1 (16 bits)                      |
| **Oscilador interno**         | 4 MHz calibrado (OSCCAL)                               |
| **Reloj externo**             | OSC1/OSC2 disponibles                                  |
| **Voltaje de operación**      | 2.0 V a 5.5 V                                          |
| **Consumo**                   | Bajo consumo con modo Sleep                            |
| **Interrupciones**            | INT externo, Timer0, Timer1, IOC (Interrupt-on-Change) |
| **Programación**              | ICSP® (In-Circuit Serial Programming)                  |
| **Encapsulado**               | DIP-14 / SOIC-14                                       |

## Configuracion General

La configuración inicial del microcontrolador define el comportamiento básico de los pines, los puertos y los periféricos antes de comenzar la ejecución del programa principal. En la familia **PIC16F6xx_14p**, es recomendable configurar primero el modo digital de los pines, establecer la dirección de los puertos y, si el modelo lo permite, habilitar el módulo **ADC**.

```v
import pin
import port
import adc
import time

pin.setup(pin.a0, pin.output) // Pines digitales
pin.setup(pin.a1, pin.input)
pin.setup(pin.a2, pin.output)
pin.setup(pin.c0, pin.input)
pin.setup(pin.c3, pin.output)

pin.digital() 
// Configurar todos los pines 
// como digitales (ANSEL = 0, CMCON = 0x07)

port.setup(port.a, 0b000000)   // Puerto A como salidas
port.setup(port.c, 0b000011)   // RC0 y RC1 entradas, resto salidas

adc.setup()          // Inicializa ADC (solo PIC16F676 y PIC16F684)
adc.read(0)          // Selecciona AN0 como canal de lectura
```

## Límites Eléctricos

| **Parámetro** | **Valor / Rango**        | **Descripción / Observación**|
| -------------------------------------- | ------------------------ | ---------------------------------------------------------------------------------------- |
| **Voltaje de operación (VDD)**         | **2.0 V – 5.5 V**        | Rango recomendado para funcionamiento normal del microcontrolador.                       |
| **Voltaje máximo en pines**            | **−0.3 V a VDD + 0.3 V** | Límites absolutos para evitar daño en los pines de E/S.                                  |
| **Corriente máxima por pin I/O**       | **25 mA**                | Máxima corriente permitida por pin de salida. No exceder para evitar sobrecalentamiento. |
| **Corriente máxima por puerto**        | **80 mA**                | Suma total de corrientes por puerto A o C. Importante para manejar múltiples LEDs.       |
| **Corriente total del dispositivo**    | **~200 mA** (máx.)       | Límite absoluto del chip. No se debe operar cerca de este valor.                         |
| **Corriente en modo Sleep**            | **< 1 µA típico**        | Consumo ultra bajo cuando se usa SLEEP.                                                  |
| **Frecuencia del oscilador interno**   | **4 MHz**                | Oscilador interno calibrado (precisión ajustable con OSCCAL).                            |
| **Resistencia recomendada para MCLR**  | **10 kΩ**                | Valor típico para pull-up en el pin RA3/MCLR.                                            |
| **Frecuencia máxima de reloj externo** | **20 MHz**               | Solo si se usa cristal o fuente externa (modo HS/XT/EC).                                 |

Estos valores corresponden a condiciones típicas de operación. Para valores absolutos y condiciones extremas, consulte siempre la hoja de datos oficial de Microchip.

## Tabla de Registros Clave (TRIS, PORT, ANSEL, ADCON)

| **Registro**             | **Función**             | **Descripción / Para qué sirve**                                                                     |
| ------------------------ | ----------------------- | ---------------------------------------------------------------------------------------------------- |
| **TRIS** (TRISA / TRISC) | Dirección de pines      | 1 = Entrada, 0 = Salida. Define el modo de cada pin antes de usarlo.                                 |
| **PORT** (PORTA / PORTC) | Estado de pines         | Permite **leer** entradas o **escribir** salidas digitales según su configuración en TRIS.           |
| **ANSEL**                | Configuración analógica | Selecciona qué pines funcionan como **entradas analógicas** para el ADC. 1 = Analógico, 0 = Digital. |
| **ADCON0**               | Control del ADC         | Activa el ADC, selecciona canal y ejecuta la conversión.                                             |
| **ADCON1**               | Configuración del ADC   | Ajusta referencias (VDD/VSS), velocidad del ADC y justificación del resultado de 10 bits.            |

Los registros **ANSEL**, **ADCON0** y **ADCON1** no existen en el **PIC16F630**, ya que este dispositivo no incluye módulo **ADC**. **Solo existen** en los PIC16F676 y PIC16F684.
Para la familia **PIC16F6xx_14p**, estos registros deben usarse únicamente cuando se trabaja con **PIC16F676** o **PIC16F684**.

## Timer

| **Timer**  | **Registro(s)**                               | **Disponible en** | **Descripción / Uso Básico** |
| ---------- | --------------------------------------------- | ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Timer0** | `OPTION_REG`<br>`INTCON` (T0IE, T0IF)         | 630 · 676 · 684   | Temporizador de 8 bits con prescaler. Usa reloj interno (Fosc/4) o entrada externa **RA2/T0CKI**. Genera interrupción al desbordar. Ideal para retardos simples y conteo de eventos. |
| **Timer1** | `T1CON`<br>`PIE1` (TMR1IE)<br>`PIR1` (TMR1IF) | 676 · 684         | Temporizador de 16 bits más preciso. Puede usar reloj interno o externo por **T1CKI**. Soporta prescaler. Adecuado para mediciones de tiempo estables.                                 |

* Timer1 NO está disponible en el **PIC16F630**.

## Interrupciones

| **Registro** | **Función**                      | **Descripción / Uso básico** |
| ------------ | -------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **INTCON**   | Control global de interrupciones | Contiene los bits principales: **GIE** (habilita todas las interrupciones), **PEIE** (periféricas), **T0IE/T0IF** (Timer0), **INTE/INTF** (RA2/INT), **RAIE/RAIF** (cambio en Puerto A). |
| **PIE1**     | Habilitación de interrupciones   | Permite activar interrupciones de periféricos internos como **Timer1 (TMR1IE)** y **ADC (ADIE)**. Requiere **PEIE = 1**.                                                                 |
| **PIR1**     | Banderas de interrupción         | Indica qué módulo generó la interrupción (**TMR1IF**, **ADIF**, etc.). Deben limpiarse por software.                                                                                     |
| **IOCA**     | Interrupt-on-change (Puerto A)   | Habilita interrupciones cuando un pin del **Puerto A** cambia de estado. Útil para botones o sensores sin sondeo continuo. |

#### Tipos de interrupciones disponibles
- Timer0 overflow
- Timer1 overflow
- Interrupción externa por pin RA2/INT
- Interrupt-on-change en pines del Puerto A
- ADC complete (solo PIC16F676 y PIC16F684)

El **PIC16F630** no incluye **ADC**, por lo tanto no genera interrupciones por **ADC**.
Todas las interrupciones requieren que `GIE` = 1 en `INTCON`.
Las interrupciones periféricas necesitan `PEIE` = 1 además del bit específico en `PIE1`.

## Configuración del Oscilador

| **Componente / Registro** | **Función**                       | **Descripción / Uso básico**                                                                                                   |
| ------------------------- | --------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| **OSCCAL**                | Calibración del oscilador interno | Ajusta la frecuencia del oscilador interno (~4 MHz). El valor viene grabado de fábrica y debe cargarse al inicio del programa. |
| **Oscilador interno**     | Fuente de reloj principal         | Oscilador interno de **4 MHz**, suficiente para la mayoría de aplicaciones sin cristal externo.                                |
| **Bits de configuración** | Selección del modo de oscilador   | Permite seleccionar **INTOSC**, **LP**, **XT**, **HS** o **EC** según la aplicación.                                           |
| **OSC1/CLKIN (RA5)**      | Entrada de reloj externo          | Se usa cuando se selecciona cristal o fuente de reloj externa.                                                                 |
| **OSC2/CLKOUT (RA4)**     | Salida de reloj                   | Proporciona la señal del oscilador externo o puede usarse como pin digital según el modo.                                      |

#### Modos de oscilador (fuses)

Los fuses (también llamados configuration bits o configuration fuses) son bits de configuración especiales que definen el comportamiento básico del microcontrolador antes de que el programa comience a ejecutarse.

Permiten configurar funciones fundamentales del PIC, como:

- Fuente de reloj / oscilador: INTOSC, XT, HS, LP, EC.
- Watchdog Timer (WDT) habilitado o deshabilitado.
- Brown-Out Reset (BOR) habilitado o deshabilitado.
- MCLR configurado como reset externo o como pin digital.
- Protección de código (Code Protection).
- Power-Up Timer (PWRT).

**Funcionamiento**:

- Los fuses se leen al encender o resetear el microcontrolador.
- Funcionan independientemente del programa.
- Se configuran al grabar el PIC, no durante la ejecución normal.
- Se definen en el programador (PICkit), en MPLAB o en el archivo de configuración del proyecto.
- En Aixt y otros compiladores, suelen declararse como directivas de configuración.

Una configuración incorrecta de fuses puede provocar que el **PIC no arranque**, **no pueda programarse fácilmente** o **funcione a una frecuencia incorrecta**.

Los fuses más importantes en una guía rápida son: **Oscilador**, **WDT** y **MCLR**; los demas se pueden consultar en la ficha de datos completa en la pagina principal (https://www.microchip.com/).

Ejemplo:
```v
Oscillator = INTOSC
WDT        = OFF
MCLR       = ENABLED
BOR        = ON
```

| **Modo**   | **Uso típico**                                                           |
| ---------- | ------------------------------------------------------------------------ |
| **INTOSC** | Oscilador interno de 4 MHz (modo recomendado para proyectos educativos). |
| **LP**     | Cristales de muy baja frecuencia (bajo consumo).                         |
| **XT**     | Cristales estándar (frecuencias medias).                                 |
| **HS**     | Cristales de alta velocidad (hasta 20 MHz).                              |
| **EC**     | Fuente de reloj externa digital.                                         |

## Modos de Reset y WDT

Es importante tener en cuenta que:
- **POR** y **BOR** actúan automáticamente y no requieren código.
- **MCLR** depende de la configuración del fuse correspondiente.
- El **WDT** puede habilitarse o deshabilitarse mediante fuses.
- En modo **SLEEP**, el consumo es extremadamente bajo y el WDT puede usarse como temporizador de despertar.

| **Modo / Registro**       | **Función**                   | **Descripción / Uso Básico**  |
| ------------------------- | ----------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| **POR (Power-On Reset)**  | Reset por encendido           | Se activa automáticamente cuando el PIC recibe alimentación. Garantiza que el microcontrolador arranque en un estado estable. |
| **MCLR (Reset Externo)**  | RA3/MCLR                      | Al llevar MCLR a nivel bajo, el PIC se reinicia. Útil para depuración o botones de reinicio.                                  |
| **BOR (Brown-Out Reset)** | Protección por bajo voltaje   | Reinicia el PIC si VDD cae por debajo de un umbral crítico. Evita funcionamiento inestable por baja tensión.                  |
| **WDT (Watchdog Timer)**  | Reinicio por tiempo excedido  | Reinicia el PIC si el programa se “congela” o tarda demasiado en ejecutarse. Requiere instrucciones periódicas **CLRWDT**.    |
| **WDT Prescaler**                | Control del tiempo del WDT               | Permite ajustar el tiempo (ms) de espera del WDT mediante prescaler (configurable por fuses).                 |
| **SLEEP**                 | Modo de bajo consumo          | El PIC entra en consumo mínimo; sale del modo por interrupciones o por WDT.  |

## Ejemplo, uso de pines

```v
import pin
import port
import time

// Configuración de pines
pin.setup(pin.a0, pin.output) // RA0 como salida
pin.setup(pin.a1, pin.input)  // RA1 como entrada
pin.setup(pin.c3, pin.output) // RC3 como salida

// Encender y apagar un pin
pin.high(pin.a0)              // Coloca RA0 en nivel alto
time.sleep_ms(500)
pin.low(pin.a0)               // Coloca RA0 en nivel bajo

// Alternar un pin
pin.toggle(pin.c3)            // Cambia el estado de RC3

// Leer un pin de entrada
value := pin.read(pin.a1)     // Lee el estado lógico de RA1

// Eco: copiar entrada a salida
pin.write(pin.c3, value)      // RC3 toma el valor leído en RA1
```