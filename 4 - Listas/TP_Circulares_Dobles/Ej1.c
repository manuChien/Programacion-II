#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int esCLL(Node* nodo)
{
    if(!nodo) return 0;

    Node* current = nodo->next;

    while(current!=NULL && current!=nodo)
    {
        current = current->next;
    };

    return (current==nodo) ? 1:0;
}
