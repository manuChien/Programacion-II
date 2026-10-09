#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "fracciones.h"

//-------------------------------------------------------------------------------------------------------------
int mcd(int mayor, int menor)
{
    if(menor>0) return mcd(menor,mayor%menor);
    return mayor;
}
//-------------------------------------------------------------------------------------------------------------

void ordenarVector(Vector* v)
{
    for(int i=0; i<vector_size(v)-1; i++)
    {
        for(int j=0; j<vector_size(v)-i-1; j++)
        {
            if(fraction_cmp(vector_get(v,j),vector_get(v,j+1))>0)
            {
                fraction* aux = vector_get(v,j);
                vector_set(v,j,vector_get(v,j+1));
                vector_set(v,j+1,aux);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------
void eliminarFraccionesRepetidas(Vector* v)
{
    if(!v) return;

    ordenarVector(v);

    int pos = 0;

    while(pos<vector_size(v)-1)
    {
        if(fraction_cmp(vector_get(v,pos),vector_get(v,pos+1))==0)
        {
            fraction_destroy(vector_get(v,pos+1));
            vector_remove(v,pos+1);
        }
        else
        {
            pos++;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------
Vector* mezclarVectoresOrdenados(Vector* v1, Vector* v2,int(*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    if(!v1 || !v2 || !cmp) return NULL;

    Vector* resultado = vector_new(1);
    vector_add(resultado,vector_get(v1,0));

//AGREGO LOS ELEMENTOS DEL PRIMER VECTOR AL VECTOR RESULTADO VERIFICANDO QUE NO SE REPITAN LOS RESULTADOS, COMO ESTAN ORDENADOS SOLO NECESITO COMPARAR EL ULTIMO ELEMENTO
    for(int i=0; i<vector_size(v1); i++)
    {
        if(cmp(vector_get(resultado,vector_size(resultado)-1),vector_get(v1,i))!=0)
        {
            vector_add(resultado,vector_get(v1,i));
        }
    }

//EN ESTA VUELTA, SI EL ELEMENTO DEL SEGUNDO VECTOR NO SE ENCUENTRA EN EL VECTOR RESULTANTE LO AGREGO
    for(int i=0; i<vector_size(v2); i++)
    {
        int presente = 0;
        for(int j=0; j<vector_size(resultado); j++)
        {
            if(cmp(vector_get(resultado,j),vector_get(v2,i))==0)
            {
                presente++;
            }
        }
        if(presente==0)
        {
            vector_add(resultado,vector_get(v2,i));
        }
    }

    ordenarVector(resultado);

    return resultado;
}
//-------------------------------------------------------------------------------------------------------------
int buscarElementoVectorOrdenadoFracciones(Vector* v, VECTOR_ELEMENT value)
{
    if(!v) return -1;

    int index = -1;

    int pos = 0;
    while(pos<vector_size(v) && index==-1)
    {
        if(fraction_cmp(vector_get(v,pos),value)==0)
        {
            index = pos;
        }
        pos++;
    }

    return index;
}
