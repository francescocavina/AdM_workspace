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


### 4. ¿Cómo es el mapa de memoria de la familia? 

La memoria es toda continua y todos los periféricos se mapean en ella. Esto no es la regla para todas las arquitecturas. El hecho de poder acceder a los periféricos, configuración y dispositivos externos es algo destacable de la familia Cortex. 

Los procesadores Cortex utilizan una memoria que se dirección por 32 bits, lo que significa que se puede direccionar hasta 4GB de memoria (2^32 = 4.294.967.296 bits). Esta memoria a su vez, se divide en regiones que tienen cada una su propósito y carecterísticas:

+ **Code:** almacena el código ejecutable del programa, como instrucciones y datos de solo lectura.
+ **Data:** almacena datos modificables durante la ejecución del programa, como variables y estructura de datos. Cabe destacar que es memoria estática, es decir, se conoce qué posición de memoria y qué cantidad de memoria tendrá antes de que arranque el programa. 
+ **Stack (pila):** almacena los datos de los registros durante las llamadas a funciones y también posee datos de variables locales en las funciones. Es memoria dinámica y se gestiona en tiempo de ejecución. 
+ **Heap:** almacena datos generados en la aplicación de forma dinámica. Eso se da cuando se utilizan funciones como malloc() en C o new() en C++;
+ **Shared Memory (memoria compartida):** se utiliza para compartir datos entre diferentes componentes y procesos.
+ **Peripheral Memory (memoria de los periféricos):** donde se encuentran mapeados todos los dispositivos periféricos, como puertos de entra/salida (GPIO). 


### 5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP? 

MSP es el Stack Pointer general del programa y el PSP es el Stack Pointer que utilizan las tarea. Ambos son registros.

Recordar que el SP es un registro que guarda la dirección de memoria del stack. Apenas inicia tendrá la dirección inicial del Stack.

En modo privilegiado el SP es el MSP puede acceder a todo, en modo no privilegiado el SP es el PSP y queda acotado a lo que puede acceder.

SP se puede apuntar a MSP o PSP (que están en memoria) según un bit en un registro de control. Sólo una a la vez.  

En un sistema embebido, la posición 0 tiene el SP inicial que a su vez es el valor de MSP.


### 6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado. 

El procesador puede operar en uno de dos estados de operación: 

+ **Estado Thumb:** es el estado normal donde se ejecutan instrucciones Thumb de 16 y 32 bits.
+ **Estado Debug:** es el estado cuando el procesador para el debugging. Y es solo posible si el debugger está conectado. 

Dentro del estado Thumb, el procesador admite dos modos de operación, el **modo Thread** y el **modo Handler**:

+ El procesador ingresa al modo Thread en el reset o al volver de manejar una excepción. El código con privilegios y sin privilegios puede ejecutarse en modo Thread.
+ El procesador ingresa al modo Handler como resultado de una excepción. Todo el código tiene privilegio en el modo Handlers.

A continuación, se muestra un diagrama en bloques de los diferentes modos de operación. 

![Diagrama en bloques de los modos de ejecución.](/IMG_cuestionario/diagrama_modos.png)

Si se quiere pasar de no privilegiado a privilegiado cambiando el bit 0 en el registro de control, el microcontrolador lo va a ignorar. La forma correcta de hacerlo es pidiéndoselo con el llamado de un manejador de excepción. Ejecutando el programa en modo Thread no privilegiado, la unica forma de ponerlo en modo privilegiado o de realizar cualquier cambio que requiera modo privilegiado, es pidiendo ese servicio a un hipotético RTOS. Para esto se incova por software la interrupción SVC (Supervisor Call) y debe hacerse mediante una función en assembler. 




### 7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo.

Se refiere a una característica del conjunto de instrucciones ARM en el que todos los registros generales se pueden utilizar de la misma manera en cualquier contexto o modo de ejecución. Esto significa que los registros se pueden utilizar para almacenar datos, direcciones de memoria, punteros, resultados intermedios, entre otros, en cualquier contexto sin restricciones especiales. Algunos ejemplos son:
	
	ADD R0, R1, R2
	LDR R0, R5, #12
	PUSH {R5, R6, R7}
	MOV PC, LR

### 8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo.

