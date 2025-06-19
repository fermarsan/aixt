// Project name:
// Author: 
// Date: 
// Arduino Mega board
import time
import lcd
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
    lcd.pins(11, 10, 5, 4, 3, 2)  // Configuración de pines
    lcd.setup(16, 2)  // Configuración de la pantalla LCD 16x2

    for {
        val := adc.read(adc.ch5)
        voltage := f32(f32(5.00)*val)/1024 // Calcular el voltaje

        lcd.set_cursor(0, 1)  // Mover cursor a la segunda línea        
        boton := read_lcd_buttons()  // Leer el botón presionado  

        match boton {
            btn_right {
                lcd.clear()
                 time.sleep_ms(700)
                lcd.set_cursor(1, 0)  
                 lcd.println("ADC Value:")

                lcd.set_cursor(11, 0) 
                lcd.print(val)
                time.sleep_ms(500)
                break
            }

			
      btn_left {
                 lcd.clear()
                 time.sleep_ms(700)
                lcd.set_cursor(1, 0)  
                lcd.println("Voltage")  
				 lcd.set_cursor(11, 0) 
                lcd.print(voltage)
                time.sleep_ms(500)
                break
            }


              else {}
        }

        time.sleep_ms(500)  // Pequeño retraso para evitar rebotes
    }
}

