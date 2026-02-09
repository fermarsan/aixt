# module cypress.cy8ckit_049_42xx.pwm


## Contents
- [Constants](#Constants)
- [write](#write)

## Constants
```v
const ch0 = 17
```

[[Return to contents]](#Contents)

```v
const ch1 = 15
```

[[Return to contents]](#Contents)

```v
const ch2 = 16
```

[[Return to contents]](#Contents)

## write
```v
fn write(channel int, val any)
```

@[as_macro] pub fn write(channel any, val any) { C.PWM_WRITE(channel, val) }

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
