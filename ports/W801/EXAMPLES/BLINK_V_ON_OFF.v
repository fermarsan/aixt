
    import time {sleep_ms}
    import pin
  // initialize the digital pin as an output.
  pin__setup(led1, output);
  pin__setup(led2, output);
  pin__setup(led3, output);
  pin__setup(led4, output);
  pin__setup(led5, output);
  pin__setup(led6, output);
  pin__setup(led7, output);


// the loop routine runs over and over again forever:
for {
  pin__high(led1);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__low(led1);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led2);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__low(led2);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led3);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__low(led3);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led4);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__low(led4);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led5);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__low(led5);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led6);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__high(led6);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
  pin__high(led7);   // turn the LED on (HIGH is the voltage level)
  time__sleep_ms(1000);               // wait for a second
  pin__high(led7);    // turn the LED off by making the voltage LOW
  time__sleep_ms(1000);               // wait for a second
}