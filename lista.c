#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
 
/* Documentacion de las funciones primitivas de la lista dentro de lista.h*/

lista_t* lista_crear()
{
    lista_t * lista = malloc(sizeof(lista_t));
    lista->nodo_inicio = NULL;
    lista->nodo_fin = NULL;
    lista->cantidad = 0;

    if (!lista) return NULL;
                
    return lista;
}

int lista_insertar(lista_t* lista, void* elemento)
{   
    if (!lista) return -1; 
    nodo_t * nodo = malloc(sizeof(nodo_t));
    if (!nodo) return -1;
    nodo->elemento = elemento;
    nodo->siguiente = NULL;
    if (lista->nodo_inicio == NULL)
    {
        lista->nodo_inicio = nodo;
        lista->nodo_fin = nodo;
    } 
    else
    {
        lista->nodo_fin->siguiente = nodo;
        lista->nodo_fin = nodo;
    }
    lista->cantidad++;
    return 0;
}

/* Recibe una lista y un elemento a agregar. Si es posible agregar el elemento al principio de la lista, devuelve 0. 
Caso contrario devuelve -1.*/
int lista_insertar_primero(lista_t* lista, void* elemento)
{   
    if (!lista) return -1;
    nodo_t * nodo_nuevo = malloc(sizeof(nodo_t));
    if (!nodo_nuevo) return -1;
    nodo_nuevo->elemento = elemento;
    nodo_nuevo->siguiente = lista->nodo_inicio;
    lista->nodo_inicio = nodo_nuevo;
    lista->cantidad++;
    return 0;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento , size_t posicion)
{   
    if ( (!lista) ) return -1;
    if ( posicion >= lista->cantidad ) lista_insertar(lista, elemento);
    else if (posicion == 0) lista_insertar_primero(lista, elemento);
    else
    {   
        nodo_t * nodo_nuevo = malloc(sizeof(nodo_t));
        if (!nodo_nuevo) return -1;
        nodo_nuevo->elemento = elemento;
        nodo_nuevo->siguiente = NULL;
        int i = 0;
        nodo_t * nodo_indice = lista->nodo_inicio;
        while (i < posicion - 1)
        {   
            nodo_indice = nodo_indice->siguiente;
            i++;
        }
        nodo_nuevo->siguiente = nodo_indice->siguiente;
        nodo_indice->siguiente = nodo_nuevo;
        lista->cantidad++;
    }
    
    return 0;
}
/* Recibe una lista. Si es posible eliminar el elemento al principio de la lista, devuelve 0. 
Caso contrario devuelve -1.*/
void lista_borrar_primero(lista_t* lista)
{   
    if ( (!lista) || (!lista->nodo_inicio) || (!lista->nodo_fin) || (!lista->cantidad) || (lista->cantidad == 0) ) return;
    nodo_t * nodo_borrar = lista->nodo_inicio;
    if (nodo_borrar->siguiente != NULL) lista->nodo_inicio = nodo_borrar->siguiente;
    if (nodo_borrar == lista->nodo_fin)
    {   
        lista->nodo_inicio = NULL; 
        lista->nodo_fin = NULL;
    }
    free(nodo_borrar);
    lista->cantidad--;
}

int lista_borrar(lista_t* lista)
{   
    if ( (!lista) || (!lista->nodo_fin) || (!lista->nodo_inicio) || (!lista->nodo_fin) || (lista->cantidad == 0) || (!lista->cantidad) ) 
    return -1;
    
    if (lista->cantidad == 1) lista_borrar_primero(lista);
    else
    {
        nodo_t * nodo_indice = lista->nodo_inicio;
        while (nodo_indice->siguiente != lista->nodo_fin)
        {
            nodo_indice = nodo_indice->siguiente;
        }
        nodo_t * nodo_borrar = nodo_indice->siguiente;
        free(nodo_borrar);
        nodo_indice->siguiente = NULL;
        lista->nodo_fin = nodo_indice;
        lista->cantidad--;
    }
    return 0;
}   

