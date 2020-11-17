#include "lista.h"
#include "pa2m.h"

bool elemento_no_null(void* elemento, void* contador){
    if(!contador || !elemento) return false;
    return true;
}

void probar_creacion_lista(){
    lista_t* lista = NULL;

    pa2m_afirmar((lista=lista_crear()) != NULL, "Puedo crear una lista");
    pa2m_afirmar(lista_vacia(lista), "La lista se crea vacia");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista tiene 0 elementos");
    pa2m_afirmar(lista_primero(lista) == NULL, "El nodo inicial de la lista apunta a NULL");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El nodo final de la lista apunta a NULL");
    lista_destruir(lista);
}

void probar_insercion_lista_invalida()
{
    pa2m_afirmar( lista_insertar(NULL, NULL) == -1, "No puedo insertar elementos al final de una lista nula");
    pa2m_afirmar( lista_insertar_en_posicion(NULL, NULL, 0) == -1, "No puedo insertar elementos al principio de una lista nula");
    pa2m_afirmar( lista_insertar_en_posicion(NULL, NULL, 2) == -1 , "No puedo insertar elementos en una posicion arbitraria de una lista nula");
    pa2m_afirmar( lista_elemento_en_posicion(NULL, 3) == NULL , "Pedir un elemento de una posicion arbitraria a una lista nula devuelve NULL");
    lista_t* lista = lista_crear();
    pa2m_afirmar( lista_elemento_en_posicion(lista, 3) == NULL , "Pedir un elemento de una posicion arbitraria a una lista vacia devuelve NULL");
    lista_destruir(lista);
}

void probar_insercion_lista()
{   
    lista_t* lista = lista_crear();
    char a='a', b='b', c='c', d='d', e='e', f='f';
        
    int exito_1 = lista_insertar(lista, &c);
    int exito_2 = lista_insertar(lista, &d);
    int exito_3 = lista_insertar(lista, &e);

    pa2m_afirmar( ((exito_1 == 0) && (exito_2 == 0) && (exito_3 == 0)), "Puedo insertar 3 elementos al final de la lista");
    pa2m_afirmar( (lista_elemento_en_posicion(lista, 0) == &c ) && (lista_elemento_en_posicion(lista, 1) == &d ) &&
    (lista_elemento_en_posicion(lista, 2) == &e ), "Los elementos se posicionaron de forma correcta");
    pa2m_afirmar(!lista_vacia(lista), "La lista no se encuentra vacia");
    pa2m_afirmar(lista_elementos(lista) == 3, "La cantidad de elementos en la lista es la esperada");
    
    exito_1 = lista_insertar_en_posicion(lista, &b, 0);
    exito_2 = lista_insertar_en_posicion(lista, &f, 55);
    exito_3 = lista_insertar_en_posicion(lista, &a, 0);

    pa2m_afirmar( ((exito_1 == 0) && (exito_2 == 0) && (exito_3 == 0)), "Puedo insertar 3 elementos en posiciones arbitrarias");
    pa2m_afirmar( (lista_elemento_en_posicion(lista, 0) == &a ) && (lista_elemento_en_posicion(lista, 1) == &b ) &&
    (lista_elemento_en_posicion(lista, 5) == &f ), "Los elementos se posicionaron de forma correcta");
    pa2m_afirmar(lista_elementos(lista) == 6, "La cantidad de elementos en la lista es la esperada");
    
    lista_destruir(lista);
    
}

void probar_borrar_lista_invalida()
{
    pa2m_afirmar( lista_borrar(NULL) == -1, "No puedo borrar un elemento al final de una lista nula");
    pa2m_afirmar( lista_borrar_de_posicion(NULL, 0) == -1, "No puedo borrar un elemento al principio de una lista nula");
    pa2m_afirmar( lista_borrar_de_posicion(NULL, 4) == -1, "No puedo borrar un elemento de una posicion arbitraria de una lista nula");

    lista_t* lista = lista_crear();
    
    pa2m_afirmar( lista_borrar(lista) == -1, "No puedo borrar un elemento al final de una lista vacia");
    pa2m_afirmar( lista_borrar_de_posicion(NULL, 0) == -1, "No puedo borrar un elemento al principio de una lista vacia");
    pa2m_afirmar( lista_borrar_de_posicion(lista, 4) == -1, "No puedo borrar un elemento de una posicion arbitraria de una lista vacia");

    lista_destruir(lista);
}

