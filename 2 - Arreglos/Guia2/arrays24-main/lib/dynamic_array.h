#ifndef _DYNAMIC_ARRAY
#define _DYNAMIC_ARRAY

int* array_create(int n);

void array_destroy(int* a);

void array_copy (int* source, int* target, int n);

int* array_clone(int a[], int n);

#endif
