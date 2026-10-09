#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float potencia(float x, float n)
{
    if(n==0)
    {
        return 1;
    }else if(n<0)
    {
        return potencia(1/x,-n);
    } else
    {
        return x*potencia(x,n-1);
    }
}
