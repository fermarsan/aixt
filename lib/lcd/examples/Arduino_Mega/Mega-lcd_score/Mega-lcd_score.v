// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import lcd
import pin
import adc


const (
    btn_right  = 0
    btn_up     = 1
    btn_down   = 2
    btn_left   = 3
    btn_select = 4
    btn_none   = 5
)

// 📌 Función para leer los botones del shield LCD
fn read_lcd_buttons() int {
    valor_adc := adc.read(adc.ch0)  

    if valor_adc < 50   { return btn_right }
    if valor_adc < 195  { return btn_up }
    if valor_adc < 380  { return btn_down }
    if valor_adc < 555  { return btn_left }
    if valor_adc < 790  { return btn_select }

    return btn_none  
}

// 📌 Función principal
fn main() {


lcd.pins(11,10,5,4,3,2)
lcd.setup(16,2)
lcd.println("Arduino LCD :)");
time.sleep_ms(1000);
mut cont := 0
mut cont_1 := 0
mut temp := 0


for {
 lcd.scroll_right()   // Mueve el texto a la derecha
 
  temp++

boton := read_lcd_buttons()  // Leer el botón presionado  

  match boton {
            btn_up {
                 
                cont++ 
				time.sleep_ms(20)
            }

    btn_right {
                 cont_1++ 
				time.sleep_ms(20)
            }

			btn_down {
                 
                cont-- 
				time.sleep_ms(20)
            }

    btn_left {
                 cont_1-- 
				time.sleep_ms(20)
            }
  else {}
}

 time.sleep_ms(500)  // Pequeño retraso para evitar rebotes
 
  lcd.clear()
  lcd.no_display()
  time.sleep_ms(20) 
  lcd.display()
  lcd.set_cursor(4, 0) 
  lcd.println("A")
  lcd.set_cursor(4, 2) 
  lcd.print(cont)
  lcd.set_cursor(7, 0) 
  lcd.println("B")
  lcd.set_cursor(7, 2)  
  lcd.print(cont_1)

 if cont== cont_1  && temp==30

   {
	 
   lcd.clear()
   lcd.no_display()
   time.sleep_ms(20) 
   lcd.display()
   lcd.set_cursor(4, 0)
   lcd.println("Draw")
   lcd.cursor() 
   time.sleep_ms(10000) 
   lcd.clear()
           
        } 

 if cont> cont_1 && temp==30 {

  lcd.clear()
  lcd.no_display()
  time.sleep_ms(20) 
  lcd.display()
  lcd.set_cursor(4, 0)
  lcd.println("Winner_A") 
  time.sleep_ms(10000) 
  lcd.clear()
       
  } 
 if cont< cont_1 && temp==30 {

   lcd.clear()
   lcd.no_display()
   time.sleep_ms(20) 
   lcd.display()
   lcd.set_cursor(4, 0)
   lcd.println("Winner_B") 
   time.sleep_ms(10000) 
   lcd.clear()
       
  }

}
}