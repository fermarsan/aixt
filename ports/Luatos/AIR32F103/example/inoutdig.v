import pin



pin.setup(p13, pin__output)
pin.setup(p4, pin__output)
pin.setup(p1, pin__input)
  
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