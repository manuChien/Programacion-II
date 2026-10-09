#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void _invertirPalabraAux(char* str, char* resultado, int n, int m)
{
    if(n<0)
    {
        resultado[m] = '\0';
        return;
    } else
    {
        resultado[m] = str[n];
        _invertirPalabraAux(str,resultado,n-1,m+1);
    }
}

char* invertirPalabra(char* str, int n)
{
    if(!str || n<0) return NULL;

    char* resultado = malloc(n+1);
    if(!resultado) return NULL;

    _invertirPalabraAux(str,resultado,n-1,0);

    return resultado;
}
