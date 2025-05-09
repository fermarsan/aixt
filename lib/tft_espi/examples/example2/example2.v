import tft_espi
import uart
import pin
import time

const screen_width = 320
const screen_height = 240
const font_size = 2

fn print_touch_to_display(touch_x int, touch_y int, touch_z int) {
	tft_espi.fill_screen(tft_espi.white)
	tft_espi.set_text_color(tft_espi.black, tft_espi.white)

	center_x := int(screen_width / 2)
	text_y := 80

	temp_text := 'Hola Mundo'
	tft_espi.draw_centre_string(temp_text, center_x, text_y, font_size)
}

x, y, z := 0, 0, 0

uart.setup(115200)

tft_espi.setup()
tft_espi.set_rotation(1)

tft_espi.fill_screen(tft_espi.white)
tft_espi.set_text_color(tft_espi.black, tft_espi.white)

// center_x := int(screen_width / 2)
// center_y := int(screen_height / 2)

for {
	print_touch_to_display(x, y, z)
	time.sleep_ms(100)
}
