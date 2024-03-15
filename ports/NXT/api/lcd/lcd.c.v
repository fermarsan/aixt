import lcd

// #################### NXC Display module ####################

// Constants that are for use with the display contrast API functions. 
#define 	lcd__contrast_default	DISPLAY_CONTRAST_DEFAULT
#define 	lcd__contrast_max    	DISPLAY_CONTRAST_MAX    

// Constants that are for use with the display flags functions. 
#define 	lcd__on                 DISPLAY_ON             
#define 	lcd__refresh         	DISPLAY_REFRESH            
#define 	lcd__popup           	DISPLAY_POPUP            
#define 	lcd__refresh_disabled	DISPLAY_REFRESH_DISABLED            
#define 	lcd__busy            	DISPLAY_BUSY             

// Constant offsets into the display module IOMAP structure. 
#define 	offset_p_func                    DisplayOffsetPFunc
#define 	offset_erase_mask                DisplayOffsetEraseMask
#define 	offset_update_mask               DisplayOffsetUpdateMask
#define 	offset_p_font                    DisplayOffsetPFont
#define 	offset_p_text_lines              DisplayOffsetPTextLines
#define 	offset_p_status_text             DisplayOffsetPStatusText
#define 	offset_p_status_icons            DisplayOffsetPStatusIcons
#define 	offset_p_screens                 DisplayOffsetPScreens
#define 	offset_p_bitmaps                 DisplayOffsetPBitmaps
#define 	offset_p_menu_text               DisplayOffsetPMenuText
#define 	offset_p_menu_icons              DisplayOffsetPMenuIcons
#define 	offset_p_step_icons              DisplayOffsetPStepIcons
#define 	offset_display                   DisplayOffsetDisplay
#define 	offset_status_icons              DisplayOffsetStatusIcons
#define 	offset_step_icons                DisplayOffsetStepIcons
#define 	offset_flags                     DisplayOffsetFlags
#define 	offset_text_lines_center_flags   DisplayOffsetTextLinesCenterFlags
#define 	offset_normal                    DisplayOffsetNormal
#define 	offset_popup                     DisplayOffsetPopup
#define 	offset_contrast                  DisplayOffsetContrast

// Constants that are for use with the DisplayExecuteFunction system call. 
#define 	erase_all      		DISPLAY_ERASE_ALL            
#define 	pixel          		DISPLAY_PIXEL            
#define 	horizontal_line		DISPLAY_HORIZONTAL_LINE            
#define 	vertical_line  		DISPLAY_VERTICAL_LINE            
#define 	char           		DISPLAY_CHAR            
#define 	erase_line     		DISPLAY_ERASE_LINE            
#define 	fill_region    		DISPLAY_FILL_REGION            
#define 	frame          		DISPLAY_FRAME           


// Constants that are for specifying drawing options in several display module API functions. 
#define 	draw_opt_normal							DRAW_OPT_NORMAL                       
#define 	draw_opt_clear_whole_screen				DRAW_OPT_CLEAR_WHOLE_SCREEN                       
#define 	draw_opt_clear_except_status_screen		DRAW_OPT_CLEAR_EXCEPT_STATUS_SCREEN                       
#define 	draw_opt_clear_pixels					DRAW_OPT_CLEAR_PIXELS                       
#define 	draw_opt_clear							DRAW_OPT_CLEAR                       
#define 	draw_opt_invert							DRAW_OPT_INVERT                       
#define 	draw_opt_logical_copy					DRAW_OPT_LOGICAL_COPY                       
#define 	draw_opt_logical_and					DRAW_OPT_LOGICAL_AND                       
#define 	draw_opt_logical_or						DRAW_OPT_LOGICAL_OR                       
#define 	draw_opt_logical_xor					DRAW_OPT_LOGICAL_XOR                       
#define 	draw_opt_fill_shape						DRAW_OPT_FILL_SHAPE                       
#define 	draw_opt_clear_screen_modes				DRAW_OPT_CLEAR_SCREEN_MODES                       
#define 	draw_opt_logical_operations				DRAW_OPT_LOGICAL_OPERATIONS                       
#define 	draw_opt_polygon_polyline				DRAW_OPT_POLYGON_POLYLINE                       
#define 	draw_opt_clear_line						DRAW_OPT_CLEAR_LINE                       
#define 	draw_opt_clear_eol						DRAW_OPT_CLEAR_EOL   

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
#define 	mode_restore			SCREEN_MODE_RESTORE   
#define 	mode_clear				SCREEN_MODE_CLEAR   
#define 	height					DISPLAY_HEIGHT                                         
#define 	width					DISPLAY_WIDTH                                         
#define 	menuicons_y				DISPLAY_MENUICONS_Y                                         
#define 	menuicons_x_offs		DISPLAY_MENUICONS_X_OFFS                                         
#define 	menuicons_x_diff		DISPLAY_MENUICONS_X_DIFF                                         
#define 	menuicon_left			MENUICON_LEFT                                         
#define 	menuicon_center			MENUICON_CENTER                                         
#define 	menuicon_right			MENUICON_RIGHT                                         
#define 	menuicons				MENUICONS                                         
#define 	frame_select			FRAME_SELECT                                         
#define 	statustext				STATUSTEXT                                         
#define 	menutext				MENUTEXT                                         
#define 	stepline				STEPLINE                                         
#define 	topline					TOPLINE                                         
#define 	specials				SPECIALS                                         
#define 	statusicon_bluetooth	STATUSICON_BLUETOOTH                                         
#define 	statusicon_usb			STATUSICON_USB                                         
#define 	statusicon_vm			STATUSICON_VM                                         
#define 	statusicon_battery		STATUSICON_BATTERY                                         
#define 	statusicons				STATUSICONS                                         
#define 	screen_background		SCREEN_BACKGROUND                                         
#define 	screen_large			SCREEN_LARGE                                        
#define 	screen_small			SCREEN_SMALL                                        
#define 	screens					SCREENS                                        
#define 	bitmap_1				BITMAP_1                                        
#define 	bitmap_2				BITMAP_2                                        
#define 	bitmap_3				BITMAP_3                                        
#define 	bitmap_4				BITMAP_4                                        
#define 	bitmaps					BITMAPS                                        
#define 	stepicon_1				STEPICON_1                                        
#define 	stepicon_2				STEPICON_2                                        
#define 	stepicon_3				STEPICON_3                                        
#define 	stepicon_4				STEPICON_4                                        
#define 	stepicon_5				STEPICON_5                                        
#define 	stepicons				STEPICONS                                        

