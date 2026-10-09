#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"
#include "vector.h"
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    vector *v = vector_new(100);
    for(int i=0; i<100; i++)
    {
        fraction *f = fraction_new(rand()%10 +1,rand()%10+1);
        vector_add(v,f);
    }

    vector_print(v,printFraction);

    return 0;
}
