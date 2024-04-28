# Functional Testing for Serial Communication module

In the next table you would be able to find listed the Functional test senarios that you can follow in order to get the Functional Testing Certification for the Serial Communication module.
  

| ID            | Name                          | Scenario | Objectives | Description                                                                                    | Gherkin Steps | Steps    | Code Example |
| ------------- | :------:                      | :------: | :------:   | :------:                                                                                       | :------:      | :------: | :------:     |
| **CP-SC-3**   | Serial Port print and reading | -        | -          | Output high/low interaction and Serial Port print depends on conditions reading on Serial Port | -             | -        | ExampleCode1 |
	  
-   ExampleCode1

```
import pin      // import the pin module
import uart     // import the uart module
 
 __global (
    num = 0    // Create a global variable to store the number of bytes to read from the serial port
    lec = 0    // Create a global variable to store the reading from the serial port
 )

 pin.setup(3, pin.output)      // Set pin #3 as output
 uart.setup(9600)           // Set the baud rate to 9600

for {
    num = uart.any()      // Store the number of bytes to read from the serial port
    if  num > 0  {          // Condition if the number of bytes to read is greater than 0
        lec = uart.read()   // Store the reading from the serial port
        if lec == `1` {     // Condition when the reading is 1

            pin.high(3)     // Output high
            uart.println('Led on')   // Message on the serial port

        }

        else if lec == `2` {    // Condition when the reading is 2

            pin.low(3)      // Output low
            uart.println('Led off')     // Message on the serial port

        }
    }
}
```