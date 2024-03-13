import adc
import pwm 

adc.setup()     //Configuramos el ADC
pwm.setup()     //Configuramos el modulo CCP(PWM)

for {
	adc.read(0)  //Asignamos el canal para el ADC

	valor := adc.reading()  //Retornamos la lectura de la conversión a la variable valor_adc
	 
	pwm.write(valor)      

}
