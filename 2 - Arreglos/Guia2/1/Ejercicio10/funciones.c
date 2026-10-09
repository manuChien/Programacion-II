#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"
int vector_firstMatchSorted(vector *v, void (*free_elem)(VECTOR_ELEMENT e))
{
    if (v== NULL) return -1;

    vector *sorted = vector_sort(v,vector_upward);
    int size = vector_size(v);
    int firstMatch = 0;
    int i=0;
    while (i<size && vector_get(v,i)!=vector_get(sorted,i))
        i++;

    while (!vector_isempty(sorted))
        free_elem(vector_remove(sorted,0));
    vector_free(sorted);


    return (i<size)?i:-1;

    /*


    int i = 0;
    do
    {
        if(vector_get(v,i)==vector_get(sorted,i))
        {
            firstMatch = i;
        }else
        {
            i++;
        }
    }while(vector_get(v,i-1)!=vector_get(sorted,i-1) && i<size);

    if(i==size)
    {
        printf("There is no match.\n");
    }

    vector_free(sorted);
    return firstMatch;

    */
}

vector *vector_pairElemFreq(vector *v)
{
    if(vector_isempty(v))
    {
        printf("The vector logged is not valid.\n");
        return NULL;
    }
    vector *sorted = vector_sort(v,vector_upward);
    int size = vector_size(sorted);
    int element = vector_get(sorted,0);
    int frequency = 1;
    vector *answer = vector_new(1);

    for(int i=1; i<size; i++)
    {
        if(element != vector_get(sorted,i))
        {
            vector_add(answer,element);
            vector_add(answer,frequency);
            element = vector_get(sorted,i);
            frequency = 1;
        }else frequency++;
    }
    //EL ULTIMO SE AGREGA APARTE PORQUE NO SE VA A CUMPLIR LA CONDICION DE QUE CAMBIE EL VALOR DEL ELEMENTO PUES LLEGO AL FINAL
    vector_add(answer,element);
    vector_add(answer,frequency);

    return answer;
}

vector *vector_sort(vector *v,void (*operation)(vector*,int))
{
    int size = vector_size(v);

    vector *aux = vector_new(size);
    for(int i=0; i<size; i++)
    {
        vector_add(aux,vector_get(v,i));
    }

    operation(aux,size);

    return aux;
}

void vector_upward(vector *v, int size)
{
    VECTOR_ELEMENT swap;
    while(size>0)
    {
        for(int i=0; i<(size-1); i++)
        {
            if(vector_get(v,i)>vector_get(v,i+1))
            {
                swap = vector_get(v,i+1);
                vector_set(v,i+1,vector_get(v,i));
                vector_set(v,i,swap);
            }
        }
        size--;
    }
}
void vector_downward(vector *v, int size)
{
    VECTOR_ELEMENT swap;
    while(size>0)
    {
        for(int i=0; i<(size-1); i++)
        {
            if(vector_get(v,i)<vector_get(v,i+1))
            {
                swap = vector_get(v,i+1);
                vector_set(v,i+1,vector_get(v,i));
                vector_set(v,i,swap);
            }
        }
        size--;
    }
}

int vector_maxelementFreq(vector *v)
{
    int size = vector_size(v);
    int max = vector_get(v,0);
    int frequency = 0;

    for(int i=0; i<size; i++)
    {
        if(max==vector_get(v,i)) frequency++;
        if(max<vector_get(v,i))
        {
            //SI ENCUENTRO UN ELEMENTO MAYOR REINICIO EL CONTADOR
            max = vector_get(v,i);
            frequency = 1;
        }
    }

    return frequency;
}

int vector_elementFrequency(vector *v,VECTOR_ELEMENT value)
{
    int size = vector_size(v);
    int frequency = 0;

    for(int i=0; i<size; i++)
    {
        if(vector_get(v,i) == value) frequency++;
    }

    return frequency;
}

VECTOR_ELEMENT vector_maxmin(vector *v,VECTOR_ELEMENT(*operacion)(VECTOR_ELEMENT,VECTOR_ELEMENT))
{
    VECTOR_ELEMENT answer = vector_get(v,0);
    int size = vector_size(v);

    for(int i=1; i<size; i++)
    {
        answer = operacion(answer,vector_get(v,i));
    }
    return answer;
}

VECTOR_ELEMENT higher(VECTOR_ELEMENT A,VECTOR_ELEMENT B)
{
    if(A>B) return A;
    return B;
}

VECTOR_ELEMENT lower(VECTOR_ELEMENT A,VECTOR_ELEMENT B)
{
    if(A<B) return A;
    return B;
}

vector *vector_sumaVectores(vector *A,vector *B)
{
    if(vector_size(A)!=vector_size(B))
    {
        printf("The arrays size doesn't match.\n");
        return NULL;
    }

    int size = vector_size(A);
    vector *answer = vector_new(size);
    for(int i=0; i<size; i++)
    {
        vector_add(answer,suma(vector_get(A,i),vector_get(B,i)));
    }
    return answer;
}

void vectorRandom(vector *v)
{
    if(v==NULL) return;

    int randomNum;
    for(int i=0; i<10; i++)
    {
        randomNum = rand() %4 + 1;
        vector_add(v,randomNum);
    }
}
void print(VECTOR_ELEMENT x)
{
    printf("%d",x);
}

int vector_serieOperaciones(vector *v, int(*operacion)(int,int))
{
    int acumulador = vector_get(v,0);
    int size = vector_size(v);
    for(int i=1; i<size; i++)
    {
        acumulador = operacion(acumulador,vector_get(v,i));
    }
    return acumulador;
}

int suma(int x, int y)
{
    return x+y;
}

int resta(int x, int y)
{
    return x-y;
}

int producto(int x, int y)
{
    return x*y;
}

int cociente(int x, int y)
{
    if(y==0)
    {
        fprintf(stderr, "ERROR: Hay terminos 0 en la division.\n");
        return 0;
    }
    return x/y;
}
