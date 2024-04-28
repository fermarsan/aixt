# Smoke Testing for Serial Communication module

In the next table you would be able to find listed the Smoke test senarios that you can follow in order to get the Smoke Testing Certification for the Serial Communication module.
  

| ID            | Name                                            | Scenario | Objectives | Description | Gherkin Steps | Steps    | Code Example |
| ------------- | :------:                                        | :------: | :------:   | :------:    | :------:      | :------: | :------:     |
| **CP-SC-1**   | prender y apagar un puerto del microcontrolador | -        | -          | -           | -             | -        | ExampleCode1 |
| **CP-SC-2**   | Enviar caracter y visualizarlo en mensaje       | -        | -          | -           | -             | -        | ExampleCode2 |


-   ExampleCode1
```
port.setup(b, ob00000000)      // Función para configurar el puerto como salida 

for {
        
    port.write(a,0b010101);
    sleep_ms(500);
    port.write(a,0b101010);
    sleep_ms(500);      
        
}
```
-   ExampleCode2
```
uart.setup()     // Inicializa la comunicación serial


for {
            
    uart.write(0x33);
	sleep_ms(500);
	uart.write(0x99);
	sleep_ms(500);
    
}
```