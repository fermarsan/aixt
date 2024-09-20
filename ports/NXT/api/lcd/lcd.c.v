module lcd


import str

// ####################  NXC Display module ####################

// Constants that are for use with the display contrast API functions. 
// #define 	lcd__contrast_default	DISPLAY_CONTRAST_DEFAULT
// #define 	lcd__contrast_max    	DISPLAY_CONTRAST_MAX    

// Constants that are for use with the display flags functions. 
// #define 	lcd__on                 DISPLAY_ON             
// #define 	lcd__refresh         	DISPLAY_REFRESH            
// #define 	lcd__popup           	DISPLAY_POPUP            
// #define 	lcd__refresh_disabled	DISPLAY_REFRESH_DISABLED            
// #define 	lcd__busy            	DISPLAY_BUSY             

// Constant offsets into the display module IOMAP structure. 
// #define 	offset_p_func                    DisplayOffsetPFunc
// #define 	offset_erase_mask                DisplayOffsetEraseMask
// #define 	offset_update_mask               DisplayOffsetUpdateMask
// #define 	offset_p_font                    DisplayOffsetPFont
// #define 	offset_p_text_lines              DisplayOffsetPTextLines
// #define 	offset_p_status_text             DisplayOffsetPStatusText
// #define 	offset_p_status_icons            DisplayOffsetPStatusIcons
// #define 	offset_p_screens                 DisplayOffsetPScreens
// #define 	offset_p_bitmaps                 DisplayOffsetPBitmaps
// #define 	offset_p_menu_text               DisplayOffsetPMenuText
// #define 	offset_p_menu_icons              DisplayOffsetPMenuIcons
// #define 	offset_p_step_icons              DisplayOffsetPStepIcons
// #define 	offset_display                   DisplayOffsetDisplay
// #define 	offset_status_icons              DisplayOffsetStatusIcons
// #define 	offset_step_icons                DisplayOffsetStepIcons
// #define 	offset_flags                     DisplayOffsetFlags
// #define 	offset_text_lines_center_flags   DisplayOffsetTextLinesCenterFlags
// #define 	offset_normal                    DisplayOffsetNormal
// #define 	offset_popup                     DisplayOffsetPopup
// #define 	offset_contrast                  DisplayOffsetContrast

// Constants that are for use with the DisplayExecuteFunction system call. 
// #define 	lcd__erase_all      		DISPLAY_ERASE_ALL            
// #define 	lcd__pixel          		DISPLAY_PIXEL            
// #define 	lcd__horizontal_line		DISPLAY_HORIZONTAL_LINE            
// #define 	lcd__vertical_line  		DISPLAY_VERTICAL_LINE            
// #define 	lcd__char           		DISPLAY_CHAR            
// #define 	lcd__erase_line     		DISPLAY_ERASE_LINE            
// #define 	lcd__fill_region    		DISPLAY_FILL_REGION            
// #define 	lcd__frame          		DISPLAY_FRAME           


// Constants that are for specifying drawing options in several display module API functions. 
// #define 	draw_opt_normal							DRAW_OPT_NORMAL                       
// #define 	draw_opt_clear_whole_screen				DRAW_OPT_CLEAR_WHOLE_SCREEN                       
// #define 	draw_opt_clear_except_status_screen		DRAW_OPT_CLEAR_EXCEPT_STATUS_SCREEN                       
// #define 	draw_opt_clear_pixels					DRAW_OPT_CLEAR_PIXELS                       
// #define 	draw_opt_clear							DRAW_OPT_CLEAR                       
// #define 	draw_opt_invert							DRAW_OPT_INVERT                       
// #define 	draw_opt_logical_copy					DRAW_OPT_LOGICAL_COPY                       
// #define 	draw_opt_logical_and					DRAW_OPT_LOGICAL_AND                       
// #define 	draw_opt_logical_or						DRAW_OPT_LOGICAL_OR                       
// #define 	draw_opt_logical_xor					DRAW_OPT_LOGICAL_XOR                       
// #define 	draw_opt_fill_shape						DRAW_OPT_FILL_SHAPE                       
// #define 	draw_opt_clear_screen_modes				DRAW_OPT_CLEAR_SCREEN_MODES                       
// #define 	draw_opt_logical_operations				DRAW_OPT_LOGICAL_OPERATIONS                       
// #define 	draw_opt_polygon_polyline				DRAW_OPT_POLYGON_POLYLINE                       
// #define 	draw_opt_clear_line						DRAW_OPT_CLEAR_LINE                       
// #define 	draw_opt_clear_eol						DRAW_OPT_CLEAR_EOL   

