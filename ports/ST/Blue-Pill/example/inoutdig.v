import pin



pin.setup(P23, output)
pin.setup(P24, output)
pin.setup(P1, input)
  
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