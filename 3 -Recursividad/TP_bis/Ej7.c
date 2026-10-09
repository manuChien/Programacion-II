#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mediaPiramide(int n)
{
    if(n>0)
    {
        mediaPiramide(n-1);
        while(n>0)
        {
            printf("%d ",n);
            n--;
        }
        printf("\n");
    }
}
