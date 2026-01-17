# Quick reference for the I2C module

## I2C (Inter-Integrated Circuit)
Use the `i2c` module for I2C communication:

```v
import i2c

i2c.as_master()           // Initialize I2C as master
i2c.start(0x50)           // Start transmission to device address 0x50
i2c.write(0x10)           // Write data byte
i2c.stop()                // End transmission
```

### Master Mode Functions
name                             | description
---------------------------------|----------------------------------------------------------
`i2c.as_master()`                | Initialize the I2C bus as master
`i2c.start(address)`             | Begin transmission to device at `address`
`i2c.write(data)`                | Write `data` byte to I2C bus
`i2c.stop()`                     | End transmission
`i2c.request_from(address, qty)` | Request `qty` bytes from device at `address`
`i2c.read()`                     | Read one byte from I2C bus
`i2c.any()`                      | Return number of bytes available for reading
`i2c.set_clock(clock_speed)`     | Set I2C clock frequency (Hz)
`i2c.end()`                      | Close the I2C bus

### Slave Mode Functions
name                            | description
--------------------------------|----------------------------------------------------------
`i2c.as_slave(address)`         | Initialize the I2C bus as slave with `address`
`i2c.receive_event(handler)`    | Register `handler` function for receive events
`i2c.request_event(handler)`    | Register `handler` function for request events

### Timeout Functions
name                           | description
-------------------------------|----------------------------------------------------------
`i2c.set_timeout(timeout)`     | Set timeout for I2C transmissions
`i2c.timeout_flag()`           | Check if timeout has occurred (returns bool)
`i2c.clear_timeout_flag()`     | Clear the timeout flag

### Example - Master Writing to Slave
```v
import i2c

i2c.as_master()               // Initialize as master
i2c.set_clock(100000)         // Set 100kHz clock
i2c.start(0x50)               // Start transmission to address 0x50
i2c.write(0x00)               // Write register address
i2c.write(0xAA)               // Write data
i2c.stop()                    // End transmission
```

### Example - Master Reading from Slave
```v
import i2c

i2c.as_master()               // Initialize as master
i2c.request_from(0x50, 2)     // Request 2 bytes from address 0x50

if i2c.any() {                // Check if data is available
    byte1 := i2c.read()       // Read first byte
    byte2 := i2c.read()       // Read second byte
}
```

### Example - Slave Mode
```v
import i2c

fn on_receive(num_bytes int) {
    // Handle received data
    for _ in 0..num_bytes {
        data := i2c.read()
        // Process data
    }
}

fn on_request() {
    // Send data when requested
    i2c.write(0x55)
}

i2c.as_slave(0x08)            // Initialize as slave with address 0x08
i2c.receive_event(on_receive) // Register receive handler
i2c.request_event(on_request) // Register request handler
```