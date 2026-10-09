#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED
#include <stdbool.h>

#define DLIST_ELEMENT int
#define DLIST_DEFAULT -1

typedef struct _list_node list_node;

typedef struct _List List;


List* list_new(int maxsize);

int list_free(List *L);

int list_length(List *L);

int list_append(List *L, DLIST_ELEMENT elem);

int list_insert(List *L, int index, DLIST_ELEMENT elem);

DLIST_ELEMENT list_first(List *L);

DLIST_ELEMENT list_next(List *L);

int list_eol(List *L);

DLIST_ELEMENT list_remove (List *L);

DLIST_ELEMENT list_get(List *L, int index);

bool list_isempty(List *L);

bool list_isfull(List *L);

#endif // LISTA_DINAMICA_H_INCLUDED
