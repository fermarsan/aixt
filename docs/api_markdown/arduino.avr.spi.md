# module arduino.avr.spi


## Contents
- [Constants](#Constants)
- [as_master](#as_master)
- [as_slave](#as_slave)
- [end](#end)
- [irq_disable](#irq_disable)
- [irq_enable](#irq_enable)
- [read](#read)
- [read16](#read16)
- [rw_buffer](#rw_buffer)
- [set_bit_order](#set_bit_order)
- [set_clock_divider](#set_clock_divider)
- [set_mode](#set_mode)
- [start](#start)
- [stop](#stop)
- [transfer](#transfer)
- [transfer16](#transfer16)
- [using_irq](#using_irq)
- [write](#write)
- [write16](#write16)

## Constants
```v
const ss = u8(C.SS)
```

[[Return to contents]](#Contents)

```v
const miso = u8(C.MISO)
```

[[Return to contents]](#Contents)

```v
const mosi = u8(C.MOSI)
```

[[Return to contents]](#Contents)

```v
const sck = u8(C.SCK)
```

[[Return to contents]](#Contents)

```v
const msb_1st = u8(C.MSBFIRST)
```

[[Return to contents]](#Contents)

```v
const lsb_1st = u8(C.LSBFIRST)
```

[[Return to contents]](#Contents)

```v
const neg_rising = u8(C.SPI_MODE0)
```

[[Return to contents]](#Contents)

```v
const neg_falling = u8(C.SPI_MODE1)
```

[[Return to contents]](#Contents)

```v
const pos_falling = u8(C.SPI_MODE2)
```

[[Return to contents]](#Contents)

```v
const pos_rising = u8(C.SPI_MODE3)
```

[[Return to contents]](#Contents)

## as_master
```v
fn as_master()
```

Inicializa el bus SPI.

[[Return to contents]](#Contents)

## as_slave
```v
fn as_slave()
```

Inicializa el bus SPI.

[[Return to contents]](#Contents)

## end
```v
fn end()
```

Finaliza el bus SPI.

[[Return to contents]](#Contents)

## irq_disable
```v
fn irq_disable()
```

irq_disable disables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)

[[Return to contents]](#Contents)

## irq_enable
```v
fn irq_enable()
```

irq_enable enables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)

[[Return to contents]](#Contents)

## read
```v
fn read() u8
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

## read16
```v
fn read16() u16
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

## rw_buffer
```v
fn rw_buffer(buffer []u8, n any)
```

Read and Write a byte buffer from SPI bus.

[[Return to contents]](#Contents)

## set_bit_order
```v
fn set_bit_order(order u8)
```

configures the bit order (lsbfirst or msbfirst).

[[Return to contents]](#Contents)

## set_clock_divider
```v
fn set_clock_divider(divider u8)
```

clock_divider configures the SPI clock frequency divider.

[[Return to contents]](#Contents)

## set_mode
```v
fn set_mode(mode u8)
```

data_mode configures the SPI data mode.

[[Return to contents]](#Contents)

## start
```v
fn start(freq any, bit_order any, mode any)
```

Inicia una transacción SPI con configuraciones específicas.

[[Return to contents]](#Contents)

## stop
```v
fn stop()
```

Finaliza una transacción SPI.

[[Return to contents]](#Contents)

## transfer
```v
fn transfer(data u8) u8
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

## transfer16
```v
fn transfer16(data u16) u16
```

Transfiere 16 bits a través del bus SPI.

[[Return to contents]](#Contents)

## using_irq
```v
fn using_irq(interrupt_num u8)
```

Habilita el uso de interrupciones en el bus SPI.

[[Return to contents]](#Contents)

## write
```v
fn write(data u8)
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

## write16
```v
fn write16(data u16)
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:30
