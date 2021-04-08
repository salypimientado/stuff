Resumen SWEBOK Cap. 1-4
=======================

#### Autor: Juan Pablo Salazar García

#### Matricula: A01740200

#### Clase: construcción de Software y Toma de Decisiones

Capítulo 1: Software Requirements
---------------------------------

### Fundamentales de requerimientos de software

El diseño de requerimientos es una área de conocimiento que se enfoca\
principalmente en los requerimientos que un proyecto tiene, haciendo
desde el\
análisis de requerimientos con el cliente hasta el manejo de los
requerimientos\
en la mitad del proyecto.

El diseño de requerimientos de software es una de las partes más
críticas del\
ciclo de vida de un proyecto, y si es mal realizada puede ser la causa
principal\
de problemas y es una de las razones principales por las que los
proyectos de\
software fallan.

Si no se hace bien el planteamiento de requerimientos se pueden causar
problemas\
considerables al necesitar agregar requerimientos o sistemas aparte de
los\
planeados originalmente.\
Usualmente es un trabajo realizado por ingenieros de software, y no por\
personal no relacionado. Esto no es necesariamente algo que se realiza
una vez\
por proyecto al inicio de este, ya que esto limitaría el proyecto al
modelo de\
cascada, y no es así.

Un requerimiento como tal es algo que se requiere para solucionar\
un problema de algún tipo.

-   Complejidad en problema = complejidad en requerimientos

-   Todos los requerimientos son individualmente funcionales o no
    funcionales

-   Se debe asegurar que los requerimientos entren en el presupuesto

-   Prioridad de requerimientos

-   Requerimiento de producto vs de proceso

-   Los requerimientos de software pueden implicar de proceso

-   Los de proceso pueden ser impuestos por organizaciones, cliente etc.

-   Requerimiento funcional - función a realizar por parte del software

-   Requerimiento no funcional - requerimiento que no cumple una
    función, son mas\
    que nada por calidad y decisiones extras e.g. el menú debe ser verde

-   Propiedades emergentes tienen varios sistemas que forman parte de
    estos

-   Dependen de la arquitectura del sistema increíblemente

-   Requisitos deberían ser cuantificables, no poco específicos

-   Sistema = combinación de todo para cumplir un objetivo

### Proceso de requerimientos

No es una actividad singular al inicio del proyecto, realmente es un
proceso que inicia al empezar el proyecto y se va refinando a lo largo
de este

-   Se debe adaptar a la organización y al proyecto debido

-   El cómo las actividades que forman parte del proceso de
    requerimientos se configuran de manera distinta para proyectos y
    situaciones diferentes

-   Roles de personas que forman parte del proceso:

    -   Usuarios

    -   Clientes

    -   Analistas del mercado (en caso de que no sea un cliente
        especifico)

    -   Organismos regulatorios (gobierno, etc.)

    -   Ingenieros de software

-   No es necesario cumplir las necesidades de todo el mundo, pero se
    debe hacer\
    lo posible para que se haga lo mejor que se puede

### Elicitacion/obtención de requerimientos

Fase donde se observa y recolectan requerimientos por parte de los
stakeholders

-   Se identifican los stakeholders y la relación entre los devs y
    clientes es\
    establecida

-   Se debe definir el alcance del proyecto de una manera adecuada

-   Los stakeholders relevantes cambian a lo largo del proyecto

-   Se debe dar prioridad de una manera que cumpla las necesidades del
    cliente de\
    manera eficiente

-   Se sacan requerimientos de varias fuentes, como las metas,
    conocimiento por\
    parte de los desarrolladores, stakeholders, business rules, el
    ambiente de\
    operación, y el ambiente organizacional

-   El ingeniero de software tiene la tarea de recolectar los
    requerimientos de\
    información dada por los stakeholders

-   Los stakeholders pueden tener problemas explicando tareas, no dar
    toda la\
    información, o de plano no querer ayudar

