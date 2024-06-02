module pin
module adc
pin__setup(a1,ADC__INPUT);  
pin__setup(a2,pin__output);
pin__setup(a3,pin__output);  

pin__low(a2);
pin__low(a3);



for{

if (250>=adc__read(a1)){
pin__high(a2);
pin__low(a3);
}
else {
pin__low(a2);
pin__high(a3);
}

}