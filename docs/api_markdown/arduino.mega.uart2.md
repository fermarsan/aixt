# module arduino.mega.uart2


## Contents
- [any](#any)
- [print](#print)
- [println](#println)
- [read](#read)
- [ready](#ready)
- [setup](#setup)

## any
```v
fn any() int
```

any function gets the number of bytes (characters) available for reading from the serial port

[[Return to contents]](#Contents)

## print
```v
fn print(message string)
```

print function prints data to the serial port as human-readable ASCII text

[[Return to contents]](#Contents)

## println
```v
fn println(message string)
```

println function prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')

[[Return to contents]](#Contents)

## read
```v
fn read() u8
```

read function reads incoming serial data

[[Return to contents]](#Contents)

## ready
```v
fn ready() u8
```

read function reads incoming serial data

[[Return to contents]](#Contents)

## setup
```v
fn setup(baud_rate int)
```

setup function sets the data rate in bits per second (baud) for serial data transmission

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:30
