#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charset.h"

int main()
{
    printf("Hello world!\n");

    char oracion[20] = "hola,,,como,,estas";

    int cantidad = string_wordCount(oracion);

    printf("%s \n",oracion);
    printf("%d",cantidad);

    return 0;
}
