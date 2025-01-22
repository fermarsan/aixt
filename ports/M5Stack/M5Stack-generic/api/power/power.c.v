// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Power module for M5Stack (arduino backend)

module power	// M5Stack power module

#include "power.c"

fn C.M5_POWER_BEGIN()
fn C.M5_POWER_CANCONTROL() bool
fn C.M5_POWER_SETPOWERBOOSTKEEPON(en  bool) bool
fn C.M5_POWER_SETAUTOBOOTONLOAD(en  bool) bool
fn C.M5_POWER_SETLOWPOWERSHUTDOWNTIME(time any) bool
fn C.M5_POWER_SETPOWERBOOSTONOFF(en  bool) bool
fn C.M5_POWER_SETPOWERBOOSTSET(en  bool) bool
fn C.M5_POWER_SETPOWERVIN(en  bool) bool
fn C.M5_POWER_SETPOWERWLEDSET(en  bool) bool
fn C.M5_POWER_SETPOWERBTNEN(en  bool) bool
fn C.M5_POWER_SETVINMAXCURRENT(cur u8) bool
fn C.M5_POWER_SETCHARGEVOLT(volt u8) bool
fn C.M5_POWER_SETCHARGE(en  bool) bool
fn C.M5_POWER_ISCHARGEFULL() bool
fn C.M5_POWER_ISCHARGING() bool
fn C.M5_POWER_GETBATTERYLEVEL() i8
fn C.M5_POWER_BATTERYMODE(en  bool) bool
fn C.M5_POWER_SETWAKEUPBUTTON(button u8)
fn C.M5_POWER_ISRESETBYWATCHDOG() bool
fn C.M5_POWER_ISRESETBYDEEPSLEEP() bool
fn C.M5_POWER_ISRESETBYSOFTWARE() bool
fn C.M5_POWER_ISRESETBYPOWERSW() bool
fn C.M5_POWER_DEEPSLEEP(time_in_us u64)
fn C.M5_POWER_LIGHTSLEEP(time_in_us u64)
fn C.M5_POWER_POWEROFF()
fn C.M5_POWER_RESET()

// init initializes the power module
@[as_macro] 
pub fn setup() {
	C.M5_POWER_BEGIN()
}

@[as_macro]
pub fn can_control() bool {
	return C.M5_POWER_CANCONTROL()
}

@[as_macro]
pub fn power_boost_keep_on(en  bool) bool {
	return C.M5_POWER_SETPOWERBOOSTKEEPON(en)
}

@[as_macro]
pub fn auto_boot_on_load(en  bool) bool {
	return C.M5_POWER_SETAUTOBOOTONLOAD(en)
}

@[as_macro]
pub fn low_power_shutdown_time(time any) bool {
	return C.M5_POWER_SETLOWPOWERSHUTDOWNTIME(time)
}

@[as_macro]
pub fn power_boost_on_off(en  bool) bool {
	return C.M5_POWER_SETPOWERBOOSTONOFF(en)
}

@[as_macro]
pub fn power_boost_set(en  bool) bool {
	return C.M5_POWER_SETPOWERBOOSTSET(en)
}

@[as_macro]
pub fn power_vin(en  bool) bool {
	return C.M5_POWER_SETPOWERVIN(en)
}

@[as_macro]
pub fn power_wled_set(en  bool) bool {
	return C.M5_POWER_SETPOWERWLEDSET(en)
}

@[as_macro]
pub fn power_btn_en(en  bool) bool {
	return C.M5_POWER_SETPOWERBTNEN(en)
}

@[as_macro]
pub fn vin_max_current(cur u8) bool {
	return C.M5_POWER_SETVINMAXCURRENT(cur)
}

@[as_macro]
pub fn charge_volt(volt u8) bool {
	return C.M5_POWER_SETCHARGEVOLT(volt)
}

@[as_macro]
pub fn charge(en  bool) bool {
	return C.M5_POWER_SETCHARGE(en)
}

@[as_macro]
pub fn is_charge_full() bool {
	return C.M5_POWER_ISCHARGEFULL()
}

@[as_macro]
pub fn is_charging() bool {
	return C.M5_POWER_ISCHARGING()
}

@[as_macro]
pub fn read_battery_level() i8 {
	return C.M5_POWER_GETBATTERYLEVEL()
}

@[as_macro]
pub fn battery_mode(en  bool) bool {
	return C.M5_POWER_BATTERYMODE(en)
}

@[as_macro]
pub fn wakeup_button(button u8) {
	C.M5_POWER_SETWAKEUPBUTTON(button)
}

@[as_macro]
pub fn is_reset_by_watchdog() bool {
	return C.M5_POWER_ISRESETBYWATCHDOG()
}

@[as_macro]
pub fn is_reset_by_deepsleep() bool {
	return C.M5_POWER_ISRESETBYDEEPSLEEP()
}

@[as_macro]
pub fn is_reset_by_software() bool {
	return C.M5_POWER_ISRESETBYSOFTWARE()
}

@[as_macro]
pub fn is_reset_by_power_sw() bool {
	return C.M5_POWER_ISRESETBYPOWERSW()
}

@[as_macro]
pub fn deep_sleep(time_in_us u64) {
	C.M5_POWER_DEEPSLEEP(time_in_us)
}

@[as_macro]
pub fn light_sleep(time_in_us u64) {
	C.M5_POWER_LIGHTSLEEP(time_in_us)
}

@[as_macro]
pub fn power_off() {
	C.M5_POWER_POWEROFF()
}

@[as_macro]
pub fn reset() {
	C.M5_POWER_RESET()
}

@[as_macro]
pub fn msec(us u64) u64 {
	return (u64(us) * u64(1000))
}

@[as_macro]
pub fn sec(us u64) u64 {
	return  (u64(us) * u64(1000000))
}

@[as_macro]
pub fn min(us u64) u64 {
	return  (u64(us) * u64(60) * u64(1000000))
}

@[as_macro]
pub fn hr(us u64) u64 {
	return   (u64(us) * u64(60) * u64(60) * u64(1000000))
}



    
	