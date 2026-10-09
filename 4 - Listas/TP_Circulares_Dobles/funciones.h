#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define NODE_ELEMENT int

typedef struct _Node
{
    NODE_ELEMENT value;
    struct _Node* next;
} Node;

// EJERCICIO 1
/*  Detectar si una lista es CLL (Circular linked list). Dado un puntero a un nodo de una SLL (Simple linked list) de
    la que no se conoce el tamaño de lista (puede ser una SLL que termina en NULL o una CLL). */
int esCLL(Node* nodo);

// EJERCICIO 2
/*  Decidir si una CLL simple es palíndromo. No se puede usar pila ni recursión. */
int esPalindromo(Node* nodo);

// EJERCICIO 3
/* Dada una SLL convertirla en una CLL. */
void SLLtoCLL(Node** h);

// EJERCICIO 5
/* Verificar si los elementos de una CLL están exactamente en orden inverso a una SLL. */
/* Resolver utilizando una pila */
int CLLinversoSLL_STACK(Node* CLL, Node* SLL);
/* Resolver en forma recursiva */
int CLLinversoSLL_recursivo(Node* CLL, Node* SLL);

#endif // FUNCIONES_H_INCLUDED
