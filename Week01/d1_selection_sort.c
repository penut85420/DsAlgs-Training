/**
 * Author: Penut Chen
 * Date: 2019-6-28
 * Description: 
 *   Practice of selection sort algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* random_array(int);
void display_array(int*, int);
void selection_sort(int*, int);
void swap(int*, int*);
void measure(int, int);

int main() {
    int i, n = 25;
    int *arr = random_array(n);

    printf("Before sort:\n");
    display_array(arr, n);

    selection_sort(arr, n);

    printf("\nAfter sort:\n");
    display_array(arr, n);

    free(arr);

    measure(25, 5000);

    return 0;
}

int* random_array(int n) {
    int i, r, *arr = (int*)malloc(sizeof(int) * n);
    
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

void selection_sort(int *arr, int n) {
    int i, j, m, t;

    for (i = 0; i < n; i++) {
        for (m = j = 0; j < n-i; j++) {
            if (arr[m] < arr[j])
                m = j;
        }
        swap(&arr[m], &arr[j - 1]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void measure(int run_times, int size) {
    double *cost_record = (double*)malloc(sizeof(double) * run_times);
    printf("\nRun %d Times - Array Size: %d\n\n", run_times, size);

    for (int i = 0; i < run_times; i++) {
        int *arr = random_array(size);
        time_t begin = clock();
        selection_sort(arr, size);
        double cost = (double)(clock() - begin) / CLOCKS_PER_SEC;
        printf("Run %2d Time Cost: %.6lf\n", i + 1, cost);
        free(arr);
        cost_record[i] = cost;
    }

    double sum = 0;
    for (int i = 0; i < run_times; i++)
        sum += cost_record[i];
    
    printf("\nAverage Time Cost: %.6lf\n", sum / run_times);
}