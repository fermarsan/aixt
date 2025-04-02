import pin



pin.setup(P23, pin.output)
pin.setup(P24, pin.output)
pin.setup(P1, pin.input)
  
for {
  
 
  if (pin.read(p1)==1){
  pin.high(p23)
	pin.low(p24)
  }
  else{
  pin.high(p24)
	pin.low(p23)
  }  
}