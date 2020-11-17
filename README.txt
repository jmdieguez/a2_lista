                                   TDA LISTA / ALGORITMOS 2 / CÁTEDRA MÉNDEZ / 2020 2C

                                                    /  Introducción  /

El trabajo presentado se trata de una implementacion de una lista simplemente enlazada. Siguiendo las estructuras y primitivas
brindadas por el archivo de cabecera "lista.h", desarrollé las funciones necesarias para poder insertar, eliminar, y analizar los 
elementos de dicha lista. También se busca implementar pilas y colas (otros tipos de datos abstractos) en la lista.

                                                    / Compilacion  /

Para compilar el programa se deberá acceder a la carpeta del programa dentro de la terminal con ayuda del comando cd, el cual nos
permite desplazarnos en los ficheros del equipo.

Una vez en la carpeta, hay que correr la siguiente línea en la terminal:

1 gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Esto nos permitirá compilar el programa y crearnos un ejecutable llamado “lista_se”

Para ejecutar el programa hay que correr la siguiente línea (puede variar según el sistema operativo):

 ./lista_se

(Adicional) Para ver detalles de uso de memoria con valgrind, usar la siguiente linea: 
valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se

                                                    / Conceptos /

Lista: Una lista es una estructura de datos secuencial cuyos espacios de memoria no son necesariamente contiguos. La diferencia entre
una lista simplemente enlazada y una doblemente enlazada es que en la primera, cada nodo (osea, cada elemento perteneciente a la lista),
posee la referencia hacia la direccion de memoria del siguiente elemento (el último elemento apunta a NULL, asi es como nos damos cuenta 
de que llegamos al final). Mientras que la lista doblemente enlazada, funciona de forma similar, aunque adicionalmente, cada elemento 
también posee una referencia hacia la dirección de memoria de su anterior (el anterior del primero apunta a NULL).

Pilas y colas: Son estructuras de datos similares a la lista. Difieren en que tienen un protocolo de entrada-salida preestablecido. En las 
pilas, el último elemento en ingresar, es el primero que tiene que salir (LIFO - last in, first out) a este elemento lo llamamos "tope", 
y es al dato que tenemos acceso. Mientras que en las colas, el primer elemento en ingresar, es el primero en salir (FIFO - first in,
first out). 
 
Iteradores: Un iterador es una variable puntero que nos ayuda a recorrer los elementos de una estructura. Su función, segun es interno
o externo, es o bien aplicarle una función a cada elemento de la lista mientras se cumpla una condición, o simplemente devolvernos dicho 
elemento.

----------------------------------------------------------------------------------------------------------------------------------------------
                     
                                                Manuel Dieguez –  106146
