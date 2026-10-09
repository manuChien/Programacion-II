#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

DSTACK_ELEM sumatoriaPila(Dstack* s)
{
    if(!s) return DSTACK_DEFAULT;
    if(Dstack_isempty(s)) return 0;

    int resultado = 0;
    if(Dstack_getsize(s)==1)
    {
        return Dtop(s);
    } else
    {
        DSTACK_ELEM current = Dpop(s);
        resultado = sumatoriaPila(s) + current;
        Dpush(s,current);
    }
    return resultado;
}
