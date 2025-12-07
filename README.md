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
