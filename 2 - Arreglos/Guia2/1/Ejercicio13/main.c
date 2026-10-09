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

    printf("El elemento %d esta en la posicion %d\n",4,vector_secuentialSearch(v,4));

    vector_sortElements(v,isHigher);
    vector_print(v,print);
    printf("El elemento %d esta en la posicion %d",4,vector_binarySearch(v,4));

    return 0;
}