// Line numbers for use with DrawText system function.  
#define 	line8		LCD_LINE8    
#define 	line7		LCD_LINE7    
#define 	line6		LCD_LINE6   
#define 	line5		LCD_LINE5   
#define 	line4		LCD_LINE4   
#define 	line3		LCD_LINE3   
#define 	line2		LCD_LINE2   
#define 	line1		LCD_LINE1   

// Constants that are for use with getting/setting display data. 
#define 	textline_1		TEXTLINE_1  
#define 	textline_2		TEXTLINE_2  
#define 	textline_3		TEXTLINE_3  
#define 	textline_4		TEXTLINE_4  
#define 	textline_5		TEXTLINE_5  
#define 	textline_6		TEXTLINE_6  
#define 	textline_7		TEXTLINE_7  
#define 	textline_8		TEXTLINE_8  
#define 	textlines 		TEXTLINES   

// Constants that are part of the NXT firmware's Display module. 
// #define 	mode_restore			SCREEN_MODE_RESTORE   
// #define 	mode_clear				SCREEN_MODE_CLEAR   
// #define 	height					DISPLAY_HEIGHT                                         
// #define 	width					DISPLAY_WIDTH                                         
// #define 	menuicons_y				DISPLAY_MENUICONS_Y                                         
// #define 	menuicons_x_offs		DISPLAY_MENUICONS_X_OFFS                                         
// #define 	menuicons_x_diff		DISPLAY_MENUICONS_X_DIFF                                         
// #define 	menuicon_left			MENUICON_LEFT                                         
// #define 	menuicon_center			MENUICON_CENTER                                         
// #define 	menuicon_right			MENUICON_RIGHT                                         
// #define 	menuicons				MENUICONS                                         
// #define 	frame_select			FRAME_SELECT                                         
// #define 	statustext				STATUSTEXT                                         
// #define 	menutext				MENUTEXT                                         
// #define 	stepline				STEPLINE                                         
// #define 	topline					TOPLINE                                         
// #define 	specials				SPECIALS                                         
// #define 	statusicon_bluetooth	STATUSICON_BLUETOOTH                                         
// #define 	statusicon_usb			STATUSICON_USB                                         
// #define 	statusicon_vm			STATUSICON_VM                                         
// #define 	statusicon_battery		STATUSICON_BATTERY                                         
// #define 	statusicons				STATUSICONS                                         
// #define 	screen_background		SCREEN_BACKGROUND                                         
// #define 	screen_large			SCREEN_LARGE                                        
// #define 	screen_small			SCREEN_SMALL                                        
// #define 	screens					SCREENS                                        
// #define 	bitmap_1				BITMAP_1                                        
// #define 	bitmap_2				BITMAP_2                                        
// #define 	bitmap_3				BITMAP_3                                        
// #define 	bitmap_4				BITMAP_4                                        
// #define 	bitmaps					BITMAPS                                        
// #define 	stepicon_1				STEPICON_1                                        
// #define 	stepicon_2				STEPICON_2                                        
// #define 	stepicon_3				STEPICON_3                                        
// #define 	stepicon_4				STEPICON_4                                        
// #define 	stepicon_5				STEPICON_5                                        
// #define 	stepicons				STEPICONS                                        

