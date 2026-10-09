#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void printInt(int n)
{
    printf("%d ",n);
}

void printFloat(float n)
{
    printf("%.1f ",n);
}

int higher(VECTOR_ELEMENT A, VECTOR_ELEMENT B)
{
    return A-B;
}

int main()
{
    matrix* m = matrix_new(6,6);
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            int n = rand()%10;
            int signo = 0;
            if(n>5)
            {
                signo = -1;
            } else
            {
                signo = 1;
            }
            matrix_set(m,i,j,(rand()%10+1)*signo);
        }
    }

    matrix_print(m,printInt);

    Vector* v = cantElementosNegativosPorFila(m);

    vector_print(v,printInt);

    return 0;
}
