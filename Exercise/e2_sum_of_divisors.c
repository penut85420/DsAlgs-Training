#include <stdio.h>

int is_sum_of_divisors(int);
void list_divisors(int);

int main() {
    for (int i = 2; i < 10000; i++) {
        if (is_sum_of_divisors(i))
            printf("%d ", i), list_divisors(i);
    }
    return 0;
}

int is_sum_of_divisors(int n) {
    int sum = 1;
    
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) sum += i + n / i;
    
    return sum == n;
}

void list_divisors(int n) {
    printf("= 1");
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            printf(" + %d", i);
    printf("\n");
}