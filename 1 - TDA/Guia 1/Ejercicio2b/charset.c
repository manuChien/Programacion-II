#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charset.h"

#define MAX_CHARS 256


/**
 * @brief Estructura para administrar conjuntos de caracteres
 * (versión 1)
 */
typedef struct _charset {
    char v[MAX_CHARS];
    char size;
} charset;


/**
 * @brief Crea e inicializa un conjunto de caracteres vacío.
 *
 * @return puntero al conjunto de caracteres.
 */
charset* charset_init(){
    charset* result;
    result = (charset*)malloc(sizeof(charset));
    result->size = 0;
    return result;
}

/**
 * @brief Destruye y libera la memoria de un conjunto de caracteres
 *
 * @param cs conjunto de caracteres a liberar.
 */
void charset_free(charset *cs) {
    free(cs);
}

/**
 * @brief agrega un carácter a un conjunto de caracteres
 *
 * @param cs conjunto de caracteres
 * @param c carácter a agregar
 * si el carácter ya estaba, lo deja como estaba.
 */
void charset_add(charset *cs, char c){
    int i = 0;

    while ((i < cs->size) && (cs->v[i] != c)){
        i++;
    }

    if (!(i < cs->size)){
        cs->v[cs->size] = c;
        cs->size++;
    }

}

/**
 * @brief remueve un caracter de un conjunto de caracteres
 *
 * @param cs conjunto de caracteres
 * @param c carácter a remover
 * si el carácter no estaba, no hace nada
 */
void charset_remove(charset *cs, char c){
    int i = 0;

    while ((i < cs->size) && (cs->v[i] != c)){
        i++;
    }

    if (i < cs->size){
        cs->size--;
    }

    while ((i < cs->size)){
        cs->v[i] = cs->v[i+1];
        i++;
    }

}

/**
 * @brief permite consultar si un carácter pertenece a un conjunto.
 *
 * @param cs conjunto de caracteres
 * @param c caracter por el cual se consulta
 * @return int 1 = el caracter pertenece al conjunto, 0 si no.
 */
int charset_in(charset *cs, char c){
    // devuelve 1 si está o 0 si no está
    char result = 0;
    int i = 0;

    while ((i < cs->size) && (cs->v[i] != c)){
        i++;
    }

    if (i < cs->size){
        result = 1;
    }

    return result;
}

/**
 * @brief agrega al conjunto de caracteres
 * todos los caracteres de un string
 *
 * @param cs conjunto de caracteres
 * @param s strinc con los caracteres a agregar
 */
void charset_add_str (charset *cs, char *s) {
    if (s == NULL) return;
    while (*s != '\0'){
        charset_add (cs, *s);
        s++;
    }
}

/**
 * @brief agrega al conjunto de caracteres
 * todos los caracteres en un rango ASCII
 *
 * @param cs con junto de caracteres
 * @param from carácter inicial
 * @param to carácter final
 */
void charset_add_range (charset *cs,unsigned char from, unsigned char to) {
    for (unsigned char i = from; i <= to; i++){
        charset_add (cs, i);
    }
}

void charset_print(charset *cs) {
    for (int i = 0; i < 256; i++) {
        if (charset_in(cs, (char)i)) {
            printf(" %c", (char)i);
        }
    }
    printf("\n");
}

void test_charset_v1() {
    charset *cs = charset_init();

    charset_add(cs, 'a');
    charset_add(cs, 'b');
    charset_add(cs, 'c');
    charset_add(cs, 'd');


    printf ("Conentendio luego de la carga: ");
    charset_print(cs);

    charset_remove(cs, 'a');

    printf ("Contenido luego de quitar 'a': ");
    charset_print(cs);

}

charset* charset_intersection (charset *A, charset *B)
{
    charset *resultado = charset_init();

    for(int i=0; i<MAX_CHARS; i++)
    {
        if(charset_in(A,i) && charset_in(B,i))
        {
            charset_add(resultado,i);
        }
    }

    return resultado;
}

char* charset_tostring (charset *cs)
{
    char *resultado = malloc(MAX_CHARS + 1);

    int j = 0;
    for(int i=0; i<MAX_CHARS; i++)
    {
        if(charset_in(cs,i))
        {
            resultado[j] = i;
            resultado[j+1] = '\0';
            j++;
        }
    }

    return resultado;
}

char* string_commonLetters (char** arrayStrings)
{
    charset **arrayCharsets = malloc(32*sizeof(charset *));
    charset *resultante = charset_init();

    for(int i=0; i<32; i++)
    {
        arrayCharsets[i] = charset_init();
        charset_add_str(arrayCharsets[i],arrayStrings[i]);
    }

    charset_add_str(resultante,arrayStrings[0]);

    for(int j=0; j<32; j++)
    {
        if(arrayStrings[j] != NULL)
        {
            charset *temporal = charset_init();
            temporal = charset_intersection(resultante,arrayCharsets[j]);
            charset_free(resultante);
            resultante = temporal;
        }
    }

    return charset_tostring(resultante);
}

int string_wordCount (char* cadena)
{
    int cantidad = 0;
    char *delimitadores = malloc(16); //ATENCION! ACÁ ASIGNO UN ESPACIO EN MEMORIA
    delimitadores = ".,:;?()[]{} \t "; //PERO ACÁ LE ASIGNO OTRO ESPACIO EN MEMORIA EN EL STACK
    charset *caracteresDelimitadores = charset_init();
    charset_add_str(caracteresDelimitadores,delimitadores);

    int flag = 1;
    int anterior = flag;

    int i = 0;
    while(cadena[i] != '\0')
    {
        anterior = flag;
        flag = charset_in(caracteresDelimitadores,cadena[i]);
        if(flag!=anterior)
        {
            if(flag!=1)
            {
                cantidad++;
            }
        }
        i++;
    }

    return cantidad;
}
