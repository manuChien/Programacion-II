#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int lista_promedio(node* h)
{
    if(!h) return -1;

    int acumulador = h->data;
    h = h->next;
    int contador = 1;
    while(h!=NULL)
    {
        acumulador+=(h->data);
        contador++;
        h = h->next;
    }

    return acumulador/contador;
}

int lista_maximoValorListaDeListas(node** h)
{
    if(!h) return -1;

    int maximo = lista_promedio(*h);
    h++;

    while(*h != NULL)
    {
        int promedio = lista_promedio(*h);
        if(promedio > maximo)
        {
            maximo = promedio;
        }
        h++;
    }

    return maximo;
}
