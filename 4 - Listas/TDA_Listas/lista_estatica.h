#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

#define SLIST_ELEMENT int
#define MAX_PILA 100

typedef struct _lista_estatica lista_estatica;

/**
* @brief Crea una lista estatica
*
* @return lista_estatica*
*/
lista_estatica* slist_crearLista(void);

/**
* @brief Agrega un elemento al final de la lista estatica
*
* @param Lista al cual se le va a agregar al final
* @param Elemento a agregar al final
*
* @return Elemento agregado si tuvo exito, sino -1
*/
SLIST_ELEMENT slist_append(lista_estatica*, SLIST_ELEMENT);

/**
* @brief Agrega un elemento en la posicion solicitada de la lista estatica
*
* @param Lista al cual se le va a agregar
* @param Elemento a agregar en la posicion
* @param Posicion en la cual se va a insertar
*
* @return Elemento agregado si tuvo exito, sino -1
*/
SLIST_ELEMENT slist_insert(lista_estatica*, SLIST_ELEMENT, int);

/**
* @brief Retorna la posicion del primer elemento de la lista estatica
*
* @param Lista a buscar la posicion del primer elemento
*
* @return 0 si tuvo exito, sino -1
*/
int slist_first(lista_estatica*);

/**
* @brief Retorna la posicion del siguiente elemento de la lista estatica
*
* @param Lista a buscar la posicion del primer elemento
* @param Posicion del elemento actual
*
* @return Siguiente posicion si tuvo exito, sino -1
*/
int slist_next(lista_estatica* lista, int posicion);

/**
* @brief Pregunta si la posicion es la del ultimo de la lista
*
* @param Lista a preguntar si es el ultimo elemento de la lista
* @param Posicion del elemento a preguntar
*
* @return Positivo si tuvo exito
*/
int slist_eol(lista_estatica* lista, int posicion);

/**
* @brief Retorna el elemento de la posicion buscada
*
* @param Lista del elemento a buscar
* @param Posicion del elemento a buscar
*
* @return Elemento o -1 si hay error
*/
SLIST_ELEMENT slist_getElement(lista_estatica* lista, int posicion);

/**
* @brief Elimina el elemento de la posicion
*
* @param Lista del elemento a eliminar
* @param Posicion del elemento a eliminar
*
* @return Elemento o -1 si hay error
*/
SLIST_ELEMENT slist_removeElement(lista_estatica* lista, int posicion);

#endif // LISTA_ESTATICA_H_INCLUDED
