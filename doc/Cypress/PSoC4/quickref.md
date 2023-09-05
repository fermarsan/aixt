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

pin_write(led1, 1)        // Enciende el pin
pin_write(led1, 0)        // Apaga el pin 
pin_read(x)         // Identica el estado del pin
```

### Se establecen los pines `pin` 
Las funciones para emular los pines de salifa y entradas en la tarjeta son: 

Pin | nombre |Tipo    |
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
4.0 |do0     |entrada
0.5 |do1     |entrada
3.7 |do2     |entrada
1.2 |out_pwm1|entrada
2.6 |out_pwm2|entrada
1.0 |out_pwm3|entrada





## PWM
Hay tres PWM; out_pwm1, out_pwm2 y out_pwm3.

Use the `machine` module and the `{ pwm }` submodule.
```go
import machine { pwm }

out_pwm1_duty(40)       // set the duty cycle for PWM 1
out_pwm2_duty(60)       // set the duty cycle for PWM 2
out_pwm3_duty(40)       // set the duty cycle for PWM 3
```

## UART
```go
import machine { uart }

uart1(115200)

uart1_put(`x`)
y := uart1_get()

uart1_write('Hello...')
msg := uart1_read()
```


### `input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.

# Tarjeta CY8CKIT-049-42XX

## pines emulados
Use el module `machine` y el submodulo `{ pin }`.
```go
import machine { pin }

pin_write(0)        // Enciende el pin
pin_write(1)        // Apaga el pin 
pin_read(x)         // Identifica en que posición está pin
```