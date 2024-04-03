import pin



pin.setup(P23, pin__output)
pin.setup(P24, pin__output)
pin.setup(P1, pin__input)
  
for {
  
 
  if (pin__read(P1)==1){
  pin__high(P23)
	pin__low(P24)
  }
  else{
  pin__high(P24)
	pin__low(P23)
  }  
}