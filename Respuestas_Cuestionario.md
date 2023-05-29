# PREGUNTAS ORIENTADORAS

## ARM GENERAL


### 1. Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características. 

Los diferentes perfiles de familias de uC/uP de ARM son:

+ **Cortex A (Applications):** son microprocesadores optimizados para correr muchas aplicaciones a la vez y no en tiempo real. Porque importe la cantidad de procesamiento y no en 			el tiempo en que responda. Además, es posible embeberle un sistema operativo de propósito general y podría ser utilizado, por ejemplo, en un smartphone. Otra característica de este perfil es que poseen memoria Caché (memoria rápida para ganar tiempo). Como estos microprocesadores a veces utilizan la memoria RAM y otras veces la Caché, no hay determinismo y es por eso que no pueden ser utilizador para tiempo real. 

+ **Cortex R (Real Time):** son muy parecidos a los Cortex A, pero no poseen memoria Caché. Por lo tanto, son más lentos para correr aplicaciones, pero existe un determinismo en el tiempo, que lo hace ideal para utilizarlos en aplicaciones de tiempo real.

+ **Cortex M (Microcontroller):** se utilizan en la mayoría de las aplicaciones. Posee una memoria SRAM, la cuál es muy rápida y que funciona a la velocidad del micro, y entonces la información está disponible casi instantáneamente. No se utilizan en sistemas embebidos de alta performance. 



## CORTEX M


### 1. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

+ **M0:** es la arquitectura más básica de Cortex-M, diseñada para aplicaciones que requieren un procesamiento pequeño y un bajo consumo de energía.
+ **M3:** es una arquitectura más potente que la anterior que ofrece más memoria y mayor procesamiento.
+ **M4:** incluye procesamiento digital de señales y soporte para punto flotante. 


### 2. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique. 

Las instrucciones Thumb se refieren a un conjunto de instrucciones de 16 bits diseñadas para mejorar la eficiencia de código y reducir el tamaño de los programas (consumo de memoria) en comparación con las instrucciones de 32 bits tradicionales. Es por esta reazón que se dice que permiten una mayor densidad de código.

Para indicar que se desea utilizar instrucciones Thumb de 16 bits, se utiliza la directiva ".thumb" al comienzo del archivo de código de ensamblador o antes de la sección específica donde se desea utilizar el conjunto de instrucciones Thumb. A partir de ese punto, todas las instrucciones siguientes serán ensambladas como instrucciones Thumb de 16 bits.

Si se desea utilizar instrucciones ARM de 32 bits, se utiliza la directiva ".arm" para cambiar al modo ARM. A partir de ese punto, todas las instrucciones siguientes se ensamblarán como instrucciones ARM de 32 bits. A partir de ese punto, todas las instrucciones siguientes se ensamblarán como instrucciones ARM de 32 bits.

Además, en las instrucciones Thumb, las banderas se actualizan por defecto. 

### 3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

En ARM todas las operaciones se realizan entre registros (o entre registro e inmediato). Por lo tanto, en esta arquitectura se dividen las instrucciones en dos categorías principales: 		
	- Instrucciones de acceso a memoria (carga y almacenamiento entre la memoria y los registros). 
	- Instrucciones de procesamiento de datos (que solo ocurren entre los registros).
Arquitecturas RISC, como ARM, PowerPC, SPARC, RISC-V y MIPS son arquitecturas load-store.
Estas arquitecturas carecen entonces de instrucciones que permitan realizar operaciones de procesamiento de datos con datos que se encuentren en memoria. Por lo tanto, los pasos a seguir en esta situación serían por ejemplo: 
	1) Cargar el dato de memoria en un registro.
	2) Realizar la operación de procesamiento entre registros.
	3) Guardar el dato del registro resultado en memoria.


### 4. ¿Cómo es el mapa de memoria de la familia? ***


### 5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP? ***


### 6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado. ***


### 7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo.

Se refiere a una característica del conjunto de instrucciones ARM en el que todos los registros generales se pueden utilizar de la misma manera en cualquier contexto o modo de ejecución. Esto significa que los registros se pueden utilizar para almacenar datos, direcciones de memoria, punteros, resultados intermedios, entre otros, en cualquier contexto sin restricciones especiales. Algunos ejemplos son:
	
	ADD R0, R1, R2
	LDR R0, R5, #12
	PUSH {R5, R6, R7}
	MOV PC, LR

### 8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo.


### 9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).


### 10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?


### 11. Describa la secuencia de reset del microprocesador. ***


### 12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?


### 13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo. ***


### 14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta? ***


### 15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo.


### 17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?


### 16. Explique las características avanzadas de atención a interrupciones: tail chaining y late arrival.


### 17. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?


### 18. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?

MPU (Memory Protecion Unit) es implementada en Cortex y se utiliza para proteger a la memoria desde una dirección hasta otra dirección determinadas. Poder acceder toda la memoria es solo posible si el modo de ejecución es privilegiado. Cuando una tarea en modo no privilegiado quiere acceder a un espacio de memoria protegido, se producirá una excepción que la deberá manejar el SO.


### 19. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?


### 20. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto de las excepciones? Dé un ejemplo.


### 21. ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un sistema operativo embebido.

