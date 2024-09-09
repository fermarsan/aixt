// Project Name: Segidor_Linea
// Author: Fernando M. Santa
// Date: 02/05/2024

import motor
import sensor

sensor.set(i4, light)	// sensor de luz por la entrada 4
//sensor.set_light(i4)	// función alternativa

sleep(2)	// retardo de arrancada

for {
	motor.forward(ab, 75)	//arranca en linea recta
	sleep_ms(100)

	if sensor.read(s4) <= 30 {	// linea negra
		motor.off(a)	// apaga motor a
		sleep_ms(300)
		motor.reverse(a, 75)	// reserva motor a
		sleep_ms(500)	
	}
}