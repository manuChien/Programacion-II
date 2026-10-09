#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic.h"

int calculoPostFijo(Dqueue* q)
{
    if(!q) return DEFAULT_NUM;

    int result = 0;

    DQUEUE_ELEM current = Ddequeue(q);
    int a = Elem_getNum(current);
    Denqueue(q,current);
    current = Ddequeue(q);
    int b = Elem_getNum(current);
    Denqueue(q,current);
    current = Ddequeue(q);
    char op = Elem_getOp(current);
    Denqueue(q,current);
    switch(op)
    {
    case '+':
        result = a+b;
        break;
    case '-':
        result = a-b;
        break;
    case '/':
        result = a/b;
        break;
    case '*':
        result = a*b;
        break;
    }
    for(int i=0; i<Dqueue_getsize(q)-3; i++)
    {
        a = result;
        current = Ddequeue(q);
        b = Elem_getNum(current);
        Denqueue(q,current);
        current = Ddequeue(q);
        op = Elem_getOp(current);
        Denqueue(q,current);

        switch(op)
        {
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '/':
            result = a/b;
            break;
        case '*':
            result = a*b;
            break;
        }
    }

    return result;
}

int main()
{
    printf("Hello world!\n");

    Dqueue* q = Dqueue_new_with(10);
    if(!q) return 0;

    Elemento* elem1 = Elem_createNum(1);
    Denqueue(q,elem1);
    Elemento* elem2 = Elem_createNum(2);
    Denqueue(q,elem2);
    Elemento* elem3 = Elem_createOp('+');
    Denqueue(q,elem3);
    Elemento* elem4 = Elem_createNum(3);
    Denqueue(q,elem4);
    Elemento* elem5 = Elem_createOp('*');
    Denqueue(q,elem5);
    Elemento* elem6 = Elem_createNum(4);
    Denqueue(q,elem6);
    Elemento* elem7 = Elem_createOp('+');
    Denqueue(q,elem7);

    printf("%d\n",calculoPostFijo(q));

    return 0;
}
