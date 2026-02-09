# module nxt.sensor


## Contents
- [Constants](#Constants)
- [as_color_full](#as_color_full)
- [as_light](#as_light)
- [as_lowspeed](#as_lowspeed)
- [as_sound](#as_sound)
- [as_temperature](#as_temperature)
- [as_touch](#as_touch)
- [as_ultrasonic](#as_ultrasonic)
- [clear](#clear)
- [read](#read)
- [read_bool](#read_bool)
- [read_temperature](#read_temperature)
- [read_us](#read_us)
- [read_us_now](#read_us_now)
- [read_us_wait](#read_us_wait)
- [reset](#reset)
- [set_type](#set_type)
- [setup](#setup)
- [setup_temperature](#setup_temperature)
- [write_mode](#write_mode)

## Constants
```v
const s1 = 0
```

[[Return to contents]](#Contents)

```v
const s2 = 1
```

[[Return to contents]](#Contents)

```v
const s3 = 2
```

[[Return to contents]](#Contents)

```v
const s4 = 3
```

[[Return to contents]](#Contents)

```v
const touch = C.SENSOR_TOUCH
```

Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call.

[[Return to contents]](#Contents)

```v
const light = C.SENSOR_LIGHT
```

[[Return to contents]](#Contents)

```v
const rotation = C.SENSOR_ROTATION
```

[[Return to contents]](#Contents)

```v
const celsius = C.SENSOR_CELSIUS
```

[[Return to contents]](#Contents)

```v
const fahrenheit = C.SENSOR_FAHRENHEIT
```

[[Return to contents]](#Contents)

```v
const pulse = C.SENSOR_PULSE
```

[[Return to contents]](#Contents)

```v
const edge = C.SENSOR_EDGE
```

[[Return to contents]](#Contents)

```v
const nxt_light = C.SENSOR_NXTLIGHT
```

[[Return to contents]](#Contents)

```v
const sound = C.SENSOR_SOUND
```

[[Return to contents]](#Contents)

```v
const lows_peed_9v = C.SENSOR_LOWSPEED_9V
```

[[Return to contents]](#Contents)

```v
const lows_peed = C.SENSOR_LOWSPEED
```

[[Return to contents]](#Contents)

```v
const color_full = C.SENSOR_COLORFULL
```

[[Return to contents]](#Contents)

```v
const color_red = C.SENSOR_COLORRED
```

[[Return to contents]](#Contents)

```v
const color_green = C.SENSOR_COLORGREEN
```

[[Return to contents]](#Contents)

```v
const color_blue = C.SENSOR_COLORBLUE
```

[[Return to contents]](#Contents)

```v
const color_none = C.SENSOR_COLORNONE
```

[[Return to contents]](#Contents)

```v
const mode_raw = C.IN_MODE_RAW
```

Use sensor mode constants to configure an input port for the desired sensor mode. The constants are intended for use in NBC.

[[Return to contents]](#Contents)

```v
const mode_bool = C.IN_MODE_BOOLEAN
```

[[Return to contents]](#Contents)

```v
const mode_edge = C.IN_MODE_TRANSITIONCNT
```

[[Return to contents]](#Contents)

```v
const mode_pulse = C.IN_MODE_PERIODCOUNTER
```

[[Return to contents]](#Contents)

```v
const mode_percent = C.IN_MODE_PCTFULLSCALE
```

[[Return to contents]](#Contents)

```v
const mode_celsius = C.IN_MODE_CELSIUS
```

[[Return to contents]](#Contents)

```v
const mode_fahrenheit = C.IN_MODE_FAHRENHEIT
```

[[Return to contents]](#Contents)

```v
const mode_rotation = C.IN_MODE_ANGLESTEP
```

[[Return to contents]](#Contents)

```v
const mode_slope_mask = C.IN_MODE_SLOPEMASK
```

[[Return to contents]](#Contents)

```v
const mode_mask = C.IN_MODE_MODEMASK
```

[[Return to contents]](#Contents)

```v
const mode_transition_cnt = C.IN_MODE_TRANSITIONCNT
```

[[Return to contents]](#Contents)

```v
const mode_period_counter = C.IN_MODE_PERIODCOUNTER
```

[[Return to contents]](#Contents)

```v
const mode_pct_full_scale = C.IN_MODE_PCTFULLSCALE
```

[[Return to contents]](#Contents)

```v
const mode_angle_step = C.IN_MODE_ANGLESTEP
```

[[Return to contents]](#Contents)

```v
const type_none = C.IN_TYPE_NO_SENSOR
```

Use sensor type constants to configure an input port for a specific type of sensor.

[[Return to contents]](#Contents)

```v
const type_touch = C.IN_TYPE_SWITCH
```

[[Return to contents]](#Contents)

```v
const type_temperature = C.IN_TYPE_TEMPERATURE
```

[[Return to contents]](#Contents)

```v
const type_light = C.IN_TYPE_REFLECTION
```

[[Return to contents]](#Contents)

```v
const type_rotation = C.IN_TYPE_ANGLE
```

[[Return to contents]](#Contents)

```v
const type_light_active = C.IN_TYPE_LIGHT_ACTIVE
```

[[Return to contents]](#Contents)

```v
const type_light_inactive = C.IN_TYPE_LIGHT_INACTIVE
```

[[Return to contents]](#Contents)

```v
const type_sound_db = C.IN_TYPE_SOUND_DB
```

[[Return to contents]](#Contents)

```v
const type_sound_dba = C.IN_TYPE_SOUND_DBA
```

[[Return to contents]](#Contents)

```v
const type_custom = C.IN_TYPE_CUSTOM
```

[[Return to contents]](#Contents)

```v
const type_low_speed = C.IN_TYPE_LOWSPEED
```

[[Return to contents]](#Contents)

```v
const type_low_speed_9v = C.IN_TYPE_LOWSPEED_9V
```

[[Return to contents]](#Contents)

```v
const type_high_speed = C.IN_TYPE_HISPEED
```

[[Return to contents]](#Contents)

```v
const type_color_full = C.IN_TYPE_COLORFULL
```

[[Return to contents]](#Contents)

```v
const type_color_red = C.IN_TYPE_COLORRED
```

[[Return to contents]](#Contents)

```v
const type_color_green = C.IN_TYPE_COLORGREEN
```

[[Return to contents]](#Contents)

```v
const type_color_blue = C.IN_TYPE_COLORBLUE
```

[[Return to contents]](#Contents)

```v
const type_color_none = C.IN_TYPE_COLORNONE
```

[[Return to contents]](#Contents)

```v
const type_color_exit = C.IN_TYPE_COLOREXIT
```

[[Return to contents]](#Contents)

## as_color_full
```v
fn as_color_full(args ...any)
```

[[Return to contents]](#Contents)

## as_light
```v
fn as_light(args ...any)
```

[[Return to contents]](#Contents)

## as_lowspeed
```v
fn as_lowspeed(args ...any)
```

[[Return to contents]](#Contents)

## as_sound
```v
fn as_sound(args ...any)
```

[[Return to contents]](#Contents)

## as_temperature
```v
fn as_temperature(args ...any)
```

[[Return to contents]](#Contents)

## as_touch
```v
fn as_touch(args ...any)
```

[[Return to contents]](#Contents)

## as_ultrasonic
```v
fn as_ultrasonic(args ...any)
```

[[Return to contents]](#Contents)

## clear
```v
fn clear(args ...any)
```

[[Return to contents]](#Contents)

## read
```v
fn read(args ...any) u16
```

[[Return to contents]](#Contents)

## read_bool
```v
fn read_bool(args ...any) bool
```

[[Return to contents]](#Contents)

## read_temperature
```v
fn read_temperature(args ...any) f32
```

[[Return to contents]](#Contents)

## read_us
```v
fn read_us(args ...any) u8
```

[[Return to contents]](#Contents)

## read_us_now
```v
fn read_us_now(args ...any) u8
```

[[Return to contents]](#Contents)

## read_us_wait
```v
fn read_us_wait(args ...any) u8
```

[[Return to contents]](#Contents)

## reset
```v
fn reset(args ...any)
```

[[Return to contents]](#Contents)

## set_type
```v
fn set_type(args ...any)
```

[[Return to contents]](#Contents)

## setup
```v
fn setup(args ...any)
```

[[Return to contents]](#Contents)

## setup_temperature
```v
fn setup_temperature(args ...any)
```

[[Return to contents]](#Contents)

## write_mode
```v
fn write_mode(args ...any)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
