#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"

int reemplazarFilaPorVector(matrix* m, Vector* v, int row)
{
    if(!m || vector_size(v)!=matrix_columns(m)) return -1;

    for(int i=0; i<matrix_columns(m); i++)
    {
        matrix_set(m,row,i,vector_get(v,i));
    }

    return 0;
}

int reemplazarColumnaPorVector(matrix* m, Vector* v, int col)
{
    if(!m || vector_size(v)!=matrix_rows(m)) return -1;

    for(int i=0; i<matrix_rows(m); i++)
    {
        matrix_set(m,i,col,vector_get(v,i));
    }


    return 0;
}

void printInt(void* elem)
{
    printf("%d",*(int*)elem);
}

void intercambiarFila(matrix* m, int row1, int row2)
{
    Vector* auxVector1 = vector_new(matrix_columns(m));
    Vector* auxVector2 = vector_new(matrix_columns(m));
    for(int i=0; i<matrix_columns(m); i++)
    {
        vector_add(auxVector1,matrix_get(m,row1,i));
        vector_add(auxVector2,matrix_get(m,row2,i));
    }

    reemplazarFilaPorVector(m,auxVector1,row2);
    reemplazarFilaPorVector(m,auxVector2,row1);
}

int main()
{
    matrix* m = matrix_new(3,3);
    int n=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int* num = malloc(sizeof(int*));
            *num = ++n;
            matrix_set(m,i,j,num);
        }
    }
    matrix_print(m,printInt);
    printf("\n");

    Vector* v = vector_new(3);
    int n2=0;
    for(int i=0; i<3; i++)
    {
        int* num = malloc(sizeof(int*));
        *num = ++n2;
        vector_add(v,num);
    }

    reemplazarFilaPorVector(m,v,1);
    matrix_print(m,printInt);
    printf("\n");

    intercambiarFila(m,0,2);
    matrix_print(m,printInt);
    printf("\n");

    reemplazarColumnaPorVector(m,v,1);
    matrix_print(m,printInt);

    return 0;
}
