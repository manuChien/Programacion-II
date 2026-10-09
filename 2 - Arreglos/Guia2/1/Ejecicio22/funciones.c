#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
#include "funciones.h"

matrix* sumarDosMatrices(matrix* A,matrix* B, void* (*suma)(MATRIX_ELEMENT,MATRIX_ELEMENT))
{
    if(!A || !B) return NULL;
    if(matrix_columns(A)!=matrix_columns(B) || matrix_rows(A)!=matrix_rows(B)) return NULL;

    matrix* resultado = matrix_new(matrix_rows(A),matrix_columns(A));

    for(int i=0; i<matrix_rows(A); i++)
    {
        for(int j=0; j<matrix_columns(A); j++)
        {
            MATRIX_ELEMENT elemento = suma(matrix_get(A,i,j),matrix_get(B,i,j));
            matrix_set(resultado,i,j,elemento);
        }
    }

    return resultado;
}

int sumarVectorATodasLasFilas(matrix* m,Vector* v,void* (*suma)(MATRIX_ELEMENT,MATRIX_ELEMENT))
{
    if(!m || !v) return -1;
    if(matrix_columns(m)!=vector_size(v)) return -1;

    for(int i=0; i<matrix_rows(m); i++)
    {
        for(int j=0; j<matrix_columns(m); j++)
        {
            matrix_set(m,i,j,suma(matrix_get(m,i,j),vector_get(v,j)));
        }
    }

    return 0;
}

matrix* productoDosMatrices(matrix* A,matrix* B,void* (*producto)(MATRIX_ELEMENT,MATRIX_ELEMENT),void* (*suma)(MATRIX_ELEMENT,MATRIX_ELEMENT))
{
    if(!A || !B) return NULL;
    if(matrix_columns(A)!=matrix_rows(B)) return NULL;

    int filasA = matrix_rows(A);
    int colsA = matrix_columns(A);
    int filasB = matrix_rows(B);
    int colsB = matrix_columns(B);
    matrix* resultado = matrix_new(filasA,colsB);

    for(int i=0; i<filasA; i++)
    {
        for(int j=0; j<colsB; j++)
        {
            MATRIX_ELEMENT acumulador = NULL;;

            for(int k=0; k<filasB; k++)
            {
                MATRIX_ELEMENT prod = producto(matrix_get(A,i,k),matrix_get(B,k,j));
                if(k==0)
                {
                    acumulador = prod;
                } else
                {
                    MATRIX_ELEMENT anterior = acumulador;
                    acumulador = suma(anterior,prod);
                    free(anterior);
                    free(prod);
                }
            }
            matrix_set(resultado,i,j,acumulador);
        }
    }

    return resultado;
}

// CALCULO DE DETERMINANTE MEDIANTE METODO DE COFACTORES
int determinanteInt(matrix* m)
{
    // SI LA MATRIX ES INVALIDA O NO ES CUADRADA NO HAY NADA QUE HACER
    if(!m || matrix_columns(m)!=matrix_rows(m)) return -1;

    // SI LA MATRIZ TIENE UN SOLO ELEMENTO ESE ES EL DETERMINANTE
    if(matrix_columns(m)==1) return matrix_get(m,0,0);

    int resultado = 0;

    // CASO BASE: MATRIX 2 x 2
    if(matrix_columns(m)==2 && matrix_rows(m)==2)
    {
        return matrix_get(m,0,0)*matrix_get(m,1,1) - matrix_get(m,0,1)*matrix_get(m,1,0);
    } else
    {
        // CREO SUBMATRIZ MAS PEQUEÑA PARA CADA SUBMATRIX (ELIMINANDO FILA Y COLUMNA)
        for(int i=0; i<matrix_columns(m)-1; i++)
        {
            matrix* aux = matrix_new(matrix_rows(m)-1,matrix_columns(m)-1);
            // SUBMATRIZ QUITANDO LA FILA SUPERIOR Y COLUMNA DEL ELEMENTO
            for(int row=1; row<matrix_rows(aux); row++)
            {
                for(int col=0; col<matrix_columns(aux); col++)
                {
                    if(col!=i)
                    {
                        matrix_set(aux,row,col,matrix_get(m,row,col));
                    }
                }
            }
            // SUMO LA LLAMADA RECURSIVA CON MATRIZ REDUCIDA
            resultado+=matrix_get(m,0,i)*determinanteInt(m);
        }
    }
    return resultado;
}
