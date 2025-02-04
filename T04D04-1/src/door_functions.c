#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846
#define NUM_SAMPLES 42

// Функция Верзьера Аньези
double verziere(double x);

// Лемниската Бернулли
double lemniscate(double x);

// Квадратичная гипербола
double hyperbola(double x);
int main() {
    double step = (2 * PI) / (NUM_SAMPLES - 1);
    double x;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        x = -PI + i * step;

        double v = verziere(x);
        double l = lemniscate(x);
        double h = hyperbola(x);

        printf("%.7f | ", x);
        if (v == -1) {
            printf("- | ");
        } else {
            printf("%.7f | ", v);
        }
        if (l == -1) {
            printf("- | ");
        } else {
            printf("%.7f | ", l);
        }
        if (h == -1) {
            printf("- | ");
        } else {
            printf("%.7f | ", h);
        }
        printf("\n");
    }
    return 0;
}

// Функция Верзьера Аньези
double verziere(double x) { return 1 / (1 + x * x); };

// Лемниската Бернулли
double lemniscate(double x) {
    if (sqrt(1 + 4 * x * x) < (x * x + 1)) {
        return -1;  // Отрицальный корень
    }
    return sqrt(sqrt(1 + 4 * x * x) - x * x + 1);
}

// Квадратичная гипербола
double hyperbola(double x) {
    if (x == 0) {
        return -1;  // Делить на 0
    }
    return 1 / (x * x);
}