-   Hay varios métodos para facilitar la obtención de requerimientos,
    entre ellos:

    -   **Entrevistas**\
        Preguntas hechas directamente a los stakeholders

    -   **Escenarios propuestos**\
        Escenarios propuestos a usuarios para tener una idea más clara
        sobre lo\
        que se busca

    -   **Prototipos simples**\
        Prototipos simples para darse una idea de lo que los
        stakeholders desean

    -   **Reuniones**\
        Reuniones grupales con stakeholders para recabar ideas entre
        todos y aclarar\
        dudas

    -   **Observación**\
        Observación de lo que se desea realizar para obtener
        conocimiento sobre lo\
        que se desea mejorar/conseguir.

    -   **User stories**\
        Método por el cual se pide al usuario que cuente lo que espera
        en el aspecto\
        de usabilidad: Yo como \<rol\> quiero \<cosa\> para \<objetivo\>

    -   **Otros métodos**

### Análisis de requerimientos

Proceso de análisis para detectar y resolver conflictos entre
requerimientos\
Sirve para asegurarse de que los requerimientos sean factibles en su
totalidad y adecuados

-   Se pueden clasificar de varias formas, que son las siguientes:

    -   Funcional o no funcional

    -   Si se deriva o no de otros requerimientos

    -   Si es de producto o de proceso

    -   La prioridad

    -   El alcance del requerimiento - que tanto afecta en el
        programa/software

    -   Estabilidad/volatilidad del requerimiento - que tan probable es
        que cambie

-   Se hacen modelos para entender la situación de una mejor manera

-   Los modelos pueden ser distintos por varios factores:

    -   Naturaleza del problema

    -   Expertis del desarrollador

    -   Requerimientos de proceso impuestos

-   Empezar por el lado del software es mejor un 99% del tiempo

-   Se debe hacer el diseño de la arquitectura del software a partir de
    esto

-   Se les asignan requerimientos a diferentes partes del software para
    determinar\
    más requerimientos a partir de estos

-   Se deben resolver conflictos que se deriven de requerimientos
    incompatibles\
    por parte de dos stakeholders distintos

-   Se debe dejar al cliente más que nada resolver estos conflictos por
    razones\
    hasta de contrato

-   Se priorizan distintos requerimientos dependiendo de que tanto
    beneficio\
    traen

-   Se puede utilizar análisis formal en ciertos casos que sea apropiado
    hacerlo

### Especificación de requerimientos

Documentos que recaban información sobre los requerimientos determinados

-   System Definition Document - lista los requerimientos del sistema
    junto con\
    información adicional sobre estos

-   System Requirements Specification - documento para ingenieros de
    sistemas que\
    habla de todo lo que se deriva de los requerimientos

-   Software Requirements Specification - documento escrito en lenguaje
    natural\
    (con anotaciones técnicas a necesidad) que detalla requerimientos y
    lo que el\
    software debe y no debe hacer

### Validación de requerimientos

Procedimientos que se pueden hacer a documentos de requerimientos para\
asegurarse de que los ingenieros de software hayan entendido los
requerimientos

-   Se deberían revisar varias veces para maximizar la cantidad de
    errores de\
    requerimientos detectados a tiempo

-   Hay varios métodos para realizar esta validación:

    -   Examinaciones

    -   Prototipos

    -   Validación del modelo utilizado

    -   Pruebas de aceptación de requerimientos

### Practical Considerations

-   El proceso de requerimientos es vital para el éxito de un proyecto,
    aunque no\
    se empiece hasta periodos más tardíos de este, como en startups que
    no empiezan\
    con este hasta muy después

-   El proceso de requerimientos es comúnmente iterativo y busca un
    producto\
    mínimamente viable sobre el que mejorar iterativamente

-   Se debería priorizar el reducir el costo de posible cambio futuro

-   Es normal que haya una revisión de requerimientos tarde en el
    desarrollo del\
    proyecto debido a la naturaleza iterativa de este en modelos agiles
    de desarrollo

-   Los requerimientos deberían ir acompañados de información relevante
    a estos\
    que es posiblemente necesaria para que estos sean entendidos de
    manera adecuada

-   Se debe tener una forma de saber qué cosas están detrás de un
    requerimiento,\
    o su historial (esto puede ser a través de un DAG o algo similar)

### Software Requirements Tools

Hay dos tipos principales de herramientas para hacer cosas de
requerimientos:

