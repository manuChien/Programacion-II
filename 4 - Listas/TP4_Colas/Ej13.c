#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void invertirColaTDAPILAS(Dqueue* q)
{
    if(!q) return;

    int queueSize = Dqueue_getsize(q);
    Dstack* tempStack = Dstack_new_with(queueSize);
    if(!tempStack) return;

    // Cargo los elementos de la cola en el stack (al final quedaran en el orden invertido)
    for(int i=0; i<queueSize; i++)
    {
        Dpush(tempStack,Ddequeue(q));
    }

    // Ahora que tengo en el stack los elementos de la cola, al cargarlos en la cola se cargaran en el orden inverso
    for(int i=0; i<queueSize; i++)
    {
        Denqueue(q,Dpop(tempStack));
    }

    Dstack_free(tempStack);
}

void invertirColaRecu(Dqueue* q)
{
    if(!q || Dqueue_isempty(q)) return;

    if(Dqueue_getsize(q)>1)
    {
        DQUEUE_ELEM current = Ddequeue(q);
        invertirColaRecu(q);
        Denqueue(q,current);
    }
}
