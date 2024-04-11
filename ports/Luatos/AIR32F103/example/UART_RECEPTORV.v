import time {sleep_ms}
import pin
import uart
	recibe_dato := int (0)


pin__setup(p5,pin__output)
pin__setup(p7,pin__output)
pin__setup(p6,pin__output)
uart__setup(9600)
for {
  if uart__ready()>0 {

    recibe_dato = uart__read()
    time__sleep_ms(100) 
  }
if recibe_dato ==`1`{  
	pin__high(p5)
    pin__low(p7)
    pin__low(p6)
 }
else if recibe_dato ==`2`{ 
    pin__low(p5)
    pin__high(p7)
    pin__low(p6)
}
else if recibe_dato ==`3`{ 
    pin__low(p5)
    pin__low(p7)
    pin__high(p6)
}
else {
    pin__low(p5)
    pin__low(p7)
    pin__low(p7)
  }
}