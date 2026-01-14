import time {sleep_ms}
import pin



for {
    if pin.read(sw2) == 1 {     // Si el botón está presionado (valor lógico alto)
        pin.high(led1)           // Encender LED
    } else {
        pin.low(led1)            // Apagar LED
    }

    time.sleep_ms(100)             // Pequeña espera para evitar rebotes
}
