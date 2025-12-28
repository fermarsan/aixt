# module pin_fast


## Contents
- [high](#high)
- [low](#low)
- [read](#read)
- [setup](#setup)
- [toggle](#toggle)
- [write](#write)

## high
```v
fn high(port_id int, pin_id int)
```

high function puts a logic `1` to a pin faster than the regular high function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`.

[[Return to contents]](#Contents)

## low
```v
fn low(port_id int, pin_id int)
```

low function puts a logic `0` to a pin faster than the regular low function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`v.

[[Return to contents]](#Contents)

## read
```v
fn read(port_id int, pin_id int) u8
```

read reads the logic `value` of a pin faster than the regular read function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`

[[Return to contents]](#Contents)

## setup
```v
fn setup(port_id int, pin_id int, mode u8)
```

setup configures the mode of a pin faster than the regular setup function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`

[[Return to contents]](#Contents)

## toggle
```v
fn toggle(port_id int, pin_id int)
```

toggle toggles the logic `value` of a pin faster than the regular toggle function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`

[[Return to contents]](#Contents)

## write
```v
fn write(port_id int, pin_id int, value u8)
```

write writes a logic `value` to a pin faster than the regular write function. `port_id` is the port id, for example `pin_fast.port_a` and `pin_id` is the pin id, for example `pin_fast.b3`

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 28 Dec 2025 15:05:31
