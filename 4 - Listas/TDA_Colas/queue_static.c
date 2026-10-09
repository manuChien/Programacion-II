#include <stdio.h>
#include <stdlib.h>

#include "queue_static.h"

struct _Squeue
{
    SQUEUE_ELEM* a;
    int head;   //mark the first element
    int tail;   //mark the next empty position
    int maxsize;// -1 for no limit
    int count;
};

Squeue* Squeue_new()
{
    return Squeue_new_with(SQUEUE_DEFAULT_MAXSIZE);
}

Squeue* Squeue_new_with(int maxsize)
{
    if(maxsize<-1) return NULL;

    if(maxsize==-1) maxsize = SQUEUE_DEFAULT_MAXSIZE;

    Squeue* newQueue = malloc(sizeof(Squeue));
    if(!newQueue) return NULL;
    SQUEUE_ELEM* a = malloc(maxsize*sizeof(SQUEUE_ELEM));
    if(!a) return NULL;

    newQueue->a = a;
    newQueue->head = 0;
    newQueue->tail = 0;
    newQueue->maxsize = maxsize;
    newQueue->count = 0;

    return newQueue;
}

void Squeue_free (Squeue* q)
{
    if(!q) return;

    free(q->a);
    free(q);
}

int Squeue_getmaxsize(Squeue* q)
{
    if(!q) return -1;
    return q->maxsize;
}

int Squeue_getsize(Squeue* q)
{
    if(!q) return -1;
    return q->count;
}

int Squeue_isfull (Squeue* q)
{
    if(!q || q->count<q->maxsize) return 0;
    return 1;
}

int Squeue_isempty (Squeue* q)
{
    if(!q || q->count==0) return 1;
    return 0;
}

void Senqueue (Squeue* q, SQUEUE_ELEM elem)
{
    if(!q || q->count==q->maxsize) return;

    q->a[q->tail] = elem;
    q->tail++;
    q->count++;
}

SQUEUE_ELEM Sdequeue (Squeue* q)
{
    if(!q || q->count==0) return SQUEUE_DEFAULT;

    SQUEUE_ELEM deleted = q->a[q->head];

    for(int i=0; i<q->tail; i++)
    {
        q->a[i] = q->a[i+1];
    }
    q->tail--;
    q->count--;
    return deleted;
}

SQUEUE_ELEM Speek (Squeue* q)
{
    if(!q || q->count==0) return SQUEUE_DEFAULT;
    return q->a[q->head];
}
