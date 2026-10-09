#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    vector *A = vector_new(10);
    vectorRandom(A);
    vector *B = vector_new(10);
    vectorRandom(B);

    vector *C = vector_sumaVectores(A,B);

    vector_print(A,print);
    vector_print(B,print);
    vector_print(C,print);

    return 0;
}
