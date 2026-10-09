#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
#include "funciones.h"

void _determinanteInt_aux(matrix* m, int* resultado)
{
    // CASO BASE: MATRIX 2 x 2
    if(matrix_columns(m)==2 && matrix_rows(m)==2)
    {
        *resultado = matrix_get(m,0,0)*matrix_get(m,1,1) - matrix_get(m,0,1)*matrix_get(m,1,0);
        return;
    }
    else
    {
        int suma_total = 0; // Aquí acumularemos la suma de esta etapa
        int filas_m = matrix_rows(m);
        int columnas_m = matrix_columns(m);

        // RECORRO LA FILA SUPERIOR
        // ES CADA ELEMENTO DE LA COMBINACION LINEAL
        // CREO SUBMATRIZ CUADRADA MAS PEQUEÑA PARA CADA SUBMATRIX (ELIMINANDO FILA Y COLUMNA DEL ELEM SUPERIOR)
        for(int i=0; i<columnas_m; i++)
        {
            // CREACION DE SUBMATRIZ MAS PEQUEÑA
            matrix* aux = matrix_new(filas_m-1,columnas_m-1);
            // CARGO LA SUBMATRIZ QUITANDO LA FILA SUPERIOR Y COLUMNA DEL ELEMENTO
            for(int row=1; row<filas_m; row++)
            {
                int col_aux = 0;
                for(int col=0; col<columnas_m; col++)
                {
                    if(col!=i)
                    {
                        matrix_set(aux, row-1, col_aux, matrix_get(m,row,col));
                        col_aux++;
                    }
                }
            }

            int det_subMatriz = 0;
            _determinanteInt_aux(aux,&det_subMatriz);
            int signo = 0;
            if(i%2==0)
            {
                signo = 1;
            }
            else
            {
                signo = -1;
            }
            int elem_superior = matrix_get(m,0,i);
            suma_total += signo*elem_superior*det_subMatriz;

            matrix_free(aux);
        }

        *resultado = suma_total;
    }
}

// CALCULO DE DETERMINANTE MEDIANTE METODO DE COFACTORES
int determinanteInt(matrix* m)
{
    // SI LA MATRIX ES INVALIDA O NO ES CUADRADA NO HAY NADA QUE HACER
    if(!m || matrix_columns(m)!=matrix_rows(m)) return -1;

    // SI LA MATRIZ TIENE UN SOLO ELEMENTO ESE ES EL DETERMINANTE
    if(matrix_columns(m)==1) return matrix_get(m,0,0);

    int resultado = 0;

    _determinanteInt_aux(m,&resultado);

    return resultado;
}

matrix* reemplazarColumnaPorVector(matrix* m, Vector* v, int col)
{
    if(!m || vector_size(v)!=matrix_rows(m)) return NULL;

    int rows_m = matrix_rows(m);
    int cols_m = matrix_columns(m);

    matrix* answer = matrix_new(rows_m,cols_m);
    if(!answer) return NULL;

    for(int i=0; i<rows_m; i++)
    {
        for(int j=0; j<cols_m; j++)
        {
            if(j==col)
            {
                matrix_set(answer,i,col,vector_get(v,i));
            } else
            {
                matrix_set(answer,i,j,matrix_get(m,i,j));
            }
        }
    }

    return answer;
}

Vector* sistemaEcuaciones(matrix* coef, Vector* resultados)
{
    if(!coef || !resultados) return NULL;
    if(matrix_columns(coef)!=matrix_rows(coef)) return NULL;
    if(vector_size(resultados)!=matrix_columns(coef)) return NULL;

    int cant = vector_size(resultados);
    Vector* answer = vector_new(cant);

    int detDenominador = determinanteInt(coef);
    if(detDenominador==0)
    {
        printf("ES TRIVIAL\n");
        return NULL;
    }

    for(int i=0; i<cant; i++)
    {
        matrix* currentMat = reemplazarColumnaPorVector(coef,resultados,i);
        vector_add(answer,determinanteInt(currentMat)/detDenominador);
        matrix_free(currentMat);
    }

    return answer;
}
