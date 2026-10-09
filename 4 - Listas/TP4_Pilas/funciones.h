#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "stack_dynamic.h"

// EJERCICIO 9: Imprimir pila dejando la pila original como estaba
/**
* @brief Imprime una pila iterativamente dejandola como estaba
*
* @param Pila a imprimir
* @param Funcion de impresion
*/
void printStack(Dstack* s,void(*print)(DSTACK_ELEM)); // Iterativa
/**
* @brief Imprime una pila recursivamente dejandola como estaba
*
* @param Pila a imprimir
* @param Funcion de impresion
*/
void printStackRec(Dstack* s, void(*print)(DSTACK_ELEM)); // Recursiva

// EJERCICIO 12: Calcular sumatoria de todos los elementos de una pila
DSTACK_ELEM sumatoriaPila(Dstack* s);

// EJERCICIO 14: Crear una copia de una pila
void _copyDstackAux(Dstack* s, Dstack* newStack);
Dstack* copyDstack(Dstack* s);

// EJERCICIO 16: Verificar si un string con operaciones matematicas esta balanceado
int operacionBalanceada(char* s);

// EJERCICIO 18: Ver si una frase es palindroma
/**
* @brief Verifica si una frase es palindroma
*
* @param String de la frase
*
* @return 0 si no es palindroma, 1 si si
*/
int esPalindroma(char* s);

#endif // FUNCIONES_H_INCLUDED
