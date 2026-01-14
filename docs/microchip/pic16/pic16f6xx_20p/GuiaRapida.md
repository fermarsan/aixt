# Guia Rápida para PIC16F6xx_20p
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F6xx_20p (Incluye PIC16F685, PIC16F687, PIC16F689 y PIC16F690)  

**NOTA:** Microcontrolador de 8 bits, arquitectura RISC, la familia **PIC16F6xx_20p** ofrece mayor cantidad de pines y periféricos que la serie 18p. Incluye **ADC**, comparadores, **USART**, **PWM (CCP1)**, oscilador interno, referencia de voltaje interna **FVR** y módulos digitales avanzados, siendo ideal para control, adquisición de señales analógicas y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `c3` indica el pin 3 del puerto c. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir. [V variable naming rules.] (https://github.com/vlang/v/blob/master/doc/docs.md#variables).

| Puerto |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
| :----: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  **A** |  a0 |  a1 |  a2 |  a3 |  a4 |  a5 |  a6 |  a7 |
|  **B** |  b0 |  b1 |  b2 |  b3 |  b4 |  b5 |  b6 |  b7 |
|  **C** |  c0 |  c1 |  c2 |  c3 |  c4 |  c5 |  c6 |  c7 |

| Pin Especial | Funciones Principales   |
| ----------------- | ---------------------------------------------------------------------- |
| **a0–a7**         | Entradas analógicas ADC (multiplexadas con pines digitales).           |
| **a5**            | MCLR (Reset) o entrada digital (configurable).                         |
| **b0**            | Interrupción externa INT.                                              |
| **b4–b7**         | Interrupciones por cambio de estado (Port Change).                     |
| **c2**            | PWM (CCP1).                                                            |
| **c6**            | USART TX (si aplica).                                                  |
| **c7**            | USART RX (si aplica).                                                  |
| **Otros pines C** | Multiplexados con ADC, temporizadores o funciones digitales generales. |

**Pines ADC**: requieren configurar **ANSEL / ANSELH** para habilitar o deshabilitar la función analógica.
**Pines multiplexados**: muchos pines pueden funcionar como digital o como periférico **(ADC, PWM, USART)**.
**MCLR/a5**: en modelos que lo permiten, se puede usar como entrada digital; de lo contrario solo reset.

**20-pin PDIP, SOIC, SSOP**

![alt text](image.png)
![alt text](image-1.png)
![alt text](image-2.png)
Fuente: (https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001262F.pdf)

## Especificaciones Principales

| Modelo        | Program Memory (KB) | RAM (bytes) | EEPROM (bytes) | Pines | Voltaje operación (V) | ADC  | PWM (CCP1) | USART | Osc. interno |
| ------------- | ------------------- | ----------- | -------------- | ----- | --------------------- | ---- | ---------- | ----- | ------------ |
| **PIC16F685** | 7                   | 256         | 256            | 20    | 2.0 – 5.5             | 8ch  | Sí         | No    | Sí           |
| **PIC16F687** | 3.5                 | 128         | 256            | 20    | 2.0 – 5.5             | 8ch  | Sí         | Sí    | Sí           |
| **PIC16F689** | 7                   | 256         | 256            | 20    | 2.0 – 5.5             | 12ch | Sí         | Sí    | Sí           |
| **PIC16F690** | 7                   | 256         | 256            | 20    | 2.0 – 5.5             | 12ch | Sí         | Sí    | Sí           |

**ADC**: resolución de 10 bits, algunos modelos tienen 8 canales (685, 687), otros 12 (689, 690).
**PWM (CCP1)**: todos los modelos incluyen un módulo de **PWM**, usando el temporizador **TMR2**.
**USART**: no disponible en **PIC16F685**, sí en 687, 689 y 690.
**Oscilador interno**: todos los modelos permiten operación sin osciloscopio externo.
**EEPROM**: 256 bytes en todos los modelos, útil para almacenamiento de datos persistente.

Fuente: (https://www.microchip.com/en-us/product/pic16f685)
(https://www.microchip.com/en-us/product/pic16f687)
(https://www.microchip.com/en-us/product/pic16f689)
(https://www.microchip.com/en-us/product/pic16f690)

## Caracterìsticas

- Todos los pines **ADC** requieren configuración de **ANSEL / ANSELH** para operar correctamente.
- Los pines de **PORTC** son multiplexados con **PWM**, **USART** y **ADC**.
- `MCLR/a5` puede funcionar como entrada digital en algunos modelos.
- Adecuados para control de motores, comunicación serial, adquisición de señales analógicas y sistemas embebidos compactos.

| Característica                | Descripción  |
| ----------------------------- | --------------------------------------------------------------------- |
| Arquitectura                  | **RISC de 8 bits**  |
| Encapsulados                  | PDIP-20, SOIC-20, SSOP-20                                             |
| Memoria de programa           | 3.5 KB – 7 KB (dependiendo del modelo)                         |
| RAM                           | 128 – 256 bytes                           |
| EEPROM de datos               | 256 bytes                           |
| Pines de E/S                  | 20 pines digitales (PORTA, PORTB, PORTC)                          |
| Voltaje de operación          | 2.0 – 5.5 V                               |
| Frecuencia máxima             | 20 MHz                             |
| Oscilador interno             | Sí, hasta 8 MHz                           |
| ADC                           | Sí, resolución 10 bits, 8–12 canales según modelo                     |
| PWM (CCP1)                    | Sí, usa TMR2 como base de tiempo                          |
| USART                         | Sí (excepto PIC16F685)             |
| Comparadores analógicos       | 2, deshabilitables mediante CMCON0                          |
| Interrupciones                | Externa (INT) + cambio de estado en PORTB4–PORTB7                   |
| Watchdog Timer                | Sí                              |
| Modo Sleep                    | Sí                              |
| Referencia de voltaje interna | Sí, controlable por VRCON/FVRCON                          |
| Temporizadores                | TMR0 (8 bits), TMR1 (16 bits), TMR2 (8 bits)                          |
| Retardos por software         | Compatibles con Aixt (`time.sleep`, `time.sleep_ms`, `time.sleep_us`) |

## Codigo Base Aixt (E/S)

Pines **ADC (a0–a7)**: deben configurarse en **ANSEL / ANSELH** si se usan como digitales.
**USART**: `TX` → `c6`, `RX` → `c7` (solo modelos con USART).
**PWM (CCP1)**: pin `c2`, requiere configurar TMR2 y CCP1CON para PWM real.
**Interrupciones**: pin `b0` → **INT** externa, pines `b4–b7` → interrupción por cambio de estado.
Este código es base de manipulación de E/S digital, para **ADC** real o **PWM** se deben usar módulos dedicados.

```v
import pin

// Configuración de pines
pin.setup(pin.a0, pin.input)    // Entrada analógica o digital
pin.setup(pin.b0, pin.input)    // Interrupción externa
pin.setup(pin.b2, pin.output)   // Salida digital
pin.setup(pin.c2, pin.output)   // PWM o salida digital
pin.setup(pin.c6, pin.output)   // USART TX (si aplica)
pin.setup(pin.c7, pin.input)    // USART RX (si aplica)

// Escritura digital
pin.high(pin.b2)   // Pone el pin B2 en alto
pin.low(pin.c2)    // Pone el pin C2 en bajo

// Alternar estado
pin.toggle(pin.b7)

// Lectura digital
value := pin.read(pin.a0)

// Eco entrada → salida
pin.write(pin.b2, pin.read(pin.a0))


adc_value := pin.read(pin.a1)       // Ejemplo de lectura múltiple y salida (Leer A1)
pin.write(pin.c2, adc_value > 512)  // Salida PWM digital simplificada
```

## Oscilador

Todos los modelos incluyen oscilador interno configurable por software.
**Frecuencias típicas**: 31 kHz – 8 MHz, suficiente para comunicación serial, temporizadores y PWM.
Permite operación sin cristal externo, simplificando el diseño.
La constante `CPU_FREQ` debe coincidir con la frecuencia real del oscilador para que los retardos y temporizaciones sean precisos.

```v
@[as_macro]
pub const CPU_FREQ: u32 = 8_000_000  // 8 MHz
```

También soporta oscilador externo (cristal o resonador):

- `LP` – Baja frecuencia
- `XT` – Cristal/resonador estándar
- `HS` – Alta velocidad
- `RC` – Oscilador RC externo

Conectar a los pines **OSC1/OSC2**.

## MCLR (Master Clear / Reset)

Pin `a5` funciona como MCLR externo (reset) o como entrada digital en los modelos que lo permiten **PIC16F685, 687, 689, 690**.
La configuración se realiza mediante bits de configuración del microcontrolador.
Si se usa como reset, se debe conectar a **VDD** mediante un resistor **pull-u**p** y a un pulsador o señal externa.
En modo digital, **TRISA5** debe configurarse como entrada.

## Temporizadores

Prescalers y postscalers permiten ajustar la frecuencia de conteo de los temporizadores.
**TMR2** se usa directamente para **PWM**, liberando al **CPU** de generar la señal manualmente.
Los temporizadores se pueden usar para retardos precisos o no bloqueantes, evitando depender solo de retardos por software (time.sleep).
Interrupciones: cada temporizador puede generar interrupciones cuando se desborda, permitiendo acciones periódicas sin bloquear el **CPU**.

| Temporizador | Tamaño  | Descripción    |
| ------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| **TMR0**     | 8 bits  | Temporizador/contador de propósito general. Puede usar prescaler compartido con Watchdog Timer. Permite contar pulsos internos o externos.       |
| **TMR1**     | 16 bits | Temporizador de alta resolución, ideal para mediciones precisas, generación de interrupciones periódicas o control de eventos temporizados.      |
| **TMR2**     | 8 bits  | Temporizador con **postscaler**, utilizado como base de tiempo para el **módulo PWM (CCP1)**. Configurable para tareas de temporización simples. |

## Retardos

Los retardos se pueden implementar por software o utilizando temporizadores. Los retardos por software son adecuados para tareas simples; para temporizaciones precisas o no bloqueantes se recomienda usar los temporizadores **TMR0, TMR1 o TMR2**.

```v
import time

time.sleep(2) // Retardo de 2 segundos      

time.sleep_ms(50) // Retardo de 50 milisegundos  

time.sleep_us(100)  // Retardo de 100 microsegundos

@[as_macro]
pub const CPU_FREQ: u32 = 8_000_000  // 8 MHz
// La constante CPU_FREQ debe coincidir con la frecuencia real del oscilador para que los retardos sean precisos.
```

Para tareas que requieren precisión de microsegundos o sincronización exacta, es recomendable usar **TMR0/TMR1/TMR2** en lugar de retardos por software.
Retardos por software bloquean la **CPU**, por lo que no se recomienda para aplicaciones multitarea o interrupciones críticas.

## Módulos integrados
- **ADC (Conversor Analógico–Digital)**

**Resolución**: 10 bits
**Canales**: 8–12, según modelo
**Pines**: a0–a7 (multiplexados)
Controlado mediante registros **ADCON0 y ADCON1**
Requiere configurar **ANSEL / ANSELH** para habilitar/deshabilitar función analógica

| Registro                         | Función                 |
| -------------------------------- | ----------------------- |
| PORTA/B/C                        | E/S digital             |
| TRISA/B/C                        | Dirección pines         |
| INTCON                           | Interrupciones          |
| PIE1 / PIR1                      | Flags periféricos       |
| TMR0 / TMR1 / TMR2               | Temporizadores          |
| CCP1CON                          | PWM                     |
| TXSTA / RCSTA                    | USART                   |
| ADCON0 / ADCON1                  | ADC                     |
| CMCON0 / VRCON                   | Comparadores analógicos |
| EECON1 / EECON2 / EEADR / EEDATA | EEPROM                  |

- **PUSART (Transmisor/Receptor Universal Asíncrono)**
Disponible en **PIC16F687**, 689, 690
Pines: c6 → TX, c7 → RX
Permite comunicación serial a diferentes velocidades (baud rate)
Usa hardware dedicado, liberando **CPU**

| Registro | Función                           |
| -------- | --------------------------------- |
| **TXSTA**    | Control del transmisor            |
| **RCSTA**    | Control del receptor              |
| **SPBRG**    | Generador de velocidad de baudios |

- **PWM (CCP1)**
**Pin**: c2
**Resolución**: 10 bits para el ciclo de trabajo
Se sincroniza con **TMR2**, no requiere **CPU** para generar señal
Ideal para control de motores y LEDs

| Registro | Función                                  |
| -------- | ---------------------------------------- |
| **CCP1CON**  | Configuración del módulo CCP1 (modo PWM) |
| **PR2**      | Determina el período del PWM             |
| **TMR2**    | Temporizador base del PWM                |
| **CCPR1L**   | Ajusta el ciclo de trabajo (duty cycle)  |

- **Comparadores Analógicos**
Dos comparadores integrados
Entradas multiplexadas con pines ADC
Deshabilitables mediante **CMCON0 = 0x07** para usar los pines como digitales
Salida: 1 → V+ > V-, 0 → V+ < V-
Salida puede usarse para interrupciones o lógica interna
Configurar **FVRCON** para referencia de 1.024V, 2.048V o 4.096V.

 | Registro | Función                       |
| -------- | ----------------------------- |
| CMCON0   | Configuración de comparadores |
| VRCON    | Referencia interna de voltaje |

- **EEPROM**

256 bytes de memoria no volátil
Guarda configuraciones o contadores aunque se apague la alimentación

| Registro | Función                                |
| -------- | -------------------------------------- |
| **EECON1**   | Control de lectura/escritura           |
| **EECON2**   | Secuencia de desbloqueo para escritura |
| **EEADR**    | Dirección del byte a leer/escribir     |
| **EEDATA**   | Dato que se leerá o escribirá          |

Todos los módulos están multiplexados con pines de **E/S**, por lo que es necesario configurar correctamente **TRIS, ANSEL/ANSELH** y los registros de control.
Los comparadores y **ADC** pueden coexistir; se recomienda deshabilitar los comparadores si se necesita usar todos los pines como digitales.
**USART** y **PWM** liberan a la **CPU** de generar señales manualmente, optimizando el rendimiento.

## ADC (Conversor Analógico–Digital)

La familia **PIC16F6xx_20p** incorpora un ADC de 10 bits, permitiendo la conversión directa de señales analógicas a valores digitales, característica inexistente en la serie 18p.

**Resolución**: 10 bits (0–1023)
**Canales ADC**: entre 8 y 12, según modelo
**Referencias**: VDD / VSS o referencia interna
Conversión controlada por hardware

| Registro   | Función                                              |
| ---------- | ---------------------------------------------------- |
| **ADCON0** | Selección de canal y control de inicio de conversión |
| **ADCON1** | Justificación del resultado y referencia de voltaje  |
| **ADRESH** | Resultado alto de la conversión                      |
| **ADRESL** | Resultado bajo de la conversión                      |

| Modelo    | Canales ADC por modelo |
| --------- | ----------- |
| PIC16F685 | 8           |
| PIC16F687 | 8           |
| PIC16F689 | 12          |
| PIC16F690 | 12          |

## Configuración analógica (ANSEL / ANSELH)

Los pines con capacidad ADC inician por defecto en modo analógico.
Para utilizarlos como pines digitales es obligatorio deshabilitar la función analógica.

| Registro   | Función                                                           |
| ---------- | ----------------------------------------------------------------- |
| **ANSEL**  | Habilita entradas analógicas en PORTA y PORTC                     |
| **ANSELH** | Habilita entradas analógicas adicionales (modelos con >8 canales) |

## Puerto C (PORTC)

El PORTC es un puerto completo de propósito general y además aloja los principales periféricos del microcontrolador:

- c2 → **PWM (CCP1)**
- c6 → **USART TX**
- c7 → **USART RX**

Pines multiplexados con **ADC** y temporizadores
Muchos pines de **PORTC** requieren:
- Configurar **TRISC**
- **ANSEL/ANSELH** y registros de periféricos antes de usarlos.

Deshabilitar funciones analógicas si no se usan

## Uso tipico

- Reemplazo del PIC16F84:

  - Más memoria y periféricos.
  - Proyectos de control básico con oscilador interno.

- Control de motores con PWM:

  - Pin c2 como salida PWM.
  - Permite regular velocidad de motores o intensidad de LEDs sin usar CPU.

- Comunicación Serial (USART):

  - Modelos 687, 689, 690.
  - Pines c6 → TX, c7 → RX.

- Lectura de señales analógicas (ADC):

  - Pines a0–a7 como entradas ADC.
  - Requiere configurar ANSEL / ANSELH y registros ADC.
 
- Interrupciones:

  - b0 → Interrupción externa (INT)
  - b4–b7 → Interrupciones por cambio de estado

- Entrada/Salida digital simple:

  - Leer y escribir pines digitales (pin.read, pin.write).

- Sistemas de bajo consumo:

  - Modo Sleep y Watchdog Timer disponibles.
  - Ideal para dispositivos portátiles o sensores remotos.

  ### Ejemplo (PWM variable – Pin c2 (CCP1))

 ```v
  import pin, pwm, time

pin.setup(pin.c2, pin.output) // Configuración del pin como salida

pwm.setup(pin.c2, 1000) // Configuración PWM: frecuencia 1 kHz

pwm.set_duty(pin.c2, 512)  // Ciclo de trabajo inicial (50%)

for duty in 0..1024 step 64 {
    pwm.set_duty(pin.c2, duty) // Ajusta ciclo de trabajo (rango es 0–1023 (10 bits).)
    time.sleep_ms(100)  // Retardo para ver cambio (barrido de LED)
}
```

  ### Ejemplo (Comunicación Serial – USART (Pins c6 → TX, c7 → RX)) - Aplican solo en PIC16F687, PIC16F689 y PIC16F690.

```v
import pin, usart, time

usart.setup(9600) // Configuración USART 9600 bps

usart.write("Hola Mundo desde PIC16F6xx_20p\n") // Enviar un mensaje

value := usart.read()  // Retorna -1 si no hay datos
if value != -1 {
    // Eco de lo recibido al mismo puerto
    usart.write(value)  // Leer datos si hay disponibles
}

while true {
    val := usart.read() // Retorna -1 si no hay datos
    if val != -1 {
        usart.write(val)  // Reenviar al PC (bucle continuo)
    } 
}
```

Estos ejemplos permiten iniciar rápidamente el desarrollo con PIC16F6xx_20p usando Aixt. Para proyectos más avanzados, se recomienda revisar los registros CCP1, TMR2 y USART según la ficha de datosa de la pagina principal de microchip (https://www.microchip.com/).
