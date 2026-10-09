#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
#include "funciones.h"

void printInt(MATRIX_ELEMENT elem)
{
    printf("%d",elem);
}

int main()
{
    matrix* A = matrix_new(4,4);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            matrix_set(A,i,j,rand()%10);
        }
    }
    matrix_print(A,printInt);
    printf("\n");

    Vector* respuestas = vector_new(4);
    for(int i=0; i<4; i++)
    {
        vector_add(respuestas,rand()%10);
    }
    vector_print(respuestas,printInt);
    printf("\n");

    Vector* soluciones = sistemaEcuaciones(A,respuestas);
    vector_print(soluciones,printInt);
    printf("\n");

    return 0;
}
