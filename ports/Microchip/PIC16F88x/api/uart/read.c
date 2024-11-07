uint8_t read() {
  while (RCIF == 0) ;  // wait for data receive
  if (OERR) {   // if there is overrun error
    CREN = 0;   // clear overrun error bit
    CREN = 1;
  }
  return RCREG; // read from EUSART receive data register
}