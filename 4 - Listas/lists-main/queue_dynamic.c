#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queue_node {
  QUEUE_ELEM value;
  struct queue_node *next;
} queue_node;

typedef struct queue {
  queue_node *head;
  queue_node *tail;
  int maxsize; // -1 for no limit
  int count;
} queue;

queue* queue_new () {
  queue* q = malloc(sizeof(queue));

  q->head = NULL;
  q->tail = NULL;
  q->maxsize = -1; // no limit
  q->count = 0;

  return q;
}

queue* queue_new_with (int maxsize) {
  queue* q = malloc(sizeof(queue));

  q->head = NULL;
  q->tail = NULL;
  q->maxsize = maxsize;
  q->count = 0;

  return q;
}

void queue_free (queue* q) {
  /*COMPLETAR*/
}

int queue_getsize (queue* q) {
  /*COMPLETAR*/
}

int queue_getmaxsize (queue* q) {
  /*COMPLETAR*/
}

int queue_isfull (queue* q) {
  /*COMPLETAR*/
}

int queue_isempty (queue* q) {
  /*COMPLETAR*/
}

void enqueue (queue* q, t_elem elem) {    
  /*COMPLETAR*/
}

t_elem dequeue (queue* q) {
  /*COMPLETAR*/
}

t_elem peek (queue* q) {
  /*COMPLETAR*/
}