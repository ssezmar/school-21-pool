#include <stdio.h>

double f(double x, double y);

int main() {
    double x, y;
    char last_symbol;

    if (!(scanf("%lf", &x))) {
        printf("n/a\n");

        return 1;
    }
    if (!(scanf("%lf", &y))) {
        printf("n/a\n");

        return 1;
    }

    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/a\n");

        return 1;
    }

    if (f(x, y) > 25) {
        printf("MISS\n");
    } else {
        printf("GOTCHA\n");
    }

    return 0;
}

double f(double x, double y) { return x * x + y * y; }