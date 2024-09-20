import time {sleep_ms}
import pin
import uart
import adc

dato := int(0) 
envia_dato := ` `  
uart.setup(9600)
uart.println("Inicio de sketch - valores del potenciometro")
for {
  dato=analogRead(p5)
  delay(100)
  uart.println(dato)
  if(dato <=400){
  uart.write('1')
  }
  else if(dato >=400 && dato<=700){ 
  uart.write('2')
  }
 else {
  uart.write('3')
  }
}