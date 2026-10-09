#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void printQueue(Dqueue* q, void (*print)(DQUEUE_ELEM))
{
    if(!q || Dqueue_isempty(q)) return;

    for(int i=0; i<Dqueue_getsize(q); i++)
    {
        DQUEUE_ELEM current = Ddequeue(q);
        print(current);
        Denqueue(q,current);
    }
}
