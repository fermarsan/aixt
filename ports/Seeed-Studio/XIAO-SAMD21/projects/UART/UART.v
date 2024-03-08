import pin
import uart
 
 __global (
    num = 0    //Crea una variable global para almacenar el número de bytes a leer del puerto serial
    lec = 0    //Crea una variable global para almacenar la lectura del puerto serial
 )
 pin.setup(3, pin.out)      // Configura el pin #5 como salida


for{
    num = uart.ready()      // Almacena el número de bytes a leer del puerto serial
    if  num>0  {
        lec = uart.read()   // Almacena la lectura del puerto serial
    }
    if lec==1 {           // Condición si la lectura es 'on'
        pin.high(3)         // Salida en Alto
    }
    if lec==2 {          // Condición si la lectura es 'off'
        pin.low(3)          // Salida en Bajo
    }
}