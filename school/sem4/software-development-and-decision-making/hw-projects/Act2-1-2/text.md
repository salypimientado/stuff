Resumen SWEBOK Cap. 1-4
==================================
#### Autor: Juan Pablo Salazar Garcia
#### Clase: Construccion de Software y Toma de Decisiones
Capitulo 1: Software Requirements
---------------------------------

### Fundamentales de requerimientos de software

El diseño de requerimientos es una area de conocimiento que se enfoca  
principalmente en los requerimientos que un proyecto tiene, haciendo desde el  
analisis de requerimientos con el cliente hasta el manejo de los requerimientos  
en la mitad del proyecto. 

El diseño de requerimientos de software es una de las partes mas criticas del  
ciclo de vida de un proyecto, y si es mal realizada puede ser la causa principal  
de problemas y es una de las razones principales por las que los proyectos de  
software fallan.

Si no se hace bien el planteamiento de requerimientos se pueden causar problemas  
considerables al necesitar agregar requerimientos o sistemas aparte de los  
planeados originalmente.  
Usualmente es un trabajo realizado por ingenieros de software, y no por  
personal no relacionado. Esto no es necesariamente algo que se realiza una vez  
por proyecto al inicio de este, ya que esto limitaria el proyecto al modelo de  
cascada, y no es asi.

Un requerimiento como tal es algo que se requiere para solucionar  
un problema de algun tipo. 

+ Complejidad en problema = complejidad en requerimientos
+ Todos los requerimientos son individualmente funcionales o no funcionales
+ Se debe asegurar que los requerimientos entren en el presupuesto
+ Prioridad de requerimientos

+ Requerimiento de producto vs de proceso
+ Los requerimientos de software pueden implicar de proceso
+ Los de proceso pueden ser impuestos por organizaciones, cliente etc
+ Requerimiento funcional - funcion a realizar por parte del software
+ Requerimiento no funcional - requerimiento que no cumple una funcion, son mas  
	que nada por calidad y decisiones extras e.g. el menu debe ser verde
+ Propiedades emergentes tienen varios sistemas que forman parte de estos
- Dependen de la arquitectura del sistema increiblemente
+ Requisitos deberian ser cuantificables, no poco especificos
+ Sistema = combinacion de todo para cumplir un objetivo

### Proceso de requerimientos

No es una actividad singular al inicio del proyecto, realmente es un proceso
que inicia al empezar el proyecto y se va refinando a lo largo de este

+ Se debe adaptar a la organizacion y al proyecto debido
+ El como las actividades que forman parte del proceso de requerimientos se
	configuran de manera distinta para proyectos y situaciones diferentes
+ Roles de personas que forman parte del proceso:
    - Usuarios
    - Clientes
    - Analistas del mercado (en caso que no sea un cliente especifico)
    - Organismos regulatorios (gobierno, etc.)
    - Ingenieros de software
+ No es necesario cumplir las necesidades de todo el mundo, pero se debe hacer  
lo posible para que se haga lo mejor que se puede

### Elicitacion/obtencion de requerimientos

 Fase donde se observa y recolectan requerimientos por parte de los
stakeholders

+ Se identifican los stakeholders y la relacion entre los devs y clientes es  
establecida
+ Se debe definir el alcance del proyecto de una manera adecuada
+ Los stakeholders relevantes cambian a lo largo del proyecto
+ Se debe dar prioridad de una manera que cumpla las necesidades del cliente de  
manera eficiente
+ Se sacan requerimientos de varias fuentes, como las metas, conocimiento por  
parte de los desarrolladores, stakeholders, business rules, el ambiente de  
operacion, y el ambiente organizacional
+ El ingeniero de software tiene la tarea de recolectar los requerimientos de  
informacion dada por los stakeholders
+ Los stakeholders pueden tener problemas explicando tareas, no dar toda la  
informacion, o de plano no querer ayudar
+ Hay varios metodos para facilitar la obtencion de requerimientos, entre ellos:
    - **Entrevistas**     
    Preguntas hechas directamente a los stakeholders
    
    - **Escenarios propuestos**  
        Escenarios propuestos a usuarios para tener una idea mas clara sobre lo  
    que se busca
    
    - **Propotipos simples**  
    Prototipos simples para darse una idea de lo que los stakeholders desean
    
    - **Reuniones**  
    Reuniones grupales con stakeholders para recabar ideas entre todos y aclarar  
    dudas
    
    - **Observacion**  
    Observacion de lo que se desea realizar para obtener conocimiento sobre lo  
    que se desea mejorar/conseguir.
    
    - **User stories**  
    Metodo por el cual se pide al usuario que cuente lo que espera en el aspecto  
    de usabilidad: Yo como <rol\> quiero <cosa\> para <objetivo\>

    - **Otros metodos**

