# Guía rápida PSoC4
Esta implementación de Aixt para PSoC 4 da soporte a la tarjeta   CY8CKIT-049-42XX; 


# Identificación tarjeta CY8CKIT-049-42XX

## Vista
*Parte superior*


## Hoja de datos
[CY8CKIT-049-42XX](https://www.infineon.com/dgdl/Infineon-CY8CKIT-049-4xxx_PSoC_4_Prototyping_Kit_Guide-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0ef17bd002cb)

# Programación de la tarjeta
Originalmente se realiza por medio de PSoC creator 4.4



# Configuración general

Se integran las funciones básicas del microcontrolados para generar una estructura hardware general, asi;

- 4 pwms
- 1 leds
- 1 pulsador
- 2 puertos de comunicación
- 11 entradas digitales
- 11 salidas digitales
- 4 entradas análogas

*visualización en PSoC creator*
![Alt text](<Imagenes/CY8CKIT04942XX/WhatsApp Image 2023-09-19 at 9.36.34 PM.jpeg>)

![Alt text](<Imagenes/CY8CKIT04942XX/WhatsApp Image 2023-09-19 at 9.36.43 PM.jpeg>)

## Identificación de puertos
A continuación se muestran los puertos que se usan y sus debidos nombramientos para la programación: 

Puerto | nombre |Tipo    |
--  |-       |-       |
1.6 |led1    |salida
0.7 |sw1     |entrada 
0.0 |di0     |entrada 
0.1 |di1     |entrada
0.2 |di2     |entrada
0.3 |di3     |entrada
0.4 |di4     |entrada
0.5 |di5     |entrada
0.6 |di6     |entrada
1.1 |di7     |entrada
1.3 |di8     |entrada
1.4 |di9     |entrada
1.5 |di10    |entrada
1.7 |do0     |entrada 
2.5 |do1     |salida
2.7 |do2     |salida
3.0 |do3     |salida
3.1 |do4     |salida
3.4 |do5     |salida
3.5 |do6     |salida
3.6 |do7     |salida
3.7 |do8     |salida
4.2 |do9     |salida
4.3 |do10    |salida
1.0 |out_pwm0|salida
1.2 |out_pwm1|salida
2.4 |out_pwm2|salida
2.6 |out_pwm3|salida
2.0 |in0_adc |entrada
2.1 |in1_adc  |entrada
2.2 |in2_adc  |entrada
2.3 |in3_adc |entrada
4.0 |\uart:rx\ |salida
4.1 |\uart:tx\ |salida

### A tener en cuenta

- El led se enciende con un cero


## Programación en lenguaje v

### Pin output

Para activar el puerto que va ha usar;
```go
pin_high(pin_name)
```
*Ejemplo: si se desea activar el puerto do0;  pin_high(do0).*

Para desactivar el puerto que se está usando;
```go
pin_low(pin_name)
```
*Ejemplo: si se desea desactivar el puerto do0;  pin_low(do0).*

Para desactivar o activar el puerto que se va ha usar;

```go
pin_write(pin_name, value)
```
*Ejemplo: si se desea desactivar el puerto do0;  pin_write(do0, 1), y si se desea activar;  pin_write(do0, 0).*


## PWM
Hay tres PWM; out_pwm1, out_pwm2 y out_pwm3.

## ADC
Use the `machine` module and the `{ adc }` submodule.
```go
import machine { adc }

val1, val2 := 0, 0
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
```
