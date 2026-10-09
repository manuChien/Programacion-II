#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
#include "funciones.h"

void* sumarIntPunteros(MATRIX_ELEMENT A, MATRIX_ELEMENT B)
{
    if(!A || !B) return NULL;

    int* resultado = malloc(sizeof(int));
    if(!resultado) return NULL;

    int valA = *A;
    int valB = *B;
    *resultado = valA + valB;

    return resultado;
}
void* productoIntPunteros(MATRIX_ELEMENT A, MATRIX_ELEMENT B)
{
    if(!A || !B) return NULL;

    int* resultado = malloc(sizeof(int));
    if(!resultado) return NULL;

    int valA = *A;
    int valB = *B;
    *resultado = valA * valB;

    return resultado;
}

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
    matrix* A = matrix_new(3,3);
    int n=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int* num = malloc(sizeof(int*));
            *num = ++n;
            matrix_set(A,i,j,num);
        }
    }
    matrix_print(A,printInt);
    printf("\n");

    matrix* B = matrix_new(3,3);
    int m=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int* num = malloc(sizeof(int*));
            *num = ++m;
            matrix_set(B,i,j,num);
        }
    }
    matrix_print(B,printInt);
    printf("\n");

    matrix* C = sumarDosMatrices(A,B,sumarIntPunteros);
    matrix_print(C,printInt);
    printf("\n");

    Vector* v = vector_new(3);
    for(int i=0; i<3; i++)
    {
        int* numero = malloc(sizeof(int));
        *numero = 1;
        vector_add(v,numero);
    }

    sumarVectorATodasLasFilas(C,v,sumarIntPunteros);
    matrix_print(C,printInt);
    printf("\n");

    matrix* D = matrix_new(2,2);
    int a=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int* num = malloc(sizeof(int*));
            *num = ++a;
            matrix_set(D,i,j,num);
        }
    }
    matrix_print(D,printInt);
    printf("\n");

    matrix* E = matrix_new(2,2);
    int b=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int* num = malloc(sizeof(int*));
            *num = ++b;
            matrix_set(E,i,j,num);
        }
    }
    matrix_print(E,printInt);
    printf("\n");

    matrix* DE = productoDosMatrices(D,E,productoIntPunteros,sumarIntPunteros);
    matrix_print(DE,printInt);
    printf("\n");

    return 0;
}
