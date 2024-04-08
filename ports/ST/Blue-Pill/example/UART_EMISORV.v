import time {sleep_ms}
import pin
import uart
import adc

dato := int(0) 
envia_dato := ` ` 
uart__setup(9600)
uart__println("Inicio de sketch - valores del potenciometro")
for {
  dato=analogRead(p5)
  delay(100)
  uart__println(dato)
  if(dato <=400){
  uart__Write('1')
  }
  else if(dato >=400 && dato<=700){ 
  uart__Write('2')
  }
 else {
  uart__Write('3')
  }
}