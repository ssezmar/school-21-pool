#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846
#define NUM_SAMPLES 42
#define Y_SCALE 21

// Функция Верзьера Аньези
double verziere(double x);

// Лемниската Бернулли
double lemniscate(double x);

// Квадратичная гипербола
double hyperbola(double x);

// Нормализация
int normalize(double value);

// Интерфес взаимодействия над тремя функциями
double super_f(int grafic_num, double num);

// Линия
void print_line();

// Вывести график
void print_grafic(double step, int grafic_num);

int main() {
    double step = (2 * PI) / (NUM_SAMPLES - 1);

    print_grafic(step, 1);
    print_grafic(step, 2);
    print_grafic(step, 3);

    return 0;
}

// Функция Верзьера Аньези
double verziere(double x) { return 1 / (1 + x * x); }

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

// Нормализация
int normalize(double value) {
    if (value < 0) return Y_SCALE;
    if (value > 1) return 0;
    return (int)((1 - value) * Y_SCALE);
}

// Интерфес взаимодействия над тремя функциями
double super_f(int grafic_num, double num) {
    if (grafic_num == 1) {
        return verziere(num);
    } else if (grafic_num == 2) {
        return lemniscate(num);
    } else if (grafic_num == 3) {
        return hyperbola(num);
    }
    return 0;
}

// Линия
void print_line() {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("-");
    }
    printf("\n");
}

// Вывести график
void print_grafic(double step, int grafic_num) {
    print_line();

    for (int i = 0; i < Y_SCALE; i++) {
        for (int j = 0; j < NUM_SAMPLES; j++) {
            double x = -PI + j * step;

            double cord = super_f(grafic_num, x);

            int cord_pos = normalize(cord);

            if (i == cord_pos) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    print_line();
}