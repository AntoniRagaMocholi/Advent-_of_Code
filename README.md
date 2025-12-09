COMENTARIO A_O_C_DIA_2

En este segundo día nos piden crear un programa que sea capaz de leer un archivo en el que hay intervalos de números, de forma que identifique los números inválidos dentro de los rangos. 
Primero se crea una estructura que contenga el vector con los dos números dados del intervalo, que representan el inicio y el final.

<img width="223" height="120" alt="image" src="https://github.com/user-attachments/assets/959322ad-4ca7-4fbd-a42f-6da0dd9f77cb" />

En segundo lugar se crea la función encargada de parsear los rangos, es decir, convertir los intervalos dados con guión, en intervalos representados con una "," (es decir por un vector).

<img width="734" height="877" alt="image" src="https://github.com/user-attachments/assets/335681e6-dd82-43be-9378-06d140f2525e" />

En tercer lugar, la función esInvalido, verifica si los números del intervalo cumplen los requisitos para ser considerados inválidos.

<img width="426" height="313" alt="image" src="https://github.com/user-attachments/assets/acbb6eaf-2fd1-45e9-a24a-67a2f2deb247" />

Por último en el main se gestiona la apertura y cierre del archivo que posee los rangos, además de leer las líneas. Llama a la función parsear rangos para convertir la línea en un vector de la estructura "Rango".
Itera cada número que contienen los rangos y en caso de detectar que es inválido, almacena en la variable sumaInválidos la suma de los valores inválidos.

<img width="772" height="331" alt="image" src="https://github.com/user-attachments/assets/f9ddb443-3aa3-4e75-9d18-8c246a43ffca" />

Para la parte dos del problema, se modifica la función esInvalido, de manera que se incluyen números que previamente con eran inválidos, puesto que los requisitos cambian y ahora pasan a considerarse como tal.

<img width="515" height="515" alt="image" src="https://github.com/user-attachments/assets/935c0717-8944-47be-bf15-1b17f6c5711e" />

Ahora las secuencias de números que se repitan como mínimo dos veces serán consideradas como inválidas.

COMENTARIO A_O_C_DIA_4

En el cuarto día nos piden crear un programa que lea un archivo que contiene secuenciuas de '.' y '@' donde las arrobas son rollos de papel. El programa te deberá indicar cuantos rollos son accesibles, siendolo estos cuando tienen menos de 4 arrobas en las 8 casillas adyacentes.
Primero creamos una funcion que se encarga de contar cuantas arrobas adyacentes tiene una casilla en concreto y devuelve este número.

<img width="740" height="324" alt="image" src="https://github.com/user-attachments/assets/0a355e71-ec21-4cfb-9c2f-8220f571771c" />

Ahora leemos el archivo desde la entrada estándar y lo guardamos como una matriz de carácteres.

<img width="406" height="154" alt="image" src="https://github.com/user-attachments/assets/e777bbaa-efbc-478c-80e8-61f758eabf03" />

Finalmente calculamos cuantas filas y columnas tiene el archivo, lo recorremos entero y sumamos 1 a la variable NumX por cada '@' que no este rodeado por 4 o mas arrobas para luego imprimir por pantalla el numero de rollos de papel accesibles.

<img width="676" height="361" alt="image" src="https://github.com/user-attachments/assets/06409c9f-026b-41c6-b8c7-be1736fa9808" />

En la segunda parte nos piden que eliminemos los rollos accesibles y volvamos a recorrer el archivopara elminiar los rollos que se vuelvan accesibles tras eliminar los accesibles anteriores.
Aqui creamos una funcion que se encarga de contar cuantos son accesibles y sustituirlos por 'X'.

<img width="703" height="274" alt="image" src="https://github.com/user-attachments/assets/2e25650b-670f-4079-9e50-e99f3d53f39d" />

Ahora el programa se encarga de sumar a una variable total el numero de rollos que va eliminando la funcion anterior, hasta que esta no detecte ningun rollo más, que es cuando el programa te muestra el numero de rollos totales por pantalla y acaba.

<img width="567" height="266" alt="image" src="https://github.com/user-attachments/assets/79a62c9a-c14f-43dd-8210-08552a0f1a91" />


COMENTARIO A_O_C_DIA_7

Estas 3 funciones son las más sencillas de este ejercicio, y se encargan de encontrar la columna en la que se sitúa S, comporbar si una posición (fila, columna) están dentro del rango y por último leer el archivo "input.txt" en el que está el ejemplo sobre el que trabajar.

<img width="682" height="150" alt="image" src="https://github.com/user-attachments/assets/d53946a2-bce1-4541-98a4-8c6a884bdda7" />


Esta función lo que hace es tomar una posición del mapa y devolver un vector con las coordenadas donde se dirigirá el haz de luz. Devolverá unas posiciones u otras dependiendo de lo que encientre por el camino que puede ser '.', '^' o 'S' (siempre y cuando estén dentro del rango).

<img width="806" height="857" alt="image" src="https://github.com/user-attachments/assets/c6fd4960-c16a-4e81-a08c-469263672cf9" />

La siguiente función se encarga de realizar la primera parte del ejercicio, devolver el número de divisones que se produce sobre el rayo, recorriendo el mapa como un grafo. Visitado es la matriz que se encarga de marcar qué celdas ya se procesaron para no contar doble. q es la cola para el recorrido y el int divisiones el contador de divisores (splitters) encontrados.

<img width="788" height="894" alt="image" src="https://github.com/user-attachments/assets/7fb70d1d-d3d8-4bf0-b6b0-de28274d2706" />

El bucle BFS, mientras hayan nodos en la cola saca la posición o en caso de estar visitada la salta. Marca como visitada y si encontramos splitter incrementa el contador ("divisiones").
Mediante la función vecinos se decide dónde ir en el siguiente movimiento. 

<img width="787" height="634" alt="image" src="https://github.com/user-attachments/assets/30d395c4-7bd0-4ef9-ad58-3d75f7b98498" />

La última función relevante es contarTimelines, usada para la segunda parte. Esta lo que hace es mediante uso de memoria y recursividad, cuenta los posibles caminos del rayo. 

El resto son llamadas a estas funciones para que se ejecuten (main y resolver_problema).


COMENTARIO A_O_C_DIA_5

En primer lugar el código almacena en el vector de estructuras de tipo Rango los valores que se encuentran en el archivo mediante la variablñe linea hasta que este se encuentre con la línea vacía, ademas de que en la variable nrangos se sume continuamente cada vez que se modifica el vector para llevar el recuento de rangos.

<img width="760" height="770" alt="image" src="https://github.com/user-attachments/assets/12d418b6-f9eb-4e88-ae23-f5c8ca3c14ff" />


Tras esto y por último en este código usaremos una función que guarda el valor contenido en el archivo, y mediante un bucle comprueba si el numero se encuentra en algun rango de los ya guardados, en este caso la variable llamada esFresco sera true y si esto sucede significa que el valor se encuentra en alguno de los rangos sumando así en una unidad el recuento de alimentos frescos.
<img width="814" height="584" alt="image" src="https://github.com/user-attachments/assets/9df2455c-ae4f-42e6-937e-2eb221be7ba1" />


