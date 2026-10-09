#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/array_search.h"
#include "lib/dynamic_array.h"
#include "lib/array_util.h"


int main (){
    int a[10];
    int* b = (int*) malloc(sizeof(int)*10);
    int* c = array_create(10);
    
    for (int i = 0; i < 10; i++) {
        a[i] = i * 10;
        b[i] = i * 100;
        c[i] = i * 1000;
    }

    int* aux = array_create(20);
    array_copy(b, aux, 10);
    array_destroy(b);
    b = aux;
    int tam_b = 10;
    array_add(b, &tam_b, 9999);

    print_int_array_leyend(a, 10, "Array a");
    print_int_array_leyend(b, tam_b, "Array b");
    print_int_array_leyend(c, 10, "Array c");


}