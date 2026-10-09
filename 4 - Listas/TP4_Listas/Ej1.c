#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int lista_ordenada(node* h, int (*cmp)(NODE_ELEMENT,NODE_ELEMENT))
{
    if(!h) return -1;

    int ordenado = 1;

    while(h->next != NULL && ordenado==1)
    {
        if(cmp((h->next)->data,h->data)<0)
        {
            ordenado = -1;
        }
        h=h->next;
    }
    return ordenado;
}
