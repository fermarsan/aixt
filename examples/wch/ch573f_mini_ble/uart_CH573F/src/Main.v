import time {sleep_ms}
import uart
import pin 


pin.high(pin.b7)
pin.setup(pin.b4, in_pullup) 
pin.setup(pin.b7, pin.output)

//Inicializamos la comunicación serial
uart.setup(115200)

for {
    uart.write(TxBuff)
    sleep_ms(2000)
	uart.read()
}