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

    int frequency = vector_elementFrequency(v,1);

    printf("element: %d\nfrequency: %d",1,frequency);

    return 0;
}
