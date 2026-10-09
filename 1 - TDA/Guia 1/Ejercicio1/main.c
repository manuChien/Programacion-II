#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charset.h"

int main()
{
    printf("Hello world!\n");

    charset* conjuntoA = charset_init();
    charset* conjuntoB = charset_init();
    charset* interseccion = charset_init();

    char A[5] = "ojos";
    char B[5] = "mijo";

    charset_add_str(conjuntoA,A);
    charset_add_str(conjuntoB,B);

    interseccion = charset_intersection(conjuntoA,conjuntoB);

    charset_print(interseccion);
    char *stringInterseccion = malloc(100);
    stringInterseccion = charset_tostring(interseccion);
    printf("%s",stringInterseccion);

    charset_free(conjuntoA);
    charset_free(conjuntoB);
    charset_free(interseccion);

    return 0;
}
