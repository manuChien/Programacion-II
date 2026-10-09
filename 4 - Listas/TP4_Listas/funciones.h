#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define NODE_ELEMENT int

typedef struct _node
{
    NODE_ELEMENT data;
    struct _node* next;
} node;

// EJERCICIO 1
/**
* @brief Verifica que una lista este ordenada
*
* @param Lista
* @param Criterio de comparacion
*/
int lista_ordenada(node* h, int (*cmp)(NODE_ELEMENT,NODE_ELEMENT));

// EJERCICIO 2
/**
* @brief Elimina los elementos repetidos de una lista
*
* @param Lista
*
*/
void lista_eliminaRepetidos(node** h);

/**
* @brief Elimina los elementos coincidentes a valor de la lista
*
* @param Lista
*
*/
void eliminarCoincidentesA(node* h, NODE_ELEMENT value);

// EJERCICIO 3
/**
* @brief Retorna el menor entero de la lista
*
* @param Lista
*
*/
int lista_menorEntero(node* h);

// EJERCICIO 4
/**
* @brief Recibe una lista y retorna una lista nueva con sentido inverso
*
* @param Lista
*
* @return node*
*/
node* lista_nuevaSentidoInverso(node* h);

// EJERCICIO 5
/**
* @brief Recibe una lista la invierte
*
* @param Lista
*/
void lista_invertirLista(node** h);

// EJERCICIO 6
/**
* @brief Recibe una lista y dos listas vacias, rellenandolas con pares e impares respectivamente
*
* @param Lista
* @param Pares
* @param Impares
*/
void lista_append(node** h, NODE_ELEMENT value);
void lista_paresImpares(node* original, node** pares, node** impares);

// EJERCICIO 7
node* lista_fusionarOrdenadoInt(node** A, node** B, int cmp(int,int));

//EJERCICIO 8
int lista_promedio(node* h);
int lista_maximoValorListaDeListas(node** h);

#endif // FUNCIONES_H_INCLUDED
