#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

void vectorRandom(vector *v)
{
    if(v==NULL) return;

    int randomNum;
    for(int i=0; i<100; i++)
    {
        randomNum = rand();
        vector_add(v,randomNum);
    }
}
void print(VECTOR_ELEMENT x)
{
    printf("%d",x);
}

int vector_sumatoria(vector *v)
{
    int resultado = 0;
    int size = vector_size(v);
    for(int i=0; i<size; i++)
    {
        resultado += vector_get(v,i);
    }
    return resultado;
}