La ventaja del uso de instrucciones de ejecución condicional es que se puede ejecutar códido o no dependiendo de alguna determinada condición. Esto es lo mismo que se logra utlizando secuencias como if, if/else o switch. Se realiza una operación de procesamiento de datos y se setean las banderas o se hace una comparación entre registros que setea automáticamente las banderas. Luego, dependiendo del resultado y las banderas seteadas, es posible ejecutar el código o no. Por ejemplo:

```
MOV R0, #10		@ R0 = 10;
MOV R1, #5		@ R1 = 5;
SUBS R2, R0, R1		@ R2 = R0 - R1; // Y se setean las banderas en función del resultado obtenido
ADDGE R0, R0, #1	@ if(R0 >= R1) { R0++; } // Se ejecutará esta instrucción si R0 es mayor igual a R1	

```

La condición se estable utilizando sufijos junto al nemónico de la instrucción. Estas condiciones se pueden utilizar junto a todas las instrucciones. 


### 9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

+ **Reset:** ocurre cuando se setea el pin de reinicio del procesador, cuando se invoca por software el reseteo o cuando se alimenta el procesador. Esta excepción solo se espera que ocurra para señalar el encendido o para reiniciar como si el procesador acabara de encenderse. Durante esta excepción se configura el procesador, se inicializan los periféricos y se comienza con la ejecución del programa. 

+ **NMI:** es una interrupción no enmascarable y puede ser señalada por un periférico o desencadenada por software. Está permanentemente habilitada y tiene una prioridad fija de -2. Esta excepción no puede ser enmascarada o impedida su activación por cualquier otra excepción y no puede ser anulada por otra excepción que no sea la de Reset. 

+ **Hardfault:** se produce debido a un error durante la ejecución normal del programa y tiene pioridad fija de -1. Las causas más comunes debido a erroes del usuario son: ejecución de una instrucción no definida, intento de carga o almacenamiento en una dirección no válida o ejecución de una instrucción desde una dirección de memoria. 

### 10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

El Stack es memoria dinámica que se utiliza para guardar el estado arquitectónico del microcontrolador a la hora de hacer un cambio de contexto. Eso se da por ejemplo, cuando se llama a una función. Aquí es necesario resguardar los registros que no se quiere que sean modificados por la función. Esta acción debe realizarse al inicio de cada función y esto incluye a todos los registros. 

Por defecto, los parámetros a funciones se pasan desde el registro R0 al R3 (R0, R1, R2 y R3). En el caso de querer pasar un quinto parámetro, esto se debe hacer a través del Stack. Por otra parte, los valores de retorno de la función se hacen con el registro R0. Todo esto es una convención y se lo conoce como "Procedure Call Standard" y es específico de la arquitectura ARM.

El Stack es una estructura de datos LIFO (Last In First Out) o pila, en español. Como en una pila, el nuevo dato se apila sobre el anterior y cuando se extrae un dato es el último que se agregó. Los datos se guardan aquí de a 32 bits, pero es direccionable de a byte (8 bits). 

En ARM se utiliza el registro R13 o SP (Stack Pointer) para el manejo del STACK, este registro contendrá la dirección del último dato guardado. Además por cada dato agregado, el Stack se expandirá a posiciones de memoria mas bajas. El espacio ocupado por una función dentro del Stack se denomina "Stack Frame". Y cada función puede acceder a su Stack Frame y no al de otras funciones. 

Una función recursiva mal diseñada puede aumentar rápidamente el Stack y no liberar el espacio nunca. Si se está en el modo privilegiado y se desborda el Stack (conocido como stack overflow), se va a empezar a pisar los datos contenidos en la otra memoria dinámica Heap. El Stack estaría utilizando espacio más allá de lo que le corresponde, y podría entonces corromper los datos contenidos allí. Al revez podría suceder también que el Heap pise datos del Stack (conocido como memory leak) y las funciones devuelvan valores erróneos. 

Es muy importante calcular el tamaño que se necesita para el Stack. Esto es así cuando se utilizan Sistemas Operativos de Tiempo Real y muchos fallos pueden darse por este problema. Es necesario tenerlo en cuenta, primero para que no suceda y si sucede, que la falla sea en modo seguro. Recordar que los sistemas críticos son aquellos de los cuáles dependen vidas humanas. 

