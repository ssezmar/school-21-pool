#include <math.h>
#include <stdio.h>

float f(float);

int main() {
    float x;
    char last_symbol;

    scanf("%f", &x);

    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/a\n");
        return 1;
    }

    if (x == 0) {
        printf("n/a\n");
        return 1;
    }

    float y = f(x);

    printf("%.1f\n", y);

    return 0;
}

float f(float x) {
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0 / 3) - 1e3) * x + 3) / (x * x / 2) -
           x * pow((10 + x), (2 / x)) - 1.01;
}
