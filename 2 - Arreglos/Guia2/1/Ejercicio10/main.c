#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"


void free_int(VECTOR_ELEMENT e)
{
    //do nothing
}

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(10);
    vectorRandom(v);

    vector_print(v,print);

    vector *A = vector_sort(v,vector_upward);

    printf("sorted upwards:\n");
    vector_print(A,print);

    printf("First match at index: %d",vector_firstMatchSorted(v,free_int));

    return 0;
}
