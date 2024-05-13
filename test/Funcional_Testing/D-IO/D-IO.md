# Functional Testing for Digital Inputs and Outputs module

In the next table you would be able to find listed the Functional test senarios that you can follow in order to get the Functional Testing Certification for the Digital Inputs and Outputs module.
  

| ID            | Name                                  | Scenario | Objectives | Description | Gherkin Steps | Steps    | Code Example |
| ------------- | :------:                              | :------: | :------:   | :------:    | :------:      | :------: | :------:     |
| **CP-ESD-3**  | Turn on an LED depends on ADC reading | -        | -          | -           | -             | -        | ExampleCode1 |
	  
-   ExampleCode1

```
import pin  // import the pin module
import adc  // import the adc module

__global (
    val = 0      // Create a global variable to store the analog reading
)     
pin.setup(2, pin.output)   // Set pin #2 as output
pin.setup(3, pin.output)   // Set pin #3 as output
pin.setup(4, pin.output)   // Set pin #4 as output


for {       // Infinite loop
    val = adc.read(8)     // Store the analog reading of pin #8
    if val >= 1000 {      // Condition for the analog reading
        pin.high(2)     // Output high
        pin.high(3)     // Output high
        pin.high(4)     // Output high
    }
    else if val >= 750 {
        pin.high(2)     // Output high
        pin.high(3)     // Output high
        pin.low(4)      // Output low
    }
    else if val >= 480 {
        pin.high(2)     // Output high
        pin.low(3)      // Output low
        pin.low(4)      // Output low
    }
    else {
        pin.low(2)      // Output low
        pin.low(3)      // Output low
        pin.low(4)      // Output low  
    }   
    }
```