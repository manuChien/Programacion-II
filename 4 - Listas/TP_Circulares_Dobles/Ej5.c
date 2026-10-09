#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "stack_dynamic.h"

/* Resolver utilizando una pila */
int CLLinversoSLL_STACK(Node* CLL, Node* SLL)
{
    if(!CLL && !SLL) return 1;
    if(!CLL || !SLL) return 0;

    // CREO UN STACK TEMPORAL PARA CARGAR EL SLL
    Dstack* stack = Dstack_new();
    if(!stack) return 0;

    // CARGO LOS ELEMENTOS DEL SLL EN EL STACK Y CUENTO LOS ELEMENTOS DE LA SLL
    Node* current = SLL;
    int lenSLL = 0;
    while(current != NULL)
    {
        Dpush(stack,current->value);
        current = current->next;
        lenSLL++;
    }

    // CUENTO LA CANTIDAD DE ELEMENTOS DEL CLL
    // SETEO AL PUNTERO DEL CLL EN HEAD
    Node* contarCLL = CLL->next;
    int lenCLL = 0;
    do
    {
        lenCLL++;
        contarCLL = contarCLL->next;
    }
    while(contarCLL != CLL->next);

    // SI LAS CANTIDADES DE CLL Y SLL DIFIEREN NO PUEDEN SER INVERSOS
    if(lenCLL != lenSLL)
    {
        Dstack_free(stack);
        return 0;
    }

    // FLAG PARA SI SON INVERSOS
    int inversos = 1;
    // SETEO CURRENT AL HEAD DEL CLL
    Node* currentCLL = CLL->next;
    // COMPARO HASTA QUE SE ACABE EL STACK
    while(!Dstack_isempty(stack) && inversos==1)
    {
        // SI EL ELEMENTO DEL STACK(ATRAS PARA DELANTE) ES DISTINTO AL ELEMENTO DEL CLL(DELANTE PARA ATRAS) LEVANTO FLAG
        DSTACK_ELEM curValue = Dpop(stack);
        if(curValue != currentCLL->value)
        {
            inversos = 0;
        }
        // AVANZO LINEALMENTE EL CLL
        currentCLL = currentCLL->next;
    }

    Dstack_free(stack);
    return inversos;
}

/* Resolver en forma recursiva */
void _CLLinversoSLL_aux(Node** CLLaux, Node* SLL, int* inversos)
{
    // CASO BASE, ULTIMO DE SLL, PRIMERO DE CLL
    if(SLL->next == NULL)
    {
        // SI NO COINCIDEN PONGO INVERSOS EN 0 Y CORTO LA RECURSION
        if(SLL->value != (*CLLaux)->value)
        {
            *inversos = 0;
            return;
        }
        *CLLaux = (*CLLaux)->next;
    } else
    {
        // AVANZO HASTA EL FINAL DE SLL MANTENIENDO CLL EN EL PRIMERO
        _CLLinversoSLL_aux(CLLaux,SLL->next,inversos);
        // SI NO COINCIDEN PONGO INVERSOS EN 0 Y CORTO LA RECURSION
        if(SLL->value != (*CLLaux)->value)
        {
            *inversos = 0;
            return;
        }
        // AVANZO CLL
        *CLLaux = (*CLLaux)->next;
    }
}

int CLLinversoSLL_recursivo(Node* CLL, Node* SLL)
{
    if(!CLL && !SLL) return 1;
    if(!CLL || !SLL) return 0;

    Node* current = SLL;
    int lenSLL = 0;
    while(current != NULL)
    {
        current = current->next;
        lenSLL++;
    }

    // CUENTO LA CANTIDAD DE ELEMENTOS DEL CLL
    // SETEO AL PUNTERO DEL CLL EN HEAD
    Node* contarCLL = CLL->next;
    int lenCLL = 0;
    do
    {
        lenCLL++;
        contarCLL = contarCLL->next;
    }
    while(contarCLL != CLL->next);

    // SI LAS CANTIDADES DE CLL Y SLL DIFIEREN NO PUEDEN SER INVERSOS
    if(lenCLL != lenSLL)
    {
        return 0;
    }

    // FLAG SI SON INVERSOS, SI NO CAMBIA EL FLAG
    int inversos = 1;
    // COMIENZO EN EL HEAD DEL CLL
    Node* CLLaux = CLL->next;
    _CLLinversoSLL_aux(&CLLaux,SLL,&inversos);

    return (inversos==1) ? 1:0;
}
