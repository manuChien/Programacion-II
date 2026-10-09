#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

node* lista_nuevaSentidoInverso(node* h)
{
    if(!h) return NULL;

    node* tail = malloc(sizeof(node));
    tail->data = h->data;
    tail->next = NULL;
    node* headNewList = tail;

    h = h->next;

    while(h!=NULL)
    {
        node* newNode = malloc(sizeof(node));
        newNode->data = h->data;
        // El nuevo nodo apunta al primer elemento del anterior
        newNode->next = headNewList;
        // El head apunta a este primer elemento nuevo
        headNewList = newNode;

        h = h->next;
    }

    return headNewList;
}
