#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//SE INCLUYEN ESTAS LIBRERIAS (VECTOR.H Y FRACCIONES.H) PARA PODER USAR SUS ESTRUCTURAS
#include "vector.h"
#include "fracciones.h"

/**
 * @brief Halla el maximo comun divisor
 *
 * @param MAYOR entero
 * @param MENOR entero
 * @return int
 */
int mcd(int mayor, int menor);

/**
 * @brief Calcula el máximo elemento fraccionario del vector
 *
 * @param Vector
 * @return fraction*
 */
fraction* max_fraction(Vector*);
fraction* _max_fraction_aux(Vector* v, int index, fraction* maxFraction);

/**
 * @brief Calcula el minimo elemento fraccionario del vector
 *
 * @param Vector
 * @return fraction*
 */
fraction* min_fraction(Vector*);
fraction* _min_fraction_aux(Vector* v, int index, fraction* maxFraction);

/**
 * @brief Calcula la suma de todos los elementos fraccionarios del vector
 *
 * @param Vector
 * @return fraction*
 */
fraction* _suma_vector_aux(Vector* v, int index, fraction* sumaTotal);
fraction* suma_vector(Vector* v);

/**
 * @brief Calcula la suma de todos los elementos fraccionarios del vector
 *
 * @param Vector
 * @return fraction*
 */
 fraction* promedio_vector(Vector* v);

/**
 * @brief Imprime los elementos del vector fraccionario de forma recursiva ordenada por indice creciente
 *
 * @param Vector
 * @return void
 */
void _impresionRecursiva_vectorFraccionario_aux(Vector* v, int index);
void impresionRecursiva_vectorFraccionario(Vector* v);

/**
 * @brief Imprime los elementos del vector fraccionario de forma recursiva ordenada por indice descendiente
 *
 * @param Vector
 * @return void
 */
void _impresionRecursivaDescendente_vectorFraccionario_aux(Vector* v, int index);
void impresionRecursivaDescendente_vectorFraccionario(Vector* v);

#endif // FUNCIONES_H_INCLUDED
