#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "fracciones.h"
#include "funciones.h"

int main()
{
    printf("Hello World!\n");

    Vector* v1 = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(v1,fraction_new(rand()%5+1,rand()%5+1));
    }
    ordenarVector(v1);
    vector_print(v1,fraction_print);

    fraction* f = fraction_new(5,3);
    fraction_print(f);
    if(buscarElementoVectorOrdenadoFracciones(v1,f)>=0)
    {
        printf("Esta\n");
    }else
    {
        printf("NO esta\n");
    }

    return 0;
}
