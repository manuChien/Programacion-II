#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct _matrix
{
    MATRIX_ELEMENT* data;
    int rows;
    int columns;
};
//-----------------------------------------------------------------
matrix* matrix_new(int rows, int columns)
{
    if(rows==0 || columns==0) return NULL;

    matrix* resultado = (matrix*)malloc(sizeof(matrix));
    if (resultado == NULL) return NULL;

//RESERVO UN BLOQUE DE MEMORIA DE ROWS*COLUMNS MATRIX_ELEMENTS, QUE SON PUNTEROS
    resultado->data = (MATRIX_ELEMENT*)calloc(rows * columns, sizeof(MATRIX_ELEMENT));
    if (resultado->data == NULL)
    {
        free(resultado);
        return NULL;
    }

    resultado->rows = rows;
    resultado->columns = columns;

    return resultado;
}
//-----------------------------------------------------------------
void matrix_free(matrix* m)
{
    if(!m) return;

    free(m->data);
    free(m);
}
//-----------------------------------------------------------------
int matrix_rows(matrix* m)
{
    if(!m) return -1;

    return m->rows;
}
//-----------------------------------------------------------------
int matrix_columns(matrix* m)
{
    if(!m) return -1;

    return m->columns;
}
//-----------------------------------------------------------------
MATRIX_ELEMENT matrix_get(matrix* m, int row, int col)
{
    if(!m || row<0 || row >= m->rows || col<0 || col >= m->columns) return -1;

    return (m->data)[row*m->columns + col];
}
//-----------------------------------------------------------------
void matrix_set(matrix* m, int row, int col, MATRIX_ELEMENT value)
{
    if(!m || row<0 || row >= m->rows || col<0 || col >= m->columns || !value) return;

    m->data[row * m->columns + col] = value;
}
//-----------------------------------------------------------------
void matrix_print(matrix* m, void prt(MATRIX_ELEMENT))
{
    if(!m || !prt) return;

    for(int i=0; i<m->rows; i++)
    {
        for(int j=0; j<m->columns; j++)
        {
            MATRIX_ELEMENT element = matrix_get(m,i,j);
            prt(element);
            printf("\t");
        }
        printf("\n");
    }
}