void probar_borrar_lista()
{   
    lista_t * lista = lista_crear();
    char a='a', b='b', c='c', d='d', e='e', f='f';
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);
    lista_insertar(lista, &e);
    lista_insertar(lista, &f);

    pa2m_afirmar( lista_borrar(lista) == 0, "Puedo borrar un elemento al final de una lista");
    pa2m_afirmar( lista_borrar_de_posicion(lista, 0) == 0, "Puedo borrar un elemento al principio de una lista");
    pa2m_afirmar( lista_borrar_de_posicion(lista, 3) == 0, "Puedo borrar un elemento en una posicion arbitraria de la lista");
    pa2m_afirmar( lista_elementos(lista) == 3, "La cantidad de elementos en la lista es la correcta");
    pa2m_afirmar( lista_elemento_en_posicion(lista, 0) == &b, "El primer elemento de la lista es el correcto");
    pa2m_afirmar( lista_elemento_en_posicion(lista, 1) == &c, "El segundo elemento de la lista es el correcto");
    pa2m_afirmar( lista_ultimo(lista) == &d, "El ultimo elemento de la lista es el correcto");
    pa2m_afirmar( (lista_borrar(lista) == 0) && (lista_borrar(lista) == 0) && (lista_borrar(lista) == 0), "Puedo borrar todos los elementos borrando siempre el ultimo");
    pa2m_afirmar( lista_vacia(lista), "La lista ahora se encuentra vacia");

    lista_destruir(lista);
}

void probar_cola()
{   
    char* a = "a";
    pa2m_afirmar(!lista_primero(NULL), "El primer elemento de una cola nula es NULL");
    pa2m_afirmar(lista_desencolar(NULL) == -1, "No puedo desencolar de una cola nula");
    lista_t* cola = lista_crear();
    pa2m_afirmar(!lista_primero(cola), "El primer elemento de una cola vacia es NULL");
    pa2m_afirmar(lista_desencolar(cola) == -1, "No puedo desencolar de una cola vacia");
    pa2m_afirmar(lista_encolar(cola, &a) == 0, "Puedo encolar de una cola vacia");
    pa2m_afirmar(!lista_vacia(cola), "La cola ya no esta vacia");
    pa2m_afirmar(lista_elementos(cola) == 1, "La cola tiene la capacidad correcta");
    pa2m_afirmar(lista_encolar(cola, NULL) == 0, "Puedo encolar otro elemento en la cola");
    pa2m_afirmar(lista_elementos(cola) == 2, "La cola tiene la capacidad correcta");
    pa2m_afirmar(lista_encolar(cola, NULL) == 0, "Puedo encolar otro elemento en la cola");
    pa2m_afirmar(lista_elementos(cola) == 3, "La cola tiene la capacidad correcta");
    pa2m_afirmar(lista_primero(cola) == &a, "El primero de la cola es el correcto");
    pa2m_afirmar(lista_desencolar(cola) == 0, "Puedo deencolar un elemento en la cola");
    pa2m_afirmar(lista_desencolar(cola) == 0, "Puedo deencolar otro elemento en la cola");
    pa2m_afirmar(lista_desencolar(cola) == 0, "Puedo deencolar otro elemento en la cola");
    pa2m_afirmar(lista_vacia(cola), "La cola esta vacia");
    lista_destruir(cola);
}
void probar_pila()
{   
    char* a = "a";
    pa2m_afirmar(!lista_tope(NULL), "El tope de una cola nula es NULL");
    pa2m_afirmar(lista_desapilar(NULL) == -1, "No puedo desapilar de una pila nula");
    lista_t* pila = lista_crear();
    pa2m_afirmar(!lista_tope(pila), "El tope de una cola vacia es NULL");
    pa2m_afirmar(lista_desapilar(pila) == -1, "No puedo desapilar de una pila vacia");
    pa2m_afirmar(lista_apilar(pila, NULL) == 0, "Puedo apilar de una pila vacia");
    pa2m_afirmar(!lista_vacia(pila), "La pila ya no esta vacia");
    pa2m_afirmar(lista_elementos(pila) == 1, "La pila tiene la capacidad correcta");
    pa2m_afirmar(lista_apilar(pila, NULL) == 0, "Puedo apilar otro elemento");
    pa2m_afirmar(lista_elementos(pila) == 2, "La pila tiene la capacidad correcta");
    pa2m_afirmar(lista_apilar(pila, &a) == 0, "Puedo apilar otro elemento");
    pa2m_afirmar(lista_elementos(pila) == 3, "La pila tiene la capacidad correcta");
    pa2m_afirmar(lista_tope(pila) == &a, "El tope de la pila es el correcto");
    pa2m_afirmar(lista_desapilar(pila) == 0, "Puedo desapilar un elemento");
    pa2m_afirmar(lista_desapilar(pila) == 0, "Puedo desapilar un elemento");
    pa2m_afirmar(lista_desapilar(pila) == 0, "Puedo desapilar un elemento");
    pa2m_afirmar(lista_vacia(pila), "La pila esta vacia");
    lista_destruir(pila);
}

