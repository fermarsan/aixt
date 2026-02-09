# module emulator.pin


## Contents
- [Constants](#Constants)
- [update](#update)
- [Pin.new](#Pin.new)
- [Pin](#Pin)
  - [high](#high)
  - [low](#low)
  - [read](#read)
  - [toggle](#toggle)
  - [write](#write)

## Constants
```v
const a = 0 // pin names
```

[[Return to contents]](#Contents)

```v
const b = 1
```

[[Return to contents]](#Contents)

```v
const c = 2
```

[[Return to contents]](#Contents)

```v
const d = 3
```

[[Return to contents]](#Contents)

```v
const w = 4
```

[[Return to contents]](#Contents)

```v
const x = 5
```

[[Return to contents]](#Contents)

```v
const y = 6
```

[[Return to contents]](#Contents)

```v
const z = 7
```

[[Return to contents]](#Contents)

## update
```v
fn update()
```

pin_update prints the pins table in the command line

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
	id int
}
```

[[Return to contents]](#Contents)

## high
```v
fn (mut p Pin) high()
```

high function puts a high value (logic 1) to a specific pin

[[Return to contents]](#Contents)

## low
```v
fn (mut p Pin) low()
```

high function puts a low value (logic 0) to a specific pin

[[Return to contents]](#Contents)

## read
```v
fn (mut p Pin) read() int
```

write puts a logic value to a specific pin

[[Return to contents]](#Contents)

## toggle
```v
fn (mut p Pin) toggle()
```

toggle function toggles the logic value of a specific pin

[[Return to contents]](#Contents)

## write
```v
fn (mut p Pin) write(val int)
```

write puts a logic value to a specific pin

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
