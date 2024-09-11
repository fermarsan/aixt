import pin
import time {sleep_ms}
  // put your setup code here, to run once:
pin.setup(a1,input);  
pin.setup(a2,output);
pin.setup(a3,output);
pin.setup(a4,output);



for {
  // put your main code here, to run repeatedly:
if (pin.read(a1)==1){
  pin.low(a2);
  pin.high(a3);
  pin.low(a4);
  time__sleep_ms (100);
}
if (pin.read(a1)==0){
  pin.high(a2);
  pin.low(a3);
  pin.high(a4);
  time__sleep_ms (100); 
}
}