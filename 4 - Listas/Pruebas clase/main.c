#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
}node;

node* node_new(int data)
{
    node* result = malloc(sizeof(node));
    //CHEQUEO SI ES NULL, ES RESPONSABILIDAD DEL INVOCADOR DE VERIFICAR QUE PASA SI ES NULL
    if(result!=NULL)
    {
        result->data = data;
        result->next = NULL;
    }
    return result;
}

int main()
{
    printf("Hello world!\n");

    //FORMA NO RECOMENDADA
    node* lista = NULL; // CREO UNA LISTA VACIA

    node* nodo = malloc(sizeof(node)); //RESERVO MEMORIA PARA UN NODO
    nodo->data = 5;
    nodo->next = NULL;

    node* nodo2 = malloc(sizeof(node));
    nodo->data = 7;
    nodo->next = NULL;

    //ENLAZO LA LISTA, HEAD "lista" apunta a nodo, nodo->next apunta a nodo2
    lista = nodo;
    nodo->next = nodo2;

    //FORMA MEJOR
    node* lista2 = NULL;

    node* nodo3 = node_new(5);
    node* nodo4 = node_new(7);

    lista2 = nodo3;
    nodo3->next = nodo4;

    return 0;
}
