#ifndef STACK_STATIC_H_INCLUDED
#define STACK_STATIC_H_INCLUDED

#define SSTACK_ELEM void*
#define SSTACK_DEFAULT NULL
#define SSTACK_DEFAULT_MAXSIZE 100

typedef struct _Sstack Sstack;

Sstack* Sstack_new();

Sstack* Sstack_new_with(int maxsize);

void Sstack_free(Sstack* s);

int Sstack_getsize(Sstack* s);

int Sstack_getmaxsize(Sstack* s);

void Spush(Sstack* s, SSTACK_ELEM elem);

SSTACK_ELEM Spop(Sstack* s);

SSTACK_ELEM Stop(Sstack* s);

int Sstack_isempty(Sstack* s);

int Sstack_isfull(Sstack* s);

void Sstack_destroy(Sstack* s, void elem_free(SSTACK_ELEM));

#endif
