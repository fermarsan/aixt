#include <stdio.h>
#include <Arduino.h>
int led1 = LED_BUILTIN_1;
int led2 = LED_BUILTIN_2;
int led3 = LED_BUILTIN_3;
int led4 = LED_BUILTIN_4;
int led5 = LED_BUILTIN_5;
int led6 = LED_BUILTIN_6;
int led7 = LED_BUILTIN_7;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led6, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
    digitalWrite(led7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led7, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}