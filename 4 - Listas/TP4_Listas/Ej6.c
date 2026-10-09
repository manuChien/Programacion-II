#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void lista_append(node** h, NODE_ELEMENT value)
{

//    node* cola = (*h);

    //ENLAZO A LA COLA VIEJA A LA COLA NUEVA
    node* nuevaCola = malloc(sizeof(node));
    nuevaCola->next = *h;
    nuevaCola->data = value;
    *h = nuevaCola;
}

void lista_paresImpares(node* original, node** pares, node** impares)
{
    while(original!=NULL)
    {
        if(original->data % 2 == 0)
        {
            lista_append(pares,original->data);
        } else
        {
            lista_append(impares,original->data);
        }

        original = original->next;
    }
}
