import tft_espi
import uart

@[as_macro] pub const XPT2046_IRQ 36   // T_IRQ
@[as_macro] pub const XPT2046_MOSI 32  // T_DIN
@[as_macro] pub const XPT2046_MISO 39  // T_OUT
@[as_macro] pub const XPT2046_CLK 25   // T_CLK
@[as_macro] pub const XPT2046_CS 33    // T_CS

fn print_touch_to_serial(touch_x int, touch_y int, touch_z int) {
  uart.print("X = ")
  uart.print(touch_x)
  uart.print(" | Y = ")
  uart.print(touch_y)
  uart.print(" | Pressure = ")
  uart.print(touch_z)
  uart.println()
}

fn print_touch_to_display(touch_x int , touch_y int,touch_z int) {

  tft_espi.fill_screen(tft_espi.white)
  tft_espi.set_text_color(tft_espi.black, tft_espi.white)

  center_x int  = SCREEN_WIDTH / 2;
  text_y int  = 80;
  
  String temp_text = "X = " + String(touch_x);
  tft_espi.draw_Centre_String(tft_espi.temp_text any, tft_espi.center_x, tft_espi.text_y, tft_espi.font_size)
  
  text_y += 20;
  temp_text = "Y = " + String(touch_y);
  tft_espi.draw_Centre_String(tft_espi.temp_text any, tft_espi.center_x, tft_espi.text_y, tft_espi.font_size)

  text_y += 20;
  temp_text = "Pressure = " + String(touch_z);
  tft_espi.draw_Centre_String(tft_espi.temp_text any, tft_espi.center_x, tft_espi.text_y, tft_espi.font_size)
}
tft_espi.set_rotation(1)
tft_espi.init()