Aunque se recomienda no utilizar memoria dinámica en sistemas embebidos, en las arquitecturas más nuevas ocurren una excpeción cuando se llega al límite del Stack. 

En resumen, las funciones más importantes del Stack son:

+ Pasar datos a funciones o subrutinas.
+ Guardar variables locales.
+ Salvaguardar el estado del procesador y de los registros de propósito general cuando ocurre una interrupción.
+ Guardar temporalmente el valor de registros previo a su reutilización. 


### 11. Describa la secuencia de reset del microprocesador. 

En Cortex M existen tres tipos de resets:

+ **Reseteo en encendido:** se resetea todo. Esto incluye el procesador, el componente de debugging y periféricos. 
+ **Reseteo del sistema:** se resetea solo el procesador y los periféricos.
+ **Reseteo del procesador:** se resetea solo el procesador.

Luego del reseteo y antes de que el procesador comience a ejecutar el programa, se lee las primeras dos palabras de la memoria. El principio de la memoria contiene la tabla de vectores y los dos primeros valores en esta tabla contiene el valor inicial del Stack Pointer (MSP) y el vector de reset, que sería la dirección inicial donde se ecuentra el Handler del reset. Después de leer estas dos palabras, se setea el MSP y el Program Counter (PC) con estos valores. Esto es necesario porque algunas excepciones como NMI o HardDefault podrían ocurrir justo al termina el reset.  

En conclusión, el programa no empieza en la función main(), sino en la rutina de inicialización o reset. Seguramente después de main() no haya nada, ninguna instrucción. Va a ver todo 0 en memoria, y se generará una excepción donde seguramente el programa termina. 


### 12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?




### 13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo. 

Lo primero que tiene la memoria FLASH es el vector de interrupciones y éstas se ordenan por prioridad. Aquí son más prioritarias las primeras (las que tengan el número más bajo). Hay interrupciones que poseen prioridad configurable y otras no. 

Estas prioridades sirven para determinar cuál interrupción se debería atender primera en el caso de que dos o más ocurran al mismo tiempo. 

En este vector de interrupciones no se tiene el manejador en sí, sino la dirección de memoria de la función que la atiende o maneja. 

ARM define una serie de excepciones que son las primeras 15. Siempre la primera es la de reset y la que tiene mayor prioridad. Las excepciones a partir de la 16 las define el fabricante y generalmente cambian de nombre dependiendo del fabricante. 

+ **Reset:** tiene prioridad -3 (la  más alta) y no es configurable.
+ **NMI:** tiene prioridad -2 y no es configurable.
+ **HardFault:** tiene prioridad -1 y no es configurable.
+ **MemManage, BusFault, UsageFault, SVC, PendSV, Systick:** son las que siguen y tienen prioridad configurable. 

Desde la excepción 1 a 15 (en la tabla de excepciones) se las conoce directamente como excepciones del sistema. Desde el número 16 en adelante se las considera como interrupciones. 


### 14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta? 

CMSIS es el estándar de interfaz de software de microcontroladores Cortex. Su objetivo es simplificar el desarrollo de software para los microcontroladores y porporcionar una interfaz uniforme y eficiente para los desarrolladores, especialmente si se trabaja con Cortex M y Cortex A. También promueve la reutilización, portabilidad y interoperabilidad de código, lo que permite a los desarrolladores centrarse en la lógica a nivel de aplicación en lugar de ocuparse en detalles de hardware de bajo nivel. 

CMSIS se define en estrecha colaboración con varios proveedores de software y hardware y proporciona un enfoque común para la interfaz con periféricos, sistemas operativos en tiempo real y componentes de software intermedio. Su objetivo es permitir la interoperabilidad de los componentes de software de múltiples proveedores.

Por otra parte, con el tiempo se fue agregando CMSIS-DSP, que permite funciones iguales para el procesamiento digital de señales en todos los microcontroladores ARM. La velocidad con la que se ejecutará esa función dependerá de cada microcontrolador, pero será siempre implementado de la misma manera. 

También existe CMSIS-RTOS con lo que se puede utilizar el RTOS en cualquier microcontrolador Cortex (siempre que sus capacidades lo permita) sin cambiar el código. 


