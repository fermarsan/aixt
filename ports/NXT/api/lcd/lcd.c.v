// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Display module for NXT (NXC backend)

module lcd


// cursor variables
__global (
	cursor_x = i8(0)
	cursor_y = i8(56)	
)

pub const x_max = i8(90)
pub const y_max = i8(56)

// Line numbers for use with DrawText system function.  
@[as_macro] pub const line_8	= 0    
@[as_macro] pub const line_7	= 8    
@[as_macro] pub const line_6	= 16   
@[as_macro] pub const line_5	= 24   
@[as_macro] pub const line_4	= 32   
@[as_macro] pub const line_3	= 40   
@[as_macro] pub const line_2	= 48   
@[as_macro] pub const line_1	= 56   

// Constants that are for use with getting/setting display data. 
@[as_macro] pub const text_line_1 = 0  
@[as_macro] pub const text_line_2 = 1  
@[as_macro] pub const text_line_3 = 2  
@[as_macro] pub const text_line_4 = 3  
@[as_macro] pub const text_line_5 = 4  
@[as_macro] pub const text_line_6 = 5  
@[as_macro] pub const text_line_7 = 6  
@[as_macro] pub const text_line_8 = 7  
@[as_macro] pub const text_lines  = 8  



fn C.ResetScreen() 
fn C.CircleOut(args ...any) i8 
fn C.LineOut(args ...any) i8 
fn C.PointOut(args ...any) i8 
fn C.RectOut(args ...any) i8 
fn C.TextOut(args ...any) i8 
fn C.NumOut(args ...any) i8 
fn C.EllipseOut(args ...any) i8 
fn C.DisplayContrast() u8 
fn C.SetDisplayContrast(args ...any) u8 
fn C.ClearScreen()
fn C.ClearLine(args ...any) 
fn C.StrLen(args ...any) u16



@[as_macro] 
pub fn reset() {
	C.ResetScreen() 
}

@[as_macro] 
pub fn draw_circle(args ...any) i8 {
	return C.CircleOut(...args) 
}

@[as_macro] 
pub fn draw_line(args ...any) i8 {
	return C.LineOut(...args) 
}

@[as_macro] 
pub fn draw_point(args ...any) i8 {
	return C.PointOut(...args) 
}

@[as_macro] 
pub fn draw_rect(args ...any) i8 {
	return C.RectOut(...args) 
}

@[as_macro] 
pub fn write_text(args ...any) i8 {
	return C.TextOut(...args) 
}

@[as_macro] 
pub fn write_num(args ...any) i8 {
	return C.NumOut(...args) 
}

@[as_macro] 
pub fn draw_ellipse(args ...any) i8 {
	return C.EllipseOut(...args) 
}

@[as_macro] 
pub fn contrast() u8 {
	return C.DisplayContrast() 
}

@[as_macro] 
pub fn set_contrast(args ...any) {
	C.SetDisplayContrast(...args) 
}

@[as_macro] 
pub fn clear() {
	C.ClearScreen()
	cursor_x = 0
	cursor_y = 56
}

@[as_macro] 
pub fn clear_line(args ...any) {
	C.ClearLine(...args) 
}

pub fn into_range(num i8, max i8, min i8) i8 {
	if num > max {
		return max
	}
	else if num < min {
		return min
	}
	else {
		return num
	}
}

pub fn move_to(x i8, y i8) {
	cursor_x = lcd.into_range(x*6, x_max, 0)
	cursor_y = lcd.into_range(56-(y*8), y_max, 0)
}

pub fn print(msg string) {
	lcd.write_text(cursor_x, cursor_y, msg)
	cursor_x += i8(C.StrLen(msg)*6)
	cursor_x = lcd.into_range(cursor_x, x_max, 0)
}


pub fn println(msg string) {
	lcd.print(msg)
	cursor_y -= 8
	cursor_y = lcd.into_range(cursor_y, y_max, 0)
	cursor_x = 0
}
