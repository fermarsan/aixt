# module arduino.spi.spi


## Contents
- [begin](#begin)
- [begin_transaction](#begin_transaction)
- [end](#end)
- [end_transaction](#end_transaction)
- [not_using_interrupt](#not_using_interrupt)
- [print](#print)
- [set_bit_order](#set_bit_order)
- [set_clock_divider](#set_clock_divider)
- [set_data_mode](#set_data_mode)
- [transfer](#transfer)
- [using_interrupt](#using_interrupt)

## begin
```v
fn begin()
```

Inicializa el bus SPI.

[[Return to contents]](#Contents)

## begin_transaction
```v
fn begin_transaction(settings SPISettings)
```

Inicia una transacción SPI con configuraciones específicas.

[[Return to contents]](#Contents)

## end
```v
fn end()
```

Finaliza el bus SPI.

[[Return to contents]](#Contents)

## end_transaction
```v
fn end_transaction()
```

Finaliza una transacción SPI.

[[Return to contents]](#Contents)

## not_using_interrupt
```v
fn not_using_interrupt(interrupt_num u8)
```

Deshabilita el uso de interrupciones en el bus SPI.

[[Return to contents]](#Contents)

## print
```v
fn print(data string)
```

Imprime datos en el puerto serie.

[[Return to contents]](#Contents)

## set_bit_order
```v
fn set_bit_order(order u8)
```

Configura el orden de los bits (LSBFIRST o MSBFIRST).

[[Return to contents]](#Contents)

## set_clock_divider
```v
fn set_clock_divider(divider u8)
```

Configura el divisor de frecuencia del reloj SPI.

[[Return to contents]](#Contents)

## set_data_mode
```v
fn set_data_mode(mode u8)
```

Configura el modo de datos SPI.

[[Return to contents]](#Contents)

## transfer
```v
fn transfer(data u8) u8
```

Transfiere un byte de datos a través del bus SPI.

[[Return to contents]](#Contents)

## using_interrupt
```v
fn using_interrupt(interrupt_num u8)
```

Habilita el uso de interrupciones en el bus SPI.

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