int lista_borrar_de_posicion(lista_t* lista, size_t posicion)
{   
    if ( (!lista) || (!lista->cantidad) || (!lista->nodo_inicio) || (!lista->nodo_fin ) || (lista->cantidad == 0) ) return -1;
    if (posicion == 0) lista_borrar_primero(lista);
    else if (posicion >= lista->cantidad) lista_borrar(lista);
    else
    {
        int i = 0;
        nodo_t * nodo_indice = lista->nodo_inicio;
        while (i < posicion - 1)
        {   
            nodo_indice = nodo_indice->siguiente;
            i++;
        }
        nodo_t * nodo_borrar = nodo_indice->siguiente;
        nodo_indice->siguiente = nodo_borrar->siguiente;
        if (nodo_borrar == lista->nodo_fin) lista->nodo_fin = nodo_indice;
        free(nodo_borrar);
        lista->cantidad--;
    }
    return 0;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion)
{   
    if ( (!lista) || (lista->cantidad == 0 ) || (posicion >= lista->cantidad) || (!lista->nodo_inicio) ) return NULL;
    void * elemento;
    size_t i = 0;
    nodo_t * nodo_indice = lista->nodo_inicio;
    while (i < posicion)
    {
        nodo_indice = nodo_indice->siguiente;
        i++;
    }
    elemento = nodo_indice->elemento;
    return elemento;
}

void* lista_ultimo(lista_t* lista)
{   
    if ((!lista) || (!lista->nodo_fin) || (!lista->nodo_fin->elemento)) return NULL;
    return(lista->nodo_fin->elemento);
}

bool lista_vacia(lista_t* lista)
{   
    if ( (!lista) ) return true;
    return (lista->cantidad == 0);
}

size_t lista_elementos(lista_t* lista)
{   
    if ( (!lista) || (!lista->cantidad) ) return 0;
    return (lista->cantidad);
}

void lista_destruir(lista_t* lista)
{   
    if (!lista) return;
    if (lista->cantidad > 0)
    {
        nodo_t * nodo_borrar;
        nodo_t * nodo_indice = lista->nodo_inicio;
        while (nodo_indice->siguiente)
        {  
            nodo_borrar = nodo_indice;
            nodo_indice = nodo_indice->siguiente;
            free(nodo_borrar);
        }
        free(nodo_indice); 
    }
    free(lista); return;
}

int lista_apilar(lista_t* lista, void* elemento)
{   
    if ( (!lista) ) return -1;
    lista_insertar(lista, elemento); return 0;
}

int lista_desapilar(lista_t* lista)
{
    if ( (!lista) || (lista->cantidad == 0) ) return -1;
    lista_borrar(lista); return 0;
}

void* lista_tope(lista_t* lista)
{   
    if ( (!lista) || (!lista->nodo_fin) || (!lista->nodo_fin->elemento) ) return NULL;
    return(lista->nodo_fin->elemento);
}

int lista_encolar(lista_t* lista, void* elemento)
{   
    if ( (!lista) ) return -1;
    lista_insertar(lista, elemento); return 0;
}

int lista_desencolar(lista_t* lista)
{   
    if ( (!lista) || (lista->cantidad == 0) ) return -1;
    lista_borrar_primero(lista); return 0;
}

void* lista_primero(lista_t* lista)
{   
    if ((!lista) || (!lista->nodo_inicio)) return NULL; // || (!lista->nodo_inicio->elemento)
    return(lista->nodo_inicio->elemento);
}

lista_iterador_t* lista_iterador_crear(lista_t* lista)
{   
    if (!lista) return NULL;
    lista_iterador_t* iterador = malloc(sizeof(lista_iterador_t));
    if (!iterador) return NULL;
    iterador->lista = lista;
    iterador->corriente = lista->nodo_inicio;
    return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador)
{   
    if ( ( !iterador) ) return false;
    return(iterador->corriente != NULL);
}

bool lista_iterador_avanzar(lista_iterador_t* iterador)
{   
    if ( ( !iterador) || (!iterador->corriente) ) return false;
    iterador->corriente = iterador->corriente->siguiente;
    if (!iterador->corriente) return false;
    return true;
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador)
{   
    if ( ( !iterador) || (!iterador->corriente) || (!iterador->corriente->elemento) ) return NULL;
    void * elemento = iterador->corriente->elemento; return elemento;
}
void lista_iterador_destruir(lista_iterador_t* iterador)
{   
    free(iterador); return;
}
size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto)
{
    if ( (!lista) || (!lista->nodo_inicio) || (!funcion) ) return 0;
    nodo_t * nodo_indice = lista->nodo_inicio;
    size_t contador = 1;
    while( (funcion(nodo_indice->elemento, contexto)) && (nodo_indice->siguiente) )
    {   
        nodo_indice = nodo_indice->siguiente;
        contador++;
    }
    return contador;
}