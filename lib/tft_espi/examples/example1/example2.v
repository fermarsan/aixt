import tft_espi
import uart
import pin
import time

const xpt2046_irq = pin.gpio36 // T_IRQ
const xpt2046_mosi = pin.gpio32 // T_DIN
const xpt2046_miso = pin.gpio39 // T_OUT
const xpt2046_clk = pin.gpio25 // T_CLK
const xpt2046_cs = pin.gpio33 // T_CS

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
