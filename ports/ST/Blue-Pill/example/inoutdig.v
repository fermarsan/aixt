import pin



pin.setup(P23, output)
pin.setup(P24, output)
pin.setup(P1, input)
  
for {
  
 
  if (pin__read(p1)==1){
  pin__high(p23)
	pin__low(p24)
  }
  else{
  pin__high(p24)
	pin__low(p23)
  }  
}