/**
 * Author: Penut Chen
 * Date: 2019-6-29
 * Description: 
 *   Practice of permutation function.
 */

#include <stdio.h>
#include <stdlib.h>

int* generate_array(int);
void swap(int*, int*);
void permutation(int*, int, int, int*);

int main() {
    int size = 4, count = 0;
    int *arr = generate_array(size);
    
    permutation(arr, size, 0, &count);
    printf("Total %d\n", count);
    free(arr);
    
    return 0;
}

int* generate_array(int size) {
    int *arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    return arr;
}

void permutation(int *arr, int size, int idx, int *count) {
    if (idx == size) {
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
        (*count) += 1;
        return ;
    }
    
    for (int i = idx; i < size; i++) {
        swap(&arr[i], &arr[idx]);
        permutation(arr, size, idx + 1, count);
        swap(&arr[i], &arr[idx]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}