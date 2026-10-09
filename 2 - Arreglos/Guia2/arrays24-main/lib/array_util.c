#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_util.h"

void array_add(int a[], int* n, int value) {
    a[*n] = value;
    (*n)++;
}

void array_insert(int a[], int* n, int value, int pos) {
    for (int i = *n; i > pos; i--) {
        a[i] = a[i-1];
    }
    a[pos] = value;
    (*n)++;
}

int array_remove(int a[], int* n, int pos){
    int value = a[pos];
    (*n)--;
    for (int i = pos; i < *n; i++) {
        a[i] = a[i+1];
    }    
    return value;
}

void print_int_array (int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, a[i]);
    }
}

void print_int_array_leyend (int a[], int n, char* leyend) {
    printf("\n%s\n", leyend);
    print_int_array (a, n);
}