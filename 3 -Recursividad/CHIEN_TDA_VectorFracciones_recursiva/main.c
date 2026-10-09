#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "fracciones.h"
#include "funciones.h"

int main()
{
//CREO E IMPRIMO UN VECTOR DE FRACCIONES RANDOM DE PRUEBA
    printf("Vector de prueba:\n");
    Vector* v = vector_new(10);
    for(int i=0; i<10; i++)
    {
        vector_add(v,fraction_new(rand()%10+1,rand()%10+1));
    }
    vector_print(v,fraction_print);
    printf("\n\n");

//PRUEBO CALCULAR MAXIMO ELEMENTO
    printf("a) El maximo elemento fraccionario del vector es: ");
    fraction* maximoElemento = max_fraction(v);
    fraction_print(maximoElemento);
    printf("\n\n");

//PRUEBO CALCULAR EL MINIMO ELEMENTO
    printf("b) El minimo elemento fraccionario del vector es: ");
    fraction* minimoElemento = min_fraction(v);
    fraction_print(minimoElemento);
    printf("\n\n");

//PRUEBO CALCULAR LA SUMA DE TODAS LAS FRACCIONES DEL VECTOR
    printf("c) La suma de todos los elementos fraccionarios del vector es: ");
    fraction* sumaTotal = suma_vector(v);
    fraction_print(sumaTotal);
    printf("\n\n");

//PRUEBO CALCULAR EL PROMEDIO DE LAS FRACCIONES DEL VECTOR
    printf("d) El promedio de los elementos fraccionarios del vector es: ");
    fraction* promedio = promedio_vector(v);
    fraction_print(promedio);
    printf("\n\n");

//PRUEBO IMPRIMIR TODOS LOS ELEMENTOS DEL VECTOR FRACCIONARIO CON ORDEN INDICE CRECIENTE DE FORMA RECURSIVA
    printf("e) Muestra de todos los elementos del vector fraccionario con orden indices crecientes de forma recursiva: ");
    printf("\n");
    impresionRecursiva_vectorFraccionario(v);
    printf("\n\n");

//PRUEBO IMPRIMIR TODOS LOS ELEMENTOS DEL VECTOR FRACCIONARIO CON ORDEN INDICE DESCENDENTE DE FORMA RECURSIVA
    printf("f) Muestra de todos los elementos del vector fraccionario con orden indices descendentes de forma recursiva: ");
    printf("\n");
    impresionRecursivaDescendente_vectorFraccionario(v);
    printf("\n\n");

//LIBERACION FINAL DE FRACCIONES RESULTADOS Y VECTOR DE PRUEBA
    fraction_destroy(sumaTotal);
    fraction_destroy(promedio);
    vector_free(v);
//No libero minimo y promedio con fraction destroy manualmente porque contienen direcciones de memoria que estan dentro del vector, habria doble free

    return 0;
}
