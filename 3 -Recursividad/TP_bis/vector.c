#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct _vector
{
    VECTOR_ELEMENT* a;
    int size;
    int max_size;
} Vector;


/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 *
 * @param ini_size
 * @return Vector*
 */
Vector* vector_new(int ini_size)
{
    Vector *b = malloc(sizeof(Vector));
    VECTOR_ELEMENT *newVector = malloc(sizeof(VECTOR_ELEMENT)*ini_size);
    if(newVector == NULL || b == NULL)
    {
        printf("An error occurred while creating the new vector.\n");
        free(b);
        free(newVector);
        return NULL;
    }

    b->a = newVector;
    b->size = 0;
    b->max_size = ini_size;

    return b;
}

/**
 * @brief Eliminar el vector
 *
 * @param v
 */
void vector_free(Vector* v)
{
    free(v->a);
    v->a = NULL;
    v->max_size = 0;
    v->size = 0;
    free(v);
}

/**
 * @brief Permite obtener el tamaño actual del vector
 *
 * @param v
 * @return int
 */
int vector_size(Vector* v)
{
    return v->size;
}

/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno.
 *
 * @param v
 * @return int
 */
int vector_isfull(Vector* v)
{
    return (v->size == v->max_size) ? 1:0;
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío.
 *
 * @param v
 * @return int
 */
int vector_isempty(Vector* v)
{
    return (v->size == 0) ? 1:0;
}


/**
 * @brief Permite obtener el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return VECTOR_ELEMENT
 */
VECTOR_ELEMENT vector_get(Vector* v, int index)
{
    if(index >= v->size || index<0)
    {
        return 0;
    }
    else
    {
        return v->a[index];
    }
}


/**
 * @brief Permite reemplazar el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return VECTOR_ELEMENT
 */
VECTOR_ELEMENT vector_set(Vector* v, int index, VECTOR_ELEMENT value)
{
    if(index >= v->size || index<0)
    {
        //The index requested is not valid
        return 0;
    }
    else
    {
        v->a[index] = value;
        //Operation successful
        return v->a[index];
    }
}

/**
 * @brief Permite agregar un elemento al final
 *
 * @param v
 * @param value
 */
int vector_add(Vector* v, VECTOR_ELEMENT value)
{
    if(vector_isfull(v) || v->size == v->max_size)
    {
        v->max_size = 2*v->max_size;
        VECTOR_ELEMENT *aux = realloc(v->a,sizeof(VECTOR_ELEMENT) * v->max_size);
        if(aux==NULL)
        {
            return -1;
        }
        else
        {
            v->a = aux;
            aux = NULL;
        }
    }
    v->a[v->size] = value;
    (v->size)++;
    return 1;
}


/**
 * @brief Permite agregar un elemento en una posición determinada.
 *
 * @param v
 * @param index
 * @param value
 */
int vector_insert(Vector* v, int index, VECTOR_ELEMENT value)
{
    if(v->size >= v->max_size || index<0 || index>v->size)
    {
        return 0;
    }
    else
    {
        int i = v->size;
        while(i>index)
        {
            v->a[i] = v->a[i-1];
            i--;
        }
        v->a[index] = value;
        (v->size)++;
    }
    return 1;
}


/**
 * @brief Permite eliminar un elemento del vector
 *
 * @param v
 * @param index
 */
VECTOR_ELEMENT vector_remove(Vector* v, int index)
{
    if(index < 0 || index >= v->size)
    {
        return 0;
    }
    else
    {
        VECTOR_ELEMENT deleted = v->a[index];
        while(index < (v->size - 1))
        {
            v->a[index] = v->a[index+1];
            index++;
        }
        (v->size)--;
        return deleted;
    }
}

/**
 * @brief print the vector
 *
 */
void vector_print(Vector* v, void (*print)(VECTOR_ELEMENT))
{
    if(v==NULL || print==NULL)
    {
        return;
    }
    printf("[");
    for(int i=0; i<v->size; i++)
    {
        print(vector_get(v,i));
        printf(" ");
    }
    printf("]\n");
}