-   **Herramientas para modelación**\
    Estas existen para facilitar la creación de diagramas y cosas por el
    estilo

-   **Herramientas para el manejo de requerimientos**\
    Estas sirven cuando existe una cantidad muy grande de requerimientos
    y hay una complejidad considerable en el diseño completo

Capítulo 2: Software Design
---------------------------

Esta es la etapa donde se analizan los requerimientos recabados para
producir la estructura interna del software con el que se cumplirán
estos requerimientos.

### Software Design Fundamentals

Conceptos y terminología básicos para entender el diseño de software

-   El diseño es en sí un tipo de ejercicio de resolución de problemas

-   Este consiste en dos partes primariamente

    -   Diseño arquitectónico - Describe como el software está
        organizado en componentes

    -   Diseño detallado - Detalla el comportamiento de los componentes
        determinados previamente

-   Entre estas dos partes se hace una serie de modelos y cosas que
    describen de una manera las decisiones mayores tomadas con una
    explicación corta del porque se tomó esta decisión sobre otras
    posibles

-   Principios de diseño de software son la base para varias decisiones
    que se toman, por ejemplo:

    -   **Abstracción**\
        Diferentes formas de ver la información que pueden dar posibles
        soluciones que de otras maneras no sería posible

    -   **Coupling and cohesión**\
        Términos que definen que tanto dependen partes del programa de
        otras partes/módulos

    -   **Descomposición y modularizarían**\
        División de partes del programa que permiten organizar
        funcionalidades y partes del programa de una mejor manera

    -   **Encapsulación e información oculta**\
        Encapsular la información en entidades y no permitir que sea
        accesada fuera de esto da orden

    -   **Separación de interfaz e implementación**\
        Esto se hace haciendo la interfaz que se separa del cómo se hace
        la implementación

    -   **Suficiencia, completez y primitividad**\
        Asegurarse que un componente tenga todo lo que requiere un nivel
        de abstracción, y primitividad se refiere a que sea basado en
        patrones fáciles de implementar

    -   **Separación de intereses**\
        Separación de áreas de diseño que incumban a los stakeholders
        con el objetivo de hacer más fácil el manejo de la complejidad
        del diseño general

### Key Issues in Software Design

Cosas importantes con las que se tienen que lidiar cuando se hace
software, como velocidad, seguridad, usabilidad, etc.

-   **Concurrency**\
    Diseño del software teniendo en mente la escalabilidad de los
    procesos para aumentar la eficiencia

-   **Control y manejo de eventos**\
    El cómo se manejan los eventos y la información dentro de estos

-   **Persistencia de información**\
    Manejo de información duradera

-   **Distribución de componentes**\
    El cómo se distribuye el software en el hardware y como se conectan
    los componentes

-   **Manejo de errores y excepciones**\
    Prevención y manejo de errores y condiciones excepcionales

-   **Interacción y presentación**\
    La presentación de datos a usuarios y la estructura de las formas de
    interacción con el usuario

-   **Seguridad**\
    La seguridad de la información que se tiene la cual se quiere tener
    protegida

### Software Structure and Architecture

El set de estructuras para hacer cosas en el sistema, que tiene
elementos de software, las relaciones entre estos y las propiedades de
estos

-   Conceptos como patrones y estilos son formas de reusar conocimiento
    de diseño

-   Hay diferentes formas de ver las facetas de la arquitectura, como
    vistas, por ejemplo:

    -   Vista lógica

    -   Vista física

    -   Vista de procesos

-   Un estilo de arquitectura es una especialización de elementos con
    limitaciones en la manera en la que pueden ser usados

-   Un patrón es una solución común a un problema común, y pueden
    describirse como una parte de un estilo de arquitectura de nivel más
    bajo

-   Las decisiones hechas durante el diseño arquitectónico tienen una
    importancia tremenda

-   Cosas como frameworks facilitan el reuso de código y patrones en
    forma de extensiones como plugin

### User Interface Design

Esta parte se centra en el diseño de la interfaz que será utilizada por
los usuarios

-   Para que el software sea lo más eficiente posible la interfaz debe
    ser diseñada con sus usuarios en mente

