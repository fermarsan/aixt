module oled 

@[as_macro]
pub fn drawbitmap(x any , y any , array_image any , width any , height any , color any) {
	C.DISPLAY_DRAWBITMAP(x,y,array_image,width,height,color)
	C.DISPLAY_DISPLAY()
}
//display.drawBitmap(95, 35, circleArrows1, 32, 29, WHITE);

//void drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
                   //int16_t h, uint16_t color);