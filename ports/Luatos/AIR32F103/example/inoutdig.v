import pin



pin.setup(p13, pin.output)
pin.setup(p4, pin.output)
pin.setup(p1, pin.input)
  
for {
  
 
  if (pin.read(p1)==1){
  pin.high(p4)
	pin.low(p13)
  }
  else{
  pin.high(p13)
	pin.low(p4)
  }  
}