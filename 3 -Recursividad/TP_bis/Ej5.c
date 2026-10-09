#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int digitosCrecientes(int n)
{
    if(n%10 == 0)
    {
        return 1;
    }else if((int)n%10 < (int)(n/10)%10)
    {
        return -1;
    } else
    {
        return digitosCrecientes(n/10);
    }
}
