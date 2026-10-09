#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/array_search.h"
#include "lib/array_util.h"

int array_find_remove(int a[], int* n, int value){
    int pos = sequential_search(value, a, *n);
    if (pos >= 0) {
        array_remove(a, n, pos);
    }
    return pos;
}

void array_insert_after (int a[], int* n, int value_find, int value_insert) {
    int pos = sequential_search_inv(value_find, a, *n); 
    array_insert(a, n, value_insert, pos+1);    
}

void array_insert_before (int a[], int* n, int value_find, int value_insert) {
    int pos = sequential_search(value_find, a, *n);     
    pos = (pos < 0)? 0 : pos;
    array_insert(a, n, value_insert, pos);    
}

void array_insert_sorted (int a[], int* n, int value) {
    int i = *n;
    while ((--i>0) && (a[i] > value))
        ;
    array_insert(a, n, value, i+1);
}

void main() {

    // Declaración
    int arreglo_ejemplo[100] = {1, 2, 3, 4, 5, 6};
    int tam = 6;

    // Impresión de contenido
    printf("\nArreglo de enteros\n");
    print_int_array_leyend(arreglo_ejemplo, tam, "Arreglo original");
    array_add(arreglo_ejemplo, &tam, 10);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 10 al final");
    array_insert(arreglo_ejemplo, &tam, 9, 6);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 9 en la posición 6");
    array_insert_after(arreglo_ejemplo, &tam, 6, 8);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 8 despues de 6");
    array_insert_before(arreglo_ejemplo, &tam, 8, 7);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 7 antes de 8");
    array_insert_after(arreglo_ejemplo, &tam, 10, 11);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 11 despues de 10");
    array_insert_before(arreglo_ejemplo, &tam, 13, 12);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 12 antes de 13 (que no existe)");
    array_insert_before(arreglo_ejemplo, &tam, 13, 20);
    print_int_array_leyend(arreglo_ejemplo, tam, "agrega 20 antes de 12");


    int v1 = array_remove(arreglo_ejemplo, &tam, 5);
    int v2 = array_remove(arreglo_ejemplo, &tam, 0);
    int v3 = array_remove(arreglo_ejemplo, &tam, 0);
    print_int_array_leyend(arreglo_ejemplo, tam, "remueve 4, 20 y 12");

    array_insert_sorted(arreglo_ejemplo, &tam, v1);
    array_insert_sorted(arreglo_ejemplo, &tam, v2);
    array_insert_sorted(arreglo_ejemplo, &tam, v3);
    print_int_array_leyend(arreglo_ejemplo, tam, "insert ordenado 4, 20 y 12");

    int a[100] = {10,20,30,40,50,60};
    int tam_a = 6;
    int b[100];
    int tam_b = 0;

    array_add(b, &tam_b, array_remove(a, &tam_a, 1));

    print_int_array_leyend(a, tam_a, "a");
    print_int_array_leyend(b, tam_b, "b");


}