-   La interfaz debería:

    -   Fácil de aprender

    -   Familiar

    -   Consistente

    -   No tener comportamiento que sorprenda al usuario

    -   Dejar al usuario tener errores y ayudarlo a recuperarse de estos

    -   Guiar al usuario

    -   Acomodar para usuarios con capacidades diferentes (Ciegos,
        sordos, etc.)

-   Entre los estilos de interacción con el usuario se encuentran los
    siguientes:

    -   Pregunta/respuesta

    -   Manipulación directa de objetos en la interfaz

    -   Selección en menú

    -   Formularios

    -   Lenguaje de comandos

    -   Lenguaje natural

-   La información debería estar separada de la presentación de esta

-   Se deberían incluir indicadores de progreso mientras el software
    responde para darle al usuario indicaciones de que no está trabado
    el software mediante feedback o algo como una barra de progreso

-   El diseño de una interfaz es un proceso iterativo que mejora cada
    vez mas

-   Se utiliza retroalimentación en este proceso iterativo

-   Se debería tomar en cuenta localización para permitir el adaptar
    para lenguajes y alfabetos distintos sin cambios mayores de software

-   Se pueden asociar cosas de la vida real con cosas del programa que
    hagan cosas similares e.g. Bote de basura para borrar archivos

### Software Design Quality Analysis and Evaluation

Existen varios atributos que contribuyen a la calidad del software, como
mantenibilidad, portabilidad, usabilidad, robustez, etc.

-   Hay varias herramientas que sirven para analizar la calidad de un
    diseño de software:

    -   **Reviews e inspecciones de calidad de diseño**

    -   **Análisis estático o análisis formal**

    -   **Simulación y prototipado**

-   Existen medidas cuyos objetivos es medir la calidad, que pueden ser
    a través de diagramas o medidas de complejidad de funcionalidad,
    etc.

### Software Design Notations

Existen muchas notaciones para describir partes del diseño

-   Para describir la estructura del diseño existen las siguientes
    notaciones:

    -   **ADLs**\
        Describen la estructura como componentes y conectores

    -   **Diagramas de componentes y conexiones entre estos**

    -   **Class responsibility collaborator cards**\
        Se usan para denotar nombres de componentes, sus
        responsabilidades y los componentes con los que colaboran

    -   **Deployment diagrams**\
        Representan un conjunto de nodos físicos y sus relaciones

    -   **Entity-relationship diagrams**

    -   **Interface description languages**\
        Lenguajes usados para definir lo que hacen los componentes del
        software

    -   **Graficas estructurales**\
        Describen que módulos llaman otros módulos y que llaman estos
        otros módulos

-   También existen otras notaciones que describen el comportamiento de
    componentes del sistema

    -   **Diagramas de actividad**\
        Muestran el flujo de control de actividad a actividad

    -   **Diagramas de comunicación**\
        Muestran la comunicación entre objetos o componentes

    -   **Diagramas de flujo de información**\
        Muestran el flujo de datos entre elementos basados en un modelo

    -   **Tablas y diagramas de decisión**

    -   **Diagramas de flujo**

    -   **Diagramas de estado**

    -   **Diagramas de secuencia**

    -   **Lenguajes de especificación formal**\
        Lenguajes de texto basados en matemáticas que usan abstracción
        para definir componentes en términos de pre y postcondiciones

    -   **Pseudocódigo**\
        Descripción en un lenguaje similar a uno de programación de lo
        que hacen ciertos métodos o componentes

### Software Design Strategies and Methods

Hay estrategias generales para el diseño de software, como divide and
conquer, top-down, bottom-up entre otras, pero los paradigmas
principales son los siguientes:

-   **Diseño orientado a objetos**\
    En este tipo de diseño se identifican los componentes individuales y
    se hace el diseño basado en estos, abstrayendo el problema un poco

-   **Diseño orientado a funciones**\
    Este tipo de diseño se basa en las funciones principales que el
    programa realiza y funciones auxiliares

-   **Diseño orientado a componentes**\
    Este se basa en componentes posiblemente ya existentes, armando lo
    que se desea sometiendo los componentes al mismo nivel de testing
    que componentes nuevos aprovechando cosas que ya existen

