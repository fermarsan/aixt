// Project name: Button example
// Author: Fernando M. Santa
// Date: 21/01/2025
// M5Stack FIRE IoT development kit

import lcd 
import button
import power


power.setup()   // Init Power module.
lcd.text_color(lcd.yellow)  // Set the font color to yellow.  
lcd.text_size(2)     	// Set the font size.
lcd.cursor(65, 10)  	// Move the cursor position to (65, 10).
lcd.println('Button example')  // The screen prints the formatted string and wraps the line.
lcd.cursor(3, 35)
lcd.println('Press button B for 700ms')
lcd.println('to clear screen.')
lcd.text_color(lcd.red)

for {
    update()  // Read the press state of the key.  A, B, C 
    if button.was_released(button.a) || button.pressed_for_ctime(button.a, 1000, 200) {
        lcd.print('A')
    } else if button.was_released(button.b) || button.pressed_for_ctime(button.b, 1000, 200) {
        lcd.print('B')
    } else if button.was_released(button.c) || button.pressed_for_ctime(button.c, 1000, 200) {
        lcd.print('C')
    } else if button.was_released_for(button.b, 700) {
        lcd.clear(lcd.white)  // Clear the screen and set white to the background color.
        lcd.cursor(0, 0)
    }
}
