import pin



pin.setup(p13, output)
pin.setup(p4, output)
pin.setup(p1, input)
  
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