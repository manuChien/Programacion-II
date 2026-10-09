#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funcion.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(100);

    vectorRandom(v);
    vector_print(v,print);

    return 0;
}
