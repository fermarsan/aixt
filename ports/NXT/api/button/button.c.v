module button

// #################### NXC Button module ####################

// Constant offsets into the Button module IOMAP structure. 
#define 	button__offset_pressed_cnt		ButtonOffsetPressedCnt  
#define 	button__offset_long_press_cnt	ButtonOffsetLongPressCnt
#define 	button__offset_short_rel_cnt	ButtonOffsetShortRelCnt
#define 	button__offset_long_rel_cnt		ButtonOffsetLongRelCnt
#define 	button__offset_rel_cnt			ButtonOffsetRelCnt
#define 	button__offset_state			ButtonOffsetState

// Constants to specify which button to use with button module functions. 
#define 	button__1      		BTN1       
#define 	button__2      		BTN2       
#define 	button__3      		BTN3       
#define 	button__4      		BTN4       
#define 	button__exit   		BTNEXIT     
#define 	button__right  		BTNRIGHT     
#define 	button__left   		BTNLEFT     
#define 	button__center 		BTNCENTER     
#define 	button__no_of		NO_OF_BTNS

// Constants for use with the ButtonState() function.
// The _EV values can be combined together using a bitwise OR operation. 
#define 	button__state_pressed_ev   			BTNSTATE_PRESSED_EV   
#define 	button__state_short_released_ev   	BTNSTATE_SHORT_RELEASED_EV   
#define 	button__state_long_pressed_ev   	BTNSTATE_LONG_PRESSED_EV   
#define 	button__state_long_released_ev   	BTNSTATE_LONG_RELEASED_EV   
#define 	button__state_pressed_state   		BTNSTATE_PRESSED_STATE   
#define 	button__state_none   				BTNSTATE_NONE   

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