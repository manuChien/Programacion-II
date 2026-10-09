#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_search.h"

int sequential_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] != key))
        i++;    
    return (i < n)? i : -1;
}

int sequential_search_inv (int key, int a[], int n) {    
    while ((--n >= 0) && (a[n] != key))
        ;
    return n;
}

int sequential_sorted_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] < key))
        i++;
    return ((i < n) && (a[i] == key)) ? i : -1;
}

int binary_sorted_search(int key, int a[], int n) {
    int high = n - 1;
    int low = 0;
    int mid = (high - low) / 2;
    while ((low < high) && (a[mid] != key)) {
        if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }
    return (a[mid] == key) ? mid : -1;
}


