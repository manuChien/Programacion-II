#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void printEntero(VECTOR_ELEMENT n)
{
    printf("%d",n);
}
void printFloat(VECTOR_ELEMENT n)
{
    printf("%.1f",n);
}

//EJERCICIO 1: Calcular en forma recursiva la suma de los n primeros números naturales.
int Ej1_sumaPrimerosNaturales(int n)
{
    int resultado = 0;
    if(n>0)
    {
        resultado = n;
        resultado += Ej1_sumaPrimerosNaturales(n-1);
    } else
    {
        return resultado;
    }
}
void Ej1_sumaPrimerosNaturalesVersionVoid(VECTOR_ELEMENT *n)
{
    if(*n>0)
    {
        VECTOR_ELEMENT aux = *n - 1;
        *n = *n + aux;
    }
}

//EJERCICIO 2: Calcular en forma recursiva el producto entre dos números enteros a través de sumas sucesivas.
/*int Ej2_productoEntreDosNEnteros(int A, int B)
{
    int resultado = A;
    if(B>1)
    {
        return resultado+=Ej2_productoEntreDosNEnteros(A,B-1);
    } else if(B<(-1))
    {
        return resultado+=Ej2_productoEntreDosNEnteros(A,B+1);
    } else if(B==0)
    {
        return 0;
    }
    return resultado;
}*/
VECTOR_ELEMENT Ej2_productoEntreDosEnteros(int A, int B)
{
    VECTOR_ELEMENT resultado = A;
    if(B>1)
    {
        return resultado += Ej2_productoEntreDosEnteros(A,B-1);
    } else if(B<(-1))
    {
        return resultado -= Ej2_productoEntreDosEnteros(A,B+1);
    }
    return resultado;
}

//EJERCICIO 3-a: Desarrollar funciones recursivas que muestren por pantalla la sucesión de Fibonacci para los n primeros términos
VECTOR_ELEMENT Ej3a_fibonacci(int n)
{

}

//EJERCICIO 3-b:

//EJERCICIO 4: Desarrollar una función que calcule recursivamente el valor xn. Considerar que tanto x como n puedan ser negativos.
VECTOR_ELEMENT Ej4_potencia(VECTOR_ELEMENT x, VECTOR_ELEMENT n)
{
    if(x==0)
    {
        return 0;
    } else if(n==0)
    {
        return 1;
    } else if(n>0)
    {
        return x * Ej4_potencia(x,n-1);
    } else if(n<0)
    {
        return (1/x)*Ej4_potencia(1/x,(-n)-1);
    }
}

//EJERCICIO 5: Desarrollar una función recursiva que determine si los dígitos de un número natural están dispuestos de forma creciente (por ejemplo: 2337, 356, 88, 459).
void Ej5_digitosCrecientes(VECTOR_ELEMENT n)
{
    if(n==0)
    {
        printf("El numero es 0.\n");
    } else if(((int)n)%10 < ((int)(n/10))%10)
    {
        printf("Los digitos no estan ordenados en forma creciente.\n");
    } else if(n<10)
    {
        printf("Los digitos estan ordenados en forma creciente.\n");
    } else
    {
        Ej5_digitosCrecientes(n/10);
    }
}

//EJERCICIO 6: Desarrollar una función recursiva que reciba como parámetro una palabra y devuelva como resultado la palabra invertida (por ejemplo: “lamina” → “animal”).
void Ej6_auxiliar(char* origen, char* destino, int i, int n)
{
    if(i==n)
    {
        return;
    } else
    {
        destino[i] = origen[n-1-i];
        Ej6_auxiliar(origen,destino,i+1,n);
    }
}
char* Ej6_palabraInvertida(char* c, int n)
{
    if(n==0)
    {
        return NULL;
    } else
    {
        char* resultado = malloc(n+1);
        Ej6_auxiliar(c,resultado,0,n);
        resultado[n] = '\0';
        return resultado;
    }
}

//EJERCICIO 7: Desarrollar una función recursiva que reciba un número n como parámetro e imprima una media pirámide
void Ej7_columna(int i, int m)
{
    if(i==1)
    {
        printf("1 ");
        return;
    } else
    {
        printf("%d ",i);
        Ej7_columna(i-1,m);
    }
}
void Ej7_fila(int m, int n)
{
    if(m>n)
    {
        return;
    }else
    {
        Ej7_columna(m,m+1);
        printf("\n");
        Ej7_fila(m+1,n);
    }
}
void Ej7_imprimirPiramide(int n)
{
    if(n<=0)
    {
        printf("El numero pedido no es valido.\n");
    } else if(n==1)
    {
        printf("1\n");
    } else
    {
        Ej7_fila(1,n);
    }
}

