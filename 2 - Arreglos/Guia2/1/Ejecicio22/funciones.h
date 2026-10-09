#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * @brief Suma dos matrices
 *
 * @param Matriz A
 * @param Matrix B
 * @param Funcion Suma
 *
 * @return matrix*
 */
matrix* sumarDosMatrices(matrix*,matrix*,void* (*prt)(MATRIX_ELEMENT,MATRIX_ELEMENT));

/**
 * @brief Suma dos matrices
 *
 * @param Matriz
 * @param Vector
 * @param Funcion Suma
 *
 * @return Estado
 */
int sumarVectorATodasLasFilas(matrix*,Vector*,void* (*prt)(MATRIX_ELEMENT,MATRIX_ELEMENT));

/**
 * @brief Multiplica dos matrices
 *
 * @param Matriz A
 * @param Matriz B
 * @param Funcion Producto
 * @param Funcion Suma
 *
 * @return Estado
 */
matrix* productoDosMatrices(matrix*,matrix*,void* (*producto)(MATRIX_ELEMENT,MATRIX_ELEMENT),void* (*suma)(MATRIX_ELEMENT,MATRIX_ELEMENT));

/**
 * @brief Calcula el determinante de una matriz de enteros
 *
 * @param Matriz de enteros
 *
 * @return Determinante
 */
int determinanteInt(matrix* m);

#endif // FUNCIONES_H_INCLUDED
