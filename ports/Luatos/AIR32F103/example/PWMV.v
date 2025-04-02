

import adc
import pin
import pwm


    pin.setup(p13, pin.input)//Entrada analogica asociada al PWM
   
    pin.setup(p20, PWM)//Salida analogica del PWM    


    adc.read(p5)//Variacion del PWM
    pwm.map(adc.read(p5), 4095, 0, 4095, 0)
    //Amplitud del PWM
    pwm.write(p13, PWM)//Salida del PWM
  
