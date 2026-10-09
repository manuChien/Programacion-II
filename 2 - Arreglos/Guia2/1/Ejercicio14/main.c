#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "fracciones.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(10);
    for(int i=0; i<10; i++)
    {
        fraction *f = fraction_new(rand()%10 +1,rand()%10+1);
        vector_add(v,f);
    }
    vector *simplified = vector_simplifyFrac(v);

    vector_print(v,print);
    vector_print(simplified,printFraction);

    return 0;
}