### 15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo.

Las excepciones son eventos que no tienen que ver con la ejecución del programa. Tiene que ver con cambios de estado en un pin, alertas de tensión baja, etc. Estos pueden suceder en cualquier momento y en cualquier parte del programa. Y cuando suceden, alguna parte del código se tiene que encargar de manejarlo. 

Las excepciones son una generalización de las interrupciones clásicas. No todo se dá porque cambia el estado en un pin, sino a veces también hay errores de software que deben ser manejados. 

Desde que aparece la interrupción hasta que se la atienda y se vuelve a la ejecución del programa, pasa un tiempo debido a todo el proceso implicado. Este tiempo se lo conoce como latencia de la interrupción. En un Cortex M, en promedio esta latencia es de 16 ciclos de reloj, lo cuál es muy poco comparado con la velocidad que tiene el microcontrolador.

Cuando ocurre una excepción, el procesador suspende lo que esté haciendo y ejecuta una parte del programa llamada manejador de la excepción. Luego, de que la ejecución del manejador de la excepción se ha completado, se vuelve a la ejecución normal del programa. 

En el caso de las interrupciones (caso especial de las excepciones) el manejador se conoce como Interrupt Service Rutine (ISR). Estas excepciones son manejadas por el NVIC o el NMI. Cada tipo de excepción tiene asociado un número y es utilizado para determinar la dirección del vector de excepción. Estos vectores son guardados en una tabla de vectores y el procesador lee esta tabla para determinar la dirección en la cuál empieza el manejador de la excepción. 

Todo lo que se ejecute desde el vector de interrupciones se hace en  modo de operación Handler que es siempre en modo privilegiado. 

Por ejemplo, una interrupción podría darse si se asocia una interrupción a un pin GPIO de entrada que podría ser el pulsador de la placa NUCLEO. Cuando se presione el interruptor, el procesador va a llevar a cabo todo lo que se mencionó anteriormente y se terminará ejecutando el manejador de dicha interrupción. Un ejemplo de manejador podría ser el siguiente:

```
void EXTI0_IRQHandler(void) { // Rutina de interrupción para el pin GPIO

    // Manejar la interrupción aquí
    // ...
}
```

Cuando se termine de ejecutar este manejador, se volverá al contexto que se estaba ejecutando antes de atender esta exceción. 


### 17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?


### 16. Explique las características avanzadas de atención a interrupciones: tail chaining y late arrival.

"Tail chaining" se da cuando se quiere atender consecutivamente dos excepciones sin sobrecargar al micro con restaurar los contextos  entre las interrupciones. El procesador va a omitir hacer el POP y PUSH de los regsitros cuando sale de un ISR y entra en otro, porque esto no tiene efecto en el contenido del Stack. 


"Late arrival" se da cuando una interrupción llega tarde después que el procesador ya ha iniciado el procesamiento para manejar la excepción. Si la interrupción que llega tarde tiene una prioridad más alta que la que el procesador ya está atendiendo, la inserción de los datos en el Stack continuará lo mismo.


### 17. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?

El systick es un temporizador integrado en varios microcontroladores, incluidos los de la familia ARM Cortex M. Su función principal es proporcionar una interrupción periódica al procesador. Esto permite al sistema operativo o al firmware realizar tareas en intervalos de tiempo regulares. Es más que todo importante en sistemas operativos. 

Este temportizador está definido por ARM y es estándar. Por lo tanto, todos los fabricantes deben respetar su diseño para lograr mayor portabilidad.  Es un temporizador de cuenta regresiva de 24 bits con recarga automática. Es decir, cuando llegua a cero, genera una interrupción y se carga un nuevo valor de conteo desde el registro de recarga.

El objetivo principal de este temporizador es generar una interrupción periódica para un sistema operativo en tiempo real (RTOS) u otra aplicación controlada por eventos. Algunos microcontroladores M0 no tiene systick y no son una buena elección para utilizar un RTOS, porque se debería utilizar otro timer y esto puede traer problemas. 

Como es un componente estándar en la arquitectura Cortex M, se puede decir que favore la portabilidad para los RTOS. 


### 18. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?

