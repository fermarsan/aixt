module oled 

@[as_macro]
pub fn drawbitmap(x,y,array_image,width,height u8,color int) {
	C.DISPLAY_DRAWBITMAP(x,y,array_image,width,height,color)
}
//display.drawBitmap(95, 35, circleArrows1, 32, 29, WHITE);

//void drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
                   //int16_t h, uint16_t color);