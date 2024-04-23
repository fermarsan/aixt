# Escenarios de prueba para la funcionalidad de conversor AC/DC 

## Lectura de datos:
-**ID:** CP-ADC-01

-**Feature:** Lectura de Datos

-**Scenario:** Lectura exitosa de datos desde un sensor digital

-**Gherkin:** *Given* que el sensor digital está correctamente conectado al sistema de lectura
*And* el sistema de lectura está operativo
*When* se inicia la lectura de datos desde el sensor
*Then* se espera que los datos sean leídos con precisión
*And* se registren correctamente en el sistema de procesamiento

**Descripción:**Estos pasos establecen un escenario de prueba claro y conciso para verificar la lectura exitosa de datos desde un sensor digital, asegurando que la lectura se realice con precisión y que los datos sean procesados adecuadamente en el sistema designado.

**Pasos:**
Lectura de los diferentes convertidores analógico-digitales (ADC)
1. Ejecutar la función adc1_read() y adc2_read().
2. Comparar el valor devuelto con el valor esperado (en este caso, 23 y 56).

### ADC
```v
val1, val2 := 0, 0
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
```
terminal output:
```
Aixt virtual ADC input     ADC 1 : 23
```
```
Aixt virtual ADC input     ADC 2 : 56
```

## Prueba de Lectura de Valores Simultáneos:

-**ID:** CP-ADC-02

-**Feature:** Lectura de Valores Simultáneos de ADC.

-**Scenario:** Lectura de Valores Simultáneos

-**Gherkin:** *Given* que se inicia la lectura de ADC 1 y ADC 2
    *When* se realiza la lectura simultánea de ambos ADC
    *Then* se verifica que los valores leídos de ADC 1 y ADC 2 son correctos

**Descripción:** Comprobar si es posible leer valores de ambos ADC simultáneamente y sin interferencias.

**Pasos:**
1. Ejecutar las lecturas de ADC 1 y ADC 2 de forma concurrente.
2. Verificar que los valores leídos no se vean afectados por la lectura simultánea.


Tabla de Pruebas Exhaustivas:

||Prueba de Lectura de ADC 1|| Prueba de Lectura de ADC 2|| Prueba de Lectura de Valores Simultáneos ||
||:-----------------------:||:------------------------:||:----------------------------------------:||
||0||0||0||
||0||1||0||
||1||0||0||
||1||1||1||
## Transmisión de datos:


## Salida de Voltaje DC:



