#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * @brief Calcula el determinante de una matriz de enteros
 *
 * @param Matriz de enteros
 *
 * @return Determinante
 */
int determinanteInt(matrix* m);

matrix* reemplazarColumnaPorVector(matrix* m, Vector* v, int col);

Vector* sistemaEcuaciones(matrix* coef, Vector* resultados);

#endif // FUNCIONES_H_INCLUDED
