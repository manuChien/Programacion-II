#include <stdio.h>
#include <stdlib.h>
#include "stack_dynamic.h"

void limpiarBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printInt(DSTACK_ELEM n)
{
    printf("%d",n);
}

void printStackRec(Dstack* s, void(*print)(DSTACK_ELEM))
{
    if(!s || Dstack_isempty(s)) return;

    DSTACK_ELEM current = Dpop(s);

    printStackRec(s,print);

    print(current);

    Dpush(s,current);
}

int _movHanoi(Dstack* origen, Dstack* destino)
{
    if (!origen || !destino) return 0;

    if (Dstack_isempty(origen))
    {
        printf("Movimiento no valido: la pila de origen esta vacia.\n");
        return 0;
    }

    // Si el destino NO está vacío y el disco que quiero poner es mayor al que ya está:
    if (!Dstack_isempty(destino) && (intptr_t)Dtop(origen) > (intptr_t)Dtop(destino))
    {
        printf("Movimiento no valido: no se puede colocar un disco mayor sobre uno menor.\n");
        return 0;
    }

    Dpush(destino, Dpop(origen));
    return 1;
}

void hanoi(int cantDiscos)
{
    if(cantDiscos<1) return;

    Dstack* A = Dstack_new_with(cantDiscos);
    if(!A) return;
    Dstack* B = Dstack_new_with(cantDiscos);
    if(!B) return;
    Dstack* C = Dstack_new_with(cantDiscos);
    if(!C) return;

    // Cargo la pila A
    for(int i = cantDiscos; i >= 1; i--)
    {
        Dpush(A, (DSTACK_ELEM)i);
    }

    // Para cargar la eleccion del usuario
    char pila1;
    char pila2;
    // Punteros a las pilas
    Dstack* origen = NULL;
    Dstack* destino = NULL;

    int intentos = 0;

    while(!Dstack_isfull(C))
    {
        printf("----------------------------------------\n");
        printf("Intentos: %d\n\n",intentos);
        printf("A: ");
        printStackRec(A,printInt);
        printf("\n");
        printf("B: ");
        printStackRec(B,printInt);
        printf("\n");
        printf("C: ");
        printStackRec(C,printInt);
        printf("\n\n");

        do
        {
            printf("Pila ORIGEN: ");
            scanf(" %c",&pila1);
            limpiarBuffer();
        } while(pila1!='A' && pila1!='B' && pila1!='C');
        do
        {
            printf("Pila DESTINO: ");
            scanf(" %c",&pila2);
            limpiarBuffer();
        } while(pila2!='A' && pila2!='B' && pila2!='C');

        switch(pila1)
        {
        case 'A':
            origen = A;
            break;
        case 'B':
            origen = B;
            break;
        case 'C':
            origen = C;
            break;
        }
        switch(pila2)
        {
        case 'A':
            destino = A;
            break;
        case 'B':
            destino = B;
            break;
        case 'C':
            destino = C;
            break;
        }
        if(_movHanoi(origen,destino))
        {
            intentos++;
        }
        printf("\n");
    }

    printf("A: ");
    printStackRec(A,printInt);
    printf("\n");
    printf("B: ");
    printStackRec(B,printInt);
    printf("\n");
    printf("C: ");
    printStackRec(C,printInt);
    printf("\n\n");

    printf("FELICITACIONES, LO LOGRASTE!\n");
    printf("Completado en %d intentos.\n",intentos);

    pila1 = 'Z';
    pila2 = 'Z';
}

int main()
{
    printf("Torre de Hanoi\n");

    int cantDiscos = 0;
    printf("Ingrese la cantidad de discos: ");
    scanf("%d",&cantDiscos);
    limpiarBuffer();
    hanoi(cantDiscos);

    return 0;
}
