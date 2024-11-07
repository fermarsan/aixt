import adc
import pwm 

adc.setup()     //Configuramos el ADC
pwm.setup()     //Configuramos el modulo CCP(PWM)

for {
	x := u16(0)
	x = adc.read(0)  //Retornamos la lectura de la conversión a la variable valor_adc
	pwm.write(x)      
}