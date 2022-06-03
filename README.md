# T2_Automatas

Programa que genere el Lenguaje (es decir, el conjunto de cadenas) de los Identificadores de un cierto
Lenguaje de Programación que aquí llamaremos Lenguaje X usando uno o varios alfabetos, los Lenguajes elementales y
las operaciones de las Expresiones Regulares.

Los Identificadores son las cadenas con las que nombramos las variable o constantes de un programa
(ejemplos: a2=10, b6="abanico", Pi=3.1459 etc). El Lenguaje X admite nombres de Identificadores que forzosamente
empiecen con una letra seguida de números o letras. Se generarán cadenas del tipo a11, ab11, z44... etc.

Ejecución.

Al inicio el programa muestra una bienvenida sencilla, donde solo es cuestión de escribir 1 para iniciar el programa o escribir 2 para terminar su ejecución.
Una vez que se escribe 1 pasa a lo que es la realización de la tarea:

![image](https://user-images.githubusercontent.com/72325257/171806979-c8c02a83-b106-4557-b4ca-19910b5bbfba.png)

Como se puede ver en la imagen anterior, imprimo lo que es el alfabeto que use y posteriormente los lenguajes elementales que lo conforman. Cabe mencionar que todo 
fue hecho de manera dinámica usando el código ASCII.

![image](https://user-images.githubusercontent.com/72325257/171807099-e3b1a2b9-ae43-442c-ba7e-f328f4dc1d8f.png)

En esta siguiente captura se puede observar que imprimo la selección entre alternativas y 
el resultado de los lenguajes de como quedan separándolos en un lenguaje para el 
abecedario (sin la ñ) y otro para números. Posteriormente pido al usuario que escriba 
hasta que número se harán las potencias en la Cerradura de Kleene. Aquí recomiendo no 
pasar de una potencia 3, ya que, como se puede observar si se hicieran potencias más 
grandes y debido a la longitud del alfabeto y de los lenguajes, querer hacer una potencia 
muy grande sería un resultado enorme que tal vez no podría realizar el equipo con el que 
se trabaja y además hay que decir que el resultado final que se espera aún es muy grande. 
Como yo lo hice para estas capturas ingrese la potencia de 1, la cual me da como 
resultado la cadena vacía en unión con la cadena original -> L* = L^0 U L^1.

Para terminar esta parte imprimo el resultado de aplicar dicha operación a los lenguajes del abecedario y de los números que obtuve del alfabeto.

![image](https://user-images.githubusercontent.com/72325257/171807221-f879d9f4-ea68-4068-88f8-04fc68b9b565.png)

En esta captura se puede observar que imprimo el resultado de aplicar la concatenación al 
lenguaje del abecedario con el resultado de aplicar la Cerradura de Kleene.

Posteriormente imprimo el Lenguaje X (resultado final) que no es más que la 
concatenación del resultado que se habla en el párrafo anterior con el resultado de aplicar 
la Cerradura de Kleene al lenguaje de los números. Este es el resultado buscado del 
lenguaje de los Identificadores.

Como se puede observar, todo está debidamente comentado para su buena apreciación
