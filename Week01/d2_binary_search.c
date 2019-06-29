/**
 * Author: Penut Chen
 * Date: 2019-6-29
 * Description: 
 *   Practice of binary search algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

int* generate_array(int);
int binary_search(int*, int, int, int);

int main() {
    int i, idx, n = 100;
    int *arr = generate_array(n);

    for (int i = 0; i < n * 2; i++) {
        printf("\nSearching %d\n", i);
        idx = binary_search(arr, 0, n, i);
        printf("Found target at index %d\n", idx);
    }

    free(arr);
    
    return 0;
}

int* generate_array(int size) {
    int i, *arr = (int*)malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++)
        arr[i] = i * 2 + 1;
    
    return arr;
}

int binary_search(int *arr, int left, int right, int target) {
    int middle = (left + right) / 2;

    printf("[%d, %d] Looking at index %d\n", left, right, middle);
    
    if (arr[middle] == target) return middle;
    if (left >= right - 1) return -1;
    if (arr[middle] < target) left = middle;
    if (arr[middle] > target) right = middle;
    
    return binary_search(arr, left, right, target);
}