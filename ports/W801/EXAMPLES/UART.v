inport uart
inport pin
module time {sleep_ms}

  uart__setup_0(115200);
  pinMode(pin1, pin__output);
  pinMode(pin2, pin__output);

for {
 	uart__println_0("\r\n Comunicacion UART tarjeta W801-PC:");
	uart__println_0("\r\n Oprimiendo la letra Q, activa la salida  del pin1.");

  if (uart__available() > 0) {
    char command = uart__read_0();

    switch(command) {  
       case 'Q':
         pin__high(pin1);
         time__sleep_ms(4000); 
         pin__low(pin1);
         time__sleep_ms(1000);
	break;

       default:
          pin__high(pin2);
          time__sleep_ms(4000);
          pin__low(pin2);
          time__sleep_ms(1000); 
        break;
    }
  }
}