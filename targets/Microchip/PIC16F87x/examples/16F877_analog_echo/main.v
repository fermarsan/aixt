// Project name:
// Author:
// Date:
// PIC16F877 fosc = 20Mhz
import adc
import pwm

adc.setup(adc.in0, adc.bits8)     //Configuramos el ADC
pwm.setup()     //Configuramos el modulo CCP(PWM)

for {
	x := adc.read_byte(0)  //Retornamos la lectura de la conversión a la variable adc_value
	pwm.write(x)
}
