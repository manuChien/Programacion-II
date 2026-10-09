#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void eliminarCoincidentesA(node* h, NODE_ELEMENT value)
{
//ESTO ES SIEMPRE QUE EL ACTUAL Y SIGUIENTE SEAN NO NULOS
    while(h!=NULL && h->next != NULL)
    {
        if((h->next)->data == value)
        {
        //SI COINCIDE PUENTEO Y LIBERO EL NODO HUERFANO (AL QUE NO ES APUNTADO POR NADIE)
            node* a_eliminar = h->next;
            h->next = (h->next)->next;
            free(a_eliminar);
        }else
        {
        //SI NO COINCIDE PASO AL SIGUIENTE, Y SI SE ELIMINA UN NODO NO PASO AL SIGUIENTE PUES EVALUO AL NUEVO PUENTEADO DIRECTAMENTE (ME SALTEARIA NODOS SINO)
            h = h->next;
        }
    }
}

void lista_eliminaRepetidos(node** h)
{
    if(!h || !(*h)) return;

    node* n = (*h);
//EVALUO TODOS LOS NODOS
    while(n != NULL)
    {
    //EVALUO SOLO A PARTIR DEL ACTUAL, LOS ANTERIORES YA SE TRABAJARON
        eliminarCoincidentesA(n,n->data);
        n = n->next;
    }
}
