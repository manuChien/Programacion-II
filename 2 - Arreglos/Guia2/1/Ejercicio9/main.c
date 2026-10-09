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

    vector *A = vector_sort(v,vector_upward);
    vector *B = vector_sort(v,vector_downward);

    printf("sorted upwards:\n");
    vector_print(A,print);
    printf("sorted downwards:\n");
    vector_print(B,print);

    vector *pairs = vector_pairElemFreq(v);

    printf("Pair element-frequency\n");
    vector_print(pairs,print);

    return 0;
}
