#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "vector.h"
#include "fracciones.h"

void vector_sortcmp(vector*,int (*cmp)(int,int));
int isHigher(int A,int B);
int isLower(int A,int B);

int vector_firstMatchSorted(vector*);

vector *vector_pairElemFreq(vector*);
vector *vector_sort(vector*,void (*operation)(vector*,int));
void vector_upward(vector*,int size);
void vector_downward(vector*,int size);

int vector_maxelementFreq(vector*);

int vector_elementFrequency(vector*,VECTOR_ELEMENT);

VECTOR_ELEMENT vector_maxmin(vector*,VECTOR_ELEMENT(*operacion)(VECTOR_ELEMENT,VECTOR_ELEMENT));
VECTOR_ELEMENT higher(VECTOR_ELEMENT,VECTOR_ELEMENT);
VECTOR_ELEMENT lower(VECTOR_ELEMENT,VECTOR_ELEMENT);

vector *vector_sumaVectores(vector *A,vector *B);

void vectorRandom(vector *v);
void print(VECTOR_ELEMENT x);

int vector_serieOperaciones(vector* v, int(*operacion)(int,int));

int suma(int,int);
int resta(int,int);
int producto(int,int);
int cociente(int,int);

#endif // FUNCIONES_H_INCLUDED
