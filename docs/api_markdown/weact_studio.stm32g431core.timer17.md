# module weact_studio.stm32g431core.timer17


## Contents
- [Constants](#Constants)
- [compare_irq_enable](#compare_irq_enable)
- [irq_enable](#irq_enable)
- [restart](#restart)
- [setmode](#setmode)
- [setup](#setup)
- [write_percent](#write_percent)
- [write_percent_channel](#write_percent_channel)

## Constants
```v
const tick = C.TICK_FORMAT
```

[[Return to contents]](#Contents)

```v
const ms = C.MICROSEC_FORMAT
```

[[Return to contents]](#Contents)

```v
const hz = C.HERTZ_FORMAT
```

[[Return to contents]](#Contents)

```v
const pwm1 = C.TIMER_OUTPUT_COMPARE_PWM1
```

[[Return to contents]](#Contents)

```v
const compare_ch1 = 1
```

[[Return to contents]](#Contents)

```v
const compare_ch2 = 2
```

[[Return to contents]](#Contents)

```v
const compare_ch3 = 3
```

[[Return to contents]](#Contents)

## compare_irq_enable
```v
fn compare_irq_enable(ch int)
```

[[Return to contents]](#Contents)

## irq_enable
```v
fn irq_enable()
```

[[Return to contents]](#Contents)

## restart
```v
fn restart()
```

[[Return to contents]](#Contents)

## setmode
```v
fn setmode(channel int, mode int, pin int)
```

[[Return to contents]](#Contents)

## setup
```v
fn setup(value f32, format int)
```

[[Return to contents]](#Contents)

## write_percent
```v
fn write_percent(val int)
```

[[Return to contents]](#Contents)

## write_percent_channel
```v
fn write_percent_channel(channel int, val int)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
