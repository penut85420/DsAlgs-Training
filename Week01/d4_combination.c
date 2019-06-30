/**
 * Author: Penut Chen
 * Date: 2019-6-30
 * Description: 
 *   Practice of combination function.
 */

#include <stdio.h>
#include <stdlib.h>

int* generate_array(int);
void combination(int*, int, int, int, int*, int*);

int main() {
    int size = 5, length = 3, count = 0;
    int *arr = generate_array(size);
    int *copy = (int*)malloc(sizeof(int) * size);

    combination(arr, size, 0, length, copy, &count);
    printf("Total %d", count);
    free(arr);

    return 0;
}

int* generate_array(int size) {
    int *arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    return arr;
}

void combination(int *arr, int size, int idx, int length, int *copy, int *count) {
    if (idx == length) {
        for (int i = 0; i < length; i++)
            printf("%d ", copy[i]);
        printf("\n");
        *count += 1;
        return ;
    }

    for (int i = 0; i < size; i++) {
        copy[idx] = arr[i];
        combination(arr, size, idx + 1, length, copy, count);
    }
}