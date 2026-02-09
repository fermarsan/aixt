# module microchip.pic16.ext


## Contents
- [Constants](#Constants)
- [irq_disable](#irq_disable)
- [irq_enable](#irq_enable)
- [setup](#setup)

## Constants
```v
const rising = 1 // edge of the external interrut
```

[[Return to contents]](#Contents)

```v
const falling = 0
```

[[Return to contents]](#Contents)

## irq_disable
```v
fn irq_disable()
```

irq_disable function disables the external interrupt

[[Return to contents]](#Contents)

## irq_enable
```v
fn irq_enable()
```

irq_enable function enables the external interrupt

[[Return to contents]](#Contents)

## setup
```v
fn setup(edge any)
```

setup function set the falling or rising `edge` of the external interrupt. `edge` can be `ext.falling` or `ext.rising`.

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
