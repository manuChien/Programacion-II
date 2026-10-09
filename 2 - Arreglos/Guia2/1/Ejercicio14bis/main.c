#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "fracciones.h"
#include "funciones.h"

int main()
{
    printf("Hello World!\n");

    Vector* v = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(v,fraction_new(rand()%5+1,rand()%5+1));
    }

    vector_print(v,fraction_print);

    ordenarVector(v);

    vector_print(v,fraction_print);

    eliminarFraccionesRepetidas(v);

    vector_print(v,fraction_print);

    return 0;
}
