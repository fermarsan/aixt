import pin
import time {sleep_ms}
  // put your setup code here, to run once:
pin.setup(pin.a1,input);  
pin.setup(pin.a2,output);
pin.setup(pin.a3,output);
pin.setup(pin.a4,output);

for {
  // put your main code here, to run repeatedly:
if (pin.read(pin.a1)==1){
  pin.low(pin.a2);
  pin.high(pin.a3);
  pin.low(pin.a4);
  time.sleep_ms (100);
}
if (pin.read(pin.a1)==0){
  pin.high(pin.a2);
  pin.low(pin.a3);
  pin.high(pin.a4);
  time.sleep_ms (100); 
}
}