#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_double_pointer(int** double_pointer) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", double_pointer[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Definir matriz
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Definir doble puntero
    int** double_pointer = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        double_pointer[i] = (int*)malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            double_pointer[i][j] = i * COLS + j + 1;
        }
    }

    // Imprimir matriz
    printf("Matriz:\n");
    print_matrix(matrix);

    // Imprimir doble puntero
    printf("Doble puntero:\n");
    print_double_pointer(double_pointer);

    // Liberar memoria del doble puntero
    for (int i = 0; i < ROWS; i++) {
        free(double_pointer[i]);
    }
    free(double_pointer);

    return  0;
}