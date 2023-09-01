# Guía rapida PSoC4
Esta implementación de Aixt para PSoC 4 da soporte a las tarjetas:
- CY8CKIT-145-40XX
- CY8CKIT-049-42XX

# Tarjeta CY8CKIT-145-40XX

## Retardos
Use el modulo `time` :
```go
import time

cydelay(2)            // sleep for 2 milisegundos
 

## pines emulados
Use el module `machine` y el submodulo `{ pin }`.
```go
import machine { pin }

pin_write(1)        // Enciende el pin
pin_write(0)        // Apaga el pin 
pin_read(x)         // Identifica en que posición está pin
```

### Se establecen los pines `pin` 
Las funciones para emular los pines de salifa y entradas en la tarjeta son: 

Pin | nombre |Tipo    |
--  |-       |-       |
1.6 |led1    |salida
1.5 |led4    |salida
1.7 |led     |salida
1.8 |led6    |salida
1.9 |led7    |salida
2   |led8    |salida
3   |led9    |salida
4   |led10   |salida
5   |led11   |salida
5   |sw2     |entrada
5   |di0     |entrada
5   |di1     |entrada
5   |di2     |entrada
5   |do0     |entrada
5   |do1     |entrada
5   |do2     |entrada




## PWM
Hay tres PWM; out_pwm1, out_pwm2 y out_pwm3.

Use the `machine` module and the `{ pwm }` submodule.
```go
import machine { pwm }

pwm1_duty(40)       // set the duty cycle for PWM 1
pwm2_duty(60)       // set the duty cycle for PWM 2
```


### `input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.

# Tarjeta CY8CKIT-049-42XX

