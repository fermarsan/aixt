# module emulator.pin_fn


## Contents
- [Constants](#Constants)
- [high](#high)
- [low](#low)
- [read](#read)
- [toggle](#toggle)
- [update](#update)
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

## high
```v
fn high(pin_id int)
```

high function puts a high value (logic 1) to a specific pin

[[Return to contents]](#Contents)

## low
```v
fn low(pin_id int)
```

low function puts a low value (logic 0) to a specific pin

[[Return to contents]](#Contents)

## read
```v
fn read(pin_id int) int
```

read puts a logic value to a specific pin

[[Return to contents]](#Contents)

## toggle
```v
fn toggle(pin_id int)
```

toggle function toggles the logic value of a specific pin

[[Return to contents]](#Contents)

## update
```v
fn update()
```

update function prints the pins table in the command line

[[Return to contents]](#Contents)

## write
```v
fn write(pin_id int, val int)
```

write puts a logic value to a specific pin

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
