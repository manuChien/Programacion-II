#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

//EJERCICIO 5
//SUMAR VECTORES DEL MISMO TAMAÑO
vector *vector_sumaVectores(vector *A,vector *B)
{
    if(vector_size(A)!=vector_size(B))
    {
        printf("The arrays size doesn't match.\n");
        return NULL;
    }

    int size = vector_size(A);
    vector *answer = vector_new(size);
    for(int i=0; i<size; i++)
    {
        vector_add(answer,suma(vector_get(A,i),vector_get(B,i)));
    }
    return answer;
}
//


void vectorRandom(vector *v)
{
    if(v==NULL) return;

    int randomNum;
    for(int i=0; i<10; i++)
    {
        randomNum = rand() %3 + 1;
        vector_add(v,randomNum);
    }
}
void print(VECTOR_ELEMENT x)
{
    printf("%d",x);
}

int vector_serieOperaciones(vector *v, int(*operacion)(int,int))
{
    int acumulador = vector_get(v,0);
    int size = vector_size(v);
    for(int i=1; i<size; i++)
    {
        acumulador = operacion(acumulador,vector_get(v,i));
    }
    return acumulador;
}

int suma(int x, int y)
{
    return x+y;
}

int resta(int x, int y)
{
    return x-y;
}

int producto(int x, int y)
{
    return x*y;
}

int cociente(int x, int y)
{
    if(y==0)
    {
        fprintf(stderr, "ERROR: Hay terminos 0 en la division.\n");
        return 0;
    }
    return x/y;
}
