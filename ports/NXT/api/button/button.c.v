module button

// ####################  NXC Button module ####################

// Constant offsets into the Button module IOMAP structure. 
// #define 	offset_pressed_cnt		ButtonOffsetPressedCnt  
// #define 	offset_long_press_cnt	ButtonOffsetLongPressCnt
// #define 	offset_short_rel_cnt	ButtonOffsetShortRelCnt
// #define 	offset_long_rel_cnt		ButtonOffsetLongRelCnt
// #define 	offset_rel_cnt			ButtonOffsetRelCnt
// #define 	offset_state			ButtonOffsetState

// Constants to specify which button to use with button module functions. 
// #define 	btn1      		BTN1       
// #define 	btn2      		BTN2       
// #define 	btn3      		BTN3       
// #define 	btn4      		BTN4       
// #define 	btn_exit   		BTNEXIT     
// #define 	btn_right  		BTNRIGHT     
// #define 	btn_left   		BTNLEFT     
// #define 	btn_center 		BTNCENTER     
// #define 	no_btns			NO_OF_BTNS

enum btns {
	btn1=0       
	btn2       
	btn3       
	btn4 
	no_btns
}



// Constants for use with the ButtonState() function.
// The _EV values can be combined together using a bitwise OR operation. 
// #define 	state_pressed_ev   			BTNSTATE_PRESSED_EV   
// #define 	state_short_released_ev   	BTNSTATE_SHORT_RELEASED_EV   
// #define 	state_long_pressed_ev   	BTNSTATE_LONG_PRESSED_EV   
// #define 	state_long_released_ev   	BTNSTATE_LONG_RELEASED_EV   
// #define 	state_pressed_state   		BTNSTATE_PRESSED_STATE   
// #define 	state_none   				BTNSTATE_NONE   

// Functions for accessing and modifying Button module features. 
@[inline]
read(btn u8) bool {
	return C.ButtonPressed(btn, false) 
}

@[inline]
read_count(btn u8btn u8) u8 {
	return C.ButtonCount(btn, false) 
}

// @[inline]
// read_ex() {
// 	return C.ReadButtonEx() 
// }

// @[inline]
// press_count(btn u8) {
// 	return C.ButtonPressCount() 
// }

// @[inline]
// long_press_count(btn u8) {
// 	return C.ButtonLongPressCount() 
// }

// @[inline]
// short_release_count(btn u8) {
// 	return C.ButtonShortReleaseCount() 
// }

// @[inline]
// long_release_count(btn u8) {
// 	return C.ButtonLongReleaseCount() 
// }

// @[inline]
// release_count(btn u8) {
// 	return C.ButtonReleaseCount() 
// }

// @[inline]
// state() {
// 	return C.ButtonState() 
// }

// @[inline]
// set_long_press_count() {
// 	return C.SetButtonLongPressCount() 
// }

// @[inline]
// set_long_release_count() {
// 	return C.SetButtonLongReleaseCount() 
// }

@[inline]
set_count(btn u8, n u8) {
	C.SetButtonPressCount(btn, n) 
}

// @[inline]
// set_release_count() {
// 	return C.SetButtonReleaseCount() 
// }

// @[inline]
// set_short_release_count() {
// 	return C.SetButtonShortReleaseCount() 
// }

// @[inline]
// set_state() {
// 	return C.SetButtonState() 
// }

// @[inline]
// sys_read() {
// 	return C.SysReadButton() 
// }

