#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "vector.h"
#include "matrix.h"

// EJERCICIO 1
int sumaPrimerosNaturales(int n);

// EJERCICIO 2
int productoEnterosRecursiva(int,int);

// EJERCICIO 3
// a
void fibonacciPrimerosTerminos(int n);
// b
void _fiboMenoresAux(int a, int b, int x);
void imprimirFibonacciMenores(int x);

// EJERCICIO 4
float potencia(float x, float n);

// EJERCICIO 5
int digitosCrecientes(int n);

// EJERCICIO 6
char* invertirPalabra(char* str, int n);
void _invertirPalabraAux(char* str, char* resultado, int n, int m);

// EJERCICIO 7
void mediaPiramide(int n);

// EJERCICIO 9
int _busquedaLinealAux(Vector* v, VECTOR_ELEMENT value, int i);
int busquedaLineal(Vector* v, VECTOR_ELEMENT value);
int _busquedaBinariaAux(Vector* v, VECTOR_ELEMENT value, int half, int vsize);
int busquedaBinaria(Vector* v, VECTOR_ELEMENT value);

// EJERCICIO 10
void quicksort(Vector* v, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT));
void merge(Vector* v, Vector* A, Vector* B, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT));
void mergesort(Vector* v, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT));

// EJERCICIO 11
int cantFilasIndiceParconX(matrix* m, MATRIX_ELEMENT x);
int _cantFilasIndiceParconX_aux(matrix* m, MATRIX_ELEMENT x, int fila, int cant);
int estaEnLaFila(matrix* m, MATRIX_ELEMENT x, int fila);

// EJERCICIO 12
Vector* cantElementosNegativosPorFila(matrix* m);
void _cantElemNegFila_aux(matrix* m, Vector* v, int row);

#endif // FUNCIONES_H_INCLUDED
