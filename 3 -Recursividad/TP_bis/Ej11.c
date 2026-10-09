#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int estaEnLaFila(matrix* m, MATRIX_ELEMENT x, int fila)
{
    int cols = matrix_columns(m);
    int esta = 0;
    int i = 0;
    while(i<cols && esta==0)
    {
        if(matrix_get(m,fila,i)==x)
        {
            esta = 1;
        }
        i++;
    }
    return esta;
}

int _cantFilasIndiceParconX_aux(matrix* m, MATRIX_ELEMENT x, int fila, int cant)
{
    if(fila>matrix_rows(m))
    {
        return 0;
    }
    else
    {
        if(estaEnLaFila(m,x,fila)==1)
        {
            cant++;
        } else
        {
            cant = 0;
        }
        return cant + _cantFilasIndiceParconX_aux(m,x,fila+2,0);
    }
}

int cantFilasIndiceParconX(matrix* m, MATRIX_ELEMENT x)
{
    int resultado = 0;

    if(!m || matrix_columns(m)!=matrix_rows(m)) resultado = -1;

    if(resultado!=-1)
    {
        resultado = _cantFilasIndiceParconX_aux(m,x,0,0);
    }

    return resultado;
}
