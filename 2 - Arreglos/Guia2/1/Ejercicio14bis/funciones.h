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

#endif // FUNCIONES_H_INCLUDED