### Software Design Tools

Las herramientas de diseño de software ayudan a la creación de un diseño
desde el inicio, y pueden ayudar de varias maneras, desde la creación de
diagramas hasta apoyos para análisis de calidad

Capítulo 3: Software Construction
---------------------------------

Esta área se refiere a la creación de software mediante código, testing
y debugging

### Software Construction Fundamentals

Hay algunos conceptos fundamentales que aplican a la construcción de
software, que son los siguientes:

-   **Minimizing complexity**\
    Reducir la complejidad del software en general, permitiendo la fácil
    comprensión del código lo que en si permite que se haga trabajo
    sobre este más fácilmente

<!-- -->

-   Esto se logra haciendo el código más simple de entender y empleando
    otras técnicas

<!-- -->

-   **Anticipating change**\
    Anticipar el cambio antes de tiempo y agregar facilidad para este
    ayuda en el futuro a cualquier persona que tenga que agregar/cambiar
    funcionalidades

-   **Constructing for verification**\
    Esto se refiere a la construcción de software de tal manera que los
    errores sean fáciles de detectar y entender

-   **Reuse**\
    Reusar componentes ya existentes puede aumentar la productividad,
    calidad y reducir costos\
    El reuso tiene dos significados, que es la construcción para el
    reuso que es la creación de nuevos componentes con el que sean
    reusables en mente, y la construcción con reuso que usa cosas hechas
    para ser reusadas

-   **Standards in construction**\
    El tener estándares de ciertas cosas permite que haya consistencia a
    lo largo de un proyecto y ayuda a tener una mayor seguridad

### Managing Construction

-   La construcción de software se hace bajo ciertos modelos de ciclo de
    vida\
    Estos determinan la manera en la que este se hace de inicio a fin\
    Ciertos modelos son más lineales como el de cascada, en comparación
    con otros métodos como los agiles que son más iterativos

-   El método de construcción elegido da el orden en el que el resto del
    proyecto será hecho (documentos, análisis, etc.) y muchos aspectos
    del proyecto se definen por esto

-   Hay varias maneras de medir la cantidad de software construido que
    sirven para medir calidad, mejorar procesos y aumentar productividad
    por parte de los desarrolladores

### Practical Considerations

-   La construcción de software suele tener limitaciones y normalmente
    se hacen las cosas porque son más prácticas que otras opciones

-   Hay varios tipos de lenguajes con los que se pueden hacer programas:

    -   **Lenguajes de configuración**\
        Estos usan opciones predefinidas para hacer software

    -   **Lenguajes de toolkits**\
        Estos usan elementos de toolkits para hacer software

    -   **Lenguajes de scripting**\
        Estos son un tipo de lenguaje de programación con diferencias
        leves

    -   **Lenguajes de programación**\
        Estos son lenguajes que permiten hacer muchas cosas, pero
        requieren mucho entrenamiento para ser usados de forma efectiva

    -   **Notación lingüística**\
        Estos representan construcciones de software complejas en texto
        en patrones simples y fáciles de entender

    -   **Notación formal**\
        Estos son notaciones lingüísticas basadas en notación matemática
        sin ambigüedades

    -   **Notación visual**\
        Estas se basan en representaciones visuales que representan el
        software como una entidad funcional

-   Hay varias consideraciones que se tienen en cuenta al momento de
    escribir código con el objetivo de reducir complejidad, como naming
    conventions, organización de código y documentación

-   El código puede ser creado con el objetivo de que sea reusable, se
    requiere hacer varias cosas para esto

-   De igual manera puede ser creado con código hecho reusable,
    cambiando ciertas cosas para que sea adecuado para el software
    actual

-   La integración del código completo en un sistema singular es una
    actividad muy importante

### Construction Technologies

-   Un API es un conjunto de funcionalidades que son expuestas para que
    otras personas puedan hacer construcción de sus propias aplicaciones
    incluyendo las funcionalidades expuestas

-   Clases genéricas o templates sirven mucho para hacer código
    reutilizable

