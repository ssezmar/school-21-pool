#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);

double mean(int *a, int n);

double variance(int *a, int n);

int search_value(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }

    int result = search_value(data, n);
    printf("%d", result);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    char last_sym = getchar();

    if (last_sym != '\n' && last_sym != EOF) {
        return 1;
    }

    return 0;
}

double mean(int *a, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_val = mean(a, n);
    double sum_squared_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_squared_diff += (a[i] - mean_val) * (a[i] - mean_val);
    }
    return sum_squared_diff / n;
}

int search_value(int *a, int n) {
    double mean_val = mean(a, n);
    double var_val = variance(a, n);
    double threshold = mean_val + 3 * sqrt(var_val);

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_val && a[i] <= threshold && a[i] != 0) {
            return a[i];
        }
    }
    return 0;
}