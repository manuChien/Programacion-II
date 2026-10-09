#include <stdio.h>
#include <stdlib.h>

#include "stack_static.h"

struct _Sstack
{
    SSTACK_ELEM* s;
    int top;
    int maxsize; // -1 for no limit
};

Sstack* Sstack_new(void)
{
    return Sstack_new_with(SSTACK_DEFAULT_MAXSIZE);
}

Sstack* Sstack_new_with(int maxsize)
{
    Sstack* newStack = malloc(sizeof(Sstack));
    if(!newStack) return NULL;
    SSTACK_ELEM* s = malloc(maxsize*sizeof(SSTACK_ELEM));
    if(!s) return NULL;

    newStack->s = s;
    newStack->maxsize = maxsize;
    newStack->top = -1;

    return newStack;
}

void Sstack_free(Sstack* s)
{
    if(!s) return;
    free(s->s);
    free(s);
}

int Sstack_getsize(Sstack* s)
{
    if(!s) return -1;
    return s->top+1;
}

int Sstack_getmaxsize(Sstack* s)
{
    if(!s) return -1;
    return s->maxsize;
}

void Spush(Sstack* s, SSTACK_ELEM elem)
{
    if(!s || (s->top)>=(s->maxsize-1)) return;

    s->s[s->top + 1] = elem;
    s->top++;
}

SSTACK_ELEM Spop(Sstack* s)
{
    if(!s || s->top==-1) return SSTACK_DEFAULT;

    SSTACK_ELEM popped = s->s[s->top];
    s->top--;
    return popped;
}

SSTACK_ELEM Stop(Sstack* s)
{
    if(!s || s->top==-1) return SSTACK_DEFAULT;

    return s->s[s->top];
}

int Sstack_isempty(Sstack* s)
{
    if(!s || s->top==-1) return 1;
    return 0;
}

int Sstack_isfull(Sstack* s)
{
    if(!s || (s->top)<(s->maxsize-1)) return 0;
    return 1;
}

void Sstack_destroy(Sstack* s, void elem_free(void*))
{
    if(!s) return;
    int i=0;
    while(i<s->top+1)
    {
        elem_free(s->s[i]);
        i++;
    };
    free(s->s);
    free(s);
}
