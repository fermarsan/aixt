import pin      // importa el modulo pin
import uart     // importa el modulo uart
 
 __global (
    num = 0    //Crea una variable global para almacenar el número de bytes a leer del puerto serial
    lec = 0    //Crea una variable global para almacenar la lectura del puerto serial
 )

 pin.setup(3, pin.out)      // Configura el pin #3 como salida
 uart.setup(9600)           // Define la velocidad en 9600 baudios 


for{
    num = uart.any()      // Almacena el número de bytes a leer del puerto serial
    if  num>0  {          // Condición si el número de bytes a leer es mayor a 0
        lec=uart.read()   // Almacena la lectura del puerto serial
        if lec == `1` {     // Condición cuando la lectura es 1

            pin.high(3)     // Salida en alto 
            uart.println('Led encendido')   //Mensaje en el puerto serial

        }

        else if lec == `2` {    // Condición cuando la lectura es 2

            pin.low(3)      // Salida en bajo 
            uart.println('Led apagado')     //Mensaje en el puerto serial

        }
    }
}