import time {sleep_ms}          // importa la funcion sleep_ms de el modulo time   
import pin 			// Importa el módulo pin en su totalidad

pin.setup(14, pin.output)    	// Establece el pin #14 como salida
pin.setup(15, pin.output)    	// Establece el pin #15 como salida
pin.setup(16, pin.output)    	// Establece el pin #16 como salida

for{
    pin.high(14)  		// salida 14 high   
    sleep_ms(2000) 		// retardo de 2000 ms
    pin.low(14)   		// salida 14 baja
    pin.high(15)     		// salida 15 high
    sleep_ms(2000) 		// retardo de 2000 ms 	
    pin.low(15)   		// salida 15 baja
    pin.high(16)     		// salida 16 high 
    sleep_ms(2000)   		// retardo de 2000 ms
    pin.low(16) 		// salida 15 baja
}