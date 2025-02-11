# **_Aixt_** Application Programming Interface v0.1.2

## Digital I/O (Pins)
requires:
```v
import pin
```

### Pin setup
```v
pin.setup(pin_name, mode)
```
- `pin_name` could change depending on the microcontroller for instance `pin.b7`, `pin.gp7`, etc.
- `mode`:
  - `pin.input`
  - `pin.output`

### Pin output
```v
pin.high(pin_name)
```
```v
pin.low(pin_name)
```
```v
pin.toggle(pin_name)    
// not available for all devices
```
```v
pin.write(pin_name, value)
```
- `value` is an integer to be written in the pin
  - `0`
  - `1`


### Pin input
```v
x = pin.read(pin_name)
```
`pin.read()` returns an integer (`0` or `1`)

## Analog to Digital Converter (ADC inputs)
requires:
```v
import adc
```


The syntax for all the ADC functions is: `adcx_function_name()`, being `x` the identifying number in case of multiple ADCs. You can omit the `x` for referring to the first ADC or in the case of having only one.

### ADC setup
```v
adc.setup(setup_value_1, setup_value_2, ... )   // equals to adc1_setup(...)
```

### ADC reading
```v
x = adc.read(channel)
```
- `channel` is an identifying number of the ADC input, for instance `adc.ch3`


## Pulse Width Modulation (PWM outputs)
requires:
```v
import pwm
```

The syntax for all the PWM functions is: `pwm_function_name()`.

### PWM setup
```v
pwm_setup(setup_value_1, setup_value_2, ... )  //or just pwm.setup(...)
```

### PWM duty cycle
```v
pwm.write(channel, duty)  //or pwm1_duty(duty)
```

- `duty` is the duty cycle (8-bit number in most of devices)
- `channel` is th output or channel name, for instance `pwm.ch1`


## Serial communication (UART)
requires:
```v
import uart
```

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart.setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

### Serial receiving
```v
str1 = input()          // read a string from the default UART
```
```v
str2 = uart2_input()    // read a string from UART2
```
```v
str2 = uart1_read()    // read a single Byte from UART1
```

### Serial transmitting
```v
uart.print(message)      // print a string to the default UART
```
```v
uart.println(message)    // print a string plus a line-new character to the default UART
```
```v
uart2.print(message)    // print a string to the UART2
```
```v
uart3.println(message)  // print a string plus a line-new character to the UART3
```
```v
uart2.write(message)    // send binary data (in Bytes) to UART2
```


## Timming
requires:
```v
import time
```


```v
time.sleep(s)    // delay in seconds
```
```v
time.sleep_ms(ms)    // delay in milliseconds
```
```v
time.sleep_us(us)    // delay in microseconds
```




### Archivo `function_name.c.v`
Todas los funciones implementadas en cada módulo de **Aixt** tienen un archivo nombrado 
`nombre_funcion.c.v` donde se hace si implementación.

en este caso la función `setup` del módulo `adc`, que configura la resolución del ADC.

En los dispositivos que usan el _backend_ de **arduino** la mayoría de funcionalidades solamente se tienen que enmascarar en lugar de implementarlas desde cero. En este caso la función `setup` en V enmascara la función `analogReadResolution` de **arduino**.

Todas las funciones tienen que ser públicas (`pub`).

El atributo `@[inline]` es opcional y define que la función creada en C sea 'inline'.


### Archivo `module_name.c.v`
Todos los módulos implementados en el directorio `api` tienen un archivo con el mismo nombre del módulo. Por ejemplo el módulo `pwm` debe tiene un archivo `pwm.c.v` donde se hacen las definiciones básicas para el módulo.

En este caso se definen las funciones que van a ser invocadas desde C (arduino).

V permite el tipo de datos `any` que resulta ser práctico si no se conoce el tipo de datos de retorno y/o de los parámetros de la función a enmascarar.

En este caso la implementación puede quedar tal cual está.

### Inclusión de archivos en C
Los módulos de la API en **Aixt** pueden incluir archivos `.c` ó `.h`con la directiva `#include <lib.h>` ó `#include "lib.h"`. Teniendo en cuenta que los archivos incluidos entre `"` se buscarán en el mismo directorio.

### Enmascaramiento de métodos de arduino
En el caso del _backend_ de **arduino**, las funciones definidas como métodos se pueden redefinir como macros en un archivo `.c` para poder ser 'llamadas' desde V sin problemas.

Reemplazando el `.` por `_`.


Y cada función a implementar o enmascarar se describe en un archivo `.c.v` separado, para poder ser llamado independientemente desde V con el fin de utilizar la menor cantidad de memoria posible si así lo desea el usuario.

en este caso debemos reemplazar `Serial1` por solo `Serial` en todas las funciones.


Borramos los módulos no soportados
y listo

Ahora compilemos los ejemplos para corroborar el funcionamiento.

Renombramos las carpetas de ejemplos y los archivos `.v`

es aconsejable abrir un sesión diferente de vscode con unicamente el archivo del proyecto de ejemplo

debemos modificar el archivo `settings.json` del directorio `.vscode` con el nombre del nuevo dispositivo

En el caso del ejemplo del parpadeo, la transcompilación generó el archivo `.ino` y el archivo binario de salida en la carpeta `build`

ahora lo probamos en el  simulador **Wokwi**
podemos copiar el código generado al simulador

Como vemos el ejemplo del parpadeo funciona

Listo

No es mas por este video
nos vemos en un próximo video








