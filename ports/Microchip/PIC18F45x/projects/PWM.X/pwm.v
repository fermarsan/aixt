import adc
import pwm 

adc.setup()     //Configuramos el ADC
pwm.setup()  //Configuramos el modulo CCP(PWM)

for {

	valor_adc := 0
	valor_adc = adc.read(0)  //Retornamos la lectura de la conversión a la variable valor_adc
	 
	pwm.write(valor_adc)      

}
