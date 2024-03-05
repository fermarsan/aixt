import adc
import pwm 

adc.setup()     //Configuramos el ADC
pwm.setup(1,2)  //Configuramos el modulo CCP(PWM)

for {
	adc.read(0)  //Asignamos el canal para el ADC

	valor_adc := adc.reading()  //Retornamos la lectura de la conversión a la variable valor_adc
	 
	pwm.write(valor_adc,1)      

}
