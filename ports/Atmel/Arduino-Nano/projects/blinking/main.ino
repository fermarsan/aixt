// Definimos el pin donde está conectado el LED
const int ledPin = 13;

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