MPU (Memory Protecion Unit) es implementada en Cortex y se utiliza para proteger a la memoria desde una dirección hasta otra dirección determinadas. Poder acceder toda la memoria es solo posible si el modo de ejecución es privilegiado. Cuando una tarea en modo no privilegiado y quiere acceder a un espacio de memoria protegido, se producirá una excepción que la deberá manejar el SO.

Por otra parte, el Heap es memoria dinámica que el programa puede utilizar (recordar la función malloc()) y se ubica apenas termina la memoria estática. En el caso de utilizar la función malloc(), por ejemplo, esta no puede utilizar toda la memoria que quiere. En un SO es necesario primero pedrile memoria, ya que esta la gestiona. En este caso la aplicación trabaja en modo no privilegiado y el SO, que gestiona los recursos del microcontrolado, trabaja en modo privilegiado. Aquí también es un caso donde se utiliza la protección de memoria. 


### 19. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?




### 20. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto de las excepciones? Dé un ejemplo.

PendSV es una excepción que tiene la prioridad más baja (aunque es configurable) y se utiliza para hacer llamadas al sistema operativo. Utilizando PendSV se puede lograr el context switching (cambio de contexto) entre tareas cuando se utiliza un Sistema Operativo de Tiempo Real. Generalmente el cambio de contexto ocurre con el systick. Como PendSV tiene prioridad baja, solo va a comenzar el cambio de contexto cuando terminen de ejecutarse otras interrupciones (si las hubiera en ese momento). Esto garantiza que el cambio de contexto no se produzca durante el systick o en el medio de una interrupción importante. 

A continuación, se presenta un ejemplo:

```
#include <stdint.h>

// Prototipo de la función de servicio de PendSV
void PendSV_Handler(void);

// Dirección del registro de control de interrupciones pendientes
#define SCB_ICSR (*((volatile uint32_t*)0xE000ED04))

int main(void) {
    // Configurar el valor de prioridad de PendSV
    uint32_t* pPendSV_Priority = (uint32_t*)0xE000ED22;
    *pPendSV_Priority = 0xFF;

    // Simular una solicitud de interrupción PendSV
    SCB_ICSR |= (1 << 28);

    // Resto del código...

    while (1) {
        // Bucle principal del programa
    }
}

// Implementación de la función de servicio de PendSV
void PendSV_Handler(void) {
    // Código de servicio de PendSV
    // Realizar tareas de baja prioridad o cambio de contexto aquí
}
```


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

+ **Bandera N (negativo):** permite evaluar si un número es negativo, tomando el estado del bit 31 del resultado.
+ **Bandera V (desborde o overflow):** permite determinar luego de una operación con signo, si el resultado sufrió desborde. Se verifica el acarreo del bit 30 y del bit 31 (ocurre desborde si no son iguales).
+ **Bandera Z (cero):** indica si la totalidad de los bits en la última operación resultaron 0. 
+ **Bandera C (acarreo o carry):** se activa cuando la suma es mayor o igual a 2^32, el resultado de una resta es positivo o por un corrimiento.
+ **Bandera Q (saturación):** se utiliza para indicar el desbordamiento en las operaciones de multiplicación y acumulación (multiply-accumulate) saturadas.		
	
Luego, es posible utilizar instrucciones condicionadas que se ejecutarán o no, dependiendo de estas banderas. Estas condiciones se colocan también como un sufijo en el nemónico. 

Ejemplo de uso de sufijo ‘S’:

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

Esta funcionalidad se podría realizar por software, pero es aconsejable utilizar la menor cantidad de condicionales posibles debido a la performance. Además, las banderas indican overflow y se podría consultar en el registro PCR todo el tiempo, pero no es aconsejable tampoco si se quiere performance. 


### 4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la pila antes de ser modificados?

Es posible escribir código Assembly junto al código en C y esto se conoce como "Assembly inline". Sin embargo, en general se utilizan archivos separados para escribir código en Assembly. Estos archivos pueen ser con extensión ".s" ó ".S". La diferencia está en que el segundo, el ensamblador pasa primero el código por el pre-procesador de C y esto permite enotnces incluir archivos header con "#include" y utlizar constantes definidas con "#define".

