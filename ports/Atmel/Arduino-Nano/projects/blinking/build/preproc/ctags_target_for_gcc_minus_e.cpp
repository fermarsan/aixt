# 1 "/home/fercho/aixt/ports/Atmel/Arduino-Nano/projects/blinking/blinking.ino"
// Definimos el pin donde está conectado el LED
const int ledPin = 13;

void setup() {
  // Inicializamos el pin del LED como salida
  pinMode(ledPin, 0x1);
}

void loop() {
  // Encendemos el LED
  digitalWrite(ledPin, 0x1);
  // Esperamos un segundo
  delay(1000);
  // Apagamos el LED
  digitalWrite(ledPin, 0x0);
  // Esperamos otro segundo
  delay(1000);
}
