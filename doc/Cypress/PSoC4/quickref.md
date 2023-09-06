# Guía rapida PSoC4
Esta implementación de Aixt para PSoC 4 da soporte a las tarjetas:
- CY8CKIT-145-40XX
- CY8CKIT-049-42XX

# Tarjeta CY8CKIT-145-40XX

## Retardos
```go
import time {
	sleep_ms,
	sleep_us,
}

sleep_us(1)     // sleep for 1 microsecond
sleep_ms(500)   // sleep for 500 milliseconds
```

## pines emulados
Use el module `machine` y el submodulo `{ pin }`.
```go
import machine { pin }

pin_high(led1)         // turn ON the led1 pin 
pin_low(led4)          // turn OFF the led4 pin 
pin_write(led5, 1)     // write 1 on led5 pin
pin_read(led6)         // read led6 pin
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
4.0 |do0     |salida
0.5 |do1     |salida
3.7 |do2     |salida
1.2 |out_pwm1|salida
2.6 |out_pwm2|salida
1.0 |out_pwm3|salida





## PWM
Se nombran 4 PWMS; out_pwm0, out_pwm1, out_pwm2 y out_pwm3.

Use the `machine` module and the `{ pwm }` submodule.
```go
import machine { pwm }

out_pwm1_duty(100)       // set the duty cycle for PWM 1
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

pin_high(led1)         // turn ON the led1 pin 
pin_low(led4)          // turn OFF the led4 pin 
pin_write(led5, 1)     // write 1 on led5 pin
pin_read(led6)         // read led6 pin
```

## PWM
Hay tres PWM; out_pwm1, out_pwm2 y out_pwm3.

Use the `machine` module and the `{ pwm }` submodule.
```go
import machine { pwm }

out_pwm0_duty(40)       // set the duty cycle for PWM 1
out_pwm1_duty(60)       // set the duty cycle for PWM 2
out_pwm2_duty(40)       // set the duty cycle for PWM 3
out_pwm3_duty(40)       // set the duty cycle for PWM 4
```
### Se establecen los pines `pin` 
Las funciones para emular los pines de salifa y entradas en la tarjeta son: 

Pin | nombre |Tipo    |
--  |-       |-       |
2.7 |di0     |entrada
2.7 |di1     |entrada
2.7 |di2     |entrada
2.7 |di3     |entrada
0.4 |di4     |entrada
1.7 |di5     |entrada
2.7 |di6     |entrada
4.0 |do0     |entrada
0.5 |do1     |salida
3.7 |do2     |salida
3.7 |do3     |salida
3.7 |do4     |salida
3.7 |do5     |salida
3.7 |do6     |salida
1.2 |out_pwm0|entrada
2.6 |out_pwm1|entrada
1.0 |out_pwm2|entrada
1.2 |out_pwm3|entrada
1.2 |in0_adc |entrada
.2  |in1_adc  |entrada
1.2 |in2_adc |entrada
1.2 |in3_adc |entrada

## ADC
Use the `machine` module and the `{ adc }` submodule.
```go
import machine { adc }

val1, val2 := 0, 0
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
```
