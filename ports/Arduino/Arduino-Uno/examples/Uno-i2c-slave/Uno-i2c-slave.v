// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024
// Arduino Uno board

import i2c
import pin
import time

const led1 = pin.d13
const led2 = pin.d12
const led3 = pin.d8

fn main() {
    // Configurar pines como salida
    pin.setup(led1, pin.output)
    pin.setup(led2, pin.output)
    pin.setup(led3, pin.output)

    i2c.as_slave(0x23) // Iniciar esclavo con dirección 0x23
    i2c.receive_event(receive)

    for {
        // Mantener LEDs apagados por defecto
        pin.write(led1, 0)
        pin.write(led2, 0)
        pin.write(led3, 0)
        time.sleep_ms(1000)
    }
}

// Función llamada al recibir datos por I2C
fn receive(num_bytes int) {
    for _ in 0 .. num_bytes {
        data := i2c.read()
        match data {
            1 { pin.write(led1, 1) } // Encender LED1
            2 { pin.write(led2, 1) } // Encender LED2
            3 { pin.write(led3, 1) } // Encender LED3
            else {}
        }
    }
}
