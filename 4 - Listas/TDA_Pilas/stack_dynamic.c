#include <stdio.h>
#include <stdlib.h>

#include "stack_dynamic.h"

struct _Dstack_node
{
    DSTACK_ELEM value;
    struct _Dstack_node *next;
};

struct _Dstack
{
    Dstack_node *head;
    int maxsize; // -1 for no limit
    int count;
};

Dstack* Dstack_new()
{
    return Dstack_new_with(DSTACK_DEFAULT_MAXSIZE);
}

Dstack* Dstack_new_with(int maxsize)
{
    Dstack* newDStack = malloc(sizeof(Dstack));
    if(!newDStack) return NULL;
    newDStack->head = NULL;
    newDStack->maxsize= maxsize;
    newDStack->count = 0;

    return newDStack;
}

void Dstack_free(Dstack* s)
{
    if(!s) return;

    Dstack_node* curNode = s->head;
    while(curNode!=NULL)
    {
        Dstack_node* aEliminar = curNode;
        curNode = curNode->next;
        free(aEliminar);
    }
    free(s);
}

int Dstack_getsize(Dstack* s)
{
    if(!s) return -1;
    return s->count;
}

int Dstack_getmaxsize(Dstack* s)
{
    if(!s) return 0;
    return s->maxsize;
}

int Dstack_isempty(Dstack* s)
{
    if(!s || s->count==0) return 1;
    return 0;
}

int Dstack_isfull(Dstack* s)
{
    if(!s || s->maxsize==-1 || s->count < s->maxsize) return 0;
    return 1;
}

void Dpush(Dstack* s, DSTACK_ELEM elem)
{
    if(!s) return;
    if(s->maxsize!=-1 && s->count>=s->maxsize) return;
    Dstack_node* newNode = malloc(sizeof(Dstack_node));
    if(!newNode) return;
    newNode->value = elem;

    newNode->next = s->head;
    s->head = newNode;

    s->count++;
}

DSTACK_ELEM Dpop(Dstack* s)
{
    if(!s || s->count==0) return DSTACK_DEFAULT;

    DSTACK_ELEM deletedValue = s->head->value;
    Dstack_node* lastTop = s->head;
    s->head = s->head->next;
    free(lastTop);

    s->count--;
    return deletedValue;
}

DSTACK_ELEM Dtop(Dstack* s)
{
    if(!s || s->count==0) return DSTACK_DEFAULT;

    return s->head->value;
}

void Dstack_destroy(Dstack* s, void elem_free(DSTACK_ELEM))
{
    if(!s) return;

    Dstack_node* curNode = s->head;
    Dstack_node* nextNode = NULL;
    for(int i=0; i<s->count; i++)
    {
        nextNode = curNode->next;
        elem_free(curNode->value);
        free(curNode);
        curNode = nextNode;
    }
    free(s);
}
