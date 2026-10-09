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
