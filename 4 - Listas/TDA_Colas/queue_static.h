#ifndef _QUEUE
#define _QUEUE

#define SQUEUE_ELEM int
#define SQUEUE_DEFAULT -1
#define SQUEUE_DEFAULT_MAXSIZE 100

typedef struct _Squeue Squeue;

Squeue* Squeue_new();

Squeue* Squeue_new_with(int maxsize);

void Squeue_free (Squeue* q);

int Squeue_getmaxsize(Squeue* q);

int Squeue_getsize(Squeue* q);

int Squeue_isfull (Squeue* q);

int Squeue_isempty (Squeue* q);

void Senqueue (Squeue* q, SQUEUE_ELEM elem);

SQUEUE_ELEM Sdequeue (Squeue* q);

SQUEUE_ELEM Speek (Squeue* q);

#endif