// 
#define     lcd__reset(...)                         ResetScreen(__VA_ARGS__)
#define     lcd__circle(...)                        CircleOut(__VA_ARGS__)
#define     lcd__line(...)                          LineOut(__VA_ARGS__)
#define     lcd__point(...)                         PointOut(__VA_ARGS__)
#define     lcd__rect(...)                          RectOut(__VA_ARGS__)
#define     lcd__print(...)                         TextOut(__VA_ARGS__)
#define     lcd__print_num(...)                     NumOut(__VA_ARGS__)
#define     lcd__ellipse(...)                       EllipseOut(__VA_ARGS__)
#define     lcd__poly(...)                          PolyOut(__VA_ARGS__)
#define     lcd__font_print(...)                    FontTextOut(__VA_ARGS__)
#define     lcd__font_print_num(...)                FontNumOut(__VA_ARGS__)
#define     lcd__graphic(...)                       GraphicOut(__VA_ARGS__)
#define     lcd__graphic_array(...)                 GraphicArrayOut(__VA_ARGS__)
#define     lcd__graphic_ex(...)                    GraphicOutEx(__VA_ARGS__)
#define     lcd__graphic_array_ex(...)              GraphicArrayOutEx(__VA_ARGS__)
#define     lcd__get_normal(...)                    GetDisplayNormal(__VA_ARGS__)
#define     lcd__set_normal(...)                    SetDisplayNormal(__VA_ARGS__)
#define     lcd__get_popup(...)                     GetDisplayPopup(__VA_ARGS__)
#define     lcd__set_popup(...)                     SetDisplayPopup(__VA_ARGS__)
#define     lcd__erase_mask(...)                    DisplayEraseMask(__VA_ARGS__)
#define     lcd__update_mask(...)                   DisplayUpdateMask(__VA_ARGS__)
#define     lcd__font(...)                          DisplayFont(__VA_ARGS__)
#define     lcd__display(...)                       DisplayDisplay(__VA_ARGS__)
#define     lcd__flags(...)                         DisplayFlags(__VA_ARGS__)
#define     lcd__text_lines_center_flags(...)       DisplayTextLinesCenterFlags(__VA_ARGS__)
#define     lcd__sys_draw_text(...)                 SysDrawText(__VA_ARGS__)
#define     lcd__sys_draw_point(...)                SysDrawPoint(__VA_ARGS__)
#define     lcd__sys_draw_line(...)                 SysDrawLine(__VA_ARGS__)
#define     lcd__sys_draw_circle(...)               SysDrawCircle(__VA_ARGS__)
#define     lcd__sys_draw_rect(...)                 SysDrawRect(__VA_ARGS__)
#define     lcd__sys_draw_graphic(...)              SysDrawGraphic(__VA_ARGS__)
#define     lcd__sys_set_mode(...)                  SysSetScreenMode(__VA_ARGS__)
#define     lcd__sys_display_execute_function(...)  SysDisplayExecuteFunction(__VA_ARGS__)
#define     lcd__contrast(...)                      DisplayContrast(__VA_ARGS__)
#define     lcd__sys_draw_graphic_array(...)        SysDrawGraphicArray(__VA_ARGS__)
#define     lcd__sys_draw_polygon(...)              SysDrawPolygon(__VA_ARGS__)
#define     lcd__sys_draw_ellipse(...)              SysDrawEllipse(__VA_ARGS__)
#define     lcd__sys_draw_font(...)                 SysDrawFont(__VA_ARGS__)
#define     lcd__clear(...)                         ClearScreen(__VA_ARGS__)
#define     lcd__clear_line(...)                    ClearLine(__VA_ARGS__)
#define     lcd__set_font(...)                      SetDisplayFont(__VA_ARGS__)
#define     lcd__set_display(...)                   SetDisplayDisplay(__VA_ARGS__)
#define     lcd__set_erase_mask(...)                SetDisplayEraseMask(__VA_ARGS__)
#define     lcd__set_flags(...)                     SetDisplayFlags(__VA_ARGS__)
#define     lcd__set_text_lines_center_flags(...)   SetDisplayTextLinesCenterFlags(__VA_ARGS__)
#define     lcd__set_update_mask(...)               SetDisplayUpdateMask(__VA_ARGS__)
#define     lcd__set_contrast(...)                  SetDisplayContrast(__VA_ARGS__)



fn init() {

}