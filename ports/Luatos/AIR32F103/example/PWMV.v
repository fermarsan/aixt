

import adc
import pin
import pwm


    pin.setup(p13, pin__input)//Entrada analogica asociada al PWM
   
    pin.setup(p20, PWM)//Salida analogica del PWM    


    adc__read(p5)//Variacion del PWM
    pwm__map(adc__read(p5), 4095, 0, 4095, 0)
    //Amplitud del PWM
    pwm__write(p13, PWM)//Salida del PWM
  
