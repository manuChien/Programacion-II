#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void printStack(Dstack* s,void(*print)(DSTACK_ELEM))
{
    if(!s) return;

    Dstack* temp = Dstack_new();
    if(!temp) return;

    while(!Dstack_isempty(s))
    {
        DSTACK_ELEM current = Dpop(s);
        print(current);
        Dpush(temp,current);
    }
    while(!Dstack_isempty(temp))
    {
        Dpush(s,Dpop(temp));
    }

    Dstack_free(temp);
}

void printStackRec(Dstack* s, void(*print)(DSTACK_ELEM))
{
    if(!s || Dstack_isempty(s)) return;

    DSTACK_ELEM current = Dpop(s);
    print(current);

    printStackRec(s,print);

    Dpush(s,current);
}
