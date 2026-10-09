#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void _copyDstackAux(Dstack* s, Dstack* newStack)
{
    if(!Dstack_isempty(s))
    {
        DSTACK_ELEM current = Dpop(s);
        _copyDstackAux(s,newStack);
        Dpush(s,current);
        Dpush(newStack,current);
    }
}

Dstack* copyDstack(Dstack* s)
{
    if(!s) return NULL;

    int stackMaxSize = Dstack_getmaxsize(s);
    int stackSize = Dstack_getsize(s);
    Dstack* newStack = Dstack_new_with(stackMaxSize);
    if(!newStack) return NULL;

    _copyDstackAux(s,newStack);

    return newStack;
}
