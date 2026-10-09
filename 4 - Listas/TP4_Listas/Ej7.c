#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

node* lista_fusionarOrdenadoInt(node** A, node** B, int cmp(int,int))
{
    if(!A || !(*A) || !B || !(*B)) return NULL;

// EN CASO DE QUE A ESTE VACIA RETORNO B
    if(!(*A))   return (*B);
// EN CASO DE QUE B ESTE VACIA RETORNO A
    if(!(*B))   return (*A);

// HEAD ES EL PUNTERO A LISTA A DEVOLVER
    node* head = NULL;
// TAIL ES EL ULTIMO ELEMENTO, EL QUE VA A IR TRACKEANDO EL FINAL
    node* tail = NULL;
// ITERO HASTA QUE ALGUNA DE LAS LISTAS SE ACABE
    while((*A)!=NULL && (*B)!=NULL)
    {
    // EL NODO A CORTAR Y APPEND AL RESULTADO
        node* elegido = NULL;
    // ELIJO EL NODO Y DE LA LISTA ELEGIDA Y DE ESE AVANZO UNO, CORTO EL ENLAZADO FRONTAL
        if( cmp( (*A)->data , (*B)->data ) <= 0)
        {
            elegido = (*A);
            (*A) = (*A)->next;
        } else
        {
            elegido = (*B);
            (*B) = (*B)->next;
        }
    // CORTO EL ENLAZADO TRASERO DEL NODO ELEGIDO
        elegido->next = NULL;

    // SI ES EL PRIMER ELEMENTO HEAD ES EL NODO ELEGIDO
        if(!head)
        {
            head = elegido;
            tail = head;
        } else
        {
    // ENLAZO AL FINAL Y AVANZO UNO
            tail->next = elegido;
            tail = tail->next;
        }
    }

    //SI QUEDO VACIO UNO ENLAZO AL FINAL AL OTRO
    if(!(*A)) tail->next = (*B);
    if(!(*B)) tail->next = (*A);

    return head;
}
