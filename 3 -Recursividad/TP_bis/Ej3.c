#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//a
void fibonacciPrimerosTerminos(int n)
{
    if (n <= 0) return;

    //Llamada recursiva para imprimir primero los n-1 anteriores
    fibonacciPrimerosTerminos(n - 1);

    //Al regresar de la recursión, calculamos el término actual (índice n-1)
    if (n == 1)
    {
        printf("0 ");
    }
    else if (n == 2)
    {
        printf("1 ");
    }
    else
    {
        int ant = 0;
        int act = 1;
        for (int i = 2; i < n; i++)
        {
            int sig = ant + act;
            ant = act;
            act = sig;
        }
        printf("%d ", act);
    }
}

//b
void _fiboMenoresAux(int a, int b, int x)
{
    if(a>=x) return;

    printf("%d ",a);

    _fiboMenoresAux(b,a+b,x);
}

void imprimirFibonacciMenores(int x)
{
    if(x<=0) return;

    _fiboMenoresAux(0,1,x);
}
