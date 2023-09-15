# Guía rapida PSoC4
Esta implementación de Aixt para PSoC 4 da soporte a la tarjeta   CY8CKIT-049-42XX


# Tarjeta CY8CKIT-049-42XX
![Alt text](../../../../imagenes/cy8kit049.jpg)


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

## ADC
Use the `machine` module and the `{ adc }` submodule.
```go
import machine { adc }

val1, val2 := 0, 0
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
```
