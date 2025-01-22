// Project name: Light and deep sleep example
// Author: Fernando M. Santa
// Date: 22/01/2025
// M5Stack FIRE IoT development kit

import lcd 
import button
import power
import time



power.setup()	// Init Power module
power.wakeup_button(BUTTON_A_PIN)  // Set the screen wake-up button A
lcd.brightness(200)  // Set the screen brightness to 200 nits.
lcd.text_size(2)  // Set the text size to 2.

for {
    update()  // Read the press state of the key.  A, B, C 
    c := power.is_resetby_power_sw()  // Determine if M5Core is started when powered on.
    d := power.is_resetby_deepsleep()  // Determine if M5Core starts after deep sleep.

    lcd.println('<Sleep test>')  // The screen prints the formatted string and wraps the line.
    lcd.printf('power-on triggered at:%s%s\n\n', (c) ? ('POWER-SW') : (''),
                  (d) ? ('DeepSleep-end') : (''))

    lcd.printf('Go lightSleep (5s or press buttonA wake up)\n')
    time.sleep(5)  // delay 5000ms.
    /*Restart after 10 seconds of light sleep and continue from the next line
    Calling this function power button will disable the power button to restore
    Please call power.set_power_boost_keep_on(false)*/

    power.light_sleep(SLEEP_SEC(10))
    lcd.printf('Go lightSleep (press buttonA wake up)\n')
    time.sleep(5)
    power.light_sleep(0)

    lcd.printf('resume.\n\nGo deepSleep (press buttonA wake up) ')
    time.sleep(5)
    /*After waking up from deep sleep for 0 seconds, the CPU will restart and
    the program will be executed from the beginning
    Calling this function will disable the power button to restore the power
    button Please call power.set_power_boost_keep_on(false)*/

    power.deep_sleep(0)
}