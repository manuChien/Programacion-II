#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(10);
    vectorRandom(v);
    int sumatoria = vector_serieOperaciones(v,suma);
    int restatoria = vector_serieOperaciones(v,resta);
    int productoria = vector_serieOperaciones(v,producto);
    int divisoria = vector_serieOperaciones(v,cociente);
    vector_print(v,print);
    printf("sumatoria: %d\nrestatoria: %d\nproductoria: %d\ndivisoria: %d\n",sumatoria,restatoria,productoria,divisoria);

    return 0;
}