void probar_iterador_externo()
{   
    pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL , "El elemento actual de un iterador NULL es NULL");
    pa2m_afirmar(!lista_iterador_tiene_siguiente(NULL), "Un iterador NULL no tiene siguiente");
    pa2m_afirmar(!lista_iterador_avanzar(NULL), "Un iterador null no puede avanzar");
    
    lista_t* lista = lista_crear();

    lista_iterador_t* it_e = lista_iterador_crear(lista);
    pa2m_afirmar(it_e != NULL, "Puedo crear un iterador externo con una lista vacia");
    pa2m_afirmar(lista_iterador_elemento_actual(it_e) == NULL , "El elemento actual de un iterador de lista vacía es NULL");
    pa2m_afirmar(!lista_iterador_tiene_siguiente(it_e), "El iterador de una lista vacía no tiene siguiente");
    pa2m_afirmar(!lista_iterador_avanzar(it_e), "El iterador de una lista vacía no puede avanzar");

    lista_iterador_destruir(it_e);

    char letras[] = {'a', 'b', 'c', 'd', 'w', 'j'};
    lista_insertar(lista, &letras[0]);
    lista_insertar(lista, &letras[1]);
    lista_insertar(lista, &letras[2]);
    lista_insertar(lista, &letras[3]);
    lista_insertar(lista, &letras[4]);
    lista_insertar(lista, &letras[5]);
    
    
    lista_iterador_t* it = lista_iterador_crear(lista);
    pa2m_afirmar(it != NULL , "Puedo crear un iterador externo con una lista con elementos");
    int iteraciones = 0;
    for(int i = 0 ; i < 5 ; i++)
    {   
        pa2m_afirmar(lista_iterador_elemento_actual(it) == &letras[i] , "Recorro un elemento con el iterador y es el correcto");
        pa2m_afirmar(lista_iterador_tiene_siguiente(it) , "El iterador de la lista tiene siguiente");
        pa2m_afirmar(lista_iterador_avanzar(it) , "El iterador puede avanzar");
        iteraciones++;
    }
        pa2m_afirmar(lista_iterador_elemento_actual(it) == &letras[iteraciones] , "Recorro un elemento con el iterador y es el correcto");
        pa2m_afirmar(!lista_iterador_avanzar(it) , "El iterador no puede avanzar en el ultimo elemento");
        iteraciones++;
    
    pa2m_afirmar(iteraciones == sizeof(letras)/sizeof(char), "Se iteran la cantidad de elementos correcta en la lista");
        
    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void probar_iterador_interno()
{   
    lista_t* lista = lista_crear();
    char letras[] = {'a', 'b', 'c', 'd', 'w', 'j'};
    lista_insertar(lista, &letras[0]);
    lista_insertar(lista, &letras[1]);
    lista_insertar(lista, &letras[2]);
    lista_insertar(lista, &letras[3]);
    lista_insertar(lista, NULL);
    lista_insertar(lista, &letras[5]);

    int contador=0;
    pa2m_afirmar(lista_con_cada_elemento(lista, NULL, (void*)&contador) == 0, "No puedo iterar una lista sin una funcion para el iterador");
    
    size_t elementos_recorridos = 0;
    elementos_recorridos = lista_con_cada_elemento(lista, elemento_no_null, (void*)&contador);
    
    pa2m_afirmar(elementos_recorridos == 5, "Se iteran la cantidad de veces correcta");

    lista_destruir(lista);
    
}
int main()
{
    pa2m_nuevo_grupo("PRUEBAS DE CREACION");
    probar_creacion_lista();
    pa2m_nuevo_grupo("PRUEBAS DE INSERCION: LISTA VALIDA");
    probar_insercion_lista();
    pa2m_nuevo_grupo("PRUEBAS DE INSERCION: LISTA INVALIDA");
    probar_insercion_lista_invalida();
    pa2m_nuevo_grupo("PRUEBAS DE BORRADO: LISTA VALIDA");
    probar_borrar_lista();
    pa2m_nuevo_grupo("PRUEBAS DE BORRADO: LISTA INVALIDA");
    probar_borrar_lista_invalida();
    pa2m_nuevo_grupo("PRUEBAS DE PILA");
    probar_pila();
    pa2m_nuevo_grupo("PRUEBAS DE COLA");
    probar_cola();
    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR EXTERNO");
    probar_iterador_externo();
    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR INTERNO");
    probar_iterador_interno();

    pa2m_mostrar_reporte();
}
