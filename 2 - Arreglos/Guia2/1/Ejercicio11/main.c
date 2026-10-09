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

    vector *A = vector_sortcmp(v,isHigher);

    printf("sorted upwards:\n");
    vector_print(A,print);

    return 0;
}
