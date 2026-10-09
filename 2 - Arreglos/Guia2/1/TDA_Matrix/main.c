#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void printInt(void* elem)
{
    printf("%d",*(int*)elem);
}

int main()
{
    printf("Hello world!\n");

    matrix* m = matrix_new(3,3);

    int n = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int* numero = malloc(sizeof(int));
            *numero = ++n;
            matrix_set(m,i,j,numero);
        }
    }

    matrix_print(m,printInt);

    matrix_free(m);

    return 0;
}
