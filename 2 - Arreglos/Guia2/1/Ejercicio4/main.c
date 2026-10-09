#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(10);
    vectorRandom(v);
    int sumatoria = vector_sumatoria(v);
    vector_print(v,print);
    int resultado = 0;
    for(int i=0; i<vector_size(v); i++)
    {
        printf("%d\t+\t%d\t=\t%d\n",resultado,vector_get(v,i),resultado+vector_get(v,i));
        resultado+=vector_get(v,i);
    }
    printf("%d",sumatoria);

    return 0;
}
