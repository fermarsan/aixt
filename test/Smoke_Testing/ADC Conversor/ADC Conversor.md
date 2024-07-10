# Smoke Testing for ADC module

The table below lists the Smoke test scenarios for the ADC module. Follow these to complete the Smoke Testing Certification for the ADC module.
  

| ID            | Name              | Scenario                               | Objectives 															                  | Description 																																																													| Gherkin Steps 																																										            	 | Steps    																																																																																																																																																												  | Expected results   																																									| Code Example |
| ------------- | :------:          | :------:                               | :------:   																	   		  | :------:    																																																													| :------:                                                                                                                                                                                               | :------: 																																																																																																																																																										          | :------:           																																									| :------:     |
| **CP-ADC-1**  | ADC Configuration | ADC data conversion and output to ports| 1.Ensure the integrity and reliability of the information collected during pre-testing.| The test focuses on verifying that the ADC conversion is performed correctly and that the data is displayed on the output ports as expected. Repeating the read and output every 10 milliseconds allows to verify the correct operation of the system over time.| **Given** that the ADC and port modules are initialized and configured correctly. <br>**When** the ADC conversion is started. <br>**Then**, the ADC reading is stored and displayed on the output port.| Step 1: Initial configuration of the ADC and port modules. <br>Configure the ADC and ports B and C as outputs. <br>Clear ports B and C. <br>Step 2: Start ADC conversion. <br>Start ADC reading. <br>Store the value of the reading in the variable ""value"". <br>Step 3: Display the data on the output ports. <br>Write to port B the value of the lower part of ""value"". <br>Write to port C the value of the high part of ""value"". <br>Wait 10 milliseconds before repeating the process. <br>These steps describe in detail the actions to be performed in the proposed scenario, from initial setup to displaying the data on the output ports. | 1.Correct ADC Configuration. <br>2.Reliable ADC Readings. <br>3.Accurate Data Display on Output Port. <br>4.Continuous and Timely Data Acquisition. <br>5.Overall System Stability. | ExampleCode1 |


-   ExampleCode1
```v
import time
import adc
import port

adc.setup() 
port.setup(b, port.output) // CONFIGURE PORT B AS OUTPUT
port.setup(c, port.output) // CONFIGURE PORT C AS OUTPUT
port.write(b, 0x00) // CLEAN PORT B
port.write(c, 0x00) // CLEAN THE PORT C

for {
	value := adc.read(0) // Stores the ADC value
	port.write(b, value & 0xFF) // Shows the lower part data on port B
	port.write(c, (value >> 8) & 0x03) // Shows the high part data on port C
	time.sleep_ms(10)
}
```