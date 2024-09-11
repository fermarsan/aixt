import pin



pin.setup(p13, output)
pin.setup(p4, output)
pin.setup(p1, input)
  
for {
  
 
  if (pin__read(p1)==1){
  pin__high(p4)
	pin__low(p13)
  }
  else{
  pin__high(p13)
	pin__low(p4)
  }  
}