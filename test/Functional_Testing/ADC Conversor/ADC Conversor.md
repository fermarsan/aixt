# Functional Testing for ADC Module

The table below lists the Functional test scenarios for the ADC module. Follow these to complete the Functional Testing Certification for this module.

| ID            | Name                                  | Scenario 					    				| Objectives    																							    																	     | Description 																																																                                                                   												| Gherkin Steps 																																																                         | Steps    																																																																																																																																																																																																																																																																																																																		| Expected results 																																																												  | Code Example |
| ------------- | :------:                              | :------: 							     		| :------:   																																										     | :------: 				   																																													       																										| :------:      																																																                         | :------: 																																																																																																																																																																																																																																																																																																																		| :------: 	   																																																													  | :------:     |
| **CP-ADC-2**  | Turn on an LED depends on ADC reading | Activating LEDs based on analog sensor reading| 1.Check that the system responds correctly to the value read from the ADC. <br>2.check that the values read from the ADC are stable and accurate, without large fluctuations or errors.| The code is expected to perform the conversion accurately and the output pins are expected to activate correctly according to the ADC values. The variable 'adc_result' must contain the correctly converted digital value.The output pins should reflect the expected state according to the conditions set in the code.| **Given** an analog input value. <br>**When** the conversion to digital is performed. <br>**Then** the digital value is stored in the variable 'adc_result'. And the output LEDs are activated according to the value of 'adc_result'. | 1.Test Environment Preparation:Configure the test environment with the necessary hardware for code execution, ensure that you have access to the ADC, output pins and reference values for comparisons. <br>2.Test Case Definition: Create test cases covering different ranges of ADC values for each code condition (>= 1020, >= 820, >= 620, and < 620). <br>3. Test Execution:Execute the code with the test values defined in the test case and verify that the output pins are activated correctly according to the conditions set in the code. <br>4.Verification of Results:Check that the output pins are in the expected state for each ADC value, record and analyze the results obtained during the execution of the tests. <br>5.Coverage Analysis:Evaluate the coverage of the tests performed to ensure that all possible paths in the code have been tested. <br>6.Documentation of Results:Document the results of the tests performed, including success cases and possible failures encountered and identify areas of improvement or possible adjustments to the code to optimize its performance. <br>7.Iteration and Continuous Improvement:in case of finding bugs, make corrections in the code and repeat the tests to validate the modifications made.| 1.**System Response to ADC Value**: The output LEDs should activate according to the ADC value, with all conditions met accurately.<br>2.**Verify Stability**: The values read from the ADC should be consistent and reliable, reflecting the true analog input.| ExampleCode1 |
  
-   ExampleCode1

```v
import adc
import pin

adc.setup()

pin.setup(2, output) // Set pin #2 as output
pin.setup(3, output) // Set pin #3 as output
pin.setup(4, output) // Set pin #4 as output

for {
	adc_result := adc.read(0) 	// Stores the ADC value
	if (adc_result >= 1020) {
		pin.high(c0)
		pin.high(c1)
		pin.high(c2)
	} else if (adc_result >= 820) {
		pin.high(c0)
		pin.high(c1)
		pin.low(c2)
	} else if (adc_result >= 620) {
		pin.high(c0)
		pin.low(c1)
		pin.low(c2)
	} else {
		pin.low(c0)
		pin.low(c1)
		pin.low(c2)
	}
}
```