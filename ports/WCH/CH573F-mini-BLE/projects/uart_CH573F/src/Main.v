import time {sleep_ms}
import uart
import pin 


pin.high(b7)
pin.setup(b4, pin.in_pullup) 
pin.setup(b7, pin.output)

//Inicializamos la comunicación serial
uart.setup()

for {
    uart.write(TxBuff)
    sleep_ms(2000)
	uart.read()
}