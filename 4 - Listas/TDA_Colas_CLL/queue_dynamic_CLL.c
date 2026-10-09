#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic_CLL.h"

struct _Dqueue_node
{
    DQUEUE_ELEM value;
    struct _Dqueue_node *next;
};

struct _Dqueue
{
    Dqueue_node *head;
    Dqueue_node *tail;
    int maxsize; // -1 for no limit
    int count;
};

Dqueue* Dqueue_new ()
{
    Dqueue* q = malloc(sizeof(Dqueue));
    if(!q) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->maxsize = -1; // no limit
    q->count = 0;

    return q;
}

Dqueue* Dqueue_new_with (int maxsize)
{
    Dqueue* q = malloc(sizeof(Dqueue));
    if(!q) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->maxsize = maxsize;
    q->count = 0;

    return q;
}

void Dqueue_free (Dqueue* q)
{
    if(!q) return;

    Dqueue_node* curNode = q->head;
    Dqueue_node* nextNode = NULL;
    for (int i = 0; i < q->count; i++)
    {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    free(q);
}

int Dqueue_getsize (Dqueue* q)
{
    if(!q) return -1;
    return q->count;
}

int Dqueue_getmaxsize (Dqueue* q)
{
    if(!q) return -1;
    return q->maxsize;
}

int Dqueue_isfull (Dqueue* q)
{
    if(!q || q->maxsize==-1) return 0;
    if(q->count < q->maxsize) return 0;
    return 1;
}

int Dqueue_isempty (Dqueue* q)
{
    if(!q || q->count==0) return 1;
    return 0;
}

void Denqueue (Dqueue* q, DQUEUE_ELEM elem)
{
    if(!q || q->count==q->maxsize) return;

    Dqueue_node* newNode = malloc(sizeof(Dqueue_node));
    if(!newNode) return;
    newNode->value = elem;

    if(q->tail != NULL)
    {
        q->tail->next = newNode;
        q->tail = newNode;
    } else
    {
        q->tail = newNode;
        q->head = newNode;
    }

    newNode->next = q->head;

    q->count++;
}

DQUEUE_ELEM Ddequeue (Dqueue* q)
{
    if(!q || !q->head) return DQUEUE_DEFAULT;

    Dqueue_node* deletedNode = q->head;
    DQUEUE_ELEM deletedValue = deletedNode->value;

    if(q->count==1)
    {
        q->head = NULL;
        q->tail = NULL;
    } else
    {
        q->head = q->head->next;
        q->tail->next = q->head;
    }
    free(deletedNode);

    q->count--;

    return deletedValue;
}

DQUEUE_ELEM Dpeek (Dqueue* q)
{
    if(!q || !q->head) return DQUEUE_DEFAULT;
    return q->head->value;
}
