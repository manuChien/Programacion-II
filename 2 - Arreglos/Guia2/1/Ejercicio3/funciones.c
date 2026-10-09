#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "fracciones.h"

int mcd(int A, int B)
{
    if(B>0) return mcd(B,A%B);
    return A;
}

void printFraction(fraction *f)
{
    printf("%d/%d ",fraction_get_num(f),fraction_get_den(f));
}
