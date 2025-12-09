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

<img width="703" height="274" alt="image" src="https://github.com/user-attachments/assets/2e25650b-670f-4079-9e50-e99f3d53f39d" />


