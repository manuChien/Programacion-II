#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(10);
    vectorRandom(v);

    vector_print(v,print);

    int max = vector_maxmin(v,higher);
    int min = vector_maxmin(v,lower);

    printf("max: %d\nmin: %d",max,min);

    return 0;
}
