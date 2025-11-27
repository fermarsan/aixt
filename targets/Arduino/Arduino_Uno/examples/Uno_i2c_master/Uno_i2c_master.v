// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024

import i2c
import time
import uart

// Constantes definidas en el nivel superior
const   pins = [u8(2), 3, 4, 5, 6] // Pines a controlar (todos son de tipo u8)
// Inicializar el bus I2C en modo maestro
i2c.as_master()
// Variable mutable para alternar el estado
mut estado := u8(0)

for {
    for pin in pins { // Iterar directamente sobre los pines
        // Comenzar la transmisión al dispositivo 1
        i2c.start(1)
        // Enviar el pin a controlar
        i2c.write(pin)
        uart.print('Enviando pin: $pin')
        // Enviar el estado (HIGH o LOW)
        i2c.write(estado)
        uart.print('Enviando estado: $estado')
        // Finalizar la transmisión
        i2c.stop()
        // Esperar 1 segundo
        time.sleep_ms(100)
    }
    // Cambiar el estado (alternar entre 0 y 1)
    if estado == 0 {
        estado = u8(1)
    } else {
        estado = u8(0)
    }
    uart.print('Cambiando estado a: $estado')
}