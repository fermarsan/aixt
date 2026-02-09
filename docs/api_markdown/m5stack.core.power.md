# module m5stack.core.power


## Contents
- [auto_boot_on_load](#auto_boot_on_load)
- [battery_mode](#battery_mode)
- [can_control](#can_control)
- [charge](#charge)
- [charge_volt](#charge_volt)
- [deep_sleep](#deep_sleep)
- [hr](#hr)
- [is_charge_full](#is_charge_full)
- [is_charging](#is_charging)
- [is_reset_by_deepsleep](#is_reset_by_deepsleep)
- [is_reset_by_power_sw](#is_reset_by_power_sw)
- [is_reset_by_software](#is_reset_by_software)
- [is_reset_by_watchdog](#is_reset_by_watchdog)
- [light_sleep](#light_sleep)
- [low_power_shutdown_time](#low_power_shutdown_time)
- [min](#min)
- [msec](#msec)
- [power_boost_keep_on](#power_boost_keep_on)
- [power_boost_on_off](#power_boost_on_off)
- [power_boost_set](#power_boost_set)
- [power_btn_en](#power_btn_en)
- [power_off](#power_off)
- [power_vin](#power_vin)
- [power_wled_set](#power_wled_set)
- [read_battery_level](#read_battery_level)
- [reset](#reset)
- [sec](#sec)
- [setup](#setup)
- [vin_max_current](#vin_max_current)
- [wakeup_button](#wakeup_button)

## auto_boot_on_load
```v
fn auto_boot_on_load(en bool) bool
```

[[Return to contents]](#Contents)

## battery_mode
```v
fn battery_mode(en bool) bool
```

[[Return to contents]](#Contents)

## can_control
```v
fn can_control() bool
```

[[Return to contents]](#Contents)

## charge
```v
fn charge(en bool) bool
```

[[Return to contents]](#Contents)

## charge_volt
```v
fn charge_volt(volt u8) bool
```

[[Return to contents]](#Contents)

## deep_sleep
```v
fn deep_sleep(time_in_us u64)
```

[[Return to contents]](#Contents)

## hr
```v
fn hr(us u64) u64
```

[[Return to contents]](#Contents)

## is_charge_full
```v
fn is_charge_full() bool
```

[[Return to contents]](#Contents)

## is_charging
```v
fn is_charging() bool
```

[[Return to contents]](#Contents)

## is_reset_by_deepsleep
```v
fn is_reset_by_deepsleep() bool
```

[[Return to contents]](#Contents)

## is_reset_by_power_sw
```v
fn is_reset_by_power_sw() bool
```

[[Return to contents]](#Contents)

## is_reset_by_software
```v
fn is_reset_by_software() bool
```

[[Return to contents]](#Contents)

## is_reset_by_watchdog
```v
fn is_reset_by_watchdog() bool
```

[[Return to contents]](#Contents)

## light_sleep
```v
fn light_sleep(time_in_us u64)
```

[[Return to contents]](#Contents)

## low_power_shutdown_time
```v
fn low_power_shutdown_time(time any) bool
```

[[Return to contents]](#Contents)

## min
```v
fn min(us u64) u64
```

[[Return to contents]](#Contents)

## msec
```v
fn msec(us u64) u64
```

[[Return to contents]](#Contents)

## power_boost_keep_on
```v
fn power_boost_keep_on(en bool) bool
```

[[Return to contents]](#Contents)

## power_boost_on_off
```v
fn power_boost_on_off(en bool) bool
```

[[Return to contents]](#Contents)

## power_boost_set
```v
fn power_boost_set(en bool) bool
```

[[Return to contents]](#Contents)

## power_btn_en
```v
fn power_btn_en(en bool) bool
```

[[Return to contents]](#Contents)

## power_off
```v
fn power_off()
```

[[Return to contents]](#Contents)

## power_vin
```v
fn power_vin(en bool) bool
```

[[Return to contents]](#Contents)

## power_wled_set
```v
fn power_wled_set(en bool) bool
```

[[Return to contents]](#Contents)

## read_battery_level
```v
fn read_battery_level() i8
```

[[Return to contents]](#Contents)

## reset
```v
fn reset()
```

[[Return to contents]](#Contents)

## sec
```v
fn sec(us u64) u64
```

[[Return to contents]](#Contents)

## setup
```v
fn setup()
```

init initializes the power module

[[Return to contents]](#Contents)

## vin_max_current
```v
fn vin_max_current(cur u8) bool
```

[[Return to contents]](#Contents)

## wakeup_button
```v
fn wakeup_button(button u8)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