-   Hay varias formas de manejar errores, ya sea incluyendo casos
    especificos para estos, incluyendo métodos de detección mejores o
    crasheando el programa como última medida

-   La manera en la que el software lidia con errores es muy importante
    ya que es una de las medidas más importantes de calidad (robustez),
    y si se evita el que se crashee siempre que haya un error la calidad
    es mayor

-   Se puede programar usando estados como autómatas y cosas por el
    estilo junto con programación orientada a objetos o se puede hacer
    con tablas que contienen información

-   Se usan gramáticas junto con parsers para determinar expresiones que
    serán procesadas

-   Hay varias cosas que facilitan el hacer uso de concurrency, entre
    estas:

    -   **Semáforo**\
        Controlan el acceso a recursos usados por múltiples threads

    -   **Monitor**\
        Controla que solo un proceso este activo a la vez en una
        variable (Mutex)

    -   **Exclusión mutua (Mutex)**\
        Tipo de dato que da acceso de una variable a un proceso a la vez

-   El middleware es una parte de software que ayuda a que dos
    componentes se conecten

-   Los sistemas distribuidos funcionan de forma diferente al software
    convencional y funcionan a través de conexión entre hosts

-   Los sistemas heterogéneos son sistemas que se conforman por muchos
    componentes y sistemas diferentes, que son hechos con esto en mente
    y funcionan de manera correcta entre estos

-   El código se optimiza con cambios chicos que no cambian lo que hace
    en sí, pero hacen que lo haga más rápido

