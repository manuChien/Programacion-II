#ifndef _CHARSET_
#define _CHARSET_

#define MAX_CHARS 256

/**
 * @brief Estructura para administrar conjuntos de caracteres
 * (versión 1)
 */
typedef struct _charset charset;

/**
 * @brief Crea e inicializa un conjunto de caracteres vacío.
 *
 * @return puntero al conjunto de caracteres.
 */
charset* charset_init();

/**
 * @brief Destruye y libera la memoria de un conjunto de caracteres
 *
 * @param cs conjunto de caracteres a liberar.
 */
void charset_free(charset *cs);

/**
 * @brief agrega un carácter a un conjunto de caracteres
 *
 * @param cs conjunto de caracteres
 * @param c carácter a agregar
 * si el carácter ya estaba, lo deja como estaba.
 */
void charset_add(charset *cs, char c);

/**
 * @brief remueve un caracter de un conjunto de caracteres
 *
 * @param cs conjunto de caracteres
 * @param c carácter a remover
 * si el carácter no estaba, no hace nada
 */
void charset_remove(charset *cs, char c);

/**
 * @brief permite consultar si un carácter pertenece a un conjunto.
 *
 * @param cs conjunto de caracteres
 * @param c caracter por el cual se consulta
 * @return int 1 = el caracter pertenece al conjunto, 0 si no.
 */
int charset_in(charset *cs, char c);

/**
 * @brief agrega al conjunto de caracteres (charset)
 * todos los caracteres de un string
 *
 * @param cs conjunto de caracteres
 * @param s strinc con los caracteres a agregar
 */
void charset_add_str (charset *cs, char *s);

/**
 * @brief agrega al conjunto de caracteres
 * todos los caracteres en un rango ASCII
 *
 * @param cs con junto de caracteres
 * @param from carácter inicial
 * @param to carácter final
 */
void charset_add_range (charset *cs,unsigned char from, unsigned char to);

void charset_print(charset *cs);

/**
 * @brief Busca los caracteres presentes en ambos charset pedidos.
 *
 * @return puntero al conjunto interseccion.
 */
charset* charset_intersection (charset*, charset*);

/**
 * @brief Convierte en string los caracteres de un conjunto.
 *
 * @return Puntero al string que contiene los caracteres del conjunto.
 */
char* charset_tostring (charset*);

char* string_commonLetters (char**);

int string_wordCount (char*);

#endif /* _CHARSET_ */
