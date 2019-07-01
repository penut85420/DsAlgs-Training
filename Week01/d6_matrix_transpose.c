/**
 * Author: Penut Chen
 * Date: 2019-7-1
 * Description: 
 *   Practice of matrix transpose.
 */

#include <stdio.h>
#include <stdlib.h>

int** generate_matrix(int, int);
void display_matrix(int**, int, int);
int** matrix_transpose(int**, int, int);

int main() {
    int row = 3, col = 5;
    int **a = generate_matrix(row, col);
    
    printf("Before Transpose\n");
    display_matrix(a, row, col);

    int **b = matrix_transpose(a, row, col);
    
    printf("\nAfter Transpose\n");
    display_matrix(b, col, row);
    
    free(a);
    free(b);
    
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

int** matrix_transpose(int **matrix, int row, int col) {
    int nrow = col, ncol = row;
    int **nmatrix = (int**)malloc(sizeof(int) * nrow);

    for (int i = 0; i < nrow; i++) {
        nmatrix[i] = (int*)malloc(sizeof(int) * ncol);
        for (int j = 0; j < ncol; j++)
            nmatrix[i][j] = matrix[j][i];
    }

    return nmatrix;
}