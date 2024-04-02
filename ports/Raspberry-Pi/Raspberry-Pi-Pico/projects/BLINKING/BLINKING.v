import time {sleep}
import pin


pin.setup(led, pin.output)


for {
  
  pin.low(led)
  sleep(2)                 

  pin.high(led)
  sleep(2)             
}