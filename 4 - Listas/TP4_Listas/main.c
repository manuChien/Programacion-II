#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//FUNCIONES ADICIONALES
int isHigherInt(NODE_ELEMENT A, NODE_ELEMENT B)
{
    return A-B;
}
int isLowerInt(NODE_ELEMENT A, NODE_ELEMENT B)
{
    return B-A;
}

node* crear_nodo(int valor) {
    node* nuevo = (node*)malloc(sizeof(node));
    if (!nuevo) return NULL;
    nuevo->data = valor;
    nuevo->next = NULL;
    return nuevo;
}

void liberar_lista(node* h) {
    while (h != NULL) {
        node* aux = h;
        h = h->next;
        free(aux);
    }
}

int main()
{
    node* l1 = crear_nodo(10);
    l1->next = crear_nodo(20);

    // 2. Armamos Lista 2: 30 -> 40 -> 50 -> NULL (Promedio = 40)
    node* l2 = crear_nodo(30);
    l2->next = crear_nodo(40);
    l2->next->next = crear_nodo(50);

    // 3. Armamos Lista 3: 4 -> 8 -> NULL (Promedio = 6)
    node* l3 = crear_nodo(4);
    l3->next = crear_nodo(8);

    // 4. Creamos el arreglo de punteros terminado con el centinela NULL
    node* lista_de_listas[] = { l1, l2, l3, NULL };

    // 5. Probamos los promedios individuales
    printf("Promedio Lista 1: %d\n", lista_promedio(l1)); // Esperado: 15
    printf("Promedio Lista 2: %d\n", lista_promedio(l2)); // Esperado: 40
    printf("Promedio Lista 3: %d\n", lista_promedio(l3)); // Esperado: 6

    // 6. Calculamos el máximo de la lista de listas
    int max_promedio = lista_maximoValorListaDeListas(lista_de_listas);
    printf("----------------------------------------\n");
    printf("Maximo promedio encontrado: %d\n", max_promedio); // Esperado: 40

    // 7. Limpieza de memoria
    liberar_lista(l1);
    liberar_lista(l2);
    liberar_lista(l3);

    return 0;

    return 0;
}
