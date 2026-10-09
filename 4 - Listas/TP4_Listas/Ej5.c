#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void lista_invertirLista(node** h)
{
    if(!h || !(*h)) return;

    node* anterior = NULL;
    node* actual = (*h);
    node* siguiente = NULL;

    while(actual != NULL)
    {
        siguiente = actual->next;
        actual->next = anterior;
        anterior = actual;
        actual = siguiente;
    }
    *h = anterior;
}
