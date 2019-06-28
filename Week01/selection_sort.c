/**
 * Author: Penut Chen
 * Date: 2019-6-28
 * Description: 
 *   Practice of selection sort algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

int* random_array(int);
void display_array(int*, int);
void selection_sort(int*, int, int);
void swap(int*, int*);

int main() {
    int i, n = 50;
    int *arr = random_array(n);

    printf("Before sort:\n");
    display_array(arr, n);

    selection_sort(arr, n, 0);

    printf("\nAfter sort:\n");
    display_array(arr, n);

    free(arr);

    return 0;
}

int* random_array(int n) {
    int i, r, *arr = (int*) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        arr[i] = i;
    
    for (i = 0; i < n; i++) {
        r = rand() % n;
        swap(&arr[i], &arr[r]);
    }

    return arr;
}

void display_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%02d ", arr[i]);
    printf("\n");
}

void selection_sort(int *arr, int n, int reversed) {
    int i, j, m, t;

    for (i = 0; i < n; i++) {
        for (m = j = 0; j < n-i; j++) {
            if (reversed && arr[m] > arr[j])
                m = j;
            if (!reversed && arr[m] < arr[j])
                m = j;
        }
        swap(&arr[m], &arr[n - i - 1]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}