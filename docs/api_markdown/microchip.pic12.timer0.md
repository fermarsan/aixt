# module microchip.pic12.timer0


## Contents
- [irq_disable](#irq_disable)
- [irq_enable](#irq_enable)
- [read](#read)
- [restart](#restart)
- [setup](#setup)

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

irq_enable function enables the Timer0 overflow interrupt

[[Return to contents]](#Contents)

## read
```v
fn read() u8
```

read function reads the current value of Timer0

[[Return to contents]](#Contents)

## restart
```v
fn restart()
```

restart function re-start the Timer0 with the predefined starting value

[[Return to contents]](#Contents)

## setup
```v
fn setup(period u32)
```

setup configures the period of the Timer0 in microseconds| fosc [Mhz] | max period |
|------------|------------|
| 4          | 65536      |
| 8          | 32768      |
| 10         | 26214      |
| 12         | 21845      |
| 16         | 16384      |
| 20         | 13107      |


[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