### Analisis de requerimientos

 Proceso de analisis para detectar y resolver conflictos entre requerimientos  
Sirve para asegurarse de que los requerimientos sean factibles en su totalidad y adecuados

+ Se pueden clasificar de varias formas, que son las siguientes:
    - Funcional o no funcional
    - Si se deriva o no de otros requerimientos
    - Si es de producto o de proceso
    - La prioridad
    - El alcance del requerimiento - que tanto afecta en el programa/software
    - Estabilidad/volatilidad del requerimiento - que tan probable es que cambie
+ Se hacen modelos para entender la situacion de una mejor manera
+ Los modelos pueden ser distintos por varios factores:
    - Naturaleza del problema
    - Expertis del desarrollador
    - Requerimientos de proceso impuestos
+ Empezar por el lado del software es mejor un 99% del tiempo
+ Se debe hacer el diseño de la arquitectura del software a partir de esto
+ Se le asignan requerimientos a diferentes partes del software para determinar  
mas requerimientos a partir de estos
+ Se deben resolver conflictos que se deriven de requerimientos incompatibles  
por parte de dos stakeholders distintos
+ Se debe dejar al cliente mas que nada resolver estos conflictos por razones  
hasta de contrato
+ Se prioritizan distintos requerimientos dependiendo de que tanto beneficio  
traen
+ Se puede utilizar analisis formal en ciertos casos que sea apropiado hacerlo

### Especificacion de requerimientos

Documentos que recaban informacion sobre los requerimientos determinados

+ System Definition Document - lista los requerimientos del sistema junto con  
informacion adicional sobre estos
+ System Requirements Specification - documento para ingenieros de sistemas que  
habla de todo lo que se deriva de los requerimientos
+ Software Requirements Specification - documento escrito en lenguaje natural  
(con anotaciones tecnicas a necesidad) que detalla requerimientos y lo que el  
software debe y no debe hacer

### Validacion de requerimientos

Procedimientos que se pueden hacer a documentos de requerimientos para  
asegurarse de que los ingenieros de software hayan entendido los requerimientos

+ Se deberian revisar varias veces para maximizar la cantidad de errores de  
requerimientos detectados a tiempo
+ Hay varios metodos para realizar esta validacion:
    - Examinaciones
    - Prototipos
    - Validacion del modelo utilizado
    - Pruebas de aceptacion de requerimientos

### Practical Considerations

+ El proceso de requerimientos es vital para el exito de un proyecto, aunque no  
se empiece hasta periodos mas tardios de este, como en startups que no empiezan  
con este hasta muy despues
+ El proceso de requerimientos es comunmente iterativo y busca un producto  
minimamente viable sobre el que mejorar iterativamente
+ Se deberia prioritizar el reducir el costo de posible cambio futuro
+ Es normal que haya una revision de requerimientos tarde en el desarrollo del  
proyecto debido a la naturaleza iterativa de este en modelos agiles de desarrollo
+ Los requerimientos deberian ir acompañados de informacion relevante a estos  
que es posiblemente necesaria para que estos sean entendidos de manera adecuada
+ Se debe tener una forma de saber que cosas estan detras de un requerimiento,  
o su historial (esto puede ser a traves de un DAG o algo similar)

