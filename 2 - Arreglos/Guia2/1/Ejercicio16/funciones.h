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
 * @brief Ordena el vector en forma creciente
 *
 * @param v
 */
void ordenarVector(Vector* v);

/**
 * @brief Elimina todas las fracciones repetidas del vector
 *
 * @param v
 */
void eliminarFraccionesRepetidas(Vector* v);

/**
 * @brief Mezcla dos vectores ordenados sin repetir elementos
 *
 * @param Vector ordenado 1
 * @param Vector ordenado 2
 * @param Funcion de comparacion
 * @return int
 */
Vector* mezclarVectoresOrdenados(Vector*, Vector*,int(*cmp)(VECTOR_ELEMENT,VECTOR_ELEMENT));

/**
 * @brief Busca en que indice se encuentra un elemento fraccionario en un vector ordenado
 *
 * @param Vector ordenado
 * @param Fraccion a buscar
 * @return int
 */
int buscarElementoVectorOrdenadoFracciones(Vector* v, VECTOR_ELEMENT);

#endif // FUNCIONES_H_INCLUDED
