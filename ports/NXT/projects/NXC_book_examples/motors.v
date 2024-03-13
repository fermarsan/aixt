 import motor
 
 motor.forward(ac, 75)
 sleep_ms(500)
 motor.off(ac)
 sleep_ms(1000)
 motor.forward(ac, 75)
 sleep_ms(500)
 motor.float(ac)