### Software Requirements Tools

Hay dos tipos principales de herramientas para hacer cosas de requerimientos:  

+ **Herramientas para modelacion**  
     Estas existen para facilitar la creacion de diagramas y cosas por el estilo

+ **Herramientas para el manejo de requerimientos**  
     Estas sirven cuando existe una cantidad muy grande de requerimientos <br>
    y hay una complejidad considerable en el diseño completo

Capitulo 2: Software Design
---------------------------------

Esta es la etapa donde se analizan los requerimientos recabados para producir la 
estructura interna del software con el que se cumpliran estos requerimientos.

### Software Design Fundamentals

Conceptos y terminologia basicos para entender el diseño de software

+ El diseño es en si un tipo de ejercicio de resolucion de problemas
+ Este consiste en dos partes primariamente
	- Diseño arquitectonico - Describe como el software esta organizado en componentes
	- Diseño detallado - Detalla el comportamiento de los componentes determinados previamente
+ Entre estas dos partes se hace una serie de modelos y cosas que describen de una manera las decisiones mayores tomadas con una explicacion corta del porque se tomo esta decision sobre otras posibles
+ Principios de diseño de software son la base para varias decisiones que se toman, por ejemplo:
	- **Abstraccion**  
Diferentes formas de ver la informacion que pueden dar posibles soluciones que de otras maneras no seria posible

	- **Coupling and cohesion**  
Terminos que definen que tanto dependen partes del programa de otras partes/modulos

	- **Descomposicion y modularizacion**  
Division de partes del programa que permiten organizar funcionalidades y partes del programa de una mejor manera

	- **Encapsulacion e informacion oculta**  
Encapsular la informacion en entidades y no permitir que sea accesada fuera de esto da orden

	- **Separacion de interfaz e implementacion**  
Esto se hace haciendo la interfaz que se separa del como se hace la implementacion

	- **Suficiencia, completez y primitividad**  
Asegurarse que un componente tenga todo lo que requiere un nivel de abstraccion, y primitividad se refiere a que sea basado en patrones faciles de implementar

	- **Separacion de intereses**  
Separacion de areas de diseño que incumban a los stakeholders con el objetivo de hacer mas facil el manejo de la complejidad del diseño general

### Key Issues in Software Design

Cosas importantes con las que se tienen que lidiar cuando se hace software, como velocidad, seguridad, usabilidad, etc.

+ **Concurrency**  
Diseño del software teniendo en mente la escalabilidad de los procesos para aumentar la eficiencia

+ **Control y manejo de eventos**  
El como se manejan los eventos y la informacion dentro de estos

+ **Persistencia de informacion**  
Manejo de informacion duradera

+ **Distribucion de componentes**  
El como se distribuye el software en el hardware y como se conectan los componentes

+ **Manejo de errores y excepciones**  
Prevencion y manejo de errores y condiciones excepcionales

+ **Interaccion y presentacion**  
La presentacion de datos a usuarios y la estructura de las formas de interaccion con el usuario

+ **Seguridad**  
La seguridad de la informacion que se tiene la cual se quiere tener protegida

### Software Structure and Architecture

El set de estructuras para hacer cosas en el sistema, que tiene elementos de software,
las relaciones entre estos y las propiedades de estos

+ Conceptos como patrones y estilos son formas de reusar conocimiento de diseño
+ Hay diferentes formas de ver las facetas de la arquitectura, como vistas, por ejemplo:
	- Vista logica
	- Vista fisica
	- Vista de procesos
+ Un estilo de arquitectura es una especializacion de elementos con limitaciones en la manera en la que pueden ser usados
+ Un patron es una solucion comun a un problema comun, y pueden describirse como una parte de un estilo de arquitectura de nivel mas bajo
+ Las decisiones hechas durante el diseño arquitectonico tienen una importancia tremenda
+ Cosas como frameworks facilitan el reuso de codigo y patrones en forma de extensiones como plugins

### User Interface Design

Esta parte se centra en el diseño de la interfaz que sera utilizada por los usuarios

