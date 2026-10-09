#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct _vector{
   VECTOR_ELEMENT* a;
   int size;
   int max_size;
} vector;


/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 *
 * @param ini_size
 * @return vector*
 */
vector* vector_new(int ini_size){
    vector *b = malloc(sizeof(vector));
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
void vector_free(vector* v){
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
int vector_size(vector* v){
   return v->size;
}

/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno.
 *
 * @param v
 * @return int
 */
int vector_isfull(vector* v) {
   return (v->size == v->max_size) ? 1:0;
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío.
 *
 * @param v
 * @return int
 */
int vector_isempty(vector* v){
   return (v->size == 0) ? 1:0;
}


/**
 * @brief Permite obtener el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return VECTOR_ELEMENT
 */
VECTOR_ELEMENT vector_get(vector* v, int index){
   if(index >= v->size || index<0)
   {
       printf("The position requested is not valid\n");
       return 0;
   } else
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
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value){
   if(index >= v->size || index<0)
   {
       //The index requested is not valid
       printf("The position requested for replace is not valid\n");
       return 0;
   } else
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
int vector_add(vector* v, VECTOR_ELEMENT value){
   if(vector_isfull(v) || v->size == v->max_size)
   {
       v->max_size = 2*v->max_size;
       VECTOR_ELEMENT *aux = realloc(v->a,sizeof(VECTOR_ELEMENT) * v->max_size);
       if(aux==NULL)
       {
           printf("An error ocurred while adding the vector.\n");
           return 0;
       } else {
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
int vector_insert(vector* v, int index, VECTOR_ELEMENT value){
    if(v->size >= v->max_size || index<0 || index>v->size)
    {
        printf("The array is already full or the index is invalid.\n");
        return 0;
    } else
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
VECTOR_ELEMENT vector_remove(vector* v, int index){
   if(index < 0 || index >= v->size)
   {
       printf("The index addressed is invalid.\n");
       return 0;
   } else
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
void vector_print(vector* v, void (*print)(VECTOR_ELEMENT)){
    if(v==NULL || print==NULL)
    {
        printf("The parameters entered for printing are invalid.\n");
        return;
    }
    printf("[");
    for(int i=0; i<v->size; i++)
    {
        print(v->a[i]);
        printf(" ");
    }
    printf("]\n");
}
