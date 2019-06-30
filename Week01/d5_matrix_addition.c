/**
 * Author: Penut Chen
 * Date: 2019-6-30
 * Description: 
 *   Practice of matrix addition.
 */

#include <stdio.h>
#include <stdlib.h>

int** generate_matrix(int, int);
void display_matrix(int**, int, int);
int** matrix_addition(int**, int**, int, int);

int main() {
    int row = 3, col = 5;
    int **a = generate_matrix(row, col);
    int **b = generate_matrix(row, col);

    printf("Matrix A\n");
    display_matrix(a, row, col);

    printf("\nMatrix B\n");
    display_matrix(b, row, col);

    int **c = matrix_addition(a, b, row, col);
    printf("\nA + B = \n");
    display_matrix(c, row, col);

    free(a);
    free(b);
    free(c);
    
    return 0;
}

int** generate_matrix(int row, int col) {
    int **matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++)
            matrix[i][j] = rand() % 90 + 10;
    }
    return matrix;
}

void display_matrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int** matrix_addition(int **a, int **b, int row, int col) {
    int **result = (int**)malloc(sizeof(int*) * row);

    for (int i = 0; i < row; i++) {
        result[i] = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++)
            result[i][j] = a[i][j] + b[i][j];
    }

    return result;
}