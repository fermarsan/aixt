# module arduino.core.pin


## Contents
- [Constants](#Constants)
- [Pin.new](#Pin.new)
- [Pin](#Pin)
  - [setup](#setup)
  - [write](#write)
  - [high](#high)
  - [low](#low)
  - [read](#read)

## Constants
```v
const input = u8(C.INPUT)
```

pin modes

[[Return to contents]](#Contents)

```v
const output = u8(C.OUTPUT)
```

[[Return to contents]](#Contents)

```v
const in_pullup = u8(C.INPUT_PULLUP)
```

[[Return to contents]](#Contents)

```v
const in_pulldown = u8(C.INPUT_PULLDOWN)
```

[[Return to contents]](#Contents)

## Pin.new
```v
fn Pin.new(id u8) Pin
```

new returns a new Pin instance

[[Return to contents]](#Contents)

## Pin
```v
struct Pin {
pub mut:
	id u8
}
```

Pin is a struct that represents a digital pin

[[Return to contents]](#Contents)

## setup
```v
fn (mut p Pin) setup(mode u8)
```

setup configures a pin's input/output mode @[as_macro]

[[Return to contents]](#Contents)

## write
```v
fn (mut p Pin) write(val u8)
```

write puts a logic value to a specific pin @[as_macro]

[[Return to contents]](#Contents)

## high
```v
fn (mut p Pin) high()
```

high puts a high value (logic 1) to a specific pin @[as_macro]

[[Return to contents]](#Contents)

## low
```v
fn (mut p Pin) low()
```

low puts a low value (logic 0) to a specific pin @[as_macro]

[[Return to contents]](#Contents)

## read
```v
fn (mut p Pin) read() u8
```

read function reads the value from a specified digital pin, either HIGH or LOW @[as_macro]

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
