#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

struct _list_node
{
    DLIST_ELEMENT value;
    struct _list_node *next;
};

struct _List
{
    list_node* head;
    list_node* current;
    int maxsize;
    int cursize;
};

List* list_new(int maxsize)
{
    if(maxsize<1) return NULL;

    List* newList = malloc(sizeof(List));
    if(!newList) return NULL;

    newList->current = NULL;
    newList->head = NULL;
    newList->maxsize = maxsize;
    newList->cursize = 0;

    return newList;
}

int list_free(List *L)
{
    if(!L) return -1;

    // ME PARO EN EL PRINCIPIO
    list_node* node = L->head;
    // MIENTRAS QUE HAYAN NODOS LOS VOY LIBERANDO
    while(node!=NULL)
    {
        list_node* next = node->next;
        free(node);
        node = next;
    }
    // LIBERO LA LISTA
    free(L);

    return 1;
}

int list_length(List *L)
{
    if(!L) return -1;

    return L->cursize;
}

int list_append(List *L, DLIST_ELEMENT elem)
{
    if(!L || L->cursize>=L->maxsize) return -1;

    // ME PARO EN EL PRINCIPIO
    list_node* curNode = L->head;

    list_node* newNode = malloc(sizeof(list_node));
    if(!newNode) return -1;
    newNode->value = elem;
    newNode->next = NULL;

    // EN CASO DE QUE LA LISTA ESTE VACIA SERA EL PRIMER ELEMENTO
    if(L->cursize == 0)
    {
        L->head = newNode;
    }
    else
        // EN CASO DE QUE LA LISTA NO ESTE VACIA RECORRO HASTA EL ULTIMO ELEMENTO Y SU SIGUIENTE SERA EL NUEVO
    {
        while(curNode->next!=NULL)
        {
            curNode = curNode->next;
        }

        curNode->next = newNode;
    }
    L->current = newNode;
    L->cursize++;

    return 1;
}

int list_insert(List *L, int index, DLIST_ELEMENT elem)
{
    if(!L || index > L->cursize || index<0 || L->cursize>=L->maxsize) return -1;

    list_node* newNode = malloc(sizeof(list_node));
    if(!newNode) return -1;
    newNode->value = elem;

    // ME PARO EN EL PRIMER NODO
    list_node* curNode = L->head;

    if(index==0)
    {
        L->head = newNode;
        newNode->next = curNode;
    }
    else
    {
        // AVANZO HASTA UNO ANTES DEL INDEX
        for(int i=0; i<(index-1); i++)
        {
            curNode = curNode->next;
        }
        // RECONECTO LOS NODOS
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
    L->cursize++;

    return 1;
}

DLIST_ELEMENT list_first(List *L)
{
    if(!L) return DLIST_DEFAULT;

    if(!L->head)
    {
        return DLIST_DEFAULT;
    }
    else
    {
        L->current = L->head;
        return L->head->value;
    }
}

DLIST_ELEMENT list_next(List *L)
{
    if(!L || !L->current || !L->current->next)
    {
        return DLIST_DEFAULT;
    }
    else
    {
        L->current = L->current->next;
        return L->current->value;
    }
}

int list_eol(List *L)
{
    if(!L) return 0;

    if(!L->head || !L->current->next)
    {
        return 1;
    } else
    {
        return 0;
    }
}

DLIST_ELEMENT list_remove (List *L)
{
    if(!L|| L->cursize == 0 || !L->current) return DLIST_DEFAULT;

    list_node* aEliminar = L->current;
    DLIST_ELEMENT eliminatedValue;

    if(L->current == L->head)
    {
        eliminatedValue = L->head->value;
        L->head = L->head->next;
        L->current = L->head;
    } else
    {
        eliminatedValue = L->current->value;
        L->current = L->head;
        while(L->current->next != aEliminar)
        {
            L->current = L->current->next;
        }
        L->current->next = aEliminar->next;
        L->current = aEliminar->next;
    }

    free(aEliminar);
    L->cursize--;
    return eliminatedValue;
}

DLIST_ELEMENT list_get(List *L, int index)
{
    if(!L || index<0 || index>=L->cursize || L->cursize==0) return DLIST_DEFAULT;

    list_node* curNode = L->head;
    for(int i=0; i<index; i++)
    {
        curNode = curNode->next;
    }
    return curNode->value;
}

bool list_isempty(List *L)
{
    return (!L || L->cursize==0);
}

bool list_isfull(List *L)
{
    if(!L) return false;
    return (L->cursize)==(L->maxsize);
}
