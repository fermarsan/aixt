import time {sleep_ms}
import pin
import uart
	recibe_dato := int (0)


pin.setup(p5,output)
pin.setup(p7,output)
pin.setup(p6,output)
uart.setup(9600)
for {
  if uart.ready()>0 {

    recibe_dato = uart.read()
    time.sleep_ms(100) 
  }
if recibe_dato ==`1` {  
	pin.high(p5)
    pin.low(p7)
    pin.low(p6)
 }
else if recibe_dato ==`2` { 
    pin.low(p5)
    pin.high(p7)
    pin.low(p6)
}
else if recibe_dato ==`3` { 
    pin.low(p5)
    pin.low(p7)
    pin.high(p6)
}
else {
    pin.low(p5)
    pin.low(p7)
    pin.low(p7)
  }
}