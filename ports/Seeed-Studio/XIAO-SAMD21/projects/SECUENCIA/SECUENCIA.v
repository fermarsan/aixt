import time {sleep_ms} // importa la función sleep_ms
import pin  // importa el modulo pin

pin.setup(3, pin.out)    // Configura el pin #3 como salida
pin.setup(4, pin.out)    // Configura el pin #4 como salida
pin.setup(5, pin.out)    // Configura el pin #5 como salida

for{
    pin.high(3)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.high(4)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.high(5)     // Salida en Alto
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(3)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(4)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
    pin.low(5)      // Salida en Bajo
    sleep_ms(250)   // Retardo de 250 milisegundos
}