#include <stdio.h>

int fib(int n) {
    if (n <= 0) {
        printf("n/a");
        return -1;
    }

    if (n == 1) {
        return 1;
    } else if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int num;
    char last_symbol;

    if (1 != scanf("%d", &num)) {
        printf("n/a");
        return 1;
    }
    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/a");
        return 1;
    }

    printf("%d", fib(num));

    return 0;
}