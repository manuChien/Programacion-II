#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//EJERCICIO 6
//MAXIMO O MINIMO
VECTOR_ELEMENT vector_maxmin(vector*,VECTOR_ELEMENT(*operacion)(VECTOR_ELEMENT,VECTOR_ELEMENT));
VECTOR_ELEMENT higher(VECTOR_ELEMENT,VECTOR_ELEMENT);
VECTOR_ELEMENT lower(VECTOR_ELEMENT,VECTOR_ELEMENT);
//

vector *vector_sumaVectores(vector *A,vector *B);

void vectorRandom(vector *v);
void print(VECTOR_ELEMENT x);

int vector_serieOperaciones(vector* v, int(*operacion)(int,int));

int suma(int,int);
int resta(int,int);
int producto(int,int);
int cociente(int,int);

#endif // FUNCIONES_H_INCLUDED
