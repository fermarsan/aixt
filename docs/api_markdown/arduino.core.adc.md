# module arduino.core.adc


## Contents
- [ADC.new](#ADC.new)
- [ADC](#ADC)
  - [read](#read)

## ADC.new
```v
fn ADC.new(id u8) ADC
```

new returns a new ADC instance

[[Return to contents]](#Contents)

## ADC
```v
struct ADC {
pub mut:
	id u8
}
```

ADC is a struct that represents an analog pin

[[Return to contents]](#Contents)

## read
```v
fn (mut a ADC) read() u16
```

read function reads the value from the specified analog pin @[as_macro]

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
