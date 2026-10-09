#ifndef ELEMENTOS_H_INCLUDED
#define ELEMENTOS_H_INCLUDED

#define DEFAULT_NUM -1
#define DEFAULT_OP '\0'

typedef enum _TipoElem TipoElem;
typedef struct _Elemento Elemento;

/**
* @brief Devuelve un elemento tipo numero
*
* @param Numero
*
* @return Elemento*
*/
Elemento* Elem_createNum(int num);
/**
* @brief Devuelve un elemento tipo operador
*
* @param Operador
*
* @return Elemento*
*/
Elemento* Elem_createOp(char op);

/**
* @brief Devuelve el tipo del elemento
*
* @param Elemento*
*
* @return TipoElem
*/
TipoElem Elem_getType(Elemento* elem);
/**
* @brief Devuelve un numero del elemento
*
* @param Elemento*
*
* @return int
*/
int Elem_getNum(Elemento* elem);
/**
* @brief Devuelve el operador del elemento
*
* @param Elemento*
*
* @return char*
*/
char Elem_getOp(Elemento* elem);

/**
* @brief Destruye el elemento
*
* @param Elemento*
*/
void Elem_destroy(Elemento* elem);

#endif // ELEMENTOS_H_INCLUDED