//EJERCICIO 7: PIRAMIDE VERSION 2
void Ej7_piramide2(int n)
{
    if(n<=0)
    {
        return;
    }else if(n>0)
    {
        Ej7_piramide2(n-1);
        while(n>0)
        {
            printf("%d ",n--);
        }
        printf("\n");
    }
}

//EJERCICIO 8: TDA VECTOR - FUNCIONES RECURSIVAS
//Calcular el máximo elemento
VECTOR_ELEMENT Ej8_maxElement_aux(vector* v, int i, int resultado)
{
    if(i==(vector_size(v)-1))
    {
        return resultado;
    } else
    {
        if(resultado<=vector_get(v,i+1))
        {
            resultado = vector_get(v,i+1);
        }
        return Ej8_maxElement_aux(v,i+1,resultado);
    }
}
VECTOR_ELEMENT Ej8_maxElement(vector *v)
{
    VECTOR_ELEMENT resultado = vector_get(v,0);
    if(vector_size(v)==0)
    {
        printf("El vector no es valido.\n");
        return -1;
    } else if(vector_size(v)==1)
    {
        return resultado;
    } else
    {
        resultado = Ej8_maxElement_aux(v,0,resultado);
        return resultado;
    }
}
//Calcular el mínimo elemento
VECTOR_ELEMENT Ej8_minElement_aux(vector* v, int i, int resultado)
{
    if(i==(vector_size(v)-1))
    {
        return resultado;
    } else
    {
        if(resultado>=vector_get(v,i+1))
        {
            resultado = vector_get(v,i+1);
        }
        return Ej8_minElement_aux(v,i+1,resultado);
    }
}
VECTOR_ELEMENT Ej8_minElement(vector *v)
{
    VECTOR_ELEMENT resultado = vector_get(v,0);
    if(vector_size(v)==0)
    {
        printf("El vector no es valido.\n");
        return -1;
    } else if(vector_size(v)==1)
    {
        return resultado;
    } else
    {
        resultado = Ej8_minElement_aux(v,0,resultado);
        return resultado;
    }
}
//Calcular la suma de sus elementos
VECTOR_ELEMENT Ej8_sumaElementos_aux(vector* v, int n)
{
    VECTOR_ELEMENT resultado = 0;
    if(n>=0)
    {
        resultado = vector_get(v,n);
        return resultado + Ej8_sumaElementos_aux(v,n-1);
    } else
    {
        return resultado;
    }
}
VECTOR_ELEMENT Ej8_sumaElementos(vector* v)
{
    VECTOR_ELEMENT resultado = 0;
    if(v==NULL)
    {
        return -1;
    } else if(vector_size(v)==0)
    {
        return resultado;
    } else
    {
        resultado = Ej8_sumaElementos_aux(v,vector_size(v)-1);
        return resultado;
    }
}
//Calcular el promedio de sus elementos
VECTOR_ELEMENT Ej8_promedio(vector* v)
{
    return (float)Ej8_sumaElementos(v) / vector_size(v);
}
//Mostrar sus elementos
void Ej8_mostrarElementos_aux(vector* v, int i, int n)
{
    if(i>=n)
    {
        return;
    } else
    {
        printf("%.1f ",vector_get(v,i));
        Ej8_mostrarElementos_aux(v,i+1,n);
    }
}
void Ej8_mostrarElementos(vector* v)
{
    Ej8_mostrarElementos_aux(v,0,vector_size(v));
    printf("\n");
}
//Mostrar sus elementos en orden inverso
void Ej8_mostrarElementosInversos_aux(vector* v, int n)
{
    if(n<=0)
    {
        return;
    } else
    {
        printf("%.1f ",vector_get(v,n-1));
        Ej8_mostrarElementosInversos_aux(v,n-1);
    }
}
void Ej8_mostrarElementosInversos(vector* v)
{
    Ej8_mostrarElementosInversos_aux(v,vector_size(v));
    printf("\n");
}

//EJERCICIO 9: Utilizando el TDA de Vector, desarrollar funciones de búsqueda recursivas para un vector de números reales:
//9a
int Ej9_busquedaLineal(vector* v, float n)
{
    int encontrado = -1;
    if(v==NULL || vector_size(v)==0)
    {
        return encontrado;
    } else
    {
        encontrado = Ej9_busquedaLineal_aux(v,0,vector_size(v),n);
        return encontrado;
    }
}

