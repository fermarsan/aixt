#include <Arduino.h>
#line 1 "/home/fercho/aixt/ports/ejemplo/ejemplo.ino"
#line 1 "/home/fercho/aixt/ports/ejemplo/ejemplo.ino"
void setup();
#line 5 "/home/fercho/aixt/ports/ejemplo/ejemplo.ino"
void loop();
#line 1 "/home/fercho/aixt/ports/ejemplo/ejemplo.ino"
void setup() {
    pinMode(3, OUTPUT);
}

void loop() {
    digitalWrite(3, HIGH);
    delay(200);
    digitalWrite(3, LOW);
    delay(200);
}

