#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_search.h"

int* array_create(int n) {
    int* result;
    result = (int*) malloc(sizeof(int) * n);
    return result;
}

void array_destroy(int* a) {
    free(a);
}

void array_copy (int* source, int* target, int n) {
    for (int i = 0; i < n; i++) {
        target[i] = source[i];
    }
}   

int* array_clone(int a[], int n) {
    int* result = array_create(n);
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
    }
    return result;
}
