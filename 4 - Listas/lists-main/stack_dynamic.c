#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct _stack_node {
  STACK_ELEM value;
  struct _stack_node *next;
} stack_node;

typedef struct _stack {
  stack_node *head;
  int maxsize; // -1 for no limit
  int count;
} stack;

stack* stack_new() {
  /*COMPLETAR*/
}

stack* stack_new_with(int maxsize) {
  /*COMPLETAR*/
}

void stack_free(stack* s) {
  /*COMPLETAR*/
}

int stack_getsize(stack* s) {
  /*COMPLETAR*/
}

int stack_getmaxsize(stack* s) {
  /*COMPLETAR*/
}

int stack_isempty(stack* s) {
  /*COMPLETAR*/
}

int stack_isfull(stack* s) {
  /*COMPLETAR*/
}

void push(stack* s, STACK_ELEM elem) {
  /*COMPLETAR*/
}

STACK_ELEM pop(stack* s) {
  /*COMPLETAR*/
}

STACK_ELEM top(stack* s) {
  /*COMPLETAR*/
}

void stack_destroy(stack* s, void elem_free(STACK_ELEM)){
  /*COMPLETAR*/
}