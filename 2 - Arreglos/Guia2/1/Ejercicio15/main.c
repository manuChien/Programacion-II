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

    Vector* v2 = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(v2,fraction_new(rand()%5+1,rand()%5+1));
    }
    ordenarVector(v2);
    vector_print(v2,fraction_print);

    Vector* resultado = mezclarVectoresOrdenados(v1,v2,fraction_cmp);
    vector_print(resultado,fraction_print);

    return 0;
}
