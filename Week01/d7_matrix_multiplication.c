/**
 * Author: Penut Chen
 * Date: 2019-7-1
 * Description: 
 *   Practice of matrix multiplication.
 */

#include <stdio.h>
#include <stdlib.h>

int** generate_matrix(int, int);
void display_matrix(int**, int, int);
int** matrix_multiplication(int**, int**, int, int, int);

int main() {
    int arow = 3, acol = 2;
    int **a = generate_matrix(arow, acol);
    
    int brow = acol, bcol = 4;
    int **b = generate_matrix(brow, bcol);

    printf("Matrix A\n");
    display_matrix(a, arow, acol);

    printf("\nMatrix B\n");
    display_matrix(b, brow, bcol);

    int crow = arow, ccol = bcol;
    int **c = matrix_multiplication(a, b, arow, acol, bcol);

    printf("\nA x B\n");
    display_matrix(c, crow, ccol);

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
            matrix[i][j] = rand() % 10;
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

int** matrix_multiplication(int **a, int **b, int a_row, int a_col, int b_col) {
    int i, j, k;
    int **c = (int**)malloc(sizeof(int*) * a_row);
    
    for (i = 0; i < a_row; i++) {
        c[i] = (int*)malloc(sizeof(int) * b_col);
        for (j = 0; j < b_col; j++) {
            c[i][j] = 0;
            for (k = 0; k < a_col; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    return c;
}

/** 3r2c  2r4c      3r4c
 *  1 2 x 1 2 3 1 =  9 12 15  3
 *  3 4   4 5 6 1   19 26 33  7
 *  5 6             29 40 51 11
 */

/**
 *  1 7 x 8 8 2 4 = 43 43  9 53
 *  4 0   5 5 1 7   32 32  8 16
 *  9 4             92 92 22 64
 */