// 
@[inline] reset() { C.ResetScreen() }
@[inline] circle() { return C.CircleOut() }
@[inline] line() { return C.LineOut() }
@[inline] point() { return C.PointOut() }
@[inline] rect() { return C.RectOut() }
@[inline] text() { return C.TextOut() }
@[inline] num() { return C.NumOut() }
@[inline] ellipse() { return C.EllipseOut() }
@[inline] poly() { return C.PolyOut() }
// @[inline] font_text() { return C.FontTextOut() }
// @[inline] font_num() { return C.FontNumOut() }
@[inline] graphic() { return C.GraphicOut() }
@[inline] graphic_array() { return C.GraphicArrayOut() }
@[inline] graphic_ex() { return C.GraphicOutEx() }
@[inline] graphic_array_ex() { return C.GraphicArrayOutEx() }
@[inline] get_normal() { return C.GetDisplayNormal() }
@[inline] set_normal() { return C.SetDisplayNormal() }
@[inline] get_popup() { return C.GetDisplayPopup() }
@[inline] set_popup() { return C.SetDisplayPopup() }
@[inline] erase_mask() { return C.DisplayEraseMask() }
@[inline] update_mask() { return C.DisplayUpdateMask() }
@[inline] font() { return C.DisplayFont() }
@[inline] display() { return C.DisplayDisplay() }
@[inline] flags() { return C.DisplayFlags() }
@[inline] text_lines_center_flags() { return C.DisplayTextLinesCenterFlags() }
@[inline] sys_draw_text() { return C.SysDrawText() }
@[inline] sys_draw_point() { return C.SysDrawPoint() }
@[inline] sys_draw_line() { return C.SysDrawLine() }
@[inline] sys_draw_circle() { return C.SysDrawCircle() }
@[inline] sys_draw_rect() { return C.SysDrawRect() }
@[inline] sys_draw_graphic() { return C.SysDrawGraphic() }
@[inline] sys_set_mode() { return C.SysSetScreenMode() }
@[inline] sys_display_execute_function() { return C.SysDisplayExecuteFunction() }
@[inline] contrast() { return C.DisplayContrast() }
@[inline] sys_draw_graphic_array() { return C.SysDrawGraphicArray() }
@[inline] sys_draw_polygon() { return C.SysDrawPolygon() }
@[inline] sys_draw_ellipse() { return C.SysDrawEllipse() }
@[inline] sys_draw_font() { return C.SysDrawFont() }
@[inline] clear() { 
	C.ClearScreen()
	cursor_x = 0
	cursor_y = 56
}
@[inline] clear_line() { return C.ClearLine() }
@[inline] set_font() { return C.SetDisplayFont() }
@[inline] set_display() { return C.SetDisplayDisplay() }
@[inline] set_erase_mask() { return C.SetDisplayEraseMask() }
@[inline] set_flags() { return C.SetDisplayFlags() }
@[inline] set_text_lines_center_flags() { return C.SetDisplayTextLinesCenterFlags() }
@[inline] set_update_mask() { return C.SetDisplayUpdateMask() }
@[inline] set_contrast() { return C.SetDisplayContrast() }

// cursor variables
__global (
	cursor_x = i8(0)
	cursor_y = i8(56)	
)

const (
	x_max = i8(90)
	y_max = i8(56)
)

// @[inline]
fn into_range(num i8, max i8, min i8) i8 {
	if num > max {
		return max
	} else if num < min {
		return min
	} else {
		return num
	}
}

// @[inline]
fn move_to(x i8, y i8) {
	cursor_x = lcd.into_range(x*6, x_max, 0)
	cursor_y = lcd.into_range(56-(y*8), y_max, 0)
}

// @[inline]
fn print(msg string) {
	lcd.text(cursor_x, cursor_y, msg)
	cursor_x += str.len(msg)*6
	cursor_x = lcd.into_range(cursor_x, x_max, 0)
}

// @[inline]
fn println(msg string) {
	lcd.print(msg)
	cursor_y -= 8
	cursor_y = lcd.into_range(cursor_y, y_max, 0)
	cursor_x = 0
}