#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    printf("Hello world!\n");

    // SLL

    Node* head = malloc(sizeof(Node));
    Node* first = malloc(sizeof(Node));
    Node* second = malloc(sizeof(Node));
    Node* tail = malloc(sizeof(Node));

    head->value = 1;
    head->next = first;

    first->value = 2;
    first->next = second;

    second->value = 3;
    second->next = tail;

    tail->value = 4;
    tail->next = NULL;

    // CLL

    Node* head1 = malloc(sizeof(Node));
    Node* first1 = malloc(sizeof(Node));
    Node* second1 = malloc(sizeof(Node));
    Node* tail1 = malloc(sizeof(Node));

    head1->value = 4;
    head1->next = first1;

    first1->value = 3;
    first1->next = second1;

    second1->value = 2;
    second1->next = tail1;

    tail1->value = 1;
    tail1->next = head1;

    if(CLLinversoSLL_recursivo(tail1,head))
    {
        printf("INVERSOS");
    } else

    {
        printf("NO INVERSOS");
    }

    return 0;
}
