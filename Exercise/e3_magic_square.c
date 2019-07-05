#include <stdio.h>
#include <stdlib.h>

void magic_square(int);
int numlen(int);

int main() {

    for (int i = 1; i < 30; i += 2)
        magic_square(i);

    return 0;
}

void magic_square(int n) {
    int i, j, sum, tlen;
    int idx = 1, nn = n * n;
    int nrow, ncol, row = 0, col = n / 2;
    int **m = (int**)malloc(sizeof(int*) * n);
    
    // Initialize Square

    for (i = 0; i < n; i++) {
        m[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            m[i][j] = 0;
    }

    // Begin Filling
    
    while (idx <= nn) {
        m[row][col] = idx++;
        nrow = (row + n - 1) % n;
        ncol = (col + n - 1) % n;
        if (m[nrow][ncol]) {
            nrow = (row + 1) % n;
            ncol = col;
        }
        row = nrow;
        col = ncol;
    }

    // Begin Display
    
    // Calculation of Print Width
    for (sum = i = 0; i < n; i++)
        sum += m[0][i];
    tlen = numlen(sum);

    // Show Square & Count the Sum of Rows
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            printf("%*d ", tlen, m[i][j]);
            sum += m[i][j];
        } printf("| %*d\n", tlen, sum);
    }

    // Print Horizontal Line
    for (i = 0; i < n; i++)
        for (j = 0; j <= tlen; j++)
            printf("-");
    printf("\n");
    
    // Count the Sum of Columns
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) 
            sum += m[j][i];
        printf("%*d ", tlen, sum);
    } printf("\n\n");

    free(m);
}

int numlen(int n) {
    int len;
    
    for (len = 1; n > 9; n /= 10, len++)
        ;
    
    return len;
}