import tft_espi
import uart

TFT_eSPI tft = TFT_eSPI();

@[as_macro] pub const XPT2046_IRQ 36   // T_IRQ
@[as_macro] pub const XPT2046_MOSI 32  // T_DIN
@[as_macro] pub const XPT2046_MISO 39  // T_OUT
@[as_macro] pub const XPT2046_CLK 25   // T_CLK
@[as_macro] pub const XPT2046_CS 33    // T_CS
@[as_macro] pub const SCREEN_WIDTH 320
@[as_macro] pub const SCREEN_HEIGHT 240
@[as_macro] pub const FONT_SIZE 2

int x, y, z;

fn print_touch_to_display(touch_x int , touch_y int,touch_z int) {
 tft_espi.fill_screen(tft_espi.white)
 tft_espi.set_text_color(tft_espi.black, tft_espi.white)

  center_x int  = screen_width / 2 
  text_y int  = 80
 
  String tempText = "Hola Mundo"
  tft_espi.draw_Centre_String(tft_espi.temp_text any, tft_espi.center_x, tft_espi.text_y, tft_espi.font_size)
  
}

void setup() {
  Serial.begin(115200)

  tft_espi.init()
  tft_espi.set_rotation(1)

  tft_espi.fill_screen(tft_espi.white)
  tft_espi.set_text_color(tft_espi.black, tft_espi.white)
  
  center_x int = screen_width / 2
  center_y int = screen_height / 2 
}

void loop() {
      print_touch_to_display(x, y, z)

    delay(100)
  
}