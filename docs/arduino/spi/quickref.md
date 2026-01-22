# Quick reference for the SPI module

## SPI (Serial Peripheral Interface)
Use the `spi` module for SPI communication:

```v
import spi

spi.begin()                   // Initialize SPI bus
data := spi.transfer(0x55)    // Send and receive data
spi.end()                     // Close SPI bus
```

### Basic Functions
name                              | description
----------------------------------|----------------------------------------------------------
`spi.begin()`                     | Initialize the SPI bus
`spi.end()`                       | Close the SPI bus
`spi.transfer(data)`              | Transfer `data` byte (send and receive simultaneously)

### Configuration Functions
name                              | description
----------------------------------|----------------------------------------------------------
`spi.set_bit_order(order)`        | Set bit order (LSBFIRST or MSBFIRST)
`spi.set_data_mode(mode)`         | Set data mode (SPI_MODE0, SPI_MODE1, SPI_MODE2, SPI_MODE3)
`spi.set_clock_divider(divider)`  | Set clock frequency divider

### Transaction Functions
name                              | description
----------------------------------|----------------------------------------------------------
`spi.begin_transaction(settings)` | Start SPI transaction with specific settings
`spi.end_transaction()`           | End SPI transaction

### Interrupt Functions
name                              | description
----------------------------------|----------------------------------------------------------
`spi.using_interrupt(interrupt)`  | Enable interrupt usage on SPI bus
`spi.not_using_interrupt(interrupt)` | Disable interrupt usage on SPI bus

### SPI Modes
Mode      | Clock Polarity | Clock Phase | Description
----------|----------------|-------------|--------------------------------------------
MODE0     | 0              | 0           | Data sampled on rising edge, shifted on falling
MODE1     | 0              | 1           | Data sampled on falling edge, shifted on rising
MODE2     | 1              | 0           | Data sampled on falling edge, shifted on rising
MODE3     | 1              | 1           | Data sampled on rising edge, shifted on falling

### Example - Basic SPI Communication
```v
import spi

spi.begin()                       // Initialize SPI
spi.set_bit_order(MSBFIRST)       // MSB first
spi.set_data_mode(SPI_MODE0)      // Mode 0
spi.set_clock_divider(SPI_CLOCK_DIV16) // Set clock divider

// Send data and receive response
response := spi.transfer(0xAA)

spi.end()                         // Close SPI
```

### Example - SPI Transaction
```v
import spi

spi.begin()                       // Initialize SPI

// Configure settings and use transaction
// Note: Use basic SPI configuration functions for simple cases
spi.set_bit_order(MSBFIRST)
spi.set_data_mode(SPI_MODE0)
spi.set_clock_divider(SPI_CLOCK_DIV16)

data1 := spi.transfer(0x01)       // Transfer data
data2 := spi.transfer(0x02)       // Transfer data

spi.end()                         // Close SPI
```

### Example - Reading from SPI Device
```v
import spi
import pin

spi.begin()                       // Initialize SPI
pin.setup(pin.d10, pin.output)    // Setup CS (chip select) pin

// Select device
pin.low(pin.d10)                  // CS LOW

// Read data
spi.transfer(0x03)                // Send read command
spi.transfer(0x00)                // Send address
data := spi.transfer(0x00)        // Read data (send dummy byte)

// Deselect device
pin.high(pin.d10)                 // CS HIGH

spi.end()                         // Close SPI
```

### Example - Writing to SPI Device
```v
import spi
import pin

spi.begin()                       // Initialize SPI
pin.setup(pin.d10, pin.output)    // Setup CS (chip select) pin

// Select device
pin.low(pin.d10)                  // CS LOW

// Write data
spi.transfer(0x02)                // Send write command
spi.transfer(0x00)                // Send address
spi.transfer(0xAB)                // Send data to write

// Deselect device
pin.high(pin.d10)                 // CS HIGH

spi.end()                         // Close SPI
```

### Clock Divider Values
Divider            | Arduino Uno (16MHz) Frequency
-------------------|------------------------------
SPI_CLOCK_DIV2     | 8 MHz
SPI_CLOCK_DIV4     | 4 MHz
SPI_CLOCK_DIV8     | 2 MHz
SPI_CLOCK_DIV16    | 1 MHz
SPI_CLOCK_DIV32    | 500 kHz
SPI_CLOCK_DIV64    | 250 kHz
SPI_CLOCK_DIV128   | 125 kHz