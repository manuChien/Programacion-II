#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"
#include "lista_dinamica.h"

int main()
{
    printf("Hello world!\n");

    List* lista = list_new(10);
    for(int i=0; i<10; i++)
    {
        list_append(lista,i+1);
    }

    printf("%d ",list_first(lista));

    for(int i=0; i<9; i++)
    {
        printf("%d ",list_next(lista));
    }

    return 0;
}
