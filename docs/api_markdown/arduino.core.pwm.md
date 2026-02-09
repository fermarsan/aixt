# module arduino.core.pwm


## Contents
- [PWM.new](#PWM.new)
- [PWM](#PWM)
  - [write](#write)
  - [setup_pin](#setup_pin)

## PWM.new
```v
fn PWM.new(id u8) PWM
```

new returns a new PWM instance

[[Return to contents]](#Contents)

## PWM
```v
struct PWM {
pub mut:
	id u8
}
```

PWM is a struct that represents an PWM pin

[[Return to contents]](#Contents)

## write
```v
fn (mut p PWM) write(value u8)
```

Writes an analog value (PWM wave) to a pin

[[Return to contents]](#Contents)

## setup_pin
```v
fn (mut p PWM) setup_pin()
```

setup_pin function configures as output a PWM pin

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
