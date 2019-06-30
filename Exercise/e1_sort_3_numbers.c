/**
 * Author: Penut Chen
 * Date: 2019-6-30
 * Description: 
 *   Try to sort 3 numbers without condition statement.
 */

#include <stdio.h>

int myabs(int n) { return ((n < 0) * -2 + 1) * n; }
int max(int a, int b) { return (a + b + myabs(a - b)) / 2; }
int min(int a, int b) { return (a + b - myabs(a - b)) / 2; }

int sort(int *a, int *b, int *c) {
    int nmin = min(min(*a, *b), *c);
    int nmax = max(max(*a, *b), *c);
    int nmid = *a + *b + *c - nmax - nmin;
    
    *a = nmin;
    *b = nmid;
    *c = nmax;
}

int main() {
    int a = 21, b = 17, c = 35;

    printf("Before:\n  %d %d %d\n", a, b, c);
    sort(&a, &b, &c);
    printf("\nAfter:\n  %d %d %d\n", a, b, c);
    
    return 0;
}