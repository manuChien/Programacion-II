#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _list_node {
  t_elem value;
  struct _list_node *next;
} list_node;

typedef struct _list {
  list_node* head;
  list_node* current;
  int maxsize;
  int count;
} list;


list* list_new(int maxsize){
  /*** COMPLETAR ***/
}

void list_free(list *L){
  /*** COMPLETAR ***/
}

int list_length(list *L){
  /*** COMPLETAR ***/
}

int list_append(list *L, LIST_ELEM elem){
  /*** COMPLETAR ***/
}

void list_insert(list *L, int index, LIST_ELEM elem){
  /*** COMPLETAR ***/
  // insert before current
}

LIST_ELEM list_first(list *L){
  /*** COMPLETAR ***/
}

LIST_ELEM list_next(list *L){
  /*** COMPLETAR ***/
}

int list_eol(list *L){
  /*** COMPLETAR ***/
}

LIST_ELEM list_remove (list *L){
  /*** COMPLETAR ***/
  // remove current element
}

LIST_ELEM list_get(list *L, int index){
  /*** COMPLETAR ***/
}

bool list_isempty(list *L){
  /*** COMPLETAR ***/
}

bool list_isfull(list *L){
  /*** COMPLETAR ***/
}