-   Los programas se hacen con los estándares de plataformas en mente
    (muchos se hacen con UNIX en mente, y otros se hacen con Windows en
    mente y programas hechos para Linux no sirven siempre para Windows y
    viceversa

-   El desarrollo basado en pruebas puede ser muy útil para detectar
    errores en los requerimientos antes

### Software Construction Tools

-   Un IDE puede ser muy útil al momento de escribir el software, con
    funcionalidades como syntax checking hasta compilación o refactoring

-   Un constructor de GUI es útil en el que permiten el hacer una
    interfaz de una manera visible, en vez de tener que cambiar valores
    en el código para mover una caja de texto un poco para la izquierda

-   Hay herramientas para hacer testing automatizado que sirven para
    asegurarse de que todo esté funcionando como debería

-   también existen herramientas para analizar el rendimiento que tiene
    el software con tal de ayudar al momento de optimizar lo que haya
    por optimizar

Capítulo 4: Software Testing
----------------------------

Los tests de software son verificaciones en las que el software debería
tener comportamientos esperados con una serie finita de casos de prueba

### Software Testing Fundamentals

-   Hay una serie de términos que se refieren a un error o falla:

    -   Fault (falla)

    -   Failure (fallo)

    -   Error

    -   Otros

-   El término 'defect' (defecto) puede referirse a ambos faults y
    failures

-   Los *failure-causing inputs* pueden ser usado en vez de las faults
    para reducir ambigüedad

-   El testing sirve para probar que hay errores, pero no para probar
    que no los hay

### Test Levels

Al hacer testing se suele separar por niveles basados en el objeto que
será sometido a los tests

-   El objeto testeado puede ser un módulo o un grupo de módulos y las
    pruebas se hacen por fases:

    -   **Unit testing**\
        Prueba módulos o componentes solos

    -   **Integration testing**\
        Prueba que las interacciones entre módulos sean correctas

    -   **System testing**\
        Prueba que todo funcione como debe\
        Mas que nada para probar requerimientos no funcionales como
        velocidad, seguridad, etc.

-   Las pruebas se suelen hacer con un objetivo en mente, y\
    Hay varios objetivos que una prueba puede tener:

    -   **Acceptance/Qualification Testing**\
        Checa que un sistema cumpla los criterios de aceptación

    -   **Installation Testing**\
        Pasa una vez que el software termina la instalación en el
        sistema

    -   **Alpha and Beta Testing**\
        En este tipo de pruebas se les da a usuarios el software para
        que lo usen y reporten problemas

    -   **Reliability Achievement and Evaluation**\
        Se generan casos de prueba random para encontrar errores

    -   **Regression Testing**\
        Se prueban componentes especificos para asegurarse de que
        modificaciones no han causado que deje de funcionar de manera
        correcta

    -   **Performance Testing**\
        Aquí se prueba que el software cumpla los requerimientos de
        performance establecidos

    -   **Security Testing**\
        Se prueba que el software no sea vulnerable a ataques externos

    -   **Stress Testing**\
        Mantiene al sistema en su carga máxima una cantidad de tiempo
        extendida para ver cómo reacciona

    -   **Back-To-Back Testing**\
        Corre el programa dos veces con el mismo input para checar si
        hay discrepancias y se analizan en caso de que si haya

    -   **Recovery Testing**\
        Analiza como el software se recupera de un fallo mayor

    -   **Interface Testing**\
        Checa que las interfaces funcionen correctamente mandando y
        recibiendo información correcta

    -   **Configuration Testing**\
        Prueba el software con configuraciones diferentes para
        asegurarse de que funciona de la manera esperada

    -   **Usability and Human Computer Interaction Testing**\
        Evalúa que tan fácil es el software de aprender y usar

### Test Techniques

Hay varias técnicas cuyo objetivo principal es detectar la mayor
cantidad de errores posibles, y estas intentan romper el programa

-   Estas técnicas se pueden clasificar en dos tipos:

    -   **White-box/glass-box**\
        Si las pruebas están basadas en como esta hecho el
        código/software

    -   **Black-box**\
        Si las pruebas nada más dependen del input/output del software

A continuación, están las técnicas más usadas para hacer testing:

-   **Ad hoc**\
    Se basa en el conocimiento y experiencia del ingeniero de software

-   **Exploratory Testing**\
    Se van haciendo pruebas con el tiempo a como el ingeniero lo vea
    necesario

-   **Equivalence Partitioning**\
    Se hacen conjuntos de inputs que los representan y se seleccionan
    una serie de estos para validar la área más grande posible

-   **Pairwise Testing**\
    Se prueban todas las posibles combinaciones con dos parámetros
    reduciendo cosas que pueden incrementar el número de casos de prueba
    demasiado

-   **Boundary-Value Analysis**\
    En este los casos de prueba suelen ser límites de algún tipo ya que
    suelen causar errores la mayoría del tiempo si se pasa del limite

-   **Random Testing**\
    Los casos de prueba se hacen completamente aleatoriamente

-   **Control Flow-Based Criteria**\
    Los casos de prueba deben cubrir todos los caminos del programa

-   **Data Flow-Based Criteria**\
    Se hacen los casos de prueba para probar todo de todas las variables

-   **Fault-Based Techniques**\
    Se ponen casos de prueba que probablemente van a causar problemas

-   **Error Guessing**\
    Casos hechos por los ingenieros de software que creen son las cosas
    principales que pueden llegar a fallar en su programa y depende del
    expertis del desarrollador bastante

-   **Mutation Testing**\
    Se generan casos de prueba que comparan el programa base de un
    modificado un poco para detectar el mutante, y si no se detectan los
    mutantes se generan casos de prueba que lo hacen

-   **Operational Profile**\
    Se trata de simular el uso cotidiano de un programa para ver qué tan
    confiable es

-   **User Observation Heuristics**\
    Se usan heurísticas para generar casos de prueba cuyo objetivo es
    determinar qué tan fácil de usar es el programa

-   **Decision Tables**\
    Se asocian inputs con outputs y se hacen los casos de prueba a
    partir de esto

-   **Finite-State Machines**\
    Se prueban todos los estados y transiciones del programa
    representado como un autómata

-   **Formal Specifications**\
    Se hacen casos de prueba de forma automática a partir de los
    requerimientos definidos en un lenguaje formal

-   **Workflow Models**\
    Se hacen casos de prueba relevantes a ciertas actividades definidas

-   Existen varias formas de combinar técnicas, determinísticas y
    aleatorias, funcionales y estructurales, entre otras y esto puede
    servir bastante ya que se pueden complementar de cierta manera

### Test-Related Measures

Hay varias indicadores que se utilizan para analizar calidad, y en el
área de testing para medir progreso se pueden utilizar varias cosas que
sirven para optimizar el proceso de testing

-   Hay medidas que se basan en el tamaño del código

-   Existen muchos tipos de faults, y saber identificarlas puede ser
    útil al analizar el software que es testeado

-   Hay modelos de confiabilidad de código que se basan en las faults
    que estiman que entre menos fallas hay más confiable es el programa

-   Hay un método llamado fault seeding en el cual se agregan fallos al
    código para encontrar errores adicionales que se encuentran al hacer
    los tests

-   Se mide el mutation score al hacer Mutation Testing, que es el ratio
    de mutantes detectados a mutantes generados

### Test Process

Todo lo anterior debe ser integrado a un proceso de testing bien
definido

-   Se debe dejar de por lado el que alguien hizo el código, y enfocarse
    en arreglar lo que causa problemas

-   El cómo se va a manejar el proceso de testing debería ser
    documentado claramente

-   Se puede tener un equipo de testing separado de los desarrolladores
    para que no haya bias de algún tipo, o se puede hacer por los mismos
    desarrolladores

-   Se usan medidas como las que fueron mencionadas en la sección
    anterior para mejorar la eficiencia del proceso

-   Se debe tener bien definido el punto en el cual el testing es
    suficiente, porque si no realmente puede llegar a ser casi infinito

-   El ambiente de testing debería estar bien integrado con el resto del
    proyecto

-   Los defectos deberían estar documentados de igual manera

### Software Testing Tools

Ya que el testing es una labor que, si se hace de manera manual toma
muchísimo tiempo, hay herramientas que hacen esto mucho menos tedioso

Existen múltiples herramientas hechas para esto:

-   **Test harnesses**\
    Estos son environments en los que las pruebas son hechas y los
    resultados son guardados

-   **Test generators**\
    Estos generan casos de pruebas basados en técnicas o mezclas de
    estas

-   **Capture/replay tools**\
    Estas son programas que dejan inspeccionar casos de prueba
    especificos con más detalle

-   **Oracle/file comparators/assertion checking tools**\
    Checan que un test sea correcto o no

-   **Coverage analyzers and instrumenters**\
    Estas herramientas ven que tanto porcentaje del programa se usa y lo
    comparan con el porcentaje esperado

-   **Tracers**\
    Ven que camino tomo el programa en un caso de prueba

-   **Regression testing tools**\
    Ejecutan un test suite después de modificar una sección de código
    para asegurarse de que no rompió el programa

-   **Reliability evaluation tools**\
    Son herramientas para evaluar medidas de confiabilidad del software
    recabadas y visualizarlas de una manera más sencilla

Conclusión
----------

Después de haber hecho la lectura me doy cuenta de que el proceso entero
detrás de la creación de un programa bueno es mucho más grande de lo que
uno normalmente pensaría cuando lo ves desde el aspecto de un
desarrollador. Normalmente cuando uno tiene una idea de un programa o
cosa que suena interesante de hacer uno se pone directo a programar, sin
dar mucho énfasis a la planeación, pruebas o diseño en sí, todo pura
construcción; y no es que sea malo en sí, mucha gente le gusta el
aspecto de la programación, pero después de leer esto me doy cuenta de
que hacer la planeación tiene un efecto tremendo en el resultado final.
Es realmente comparable a hacer una casa de troncos en el bosque contra
una casa bien planeada; puede que la casa de troncos si sirva para
dormir y taparte de la lluvia y animales salvajes, pero al momento de
querer expandir o que tenga cosas mínimamente complejas como cableado o
cosas por el estilo, la conveniencia de ser más fácil de construir se
derrumba ya que no puedes hacer realmente nada sin hacer un destrozo de
la casa; o mínimo, así lo percibo yo.

### Respuesta a la pregunta

Lo que más me llamo la atención de la lectura fue la sección de testing
ya que es un área que sabía que existía, pero no había investigado
realmente como se hacía o nada por el estilo, y el aprender cosas nuevas
me gusta bastante, así que probablemente es una de las cosas que más me
llamo la atención de la lectura. también se me hizo bastante interesante
el que hubiera matemáticas en lugares inesperados en secciones que no
tenía ni idea que podría estar, como la parte de generación de casos de
prueba.
