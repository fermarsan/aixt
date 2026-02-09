# module microchip.nxt.sensor


## Contents
- [Constants](#Constants)
- [Sensor.new](#Sensor.new)
- [Sensor](#Sensor)
  - [setup](#setup)
  - [as_touch](#as_touch)
  - [as_light](#as_light)
  - [as_sound](#as_sound)
  - [as_lowspeed](#as_lowspeed)
  - [as_ultrasonic](#as_ultrasonic)
  - [as_temperature](#as_temperature)
  - [as_color_full](#as_color_full)
  - [read](#read)
  - [read_bool](#read_bool)
  - [read_us](#read_us)
  - [read_us_now](#read_us_now)
  - [read_us_wait](#read_us_wait)
  - [setup_temperature](#setup_temperature)
  - [read_temperature](#read_temperature)
  - [set_type](#set_type)
  - [write_mode](#write_mode)
  - [clear](#clear)
  - [reset](#reset)

## Constants
```v
const s1 = u8(0)
```

[[Return to contents]](#Contents)

```v
const s2 = u8(1)
```

[[Return to contents]](#Contents)

```v
const s3 = u8(2)
```

[[Return to contents]](#Contents)

```v
const s4 = u8(3)
```

[[Return to contents]](#Contents)

```v
const touch = u16(C.SENSOR_TOUCH)
```

Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call.

[[Return to contents]](#Contents)

```v
const light = u16(C.SENSOR_LIGHT)
```

[[Return to contents]](#Contents)

```v
const rotation = u16(C.SENSOR_ROTATION)
```

[[Return to contents]](#Contents)

```v
const celsius = u16(C.SENSOR_CELSIUS)
```

[[Return to contents]](#Contents)

```v
const fahrenheit = u16(C.SENSOR_FAHRENHEIT)
```

[[Return to contents]](#Contents)

```v
const pulse = u16(C.SENSOR_PULSE)
```

[[Return to contents]](#Contents)

```v
const edge = u16(C.SENSOR_EDGE)
```

[[Return to contents]](#Contents)

```v
const nxt_light = u16(C.SENSOR_NXTLIGHT)
```

[[Return to contents]](#Contents)

```v
const sound = u16(C.SENSOR_SOUND)
```

[[Return to contents]](#Contents)

```v
const lows_peed_9v = u16(C.SENSOR_LOWSPEED_9V)
```

[[Return to contents]](#Contents)

```v
const lows_peed = u16(C.SENSOR_LOWSPEED)
```

[[Return to contents]](#Contents)

```v
const color_full = u16(C.SENSOR_COLORFULL)
```

[[Return to contents]](#Contents)

```v
const color_red = u16(C.SENSOR_COLORRED)
```

[[Return to contents]](#Contents)

```v
const color_green = u16(C.SENSOR_COLORGREEN)
```

[[Return to contents]](#Contents)

```v
const color_blue = u16(C.SENSOR_COLORBLUE)
```

[[Return to contents]](#Contents)

```v
const color_none = u16(C.SENSOR_COLORNONE)
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

## Sensor.new
```v
fn Sensor.new(id u8) Sensor
```

new returns a new Sensor instance

[[Return to contents]](#Contents)

## Sensor
```v
struct Sensor {
mut:
	id u8
}
```

Sensor struct

[[Return to contents]](#Contents)

## setup
```v
fn (mut s Sensor) setup(config u16)
```

[[Return to contents]](#Contents)

## as_touch
```v
fn (mut s Sensor) as_touch()
```

[[Return to contents]](#Contents)

## as_light
```v
fn (mut s Sensor) as_light(b_active bool)
```

[[Return to contents]](#Contents)

## as_sound
```v
fn (mut s Sensor) as_sound(b_db_scaling bool)
```

[[Return to contents]](#Contents)

## as_lowspeed
```v
fn (mut s Sensor) as_lowspeed(b_is_powered bool)
```

[[Return to contents]](#Contents)

## as_ultrasonic
```v
fn (mut s Sensor) as_ultrasonic()
```

[[Return to contents]](#Contents)

## as_temperature
```v
fn (mut s Sensor) as_temperature()
```

[[Return to contents]](#Contents)

## as_color_full
```v
fn (mut s Sensor) as_color_full()
```

[[Return to contents]](#Contents)

## read
```v
fn (mut s Sensor) read() u16
```

[[Return to contents]](#Contents)

## read_bool
```v
fn (mut s Sensor) read_bool() bool
```

[[Return to contents]](#Contents)

## read_us
```v
fn (mut s Sensor) read_us() u8
```

[[Return to contents]](#Contents)

## read_us_now
```v
fn (mut s Sensor) read_us_now() u8
```

[[Return to contents]](#Contents)

## read_us_wait
```v
fn (mut s Sensor) read_us_wait(wait u8) u8
```

[[Return to contents]](#Contents)

## setup_temperature
```v
fn (mut s Sensor) setup_temperature(config u8)
```

[[Return to contents]](#Contents)

## read_temperature
```v
fn (mut s Sensor) read_temperature() f32
```

[[Return to contents]](#Contents)

## set_type
```v
fn (mut s Sensor) set_type(typ u8)
```

[[Return to contents]](#Contents)

## write_mode
```v
fn (mut s Sensor) write_mode(mode u8)
```

[[Return to contents]](#Contents)

## clear
```v
fn (mut s Sensor) clear()
```

[[Return to contents]](#Contents)

## reset
```v
fn (mut s Sensor) reset()
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
