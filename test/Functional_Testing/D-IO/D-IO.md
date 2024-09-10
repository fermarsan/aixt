# Functional Testing for Digital Inputs and Outputs Module

The table below lists the Functional test scenarios for the Digital Inputs and Outputs module. Follow these to complete the Functional Testing Certification for this module.
  
| ID            | Name                                  | Scenario                                       | Objectives                                                                                                                                                                                                                                                 | Description                                                                                           | Gherkin Steps                                                                                                                                                                                                                                                                                           | Steps                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               | Expected results                                                                                                                                                                                                                                                                                                                                                                                                                 | Code Example |
| ------------- | :------:                              | :------:                                       | :------:                                                                                                                                                                                                                                                   | :------:                                                                                              | :------:                                                                                                                                                                                                                                                                                                | :------:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | :------:                                                                                                                                                                                                                                                                                                                                                                                                                         | :------:     |
| **CP-ESD-3**  | Turn on an LED depends on ADC reading | Activating LEDs based on analog sensor reading | 1.Validate the functionality of analog sensor reading using the ADC module. <br>2.Confirm the proper control of multiple LEDs based on different analog voltage thresholds.<br>3.Ensure that LEDs are turned on or off based on the analog sensor reading. | This verifies the basic operation of the Pin module in controlling LEDs based on analog input values. | -**Given** I configure the pin module to set up multiple LEDs as output pins <br>-**And** I configure the ADC module to read analog input from a pin <br>-**When** I continuously read the analog input from the pin <br>-**Then** I adjust the state of the LEDs based on different voltage thresholds | 1.**Setup Hardware**: Connect multiple LEDs to the microcontroller's pins, ensuring proper wiring and connections. <br>2.**Configure Pin Module**: Set up the microcontroller environment to include the necessary Pin module for LED control.<br>3.**Configure ADC Module**: Set up the microcontroller environment to include the necessary ADC module for analog sensor reading.<br>4.**Load the Code**: Copy the provided code snippet into the microcontroller's development environment or IDE.<br>5.**Compile/Upload**: Compile the code if necessary and upload it to the microcontroller. Ensure that the upload process completes without errors.<br>6.**Run the Code**: Execute the uploaded code on the microcontroller. This may involve pressing a button or issuing a command, depending on the specific development environment and hardware setup. | 1.**Observe LED Behavior**: LEDs should turn on or off based on the analog sensor reading from the pin selected.<br>2.**Verify Analog Input**: Ensure that the LED states change accurately according to the different voltage thresholds defined in the code.<br>The LEDs should respond appropriately to changes in the analog sensor reading, displaying different combinations of on/off states based on the voltage levels. | ExampleCode1 |

-   ExampleCode1

```v
import pin // import the pin module
import adc // import the adc module

pin.setup(2, output) // Set pin #2 as output
pin.setup(3, output) // Set pin #3 as output
pin.setup(4, output) // Set pin #4 as output

adc.setup()

for { // Infinite loop
	val := adc.read(8) // Store the analog reading of pin #8
	if val >= 1000 { // Condition for the analog reading
		pin.high(2) // Output high
		pin.high(3) // Output high
		pin.high(4) // Output high
	} else if val >= 750 {
		pin.high(2) // Output high
		pin.high(3) // Output high
		pin.low(4) // Output low
	} else if val >= 480 {
		pin.high(2) // Output high
		pin.low(3) // Output low
		pin.low(4) // Output low
	} else {
		pin.low(2) // Output low
		pin.low(3) // Output low
		pin.low(4) // Output low
	}
}
```