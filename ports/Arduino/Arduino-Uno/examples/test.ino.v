#include<spi.h>
#define inputbutton 2
#define outputLED 7

volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;

void setup()

{
  Serial.begin(9600);
  
  pinMode(inputbutton,INPUT); 
  pinMode(outputLED,OUTPUT);               
  pinMode(MISO,OUTPUT);                  

  SPCR |= _BV(SPE);                  
  received = false;

//   SPI.attachInterrupt();                  
  
}

// ISR (SPI_STC_vect)                        
// {
//   Slavereceived = SPDR;         
//   received = true;                        
// }

@[spi_receive_isr]
fn receive_data(){


}

// ISR (SPI_STC_vect)                        
// {
//   Slavereceived = SPDR;         
//   received = true;                        
// }

void loop()
{  
 if(received)                           
   {
      if (Slavereceived==1) 
      {
        digitalWrite(outputLED,HIGH);       
      }else
      {
        digitalWrite(outputLED,LOW);          
      }
      
      buttonvalue = digitalRead(inputbutton);  
      
      if (buttonvalue == HIGH)           
      {
        x=1;
        
      }else
      {
        x=0;
      }
      
  Slavesend=x;                             
  SPDR = Slavesend;                       
  delay(1000);
}
}