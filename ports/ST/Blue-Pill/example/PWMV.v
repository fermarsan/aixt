

import adc
import pin
import pwm


    pin.setup(p5, pin__input)//Entrada analogica asociada al PWM
   
    pin.setup(p7, PWM)//Salida analogica del PWM    


    adc__read(p5)//Variacion del PWM
    pwm__map(adc__read(p5), 4095, 0, 4095, 0)
    //Amplitud del PWM
    pwm__write(p7, PWM)//Salida del PWM
  
