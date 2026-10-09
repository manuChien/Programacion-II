#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

struct _lista_estatica
{
    SLIST_ELEMENT datos[MAX_PILA];
    int cantidad;
};

lista_estatica* slist_crearLista(void)
{
    lista_estatica* nuevaSLista = malloc(sizeof(lista_estatica));
    if(!nuevaSLista)
    {
        return NULL;
    }

    nuevaSLista->cantidad = 0;

    return nuevaSLista;
}

SLIST_ELEMENT slist_append(lista_estatica* lista, SLIST_ELEMENT element)
{
    if(!lista) return -1;

    lista->datos[lista->cantidad] = element;
    (lista->cantidad)++;

    return element;
}

SLIST_ELEMENT slist_insert(lista_estatica* lista, SLIST_ELEMENT elemento, int i)
{
    if(!lista) return -1;
    if(i<0 || i>lista->cantidad || lista->cantidad == MAX_PILA) return -1;

    int j = lista->cantidad;
    while(j>i)
    {
        lista->datos[j] = lista->datos[j-1];
        j--;
    }
    lista->datos[i] = elemento;
    (lista->cantidad)++;

    return elemento;
}

int slist_first(lista_estatica* lista)
{
    if(!lista || lista->cantidad==0) return -1;

    return 0;
}

int slist_next(lista_estatica* lista, int posicion)
{
    return posicion + 1;
}

int slist_eol(lista_estatica* lista, int posicion)
{
    if (!lista) return 1;
    return posicion >= lista->cantidad;
}

SLIST_ELEMENT slist_getElement(lista_estatica* lista, int posicion)
{
    if(!lista) return -1;
    if(lista->cantidad <= posicion) return -1;

    return lista->datos[posicion];
}

SLIST_ELEMENT slist_removeElement(lista_estatica* lista, int posicion)
{
    if(!lista) return -1;
    if(lista->cantidad <= posicion) return -1;

    SLIST_ELEMENT eliminado = lista->datos[posicion];
    for(int i=posicion; i<lista->cantidad-1; i++)
    {
        lista->datos[i] = lista->datos[i+1];
    }

    return eliminado;
}
