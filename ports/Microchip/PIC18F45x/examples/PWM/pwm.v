import adc
import pwm 

adc.setup()     //Configuramos el ADC
pwm.setup()  //Configuramos el modulo CCP(PWM)

for {

	adc_value := 0
	adc_value = adc.read(0)  //Retornamos la lectura de la conversión a la variable adc_value
	 
	pwm.write(adc_value)      

}
