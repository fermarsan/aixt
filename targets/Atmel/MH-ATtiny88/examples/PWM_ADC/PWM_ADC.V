import pin                            // Importa el módulo pin en su totalidad
import adc                            // Importa el módulo adc en su totalidad
import pwm                            // Importa el módulo pwm en su totalidad
import time { sleep_ms }
__global (
    brillo = 0                        // crea una variable global
    )
   


for{                      // crea el ciclo
  brillo=adc.read(-5)     //lee la entrada anologa digital
    pwm.write(3,brillo)   //escribe la salida pwm
}

