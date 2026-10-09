#include <stdio.h>
#include <stdlib.h>

#include "queue_static.h"

typedef struct _queue{
    QUEUE_ELEM* a;
    int head;   //mark the first element
    int tail;   //mark the next empty position
    int maxsize;// -1 for no limit
    int count;
} queue;

queue* queue_new(){
    /*COMPLETAR*/
}

queue* queue_new_with(int maxsize){
    /*COMPLETAR*/
}

void queue_free (queue* q){
    /*COMPLETAR*/    
}

int queue_getmaxsize(queue* q){
    /*COMPLETAR*/
}

int queue_getsize(queue* q){
    /*COMPLETAR*/
}

int queue_isfull (queue* q){
    /*COMPLETAR*/
}

int queue_isempty (queue* q){
    /*COMPLETAR*/
}

void enqueue (queue* q, QUEUE_ELEM elem){    
    /*COMPLETAR*/
}

QUEUE_ELEM dequeue (queue* q){
    /*COMPLETAR*/
}

QUEUE_ELEM peek (queue* q){
    /*COMPLETAR*/
}




