#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int _busquedaLinealAux(Vector* v, VECTOR_ELEMENT value, int i)
{
    if(i>=vector_size(v))
    {
        return -1;
    }
    else
    {
        if(vector_get(v,i)==value)
        {
            return i;
        }
        else
        {
            _busquedaLinealAux(v,value,i+1);
        }
    }
}

int busquedaLineal(Vector* v, VECTOR_ELEMENT value)
{
    if(!v) return -1;
    return _busquedaLinealAux(v,value,0);
}

int _busquedaBinariaAux(Vector* v, VECTOR_ELEMENT value, int half, int vsize)
{
    // CASO ENCONTRADO
    if(vector_get(v,half)==value)
    {
        return half;
    }
    // CASO NO ESTA EL ELEMENTO
    else if(vsize<=0)
    {
        return -1;
    }
    else
    {
        // REDUZCO EL RANGO A LA MITAD
        int newRange = vsize/2;
        // CASO VALOR ESTA A LA IZQUIERDA
        if(value<vector_get(v,half))
        {
            // NUEVO HALF: MUEVO NEWRANGE-1 ELEMENTOS HACIA LA IZQUIERDA ASI NO PIERDO EL INMEDIATAMENTE ANTERIOR
            return _busquedaBinariaAux(v,value,half-(newRange-1),newRange);
        }
        // CASO EL VALOR ESTA A LA DERECHA
        else
        {
            // NUEVO HALF: MUEVO NEWRANGE-1 ELEMENTOS HACIA LA DERECHA ASI NO PIERDO EL INMEDIATAMENTE POSTERIOR
            return _busquedaBinariaAux(v,value,half+(newRange-1),newRange);
        }
    }
}

int busquedaBinaria(Vector* v, VECTOR_ELEMENT value)
{
    if(!v) return -1;
    if(vector_size(v)==1) return vector_get(v,0);
    return _busquedaBinariaAux(v,value,vector_size(v)/2,vector_size(v));
}
