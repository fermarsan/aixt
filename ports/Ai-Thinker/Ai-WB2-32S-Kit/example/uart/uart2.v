import time {sleep_ms}
import pin
import uart

  uart.setup(115200)
  pin.out(4)
  pin.out(5)
  pin.out(12)

for {
  uart.println_0("\r\n Este programa realiza unas funciones establecidas:")
  uart.println_0("\r\n Oprimiendo la letra A, activa la salida  del pin GPIO4.")
  uart.println_0("\r\n Oprimiendo la letra B, activa la salida  del pin GPIO5.")
  uart.println_0("\r\n El piloto (led) Rojo indica que esta esperando instrucciones.")
  uart.println_0("\r\n Esperando instrucciones: \r\n")

  pin.high(12)
  sleep_ms(500)

  pin.low(12)
  sleep_ms(500)
  if (uart.available() > 0) {
    str command = uart.read_0()


    if (command ==A) {
      uart.println_0("\r\n Comando A recibido. \r\n")
      uart.println_0("\r\n Realizando acción A. \r\n")
      pin.high(4)
      sleep_ms(5000)

      pin.low(4)
      sleep_ms(1000)
      uart.println_0("\r\n Proceso A finalizado. \r\n")
    }

    if (command ==B) {
      uart.println_0("\r\n Comando B recibido. \r\n")
      uart.println_0("\r\n Realizando acción B. \r\n")
      pin.high(5)
      sleep_ms(5000)

      pin.low(5)
      sleep_ms(1000)
      uart.println_0("\r\n Proceso B finalizado. \r\n")
    }

    else {
      pin.high(12)
      sleep_ms(1000)

      pin.low(12)
      sleep_ms(1000)
    }
  }
}