+ Para que el software sea lo mas eficiente posible la interfaz debe ser diseñada con sus usuarios en mente
+ La interfaz deberia:
	- Facil de aprender
	- Familiar
	- Consistente
	- No tener comportamiento que sorprenda al usuario
	- Dejar al usuario tener errores y ayudarlo a recuperarse de estos
	- Guiar al usuario
	- Acomodar para usuarios con capacidades diferentes (Ciegos, sordos, etc.)
+ Entre los estilos de interaccion con el usuario se encuentran los siguientes:
	- Pregunta/respuesta
	- Manipulacion directa de objetos en la interfaz
	- Seleccion en menu
	- Formularios
	- Lenguaje de comandos
	- Lenguaje natural
+ La informacion deberia estar separada de la presentacion de esta
+ Se deberian incluir indicadores de progreso mientras el software responde para darle al usuario indicaciones de que no esta trabado el software mediante feedback o algo como una barra de progreso
+ El diseño de una interfaz es un proceso iterativo que mejora cada vez mas
+ Se utiliza retroalimentacion en este proceso iterativo
+ Se deberia tomar en cuenta localizacion para permitir el adaptar para lenguajes y alfabetos distintos sin cambios mayores de software
+ Se pueden asociar cosas de la vida real con cosas del programa que hagan cosas similares e.g. Bote de basura para borrar archivos

### Software Design Quality Analysis and Evaluation

Existen varios atributos que contribuyen a la calidad del software, como mantenibilidad, portabilidad, usabilidad, robustez, etc.

+ Hay varias herramientas que sirven para analizar la calidad de un diseño de software:
	- **Reviews e inspecciones de calidad de diseño**
	- **Analisis estatico o analisis formal**
	- **Simulacion y prototipado**
+ Existen medidas cuyos objetivos es medir la calidad, que pueden ser a traves de diagramas o medidas de complejidad de funcionalidad, etc.

### Software Design Notations

Existen muchas notaciones para describir partes del diseño

+ Para describir la estructura del diseño existen las siguientes notaciones:
	- **ADLs**  
Describen la estructura como componentes y conectores
	- **Diagramas de componentes y conexiones entre estos**
	- **Class responsibility collaborator cards**  
Se usan para denotar nombres de componentes, sus responsabilidades y los componentes con los que colaboran

	- **Deployment diagrams**  
Representan un conjunto de nodos fisicos y sus relaciones

	- **Entity-relationship diagrams**
	- **Interface description languages**  
Lenguajes usados para definir lo que hacen los componentes del software

	- **Graficas estructurales**  
Describen que modulos llaman otros modulos y que llaman estos otros modulos

+ Tambien existen otras notaciones que describen el comportamiento de componentes del sistema
	- **Diagramas de actividad**  
Muestran el flujo de control de actividad a actividad

	- **Diagramas de comunicacion**  
Muestran la comunicacion entre objetos o componentes

	- **Diagramas de flujo de informacion**  
Muestran el flujo de datos entre elementos basados en un modelo

	- **Tablas y diagramas de decision**

	- **Diagramas de flujo**

	- **Diagramas de estado**

	- **Diagramas de secuencia**

	- **Lenguajes de especificacion formal**  
Lenguajes de texto basados en matematicas que usan abstraccion para definir componentes en terminos de pre y poscondiciones

	- **Pseudocodigo**  
Descripcion en un lenguaje similar a uno de programacion de lo que hacen ciertos metodos o componentes

### Software Design Strategies and Methods

Hay estrategias generales para el diseño de software, como divide and conquer, top-down, bottom-up entre otras, pero los paradigmas principales son los siguientes:

+ **Diseño orientado a objetos**  
En este tipo de diseño se identifican los componentes individuales y se hace el diseño basado en estos, abstrayendo el problema un poco

+ **Diseño orientado a funciones**  
Este tipo de diseño se basa en las funciones principales que el programa realiza y funciones auxiliares

