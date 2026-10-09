#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/array_search.h"
#include "lib/array_util.h"

/**
 * @brief muestra si un valor se encuentra en un arreglo
 * 
 * @param value valor a buscar
 * @param a arreglo de enteros
 * @param n tamaño del arreglo
 */
void print_find_value (int value, int a[], int n){
    int pos = sequential_search(value, a, n);
    if (pos >= 0){
        printf("El valor %d se encuentra en %d\n", value, pos);
    } else {
        printf("El valor %d no se encuentra en el arreglo\n", value);
    }
}

/**
 * @brief muestra si un valor se encuentra en un arreglo
 * buscando desde el final 
 * 
 * @param value valor a buscar
 * @param a arreglo de enteros
 * @param n tamaño del arreglo
 */
void print_find_value_inv (int value, int a[], int n){
    int pos = sequential_search_inv(value, a, n);
    if (pos >= 0){
        printf("El valor %d se encuentra en %d\n", value, pos);
    } else {
        printf("El valor %d no se encuentra en el arreglo\n", value);
    }
}

void main() {
    // Declara un arreglo de enteros
    int arreglo_enteros[100];

    // Asignación de valores
    arreglo_enteros[0] = -1;
    arreglo_enteros[1] = -2;
    arreglo_enteros[2] = -3;

    // Declaración y Asignación
    int arreglo_ejemplo[] = {1, 2, 3, 4, 5, 6};

    // Impresión de contenido
    printf("\nArreglo de enteros\n");
    print_int_array(arreglo_enteros, 3);

    printf("\nArreglo de ejemplo\n");
    print_int_array(arreglo_ejemplo, 6);

    // Búsqueda secuencial 
    printf("\nBúsqueda secuencial\n");
    print_find_value(2, arreglo_ejemplo, 6);
    print_find_value(8, arreglo_ejemplo, 6);

    // Búsqueda secuencial inv
    printf("\nBúsqueda secuencial inversa\n");
    print_find_value_inv(2, arreglo_ejemplo, 6);
    print_find_value_inv(8, arreglo_ejemplo, 6);



}
