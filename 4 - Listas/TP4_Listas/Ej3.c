#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int lista_menorEntero(node* h)
{
    if(!h) return -1;
    int menorEntero = h->data;

    if(h->next == NULL)
    {
        return h->data;
    } else
    {
        int nextNodeData = lista_menorEntero(h->next);
        if(h->data > nextNodeData)
        {
            menorEntero = nextNodeData;
        }
        return menorEntero;
    }
}
