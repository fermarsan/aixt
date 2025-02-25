module main

import spi
import pin
import time

// Definir los pines
const push = u8(2)  // Pin del botón
const led = u8(7)   // Pin del LED

fn main() {
    // Inicializar el puerto serie
    spi.print("Iniciando maestro SPI...")

    // Configurar los pines
    pin.setup(push, pin.input)   // Pin del botón como entrada
    pin.setup(led, pin.output)   // Pin del LED como salida

    // Inicializar el bus SPI
    spi.begin()
    spi.set_clock_divider(8)     // Configurar el divisor de frecuencia del reloj (SPI_CLOCK_DIV8)

    // Variable para almacenar el estado del botón
    mut value := u8(0)

    for {
        // Leer el estado del botón
        value = pin.read(push)

        // Enviar el estado del botón a través de SPI
        spi.transfer(value)

        // Leer la respuesta del esclavo
        response := spi.transfer(0)  // Enviar un byte dummy para recibir datos

        // Controlar el LED en función de la respuesta del esclavo
        if response == 1 {
            pin.write(led, pin.high)  // Encender el LED
        } else {
            pin.write(led, pin.low)   // Apagar el LED
        }

        // Esperar 1 segundo
        time.sleep_ms(1000)
    }
}