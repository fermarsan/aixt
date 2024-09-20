import time {sleep_ms}
import pin
import uart

  uart.setup(0, 9600)
  pin.setup(pin1, pin.output)
  pin.setup(pin2, pin.output)

for {
 	uart.println(0, '\r\n Comunicacion UART tarjeta W801-PC:')
	uart.println(0, '\r\n Oprimiendo la letra Q, activa la salida  del pin1.')

pin.high(pin2)
  sleep_ms(250)

  pin.low(pin2)
  sleep_ms(250)
  x:=0
  x=uart.any()

  if (uart.available() > 0) {
    command := ` ` 
    command = uart.read(0)
       
       if  command == `Q`  {
         pin.high(pin1)
         time.sleep_ms(2000)
         pin.low(pin1)
         time.sleep_ms(500)}
	
       else{
          pin.high(pin2)
          time.sleep_ms(500)
          pin.low(pin2)
          time.sleep_ms(500)
        }
    
  }
}