El código de DSP (Digital Signal Processing) se suele hacer en Assembly, ya que es mucho más eficiente. Tener en cuenta que cuando uno escribre código en Assembly, no escribe programas enteros, sino que optimiza funciones específicas. 

Ejemplos de "Assembly inline":

```
__asm volatile(“ /* assembly instruction 1 */ “);
__asm volatile(“ /* assembly instruction 2 */ “);
__asm volatile(“ /* assembly instruction 3 */ “);

__asm volatile(“ MOV R0, %0“ :: “r”(variable)); // se re-asignan los parámetros a los registros. Esto empeoraría la eficiencia.

```

Por otra pate, los "intrinsics" permiten llamar a funciones de Assembly desde el código en C. Esto es una gran ventaja, porque sepodría utilizar la función USAT (de aritmética saturada) en C. 

Por último, y como se nombró anteriormente, se utiliza la convención "Procedure Call Standard" para establecer como se pasan los parámetros a funciones y cómo estas devuelven los valores de retorno. Siguiente estos criterios, los parámteros se pasan a las funciones en los registros R0, R1, R2 y R3, y en el caso de haber más de 4 parámetros, se pasan a través del Stack. Y los valores de retorno se guardan en R0 antes de salir de la función. 

Como una función no debe afectar ningún registro o zona de memoria utilizada por el programa que llamó a la función, la función llamada deberá guardar en el Stack los registros utilizados dentro de la misma para recuperar su valor antes de retornar el programa a la función que la llamó. 

ARM divide los registros en preservados y no preservados:

+ **Preservados:** R4 a R11, SP y LR, una función debe guardar estos registros antes de ser modificados y restaurar su valor antes de salir de la función. El código que llama a una función supone que ésta no va a modificar estos registros.
+ **No Preservados:** R0 a R3 y R12 pueden ser modificados libremente, no se puede asumir que no serán modificados luego de llamar a una función. Por lo tanto, será obligación de la función llamadora (caller) resguardarlos en el Stack si no se quiere que sean modificados. 


### 5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un ejemplo.

SIMD (Single Instruction, Multiple Data) es una técnica computacional para procesar una cantidad de valores de datos (generalmente una potencia de dos) usando una sola instrucción. Por lo tanto, una instrucción SIMD puede hacer el trabajo de muchas instrucciones separadas. 

Los elementos de datos pueden tener un tamaño inferior a 32 bits. Los datos de píxeles de 8 bits son comunes en el procesamiento de video, gráficos e imágenes, las muestras de 16 bits en los códecs de audio. En tales casos, las operaciones a realizar son simples, se repiten muchas veces y requieren poco código de control. SIMD puede ofrecer mejoras de rendimiento considerables para este tipo de procesamiento de datos. 

SIMD permite que una sola instrucción trate un valor de registro como elementos de datos múltiples (por ejemplo, como cuatro valores de 8 bits en un registro de 32 bits) y realice múltiples operaciones idénticas en esos elementos.

Por ejemplo, si se tiene un registro R1 y otro R2 de 32 bits, se podría hacer la suma como:

```
ADD R0, R1, R2
```

Pero sucede muchas veces que no es necesario utilizar datos de 32 bits de largo, como se dijo anteriormente, sino que podría ser por ejemplo, de 16 bits. En este caso, cada registro almacenaría dos datos. No utilizando SIMD, se debería tener un registro para cada dato de 16 bits y hacer la siguiente operación:

```
ADD R0, R1, R2
ADD R3, R4, R5
```

Utilizando SIMD de 16 bits, la primera parte de R1 contendría un dato de 16 bits y la segunda parte otro dato de 16 bits. De la misma manera, R2 contendría un dato de 16 bits en la primera parte y otro dato de 16 bits en la segunda parte. Bajo este contexto, se podría utilizar la siguiente instrucción, danto como resultado tambień un registro de 32 bits con dos datos de 16 bits. 

```
SADD16 R0, R1, R2
```

En este caso, utilizando datos de 16 bits, la cantidad de instrucciones se divide a la mitad. En el caso de utilizar datos de 8 bits, la cantidad de instrucciones se divide en 4. Esto trae considerables mejoras en performance, si estas instrucciones se ejecutan repetidamente dentro de un búcle. 

