#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int esPalindromo(Node* nodo)
{
    if(!nodo) return 0;

    // CUENTO LA CANTIDAD DE ELEMENTOS
    int n = 0;
    Node* current = nodo;
    do
    {
        n++;
        current = current->next;
    }
    while(current!=nodo && current!=NULL);

    // CARGADO DE STRING CON LA PRIMERA MITAD DE ELEMENTOS
    int* mitad = malloc(n/2);
    current = nodo;
    for(int i=0; i<n/2; i++)
    {
        mitad[i] = current->value;
        current = current->next;
    }

    // COMPARO CASOS POR CANTIDAD DE ELEMENTOS
    // CONTADOR COINCIDENCIAS EN ESPEJO
    int coincidencias = 0;

    // CASO NO HAY ELEMENTOS
    if(n==0)
    {
        coincidencias=0;
    }
    // CASO UN SOLO ELEMENTO
    else if(n==1)
    {
        coincidencias = 0;
    }
    // CASO CANTIDAD PAR
    else if(n%2==0)
    {
        // INDEX DEL PRIMERO DE LA SEGUNDA MITAD
        int i = n/2;

        // COMPARO DESDE EL MEDIO HASTA EL FINAL
        while(i<n)
        {
            if(current->value == mitad[n-1-i])
            {
                coincidencias++;
            }
            current = current->next;
            i++;
        }
    }
    // CASO CANTIDAD IMPAR
    else if(n%2 != 0)
    {
        // INDEX DEL PRIMERO DE LA SEGUNDA MITAD
        int i = n/2 + 1;

        // COMIENZO A CONTAR DESDE UN ELEMENTO MAS ATRAS PUES EL DEL MEDIO DA IGUAL
        current = current->next;

        // COMPARO DESDE EL MEDIO HASTA EL FINAL
        while(i<n)
        {
            if(current->value == mitad[n-1-i])
            {
                coincidencias++;
            }
            current = current->next;
            i++;
        }
    }

    free(mitad);
    return (coincidencias==n/2) ? 1:0;
}
