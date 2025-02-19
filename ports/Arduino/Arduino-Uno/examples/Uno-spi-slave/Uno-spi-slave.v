// esclavo.v

import spi
import pin
import time

// Definir los pines
const input_button = u8(2)  // Pin del botón
const output_led = u8(7)    // Pin del LED

// Variables para almacenar el estado recibido y enviado
mut received := false
mut slave_received := u8(0)
mut slave_send := u8(0)

// Función de configuración
fn setup() {
    // Inicializar el puerto serie
    spi.print("Iniciando esclavo SPI...")

    // Configurar los pines
    pin.setup(input_button, pin.input)   // Pin del botón como entrada
    pin.setup(output_led, pin.output)    // Pin del LED como salida

    // Inicializar el bus SPI en modo esclavo
    spi.begin()
}

// Función de bucle principal
fn loop() {
    // Verificar si hay datos disponibles en el bus SPI
    if spi.available() > 0 {
        // Leer el byte recibido
        slave_received = spi.transfer(0)  // Dummy byte para recibir datos
        received = true
    }

    if received {
        // Controlar el LED en función del dato recibido
        if slave_received == 1 {
            pin.write(output_led, pin.high)  // Encender el LED
        } else {
            pin.write(output_led, pin.low)   // Apagar el LED
        }

        // Leer el estado del botón
        button_value := pin.read(input_button)

        // Preparar el dato a enviar
        if button_value == pin.high {
            slave_send = u8(1)
        } else {
            slave_send = u8(0)
        }

        // Enviar el dato al maestro
        spi.transfer(slave_send)

        // Reiniciar la bandera de recepción
        received = false
    }

    // Esperar un breve momento antes de la siguiente verificación
    time.sleep_ms(100)
}

// Punto de entrada del programa
fn main() {
    setup()
    for {
        loop()
    }
}