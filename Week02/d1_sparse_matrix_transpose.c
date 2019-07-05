#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row, col, val;
} term;

term* generate_matrix(int, int);
void display_matrix(term*);
term* transpose_matrix(term*);

int main() {
    srand(time(NULL));
    int row = rand() % 10 + 1, col = rand() % 10 + 1;
    term *a = generate_matrix(row, col);
    term *b = transpose_matrix(a);
    
    display_matrix(a);
    display_matrix(b);
    
    free(a);
    free(b);
    
    return 0;
}

term* generate_matrix(int row, int col) {
    printf("Generating Matrix\n");
    int i, j, r, idx = 0, n = row * col;
    term *m = (term*)malloc(sizeof(term) * (n + 1));
    
    m[0].row = row;
    m[0].col = col;
    m[0].val = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            r = rand() % n;
            if (r < (n / 4)) {
                r = rand() % 90 + 10;
                m[++idx].row = i;
                m[idx].col = j;
                m[idx].val = r;
                m[0].val++;
            }
        }
    }

    m = (term*)realloc(m, sizeof(term) * (idx + 1));
    
    return m;
}

void display_matrix(term *m) {
    int idx = 1;
    printf("=== %dx%d Total %d ===\n", m[0].row, m[0].col, m[0].val);
    
    for (int i = 0; i <= m[0].val; i++)
        printf("(%d, %d, %d)\n", m[i].row, m[i].col, m[i].val);
    printf("\n");
    
    for (int i = 0; i < m[0].row; i++) {
        for (int j = 0; j < m[0].col; j++) {
            int val = 0;
            if (m[idx].row == i && m[idx].col == j)
                val = m[idx++].val;
            printf("%2d ", val);
        } printf("\n");
    } printf("\n");
}

term* transpose_matrix(term *a) {
    int i, j, idx = 1;
    term *b = (term*)malloc(sizeof(term) * a[0].val);

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for (i = 0; i < a[0].col; i++) {
        for (j = 1; j <= a[0].val; j++) {
            if (a[j].col == i) {
                b[idx].row = a[j].col;
                b[idx].col = a[j].row;
                b[idx].val = a[j].val;
                idx++;
            }
        }
    }

    return b;
}