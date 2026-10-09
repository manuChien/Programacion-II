#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int sumatoriaCola(Dqueue* q)
{
    if(!q || Dqueue_isempty(q)) return 0;

    int size = Dqueue_getsize(q);
    int sumatoria = 0;
    for(int i=0; i<size; i++)
    {
        int current = Ddequeue(q);
        sumatoria+=current;
        Denqueue(q,current);
    }

    return sumatoria;
}
