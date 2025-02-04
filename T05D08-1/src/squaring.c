#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) {
            return 1;
        }
    }
    char last_symb = getchar();
    if (last_symb != '\n' && last_symb != EOF) {
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    int *p = a;
    printf("%d", *p);
    p++;
    for (; p - a < n; p++) {
        printf(" %d", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}