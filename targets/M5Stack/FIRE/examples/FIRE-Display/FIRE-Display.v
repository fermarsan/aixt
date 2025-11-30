// Project name:
// Author: 
// Date: 
// M5Stack FIRE IoT development kit

import lcd 
import random
import power
import time


power.setup()  // Init Power module

lcd.fill_screen(lcd.white)  // Set the screen background
time.sleep_ms(500)		// Delay 500ms
lcd.fill_screen(lcd.red)
time.sleep_ms(500)
lcd.fill_screen(lcd.green)
time.sleep_ms(500)
lcd.fill_screen(lcd.blue)
time.sleep_ms(500)
lcd.fill_screen(lcd.black)o
time.sleep_ms(500)

lcd.cursor(10, 10)  // Move the cursor position to (x,y)
lcd.text_color(lcd.white)  // Set the font color to white
lcd.text_size(1)  // Set the font size
lcd.print("Display Test!")  // Serial output format string

// draw graphic
time.sleep_ms(1000)
lcd.rect(100, 100, 50, 50, lcd.blue)  // 50x50 blue rectangle wireframe at (x,y)
time.sleep_ms(1000)  
lcd.fill_rect(100, 100, 50, 50, lcd.blue)  // blue rectangle 50x50 at (x,y)
time.sleep_ms(1000)
lcd.circle(100, 100, 50, lcd.red)	// Draw a red circle of radius 50 at (x,y)
time.sleep_ms(1000)
lcd.fill_circle(100, 100, 50, lcd.red)  // Draw a red circle of radius 50 at (x,y)
time.sleep_ms(1000)
lcd.triangle(30, 30, 180, 100, 80, 150, lcd.yellow)  // Make a triangle wireframe with (x1,y1) (x2,y2) (x3,y3) as the vertices
time.sleep_ms(1000)
lcd.fill_triangle(30, 30, 180, 100, 80, 150, lcd.yellow)	// Construct a triangle with (x1,y1) (x2,y2) (x3,y3) as its vertices

for {
    lcd.fill_triangle(	
		random.rand(lcd.width() - 1), random.rand(lcd.height() - 1),
        random.rand(lcd.width() - 1), random.rand(lcd.height() - 1),
        random.rand(lcd.width() - 1), random.rand(lcd.height() - 1),
        u32(random.rand(0xfffe))
	)
    update()  // Read the press state of the key
}