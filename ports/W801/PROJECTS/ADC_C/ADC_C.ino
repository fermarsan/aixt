#include "Arduino.h"
/*
 * HLK-W80x Analog read example.
 * 
 * W80x boards has four analog ports.
 * You can access it from Arduino code by pin numbers PA1-PA4
 * or by short names A1-A4.
 * 
 * Name A0 is alias to A1, added for compatibility.
 * 
 */
 int a1=PA4;
 int a2=PB0;
 int a3=PB1;


void setup()
{
pinMode(a1,ANALOG_INPUT);  
pinMode(a2,OUTPUT);
pinMode(a3,OUTPUT);  

digitalWrite(a2,LOW);
digitalWrite(a3,LOW);


}
void loop()
{
if (250>=analogRead(a1)){
digitalWrite(a2,HIGH);
digitalWrite(a3,LOW);
}
else {
digitalWrite(a2,LOW);
digitalWrite(a3,HIGH);
}

}


