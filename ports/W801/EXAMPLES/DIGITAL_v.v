import pin
import time {sleep_ms}
  // put your setup code here, to run once:
pin__setup(a1,pin__input);  
pin__setup(a2,pin__output);
pin__setup(a3,pin__output);
pin__setup(a4,pin__output);



for {
  // put your main code here, to run repeatedly:
if (pin__read(a1)==1){
  pin__low(a2);
  pin__high(a3);
  pin__low(a4);
  time__sleep_ms (100);
}
if (pin__read(a1)==0){
  pin__high(a2);
  pin__low(a3);
  pin__high(a4);
  time__sleep_ms (100); 
}
}