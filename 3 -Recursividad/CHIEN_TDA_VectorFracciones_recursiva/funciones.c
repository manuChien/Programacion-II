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

//MAXIMO ELEMENTO FRACCIONARIO DEL VECTOR
fraction* _max_fraction_aux(Vector* v, int index, fraction* maxFraction)
{
    if(index<0)
    {
        return maxFraction;
    }
    else
    {
        //SI MAYOR ENTONCES ESE SERA EL NUEVO ELEGIDO
        if(fraction_cmp(vector_get(v,index),maxFraction))
        {
            maxFraction = vector_get(v,index);
        }
        return _max_fraction_aux(v,index-1,maxFraction);
    }
}
fraction* max_fraction(Vector* v)
{
    if(!v) return NULL;

    int vectorSize = vector_size(v);
    fraction* maxFraction = vector_get(v,vectorSize-1);

    if(vectorSize>1)
    {
        maxFraction = _max_fraction_aux(v,vectorSize-2,maxFraction);
    }
    return maxFraction;
}
//-------------------------------------------------------------------------------------------------------------

//MAXIMO ELEMENTO FRACCIONARIO DEL VECTOR
fraction* _min_fraction_aux(Vector* v, int index, fraction* minFraction)
{
    if(index<0)
    {
        return minFraction;
    }
    else
    {
        //SI NO ES MAYOR ES MENOR O IGUAL, ENTONCES ESE SERA EL NUEVO ELEGIDO
        if(!fraction_cmp(vector_get(v,index),minFraction))
        {
            minFraction = vector_get(v,index);
        }
        return _min_fraction_aux(v,index-1,minFraction);
    }
}
fraction* min_fraction(Vector* v)
{
    //CHEQUEO QUE EL VECTOR SEA VALIDO
    if(!v) return NULL;

    int vectorSize = vector_size(v);
    fraction* minFraction = vector_get(v,vectorSize-1);

    if(vectorSize>1)
    {
        minFraction = _min_fraction_aux(v,vectorSize-2,minFraction);
    }
    return minFraction;
}
//-------------------------------------------------------------------------------------------------------------
//SUMA DE TODOS LOS ELEMENTOS FRACCIONARIOS DEL VECTOR
fraction* _suma_vector_aux(Vector* v, int index, fraction* sumaTotal)
{
    if(index<0)
    {
        return sumaTotal;
    }
    else
    {
        // VUELVO AL PRINCIPIO: INDEX=0
        fraction* aux = _suma_vector_aux(v,index-1,sumaTotal);
        // UNA VEZ QUE VOLVI A INDEX=0 COMIENZO A SUMAR: 0+1+2+3+4+5+6+7+8+9
        sumaTotal = fraction_add(vector_get(v,index),aux);
        // LIBERO EL AUXILIAR
        fraction_destroy(aux);
        // RETORNO LA VARIABLE ENVIADA POR PARAMETRO
        return sumaTotal;
    }
}
fraction* suma_vector(Vector* v)
{
    if(!v) return NULL;

    int vectorSize = vector_size(v);
    fraction* sumaTotal = fraction_new(0,1);

    if(vectorSize>1)
    {
        sumaTotal = _suma_vector_aux(v,vectorSize-1,sumaTotal);
    }

    return sumaTotal;
}
//-------------------------------------------------------------------------------------------------------------
//CALCULO DE PROMEDIO DE LAS FRACCIONES DEL VECTOR
fraction* promedio_vector(Vector* v)
{
    if(!v) return NULL;

    // ERROR: INVERTIDO EL NUMERADOR Y DENOMINADOR DE LA FRACCION QUE REPRESENTA LA CANTIDAD DE ELEMENTOS
    // fraction *aux = fraction_new(1,vector_size(v));
    fraction *aux = fraction_new(vector_size(v),1);
    fraction* suma = suma_vector(v);
    fraction* promedio = fraction_div(suma,aux);

    fraction_destroy(aux);
    fraction_destroy(suma);

    return promedio;
}
//-------------------------------------------------------------------------------------------------------------
//IMPRESION RECURSIVA DE VECTOR FRACCIONARIO
void _impresionRecursiva_vectorFraccionario_aux(Vector* v,int index)
{
    if(index == 0)
    {
        fraction_print(vector_get(v,index));
    }
    else
    {
        _impresionRecursiva_vectorFraccionario_aux(v,index-1);
        printf(" ");
        fraction_print(vector_get(v,index));
    }
}
void impresionRecursiva_vectorFraccionario(Vector* v)
{
    if(!v) return;

    int vectorSize = vector_size(v);

    printf("[");
    _impresionRecursiva_vectorFraccionario_aux(v,vectorSize-1);
    printf("]");
}
//-------------------------------------------------------------------------------------------------------------
//IMPRESION RECURSIVA DE VECTOR FRACCIONARIO
void _impresionRecursivaDescendente_vectorFraccionario_aux(Vector* v,int index)
{
    if(index == 0)
    {
        fraction_print(vector_get(v,index));
    }
    else
    {
        fraction_print(vector_get(v,index));
        printf(" ");
        _impresionRecursivaDescendente_vectorFraccionario_aux(v,index-1);
    }
}
void impresionRecursivaDescendente_vectorFraccionario(Vector* v)
{
    if(!v) return;

    int vectorSize = vector_size(v);

    printf("[");
    _impresionRecursivaDescendente_vectorFraccionario_aux(v,vectorSize-1);
    printf("]");
}
