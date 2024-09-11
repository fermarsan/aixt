
    import time {sleep_ms}
    import pin
  // initialize the digital pin as an output.
  pin.setup(led1, output);
  pin.setup(led2, output);
  pin.setup(led3, output);
  pin.setup(led4, output);
  pin.setup(led5, output);
  pin.setup(led6, output);
  pin.setup(led7, output);


// the loop routine runs over and over again forever:
for {
  pin.high(led1);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.low(led1);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led2);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.low(led2);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led3);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.low(led3);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led4);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.low(led4);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led5);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.low(led5);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led6);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.high(led6);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
  pin.high(led7);   // turn the LED on (HIGH is the voltage level)
  time.sleep_ms(1000);               // wait for a second
  pin.high(led7);    // turn the LED off by making the voltage LOW
  time.sleep_ms(1000);               // wait for a second
}