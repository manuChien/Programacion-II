#include <stdio.h>
#include <stdlib.h>

long factorial(long n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}

int len(char* s)
{
    int result = 0;
    while(*s != '\0')
    {
        result++;
        s++;
    }
    return result;
}

int lenRecursivo(char* s)
{
    int result = 0;

    //Hola_Mundo!'\0' -> ola_Mundo!'\0' -> ... -> '\0' FIN
    if(*s != '\0')
    {
        result = 1 + len(s+1);
    }
    return result;
}

int intIn(int a[], int n, int size)
{
    int in = 0;

    if(size>0)
    {
        if(a[size-1]==n)
        {
            in = 1;
        }
        else
        {
            return intIn(a,n,size-1);
        }
    }
    return in;
}

void printInt(int v[], int n, int i)
{
    if(i<n)
    {
        printf("%d",v[i]);
        printInt(v,n,i+1);
    }
    else
    {
        printf("\n");
    }
}

void printIntV2(int v[], int n)
{
    if(n>0)
    {
        printf("%d",v[n-1]);
        printIntV2(v,n-1);
    }
    else
    {
        printf("\n");
    }
}

void hanoi(int n, char O, char D, char aux)
{
    if(n>0)
    {
        hanoi(n-1,O,aux,D);
        printf("%c -> %c\n",O,D);
        hanoi(n-1,aux,D,O);
    }
}

int main()
{
    char string[] = "Hola Mundo!";

    printf("%s\n",string);

    printf("%s tiene %d caractres\n",string,len(string));
    printf("%s tiene %d caractres\n",string,lenRecursivo(string));

    int a[] = {1,2,3,4,5};
    int size = 5;

    int value = 5;
    if(intIn(a,value,size))
    {
        printf("%d esta en el array\n",value);
    }
    else
    {
        printf("%d NO esta en el array\n",value);
    }

    printInt(a,size,0);
    printIntV2(a,size);

    hanoi(4,'A','B','C');
    printf("\n");

    /*
    int finalizar = 0;
    long n;
    while(finalizar!=1)
    {
        printf("Ingrese el numero que desea hallar su factorial: ");
        scanf("%ld",&n);
        printf("El factorial de %ld es %ld\n",n,factorial(n));
        printf("Ingrese 1 si desea finalizar: ");
        scanf("%d",&finalizar);
        printf("\n");
    }
    */

    return 0;
}
