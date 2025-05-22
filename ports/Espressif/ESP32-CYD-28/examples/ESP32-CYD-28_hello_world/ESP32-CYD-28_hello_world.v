import lcd
import uart
import pin
import time

const screen_width = 320
const screen_height = 240
const font_size = 2

fn print_touch_to_display(touch_x int, touch_y int, touch_z int) {
	lcd.fill_screen(lcd.white)
	lcd.text_color(lcd.black, lcd.white)

	center_x := int(screen_width / 2)
	text_y := 80

	temp_text := 'Hola Mundo'
	lcd.draw_centre_string(temp_text, center_x, text_y, font_size)
}

x, y, z := 0, 10, 100

uart.setup(115200)

lcd.rotation(1)

lcd.fill_screen(lcd.white)
lcd.text_color(lcd.black, lcd.white)

// center_x := int(screen_width / 2)
// center_y := int(screen_height / 2)

for {
	print_touch_to_display(x, y, z)
	time.sleep_ms(100)
}
