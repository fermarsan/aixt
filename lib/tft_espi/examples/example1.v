import tft_espi
import uart


fn print_touch_to_serial(touch_x int, touch_y int, touch_zint) {
  uart.print("X = ")
  uart.print(touch_x)
  uart.print(" | Y = ")
  uart.print(touch_y)
  uart.print(" | Pressure = ")
  uart.print(touch_z)
  uart.println()
}


tft_espi.fill_screen(tft_espi.white)
tft_espi.set_text_color(tft_espi.black, tft_espi.white)