+ **Diseño orientado a componentes**  
Este se basa en componentes posiblemente ya existentes, armando lo que se desea sometiendo los componentes al mismo nivel de testing que componentes nuevos aprovechando cosas que ya existen

### Software Design Tools

Las herramientas de diseño de software ayudan a la creacion de un diseño desde el inicio, y pueden ayudar de varias maneras, desde la creacion de diagramas hasta apoyos para analisis de calidad


Capitulo 3: Software Construction
---------------------------------
Esta area se refiere a la creacion de software mediante codigo, testing y debugging

### Software Construction Fundamentals

Hay algunos conceptos fundamentales que aplican a la construccion de software, que son los siguientes:

+ **Minimizing complexity**  
Reducir la complejidad del software en general, permitiendo la facil comprension del codigo lo que en si permite que se haga trabajo sobre este mas facilmente  

	Esto se logra haciendo el codigo mas simple de entender y empleando otras tecnicas

+ **Anticipating change**  
Anticipar el cambio antes de tiempo y agregar facilidad para este ayuda en el futuro a cualquier persona que tenga que agregar/cambiar funcionalidades

+ **Constructing for verification**  
Esto se refiere a la construccion de software de tal manera que los errores sean faciles de detectar y entender

+ **Reuse**  
Reusar componentes ya existentes puede aumentar la productividad, calidad y reducir costos  
El reuso tiene dos significados, que es la construccion para el reuso que es la creacion de nuevos componentes con el que sean reusables en mente, y la construccion con reuso que usa cosas hechas para ser reusadas

+ **Standards in construction**  
El tener estandares de ciertas cosas permite que haya consistencia a lo largo de un proyecto y ayuda a tener una mayor seguridad

### Managing Construction

+ La construccion de software se hace bajo ciertos modelos de ciclo de vida  
Estos determinan la manera en la que este se hace de inicio a fin  
Ciertos modelos son mas lineales como el de cascada, en comparacion con otros metodos como los agiles que son mas iterativos

+ El metodo de construccion elegido da el orden en el que el resto del proyecto sera hecho (documentos, analisis, etc.) y muchos aspectos del proyecto se definen por esto
+ Hay varias maneras de medir la cantidad de software construido que sirven para medir calidad, mejorar procesos y aumentar productividad por parte de los desarrolladores

### Practical Considerations

+ La construccion de software suele tener limitaciones y normalmente se hacen las cosas por que son mas practicas que otras opciones
+ Hay varios tipos de lenguajes con los que se pueden hacer programas:  
	- **Lenguajes de configuracion**  
Estos usan opciones predefinidas para hacer software

	- **Lenguajes de toolkits**  
Estos usan elementos de toolkits para hacer software

	- **Lenguajes de scripting**  
Estos son un tipo de lenguaje de programacion con diferencias leves

	- **Lenguajes de programacion**  
Estos son lenguajes que permiten hacer muchas cosas pero requieren mucho entrenamiento para ser usados de forma efectiva

	- **Notacion linguistica**  
Estos representan construcciones de software complejas en texto en patrones simples y faciles de entender

	- **Notacion formal**  
Estos son notaciones linguisticas basadas en notacion matematica sin ambiguedades

	- **Notacion visual**  
Estas se basan en representaciones visuales que representan el software como una entidad funcional

+ Hay varias consideraciones que se tienen en cuenta al momento de escribir codigo con el objetivo de reducir complejidad, como naming conventions, organizacion de codigo y documentacion
+ El codigo puede ser creado con el objetivo de que sea reusable, se requiere hacer varias cosas para esto
+ De igual manera puede ser creado con codigo hecho reusable, cambiando ciertas cosas para que sea adecuado para el software actual
+ La integracion del codigo completo en un sistema singular es una actividad muy importante

### Construction Technologies

