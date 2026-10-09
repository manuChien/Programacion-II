#ifndef _VECTOR
#define _VECTOR

#define VECTOR_ELEMENT int

typedef struct _vector vector;

// Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño
// Máximo = ini_size.
vector* vector_new(int ini_size);

// Eliminar el vector
void vector_free(vector* v);

// Permite obtener el tamaño actual del vector
int vector_size(vector* v);

// Devuelve 0 si no está lleno y 1 si está lleno.
int vector_isfull(vector* v);

// Devuelve 0 si no está vacío y 1 si está vacío.
int vector_isempty(vector* v);

// Permite obtener el valor de una posición del vector
VECTOR_ELEMENT vector_get(vector* v, int index);

// Permite reemplazar el valor de una posición del vector
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value);

// Permite agregar un elemento al final
int vector_add(vector* v, VECTOR_ELEMENT value);

// Permite agregar un elemento en una posición determinada.
int vector_insert(vector* v, int index, VECTOR_ELEMENT value);

// Permite eliminar un elemento del vector
VECTOR_ELEMENT vector_remove(vector* v, int index);

// Permite imprimir un vector por consola
void vector_print(vector* v, void (*print)(VECTOR_ELEMENT));

//Permite ordenar un vector segun el criterio de ordenamiento deseado
void vector_sortElements(vector* v, VECTOR_ELEMENT(*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT));

#endif
