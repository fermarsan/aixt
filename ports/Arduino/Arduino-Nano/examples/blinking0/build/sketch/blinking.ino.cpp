#include <Arduino.h>
#line 1 "/home/fercho/aixt/ports/Atmel/Arduino-Nano/projects/blinking/blinking.ino"
// Definimos el pin donde está conectado el LED
const int ledPin = 13;

#line 4 "/home/fercho/aixt/ports/Atmel/Arduino-Nano/projects/blinking/blinking.ino"
void setup();
#line 9 "/home/fercho/aixt/ports/Atmel/Arduino-Nano/projects/blinking/blinking.ino"
void loop();
#line 4 "/home/fercho/aixt/ports/Atmel/Arduino-Nano/projects/blinking/blinking.ino"
void setup() {
  // Inicializamos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Encendemos el LED
  digitalWrite(ledPin, HIGH);
  // Esperamos un segundo
  delay(1000);
  // Apagamos el LED
  digitalWrite(ledPin, LOW);
  // Esperamos otro segundo
  delay(1000);
}
