#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int sumaPrimerosNaturales(int n)
{
    if(n<0) return -1;

    int resultado = 0;
    if(n==0)
    {
        return resultado;
    } else
    {
        resultado = n;
        return resultado + sumaPrimerosNaturales(n-1);
    }
}
