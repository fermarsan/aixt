# Smoke Testing for Digital Inputs and Outputs module

In the next table you would be able to find listed the Smoke test senarios that you can follow in order to get the Smoke Testing Certification for the Digital Inputs and Outputs module.
  

| ID            | Name                         | Scenario                                           | Objectives                                                                                                                                                                                                                                                     | Description                                                                                                                            | Gherkin Steps                                                                                                                                                                                                                                                                           | Steps    | Code Example |
| ------------- | :------:                     | :------:                                           | :------:                                                                                                                                                                                                                                                       | :------:                                                                                                                               | :------:                                                                                                                                                                                                                                                                                | :------: | :------:     |
| **CP-ESD-1**  | Blinking LED                 | Turning an LED on and off at half-second intervals | 1. Verify the correct operation of the Time module in controlling the timing of LED blinking. <br> 2. Confirm the proper functioning of the Pin module in controlling the LED output. <br> 3. Ensure that the LED blinks at a consistent half-second interval. | This verifies the basic functionality of the time and pin modules on the microcontroller by blinking the LED at half-second intervals. | - **Given** I configure the time and pin modules on the microcontroller <br> - **When** I run a for loop code to turn on and off the pin configured within 500 ms difference <br> - **Then** The led connected to the configured pin will turn on and off with a half-second difference | -        | ExampleCode1 |
| **CP-ESD-2**  | Turn on an LED with a Button | -                                                  | -                                                                                                                                                                                                                                                              | -                                                                                                                                      | -                                                                                                                                                                                                                                                                                       | -        | ExampleCode2 |

-   ExampleCode1
```
import time
import pin

for {
	pin.high(led10)
	time.sleep_ms(500)
	pin.low(led10)
	time.sleep_ms(500)
}
```
-   ExampleCode2
```
import pin  // Import the pin module

__global (
    reading = 0      // Create a global variable to store digital reading
)    

pin.setup(3, pin.input)     // Set pin #3 as input
pin.setup(5, pin.output)       // Set pin #5 as output

for{        // Infinite loop
    reading=pin.read(3)     // Store digital reading of pin #3
    if reading==1{         // Condition if reading value is 1 (High)
        pin.high(5);        // Output high
    }
    pin.low(5)              // Output low 
}
```