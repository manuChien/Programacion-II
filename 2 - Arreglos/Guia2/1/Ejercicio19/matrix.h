#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#define MATRIX_ELEMENT int*
typedef struct _matrix matrix;

/**
 * @brief Crea la matriz con el tamaño apropiado según las dimensiones establecidas
 *
 * @param Cantidad de filas
 * @param Cantidad de columnas
 *
 * @return matrix*
 */
matrix* matrix_new(int rows, int columns);

/**
 * @brief Elimina la matriz
 *
 * @param Matriz a eliminar
 */
void matrix_free(matrix* m);

/**
 * @brief Permite obtener la cantidad de filas
 *
 * @param Matriz
 *
 * @return int
 */
int matrix_rows(matrix* m);

/**
 * @brief Permite obtener la cantidad de columnas
 *
 * @param Matriz
 *
 * @return int
 */
int matrix_columns(matrix* m);

/**
 * @brief Permite obtener el valor de una posición de la matriz
 *
 * @param Matriz
 * @param Columna
 * @param Fila
 *
 * @return void*
 */
void* matrix_get(matrix* m, int row, int col);

/**
 * @brief Permite reemplazar o asignar un elemento a la matriz
 *
 * @param Matriz
 * @param Columna
 * @param Fila
 * @param Valor a reemplazar
 */
void matrix_set(matrix* m, int row, int col, void* value);

/**
 * @brief Permite imprimir una matriz por consola
 *
 * @param Matriz
 * @param Print function
 */
void matrix_print(matrix* m, void prt(void*));

#endif // MATRIX_H_INCLUDED
