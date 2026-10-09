#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void _cantElemNegFila_aux(matrix* m, Vector* v, int row)
{
    if(row==matrix_rows(m))
    {
        return;
    }
    else
    {
        int cantNeg = 0;
        for(int i=0; i<matrix_columns(m); i++)
        {
            if(matrix_get(m,row,i)<0)
            {
                cantNeg++;
            }
        }
        vector_add(v,cantNeg);
        _cantElemNegFila_aux(m,v,row+1);
    }
}

Vector* cantElementosNegativosPorFila(matrix* m)
{
    if(!m) return NULL;

    Vector* result = vector_new(matrix_columns(m));

    _cantElemNegFila_aux(m,result,0);

    return result;
}
