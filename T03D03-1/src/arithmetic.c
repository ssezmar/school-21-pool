#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int n1, n2;
    char last_symbol;

    if (!(scanf("%d", &n1))) {
        printf("n/a\n");
        return 1;
    }
    if (!(scanf("%d", &n2))) {
        printf("n/a\n");
        return 1;
    }

    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/a\n");
        return 1;
    }

    if (n2 == 0) {
        printf("%d %d %d n/a\n", sum(n1, n2), dif(n1, n2), mul(n1, n2));
    } else {
        printf("%d %d %d %d\n", sum(n1, n2), dif(n1, n2), mul(n1, n2), div(n1, n2));
    }
    return 0;
}

int sum(int a, int b) { return (a + b); }

int dif(int a, int b) { return (a - b); }

int mul(int a, int b) { return (a * b); }

int div(int a, int b) { return (a / b); }