int main()
{
    //EJERCIIO 1
    printf("Ejercicio 1\n");
    printf("La suma de los primeros 100 numeros naturales es %d\n",Ej1_sumaPrimerosNaturales(100));
    VECTOR_ELEMENT Ejercicio1_n = 10;
    Ej1_sumaPrimerosNaturalesVersionVoid(&Ejercicio1_n);
    printf("La suma de los primeros 10 numeros naturales es %d\n",Ejercicio1_n);
    printf("\n");

    //EJERCICIO 2
    printf("Ejercicio 2\n");
    int A = -8;
    int B = 5;
    printf("El producto entre %d y %d es %d\n",A,B,Ej2_productoEntreDosEnteros(A,B));
    printf("\n");

    //EJERCICIO 3-a


    //EJERCICIO 4
    printf("Ejercicio 4\n");
    float x = 2;
    float n = -2;
    printf("%.2f a la %.2f es %.2f\n",x,n,Ej4_potencia(x,n));
    printf("\n");

    //EJERCICIO 5
    printf("Ejercicio 5\n");
    int Ej5_n = 12354;
    Ej5_digitosCrecientes(Ej5_n);
    printf("\n");

    //EJERCICIO 6
    printf("Ejercicio 6\n");
    char Ej6_a[] = "lamina";
    char* Ej6_b = malloc(strlen(Ej6_a)+1);
    Ej6_b = Ej6_palabraInvertida(Ej6_a,strlen(Ej6_a));
    printf("%s\n",Ej6_b);

    //EJERCICIO 7
    printf("Ejercicio 7\n");
    Ej7_imprimirPiramide(10);
    printf("\n");

    //EJERCICIO 7 VERSION 2
    printf("Ejercicio 7v2\n");
    Ej7_piramide2(10);
    printf("\n");

    //EJERICIO 8 a
    printf("Ejercicio 8a\n");
    vector* Ej8a_v = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(Ej8a_v,rand()%100+1);
    }
    vector_print(Ej8a_v,printFloat);
    printf("El maximo valor del array es %.1f.\n",Ej8_maxElement(Ej8a_v));
    printf("\n");

    //EJERICIO 8 b
    printf("Ejercicio 8b\n");
    vector* Ej8b_v = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(Ej8b_v,rand()%100+1);
    }
    vector_print(Ej8b_v,printFloat);
    printf("El minimo valor del array es %.1f.\n",Ej8_minElement(Ej8b_v));
    printf("\n");

    //EJERICIO 8 c
    printf("Ejercicio 8c\n");
    vector* Ej8c_v = vector_new(5);
    for(int i=0; i<5; i++)
    {
        vector_add(Ej8c_v,rand()%5+1);
    }
    vector_print(Ej8c_v,printFloat);
    printf("La suma de los elementos del array es %.1f.\n",Ej8_sumaElementos(Ej8c_v));
    printf("\n");

    //EJERICIO 8 d
    printf("Ejercicio 8d\n");
    vector* Ej8d_v = vector_new(5);
    for(int i=0; i<5; i++)
    {
        vector_add(Ej8d_v,rand()%5+1);
    }
    vector_print(Ej8d_v,printFloat);
    printf("La promedio de los elementos del array es %.1f.\n",Ej8_promedio(Ej8d_v));
    printf("\n");

    //EJERICIO 8 e
    printf("Ejercicio 8e\n");
    vector* Ej8e_v = vector_new(5);
    for(int i=0; i<5; i++)
    {
        vector_add(Ej8e_v,rand()%5+1);
    }
    vector_print(Ej8e_v,printFloat);
    Ej8_mostrarElementos(Ej8e_v);
    printf("\n");

    //EJERICIO 8 f
    printf("Ejercicio 8f\n");
    vector* Ej8f_v = vector_new(5);
    for(int i=0; i<5; i++)
    {
        vector_add(Ej8f_v,rand()%5+1);
    }
    vector_print(Ej8f_v,printFloat);
    Ej8_mostrarElementosInversos(Ej8f_v);
    printf("\n");

    //EJERICIO 8 f
    printf("Ejercicio 9a\n");
    vector* Ej9a_v = vector_new(5);
    for(int i=0; i<5; i++)
    {
        vector_add(Ej9a_v,i+1);
    }
    vector_print(Ej9a_v,printFloat);
    float Ej9a_elemento = 9;
    if(Ej9_busquedaLineal(Ej9a_v,Ej9a_elemento))
    {
        printf("El elemento %.1f esta en el vector.\n",Ej9a_elemento);
    } else
    {
        printf("El elemento %.1f no esta en el vector.\n",Ej9a_elemento);
    }
    printf("\n");

    return 0;
}
