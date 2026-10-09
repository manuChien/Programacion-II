#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void _quicksort_aux(Vector* v, int min, int max, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    if(min>=max)
    {
        return;
    }
    else
    {
        // PIVOT EL ULTIMO
        VECTOR_ELEMENT pivot = vector_get(v,max);

        // INDICE DEL PRIMER ELEMENTO
        int cumplen = min;

        // RECORRO EL VECTOR BUSCANDO CUANTOS ELEMENTOS QUE CUMPLEN LA CONDICION AL PIVOT HAY, ACTUALIZANDO EL INDEX A DONDE VA A INTERCAMBIAR EL PIVOT
        for(int i=cumplen; i<max; i++)
        {
            // UBICO LOS ELEMENTOS QUE CUMPLEN A LA IZQUIERDA DE DONDE VA A IR EL PIVOT
            if (cmp(pivot, vector_get(v, i)) > 0)
            {
                VECTOR_ELEMENT aux_i = vector_get(v, i);
                vector_set(v, i, vector_get(v, cumplen));
                vector_set(v, cumplen, aux_i);
                // ACTUALIZO EL INDEX DEL SIGUIENTE INDEX DONDE IRIA EL SIGUIENTE QUE CUMPLA
                cumplen++;
            }
        }
        // PONGO AL PIVOT JUSTO DESPUES DEL ULTIMO QUE CUMPLE, QUEDANDO LOS QUE CUMPLEN A LA IZQUIERDA Y LOS QUE NO A LA DERECHA
        VECTOR_ELEMENT aux = vector_get(v,cumplen);
        vector_set(v,cumplen,pivot);
        vector_set(v,max,aux);

        //LLAMADAS RECURSIVAS CON LOS OTROS SEGMENTOS
        _quicksort_aux(v,min,cumplen-1,cmp);
        _quicksort_aux(v,cumplen+1,max,cmp);
    }
}

void quicksort(Vector* v, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    if(!v) return;

    // ESTABLEZO LOS INDICES DE MAXIMO Y MINIMO
    int min = 0;
    int max = vector_size(v)-1;

    _quicksort_aux(v,min,max,cmp);
}

void merge(Vector* v, Vector* A, Vector* B, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    // INDICE A INSERTAR EL ELEMENTO ORDENADO
    int i=0;
    // INSERTO DE FORMA ORDENADA HASTA QUE SE ACABE ALGUNO DE LOS VECTORES
    while(vector_size(A)!=0 && vector_size(B)!=0)
    {
        if(cmp(vector_get(B,0),vector_get(A,0))>0)
        {
            vector_set(v,i,vector_get(A,0));
            vector_remove(A,0);
        }
        else
        {
            vector_set(v,i,vector_get(B,0));
            vector_remove(B,0);
        }
        i++;
    }
    // COMPLETO INSERTANDO EL RESTO DE ELEMENTOS DEL VECTOR RESTANTE
    if(vector_size(A)!=0)
    {
        while(vector_size(A)!=0)
        {
            vector_set(v,i,vector_get(A,0));
            vector_remove(A,0);
            i++;
        }
    }
    else
    {
        while(vector_size(B)!=0)
        {
            vector_set(v,i,vector_get(B,0));
            vector_remove(B,0);
            i++;
        }
    }
}

void mergesort(Vector* v, int (*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    // CASO BASE: EL VECTOR TIENE UN SOLO ELEMENTO
    if(!v || vector_size(v)==1) return;

    // CALCULO LA MITAD DEL VECTOR
    int vsize = vector_size(v);
    int half = vsize/2;

    // VECTORES ADICIONALES CON MITAD DEL ARREGLO ANTERIOR CADA UNO
    Vector* A = vector_new(half+1);
    if(!A) return;
    for(int i=0; i<half; i++)
    {
        vector_add(A,vector_get(v,i));
    }
    Vector* B = vector_new(half+1);
    if(!B) return;
    for(int i=half; i<vsize; i++)
    {
        vector_add(B,vector_get(v,i));
    }

    // LLAMADAS RECURSIVAS
    mergesort(A,cmp);
    mergesort(B,cmp);

    // CUANDO VUELVO LAS DEVUELVO ORDENADAS
    merge(v,A,B,cmp);
}
