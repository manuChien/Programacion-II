#include <stdio.h>
#include <stdlib.h>

//EJERCICIO 1: Calcular en forma recursiva la suma de los n primeros números naturales.
int sumaPrimerosNaturales(int n)
{
    int resultado = 0;
    if(n>0)
    {
        resultado = n;
        return resultado + sumaPrimerosNaturales(n-1);
    } else
    {
        return resultado;
    }
}

//EJERCICIO 2 Calcular en forma recursiva el producto entre dos números enteros a través de sumas sucesivas.



int main()
{
    printf("Hello world!\n");

    printf("La suma de los primeros 100 numeros naturales es %d",sumaPrimerosNaturales(100));

    return 0;
}