+ Un API es un conjunto de funcionalidades que son expuestas para que otras personas puedan hacer construccion de sus propias aplicaciones incluyendo las funcionalidades expuestas
+ Clases genericas o templates sirven mucho para hacer codigo reutilizable
+ Hay varias formas de manejar errores, ya sea incluyendo casos especificos para estos, incluyendo metodos de deteccion mejores o crasheando el programa como ultima medida
+ La manera en la que el software lidia con errores es muy importante ya que es una de las medidas mas importantes de calidad (robustez), y si se evita el que se crashee siempre que haya un error la calidad es mayor
+ Se puede programar usando estados como automatas y cosas por el estilo junto con programacion orientada a objetos o se puede hacer con tablas que contienen informacion
+ Se usan gramaticas junto con parsers para determinar expresiones que seran procesadas
+ Hay varias cosas que facilitan el hacer uso de concurrency, entre estas:
	- **Semaforo**  
Controlan el acceso a recursos usados por multiples threads

	- **Monitor**  
Controla que solo un proceso este activo a la vez en una variable (Mutex)

	- **Exclusion mutua (Mutex)**  
Tipo de dato que da acceso de una variable a un proceso a la vez


+ El middleware es una parte de software que ayuda a que dos componentes se conecten
+ Los sistemas distribuidos funcionan de forma diferente al software convencional y funcionan a traves de conexion entre hosts
+ Los sistemas heterogeneos son sistemas que se conforman por muchos componentes y sistemas diferentes, que son hechos con esto en mente y funcionan d emanera correcta entre estos
+ El codigo se optimiza con cambios chicos que no cambian lo que hace en si, pero hacen que lo haga mas rapido
+ Los programas se hacen con los estandares de plataformas en mente (muchos se hacen con UNIX en mente, y otros se hacen con Windows en mente y programas hechos para Linux no sirven siempre para Windows y viceversa
+ El desarrollo basado en pruebas puede ser muy util para detectar errores en los requerimientos antes

### Software Construction Tools

+ Un IDE puede ser muy util al momento de escribir el software, con funcionalidades como syntax checking hasta compilacion o refactoring
+ Un constructor de GUI es util en el que permiten el hacer una interfaz de una manera visible, en vez de tener que cambiar valores en el codigo para mover una caja de texto un poco para la izquierda
+ Hay herramientas para hacer testing automatizado que sirven para asegurarse de que todo este funcionando como deberia
+ Tambien existen herramientas para analizar el rendimiento que tiene el software con tal de ayudar al momento de optimizar lo que haya por optimizar


Capitulo 4: Software Testing
---------------------------------

Los tests de software son verificaciones en las que el software deberia tener comportamientos esperados con una serie finita de casos de prueba

### Software Testing Fundamentals

+ Hay una serie de terminos que se refieren a un error o falla:
	- Fault (falla)
	- Failure (fallo)
	- Error
	- Otros
+ El termino 'defect' (defecto)  puede referirse a ambos faults y failures
+ Los *failure-causing inputs* pueden ser usado en vez de las faults para reducir ambiguedad
+ El testing sirve para probar que hay errores, pero no para probar que no los hay

### Test Levels

Al hacer testing se suele separar por niveles basados en el objeto que sera sometido a los tests

+ El objeto testeado puede ser un modulo o un grupo de modulos y las pruebas se hacen por fases:
	- **Unit testing**  
Prueba modulos o componentes solos
	- **Integration testing**  
Prueba que las interacciones entre modulos sea correcta
	- **System testing**  
Prueba que todo funcione como debe  
Mas que nada para probar requerimientos no funcionales como velocidad, seguridad, etc.

+ Las pruebas se suelen hacer con un objetivo en mente, y  
Hay varios objetivos que una prueba puede tener:
	- **Acceptance/Qualification Testing**  
Checa que un sistema cumpla los criterios de aceptacion
	- **Installation Testing**  
Pasa una vez que el software termina la instalacion en el sistema
	- **Alpha and Beta Testing**  
En este tipo de pruebas se le da a usuarios el software para que lo usen y reporten problemas
	- **Reliability Achievement and Evaluation**  
Se generan casos de prueba random para encontrar errores
	- **Regression Testing**  
Se prueban componentes especificos para asegurarse de que modificaciones no han causado que deje de funcionar de manera correcta
	- **Performance Testing**  
Aqui se prueba que el software cumpla los requerimientos de performance establecidos
	- **Security Testing**  
Se prueba que el software no sea vulnerable a ataques externos
	- **Stress Testing**  
Mantiene al sistema en su carga maxima una cantidad de tiempo extendida para ver como reacciona
	- **Back-To-Back Testing**  
Corre el programa dos veces con el mismo input para checar si hay discrepancias y se analizan en caso de que si hayan
	- **Recovery Testing**  
Analiza como el software se recupera de un fallo mayor
	- **Interface Testing**  
Checa que las interfaces funcionen correctamente mandando y recibiendo informacion correcta
	- **Configuration Testing**  
Prueba el software con configuraciones diferentes para asegurarse de que funciona de la manera esperada
	- **Usability and Human Computer Interaction Testing**  
Evalua que tan facil es el software de aprender y usar

### Test Techniques

Hay varias tecnicas cuyo objetivo principal es detectar la mayor cantidad de errores posibles, y estas intentan romper el programa

+ Estas tecnicas se pueden clasificar en dos tipos:
	- **White-box/glass-box**  
Si las pruebas estan basadas en como esta hecho el codigo/software
	- **Black-box**  
Si las pruebas nada mas dependen del input/output del software

A continuacion estan las tecnicas mas usadas para hacer testing:
+ **Ad hoc**  
Se basa en el conocimiento y experiencia del ingeniero de software
+ **Exploratory Testing**  
Se van haciendo pruebas con el tiempo a como el ingeniero lo vea necesario
+ **Equivalence Partitioning**  
Se hacen conjuntos de inputs que los representan y se seleccionan una serie de estos para validar la area mas grande posible
+ **Pairwise Testing**  
Se prueban todas las posibles combinaciones con dos parametros reduciendo cosas que pueden incrementar el numero de casos de prueba demasiado
+ **Boundary-Value Analysis**  
En este los casos de prueba suelen ser limites de algun tipo ya que suelen causar errores la mayoria del tiempo si se pasa del limite
+ **Random Testing**  
Los casos de prueba se hacen completamente aleatoriamente
+ **Control Flow-Based Criteria**  
Los casos de prueba deben cubrir todos los caminos del programa
+ **Data Flow-Based Criteria**  
Se hacen los casos de prueba para probar todo de todas las variables
+ **Fault-Based Techniques**  
Se ponen casos de prueba que probablemente van a causar problemas
+ **Error Guessing**  
Casos hechos por los ingenieros de software que creen son las cosas principales que pueden llegar a fallar en su programa y depende del expertis del desarrollador bastante
+ **Mutation Testing**  
Se generan casos de prueba que comparan el programa base de un modificado un poco para detectar el mutante, y si no se detectan los mutantes se generan casos de prueba que lo hacen
+ **Operational Profile**  
Se trata de simular el uso cotidiano de un programa para ver que tan confiable es
+ **User Observation Heuristics**  
Se usan heuristicas para generar casos de prueba cuyo objetivo es determinar que tan facil de usar es el programa
+ **Decision Tables**  
Se asocian inputs con outputs y se hacen los casos de prueba a partir de esto
+ **Finite-State Machines**  
Se prueban todos los estados y transiciones del programa representado como un automata
+ **Formal Specifications**  
Se hacen casos de prueba de forma automatica a partir de los requerimientos definidos en un lenguaje formal
+ **Workflow Models**  
Se hacen casos de prueba relevantes a ciertas actividades definidas
+ Existen varias formas de combinar tecnicas, deterministicas y aleatorias, funcionales y estructurales, entre otras y esto puede servir bastante ya que se pueden complementar de cierta manera

### Test-Related Measures

Hay varias indicadores que se utilizan para analizar calidad, y en el area de testing para medir progreso se pueden utilizar varias cosas que sirven para optimizar el proceso de testing
+ Hay medidas que se basan en el tamaño del codigo
+ Existen muchos tipos de faults, y saber identificarlas puede ser util al analizar el software que es testeado
+ Hay modelos de confiabilidad de codigo que se basan en las faults que estiman que entre menos fallas hay mas confiable es el programa
+ Hay un metodo llamado fault seeding en el cual se agregan fallos al codigo para encontrar errores adicionales que se encuentran al hacer los tests
+ Se mide el mutation score al hacer Mutation Testing, que es el ratio de mutantes detectados a mutantes generados

### Test Process

Todo lo anterior debe ser integrado a un proceso de testing bien definido

+ Se debe dejar de por lado el que alguien hizo el codigo, y enfocarse en arreglar lo que causa problemas
+ El como se va a manejar el proceso de testing deberia ser documentado claramente
+ Se puede tener un equipo de testing separado de los desarrolladores para que no haya bias de algun tipo, o se puede hacer por los mismos desarrolladores
+ Se usan medidas como las que fueron mencionadas en la seccion anterior para mejorar la eficiencia del proceso
+ Se debe tener bien definido el punto en el cual el testing es suficiente, porque si no realmente puede llegar a ser casi infinito
+ El ambiente de testing deberia estar bien integrado con el resto del proyecto
+ Los defectos deberian estar documentados de igual manera

### Software Testing Tools

Ya que el testing es una labor que si se hace de manera manual toma muchisimo tiempo, hay herramientas que hacen esto mucho menos tedioso

Existen multiples herramientas hechas para esto:
+ **Test harnesses**  
Estos son environments en los que las pruebas son hechas y los resultados son guardados

+ **Test generators**  
Estos generan casos de pruebas basados en tecnicas o mezclas de estas

+ **Capture/replay tools**  
Estas son programas que dejan inspeccionar casos de prueba especificos con mas detalle

+ **Oracle/file comparators/assertion checking tools**  
Checan que un test sea correcto o no

+ **Coverage analyzers and instrumenters**  
Estas herramientas ven que tanto porcentaje del programa se usa y lo comparan con el porcentaje esperado

+ **Tracers**  
Ven que camino tomo el programa en un caso de prueba

+ **Regression testing tools**  
Ejecutan un test suite despues de modificar una seccion de codigo para asegurarse de que no rompio el programa

+ **Reliablility evaluation tools**  
Son herramientas para evaluar medidas de confiabilidad del software recabadas y visualizarlas de una manera mas sencilla

Conclusion
-------
Despues de haber hecho la lectura me doy cuenta de que el proceso entero detras de la creacion de un programa bueno es mucho mas grande de lo que uno normalmente pensaria cuando lo ves desde el aspecto de un desarrollador. Normalmente cuando uno tiene una idea de un programa o cosa que suena interesante de hacer uno se pone directo a programar, sin dar mucho enfasis a la planeacion, pruebas o diseño en si, todo pura construccion; y no es que sea malo en si, mucha gente le gusta el aspecto de la programacion pero despues de leer esto me doy cuenta de que hacer la planeacion tiene un efecto tremendo en el resultado final. Es realmente comparable a hacer una casa de troncos en el bosque contra una casa bien planeada; puede que la casa de troncos si sirva para dormir y taparte de la lluvia y animales salvajes, pero al momento de querer expandir o que tenga cosas minimamente complejas como cableado o cosas por el estilo, la conveniencia de ser mas facil de construir se derrumba ya que no puedes hacer realmente nada sin hacer un destrozo de la casa; o minimo, asi lo percibo yo.

### Respuesta a la pregunta
Lo que mas me llamo la atencion de la lectura fue la seccion de testing ya que es un area que sabia que existia, pero no habia investigado realmente como se hacia o nada por el estilo, y el aprender cosas nuevas me gusta bastante, asi que probablemente es una de las cosas que mas me llamo la atencion de la lectura. Tambien se me hizo bastante interesante el que hubieran matematicas en lugares inesperados en secciones que no tenia ni idea que podia estar, como la parte de generacion de casos de prueba.
