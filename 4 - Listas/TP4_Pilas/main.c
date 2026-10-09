#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void printInt(int A)
{
    printf("%d ",A);
}

int main()
{
    printf("Hello world!\n");

    char operacion[] = "la ruta nos aporto otro paso natural";

    printf("%s\n",operacion);

    if(esPalindroma(operacion)==1)
    {
        printf("Es palindroma\n");
    } else
    {
        printf("No es palindroma\n");
    }

    return 0;
}
