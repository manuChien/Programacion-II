#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void printInt(int A)
{
    printf("%d ",A);
}

int main()
{
    printf("Hello world!\n");

    Dqueue* queue = Dqueue_new();
    if(!queue) return -1;

    for(int i=0; i<10; i++)
    {
        Denqueue(queue,i+1);
    }

    printQueue(queue,printInt);
    printf("\n");
    Dqueue* copiedQueue = copyDqueue(queue);
    printQueue(copiedQueue,printInt);
    printf("\n");

    Dqueue_free(queue);

    return 0;
}
