#include <stdio.h>
#include <stdlib.h>
#include "elementos.h"

enum _TipoElem
{
    ELEM_NUMERO,
    ELEM_OPERADOR,
    ELEM_ERROR = -1
};

struct _Elemento
{
    enum _TipoElem tipo;
    union
    {
        int numero;
        char operador;
    } dato;
};

Elemento* Elem_createNum(int num)
{
    Elemento* newElem = malloc(sizeof(Elemento));
    if(!newElem) return NULL;

    newElem->tipo = ELEM_NUMERO;
    newElem->dato.numero = num;

    return newElem;
}

Elemento* Elem_createOp(char op)
{
    Elemento* newElem = malloc(sizeof(Elemento));
    if(!newElem) return NULL;

    newElem->tipo = ELEM_OPERADOR;
    newElem->dato.operador = op;

    return newElem;
}

TipoElem Elem_getType(Elemento* elem)
{
    if(!elem) return ELEM_ERROR;
    return elem->tipo;
}

int Elem_getNum(Elemento* elem)
{
    if(!elem) return DEFAULT_NUM;
    return elem->dato.numero;
}

char Elem_getOp(Elemento* elem)
{
    if(!elem) return DEFAULT_OP;
    return elem->dato.operador;
}

void Elem_destroy(Elemento* elem)
{
    free(elem);
}
