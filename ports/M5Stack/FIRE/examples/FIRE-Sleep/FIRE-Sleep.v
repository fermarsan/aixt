// Project name: Light and deep sleep example
// Author: Fernando M. Santa
// Date: 22/01/2025
// M5Stack FIRE IoT development kit

import lcd 
import button
import power
import time



power.setup()	// Init Power module
power.wakeup_button(button.a_pin)  // Set the screen wake-up button A
lcd.brightness(200)  // Set the screen brightness to 200 nits.
lcd.text_size(2)  // Set the text size to 2.

for {
    update()  // Read the press state of the key.  A, B, C 
    power_sw := if power.is_reset_by_power_sw() { 'POWER-SW' } else { '' }   // started when powered on.
    deepsleep_end := if power.is_reset_by_deepsleep() { 'DeepSleep-end' } else { '' }    // starts after deep sleep.

    lcd.println('<Sleep test>')  // prints the formatted string and wraps the line.
    lcd.println('power-on triggered at:${power_sw}${deepsleep_end}\n')

    lcd.println('Go lightSleep (5s or press buttonA wake up)')
    time.sleep(5)  // delay 5000ms.
    /*Restart after 10 seconds of light sleep and continue from the next line
    Calling this function power button will disable the power button to restore
    Please call power.set_power_boost_keep_on(false)*/

    power.light_sleep(power.sec(10))
    lcd.println('Go lightSleep (press buttonA wake up)')
    time.sleep(5)
    power.light_sleep(0)

    lcd.println('resume.\n\nGo deepSleep (press buttonA wake up) ')
    time.sleep(5)
    /*After waking up from deep sleep for 0 seconds, the CPU will restart and
    the program will be executed from the beginning
    Calling this function will disable the power button to restore the power
    button Please call power.set_power_boost_keep_on(false)*/

    power.deep_sleep(0)
}