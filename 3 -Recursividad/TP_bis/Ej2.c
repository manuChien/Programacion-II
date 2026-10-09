#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int productoEnterosRecursiva(int A, int B)
{
    if(B==0)
    {
        return 0;
    }else if(B>0)
    {
        return A+productoEnterosRecursiva(A,B-1);
    } else
    {
        return productoEnterosRecursiva(-A,-B);
    }
}
