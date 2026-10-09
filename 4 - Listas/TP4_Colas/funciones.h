#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "queue_dynamic.h"
#include "stack_dynamic.h"

// EJERCICIO 11: Imprimir una cola dejandola como estaba
void printQueue(Dqueue* q, void (*print)(DQUEUE_ELEM));

// EJERCICIO 12: Calcular la suma de una cola de enteros
int sumatoriaCola(Dqueue* q);

// EJERCICIO 13: Invertir los elementos de una cola
// Usando TDA PILAS
void invertirColaTDAPILAS(Dqueue* q);
// Sin TDA, de forma RECURSIVA
void invertirColaRecu(Dqueue* q);

// EJERCICIO 15: Copiar cola
Dqueue* copyDqueue(Dqueue* q);

#endif // FUNCIONES_H_INCLUDED
