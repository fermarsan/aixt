module button

// #################### NXC Button module ####################

// Constant offsets into the Button module IOMAP structure. 
#define 	offset_pressed_cnt		ButtonOffsetPressedCnt  
#define 	offset_long_press_cnt	ButtonOffsetLongPressCnt
#define 	offset_short_rel_cnt	ButtonOffsetShortRelCnt
#define 	offset_long_rel_cnt		ButtonOffsetLongRelCnt
#define 	offset_rel_cnt			ButtonOffsetRelCnt
#define 	offset_state			ButtonOffsetState

// Constants to specify which button to use with button module functions. 
#define 	btn1      		BTN1       
#define 	btn2      		BTN2       
#define 	btn3      		BTN3       
#define 	btn4      		BTN4       
#define 	btn_exit   		BTNEXIT     
#define 	btn_right  		BTNRIGHT     
#define 	btn_left   		BTNLEFT     
#define 	btn_center 		BTNCENTER     
#define 	btn_no_of		NO_OF_BTNS

// Constants for use with the ButtonState() function.
// The _EV values can be combined together using a bitwise OR operation. 
#define 	state_pressed_ev   			BTNSTATE_PRESSED_EV   
#define 	state_short_released_ev   	BTNSTATE_SHORT_RELEASED_EV   
#define 	state_long_pressed_ev   	BTNSTATE_LONG_PRESSED_EV   
#define 	state_long_released_ev   	BTNSTATE_LONG_RELEASED_EV   
#define 	state_pressed_state   		BTNSTATE_PRESSED_STATE   
#define 	state_none   				BTNSTATE_NONE   

// Functions for accessing and modifying Button module features. 
#define     button__pressed(...)                    ButtonPressed(__VA_ARGS__)
#define     button__count(...)                      ButtonCount(__VA_ARGS__)
#define     button__read_ex(...)                    ReadButtonEx(__VA_ARGS__)
#define     button__press_count(...)                ButtonPressCount(__VA_ARGS__)
#define     button__long_press_count(...)           ButtonLongPressCount(__VA_ARGS__)
#define     button__short_release_count(...)        ButtonShortReleaseCount(__VA_ARGS__)
#define     button__long_release_count(...)         ButtonLongReleaseCount(__VA_ARGS__)
#define     button__release_count(...)              ButtonReleaseCount(__VA_ARGS__)
#define     button__state(...)                      ButtonState(__VA_ARGS__)
#define     button__set_long_press_count(...)       SetButtonLongPressCount(__VA_ARGS__)
#define     button__set_long_release_count(...)     SetButtonLongReleaseCount(__VA_ARGS__)
#define     button__set_press_count(...)            SetButtonPressCount(__VA_ARGS__)
#define     button__set_release_count(...)          SetButtonReleaseCount(__VA_ARGS__)
#define     button__set_short_release_count(...)    SetButtonShortReleaseCount(__VA_ARGS__)
#define     button__set_state(...)                  SetButtonState(__VA_ARGS__)
#define     button__sys_read(...)                   SysReadButton(__VA_ARGS__)



fn init() {

}