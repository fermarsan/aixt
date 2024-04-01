import time {sleep}
import pin

void setup() {

  pin_setup(led, out);

}

void loop() {
  
  pin_low(led);
  sleep(2);                  

  pin_high(led);
  sleep(2);             
}