SVC es un mecanismo de excepción proporcionado por el núcleo del procesador ARM Cortex-M. La ejecución de una instrucción SVC genera una llamada de supervisor, que se utiliza para llevar a cabo operaciones privilegiadas desde dentro de un núcleo de sistema operativo.  Esto permite al código de la aplicación acceder a los recursos del procesador y controlarlos.

Normalmente, en un sistema de alta fiabilidad, la tarea de aplicación se ejecuta en un nivel sin privilegios. Algunos de los recursos de hardware están protegidos y se utiliza una unidad de protección de memoria (MPU) para proteger determinadas regiones de memoria. Si la aplicación intenta acceder directamente a estos recursos protegidos, puede producirse una violación de acceso que provoque una excepción o un fallo. En tales casos, el acceso a los recursos sólo es posible a través de los servicios proporcionados por el sistema operativo. Por lo tanto, la aplicación llama a estos servicios y el SO ejecuta código para llevar a cabo el servicio requerido. El SVC proporciona este mecanismo de servicio. El código de servicio se encuentra en el controlador de excepciones SVC, que se activa mediante la instrucción SVC.



## ISA (Instruction Set Architecture)

### 1. ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo. 

Los sufijos se utilizan junto a los nemónicos para modificar el comportamiento de las instrucciones. En ARM existen los siguientes sufijos:

+ **De condición:** se utilizan para especificar una condición bajo la cual se ejecutará la instrucción. Permite realizar ejecuciones condicionales basadas en el estado de las banderas (ver siguiente pregunta).
+ **De actualización de banderas:** se utilizan par actualizar las banderas según el resultado de una operación de procesamiento de datos (ver siguiente pregunta).
+ **De tamaño de carga/almacenamiento de datos:** se utilizan junto a las instrucciones como LDR y STR para indicar el tamaño de los datos, por ejemplo: ‘B’ indica byte, ‘H’ indica media palabra (halfword) y ‘W’ indica palabra completa (word).  


### 2. ¿Para qué se utiliza el sufijo ‘S’? Dé un ejemplo. 

En la arquitectura ARM se tienen banderas que almacenan información referida a la última operación realizada por la ALU (siempre que se haya habilitado en la instrucción). Estas banderas generalmente son 4 y se encuentran en el Current Program Status Register (CPSR). Se pueden modificar cuando se utilizan instrucciones de procesamiento de datos, agregando el sufjo ‘S’ al nemónico. Las banderas son las siguientes:
	- Bandera N (negativo): permite evaluar si un número es negativo, tomando el estado del bit 31 del resultado.
	- Bandera V (desborde o overflow): permite determinar luego de una operación con signo, si el resultado sufrió desborde. Se verifica el acarreo del bit 30 y del bit 31 (ocurre desborde si no son iguales).
	- Bandera Z (cero): indica si la totalidad de los bits en la última operación resultaron 0. 
	- Bandera C (acarreo o carry): se activa cuando la suma es mayor o igual a 2^32, el resultado de una resta es positivo o por un corrimiento.
	
Existe otra bandera en la arquitectura ARM, llamada bandera Q de Saturación. Esta permite detectar saturación en variables de 32 bits con contenido de 16 bits. 	
	
Luego, es posible tomando estas bandera y utilizar instrucciones condicionadas, que se ejecutarán o no, dependiendo de estas banderas. Estas condiciones se colocan también como un sufijo en el nemónico. 

Ejemplo de uso de sufijo ‘s’:

	MOV R1, #0x7B000000 	(R1 = 2.063.597.568)
	MOV R2, #0xF0000000	(R2 = 4.026.531.840)
	ADDS R0, R1, R2		(R0 = 6.090.129.408)
	
Con el resultado de la suma se actualizarán las banderas. El resultado será 0x16B000000, con lo que se activará la bandera de acarreo porque el número resultante excede los 32 bits. 		

### 3. ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un ejemplo con operaciones con datos de 8 bits.

La utilidad de las instrucciones de aritmética saturada se da cuando se produce overflow o underflow (en ambos casos desborde creciente o descreciente respectivamente). Esto sirve para que en estas situaciones el número almacenado no continúe desde el extremo opuesto y se mantenga dentro de los límites establecidos. De esta forma el número quedaría solo saturado en máximo o mínimo y es muy útil, por ejemplo, en DSP (Digital Signal Processing). 

Un ejemplo sería la suma de dos números enteros de 8 bits: A y B. Si se realiza la suma, el resultado podría desbordarse si el producto excede el rango permitido en números binarios de 8 bits. Al utilizar aritmética saturada, se ajusta el resultado para mantenerlo dentro del rango permitido.

```
A = 0011 0110 (binario) = +54 (decimal)

B = 0101 0110 (binario) = +86 (decimal)

A + B (sin aritmética saturada) = 1000 1100 (binario) = -116 (decimal)

A + B (con aritmética saturada) = 0111 1111 (binario) = +127 (decimal)
```

Se puede ver que en el primer caso, resultaría un número negativo de la suma de dos números positivos.
En el segundo caso, el resultado queda saturado en el máximo valor posible, ya que en números de 8 bits con signo, se tiene que:

+ Números positivos: 0 - 127
+ Números negativos: 128 - 256


### 4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la pila antes de ser modificados?


### 5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un ejemplo.


