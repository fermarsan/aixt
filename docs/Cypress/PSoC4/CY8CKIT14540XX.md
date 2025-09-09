# Guía rápida PSoC4
Esta implementación de Aixt para PSoC 4 da soporte a la tarjeta   CY8CKIT14540XX

# Identificación tarjeta CY8CKIT14540XX	

## Vista

![Alt text](Imagenes/CY8CKIT14540XX/vista_general.jpg)

## Hoja de datos
[CY8CKIT14540XX](https://www.infineon.com/dgdl/Infineon-CY8CKIT-145-40XX_PSoC_4000S_Prototyping_Kit_Guide-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0efccdd91344)



# Configuración general

Se integran las funciones básicas del microcontrolados para generar una estructura hardware general, asi;

- 3 pwms
- 9 leds
- 1 pulsador
- 2 puertos de comunicación
- 3 entradas digitales
- 3 salidas digitales
- 5 sensores capacitivos tipo slider
- 3 sensores capacitivos tipo boton

*visualización en PSoC creator*

![!\[Alt text\](Imagenes/CY8CKIT14540XX/vista_general.jpg)](Imagenes/CY8CKIT14540XX/Estructura_general_hardware_14540.jpg)

## Identificación de puertos
A continuación se muestran los puertos que se usan y sus debidos nombramientos para la programación: 

Puerto | nombre |Tipo    |
--  |-       |-       |
2.5 |led1    |salida
2.0 |led4    |salida
2.1 |led5    |salida
2.2 |led6    |salida
2.3 |led7    |salida
2.4 |led8    |salida
3.4 |led9    |salida
3.5 |led10   |salida
3.6 |led11   |salida
0.7 |sw2     |entrada
2.7 |di0     |entrada
0.4 |di1     |entrada
1.7 |di2     |entrada
4.0 |do0     |salida
0.5 |do1     |salida
3.7 |do2     |salida
1.2 |out_pwm0|salida
2.6 |out_pwm1|salida
1.0 |out_pwm2|salida
3.0 |\uart:rx\ |salida
3.1 |\uart:tx\ |salida
0.0 |sld0     |entrada
0.1 |sld1     |entrada
0.2 |sld2     |entrada
0.3 |sld3     |entrada
0.6 |sld4     |entrada
1.4 |btn0     |entrada
1.5 |btn1     |entrada
1.6 |btn2     |entrada

## Programación en lenguaje v

For each of these modules, you will have a file in .c.v format with the same name of the module and in this you will have the text module followed by the name of the module, example:

* module pin
* module pwm
* module uart
* module adc

Algo importante en esta tarjeta es la activación de los leds, estos se encienden con ceros logicos, como se puede apreciar en los leds correspondientes a los sensores capacitivos tipo slider:

![Alt text](Imagenes/CY8CKIT14540XX/leds14540.jpg)

### Output port configuration

Para activar el puerto que va ha usar;
```v
pin.high(pin_name)
```
*Ejemplo: si se desea activar el puerto de salida llamado led1; ` pin.high(led1)`.*

Para desactivar el puerto que se está usando;
```v
pin.low(pin_name)
```
*Ejemplo: si se desea desactivar puerto de salida llamado led1; `pin.low(led1)`.*

Para desactivar o activar el puerto que se va ha usar;

```v
pin.write(pin_name, value)
```
*Ejemplo: si se desea desactivar el puerto led1;  `pin.write(led1, 1)`, y si se desea activar;  `pin.write(led1, 0)`.*

### Detección puertos de entrada

Si se necesita saber en que estado esta un puerto de entrada:
```v
x = pin.read(pin_name)
```

*Ejemplo: Si se desea detectar el valor del puerto sw2;  `x = pin.read(sw2) `, y x tomara el valor de 0 o 1, dependiendo si el puerto está activo o desactivado.*

### PWM

Para configurar algún pwm;
```v
pwm.write(pwm.channel,duty)
```
*En pwm.channel se pone el pwm a usar,  y en duty el valor del ciclo de trabajo de un modulador (de 0 a 10000).*

### Serial comunication (UART)

Para configurar un puerto UART;
```v

uart.setup(),Starts the uart. 

uart.print("message...\r\n")

```
*Debido a que el puerto ya está definido como "uart:tx", este es el único puerto de comunicación serial Uart disponible, por lo tanto lo que se cescriba en lugar de "message" es la información que se va a imprimir.

uart.print(message string),  Places a NULL terminated string in the transmit buffer to be sent at the next
available bus time.

uart.println(), Places byte of data followed by a carriage return (0x0D) and line feed (0x0A)
to the transmit buffer.

uart.read(), Retrieves next data element from receive buffer.

uart.write(), Places a byte of data in the transmit buffer to be sent at the next available bus
time.


### ADC

Para configurar el módulo ADC utilizando los capsense de la tarjeta

adc.read(adc.channel)

El ADC por sí solo convierte la señal analógica en un número digital, pero ese número se queda dentro del microcontrolador. Para que la transmición y visualización de datos sea posible, se hace llamado de las funciones de la uart.

uart.setup(), inicia el modulo Uart

uart.println('ADC channel 0: ${analog}'), imprimir una cadena de texto y al final añadir un salto de línea. Contiene un texto fijo: "ADC channel 0:", contiene una interpolación de variable: ${analog}.



Para 
### Retardos

Uso de tiempos;

-Segundos
```v
time.sleep(s)
```
-milisegundos

```v
time.sleep_ms(ms)
```


-Microsegundos

```v
time.sleep_us(us)
```
*En cada expresión, el valor del tiempo se pone dentro del parentesis.*

Ejemplo LED parapadeante funcion high and low

import time {sleep_ms}
import pin



for {
<<<<<<< HEAD
	pin.high(led1)
	time.sleep_ms(5000)
	pin.low(led1)
	time.sleep_ms(5000)
}

Ejemplo LED parapadeante funcion write

```v
import time
import pin

for {
	pin.write(led_1, 0)
	time.sleep_ms(500)
	pin.write(led_1, 1)
	time.sleep_ms(500)
}

```
Ejemplo LED parapadeante funcion read

import time {sleep_ms}
import pin



for {
    if pin.read(sw2) == 1 {     // Si el botón está presionado (valor lógico alto)
        pin.high(led1)           // Encender LED
    } else {
        pin.low(led1)            // Apagar LED
    }

    time.sleep_ms(100)             // Pequeña espera para evitar rebotes
}


Ejemplo PWM

```v
import time {sleep_ms}
import pwm

//pin.setup(17, pin.output)

for {
    pwm.write(pwm.ch1, 10000)
    sleep_ms(500)

    pwm.write(pwm.ch1, 5000)
    sleep_ms(500)

    pwm.write(pwm.ch1, 0)
    sleep_ms(500)
    
 }

 ```

 Ejemplo UART

 import time {sleep_ms}
import uart

uart.setup()


for {

uart.print("Enviando por UART...\r\n")
time.sleep_ms(1000) 

}

Ejemplo ADC

import time
import uart
import adc

uart.setup()

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}

