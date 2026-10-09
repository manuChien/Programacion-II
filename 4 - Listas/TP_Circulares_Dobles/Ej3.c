#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void SLLtoCLL(Node** h)
{
    if(!h) return;

    Node* head = *h;
    Node* current = *h;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = head;
}
