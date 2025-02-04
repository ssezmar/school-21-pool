#include <stdio.h>
#include <stdlib.h>

int invert(double **matrix, int n, int m, double **result_matrix);
double algebraic_complement(double **matrix, int n, int m, int i, int j);
double det(double **matrix, int n, int m);
int create_matrix(double ***mptr, int m, int n);
int input_matrix(double **matrix, int r, int c);
void output(double **matrix, int n, int m);

int main() {
    int r1, c1;
    double **m1, **m2;
    m1 = NULL;
    m2 = NULL;
    int error = 0;

    if (scanf("%d %d", &r1, &c1) != 2) {
        error = 1;
    }
    if (!error && r1 != c1) {
        error = 1;
    }
    if (!error && r1 <= 0) {
        error = 1;
    }
    if (!error && (create_matrix(&m1, r1, c1) || input_matrix(m1, r1, c1))) {
        error = 1;
    }
    if (!error && create_matrix(&m2, r1, c1)) {
        error = 1;
    }

    if (!error && invert(m1, r1, c1, m2)) {
        error = 1;
    }

    if (!error) {
        output(m2, r1, c1);
    }
    if (error) {
        printf("n/a");
    }

    free(m1);
    free(m2);

    return 0;
}

double algebraic_complement(double **matrix, int n, int m, int i, int j) {
    double ans;
    double **new_matrix;
    new_matrix = NULL;

    create_matrix(&new_matrix, n - 1, m - 1);
    for (int ind1 = 0; ind1 < n; ind1++) {
        if (ind1 == i) continue;
        for (int ind2 = 0; ind2 < m; ind2++) {
            if (ind2 == j) continue;
            if (ind1 > i)
                if (ind2 > j)
                    new_matrix[ind1 - 1][ind2 - 1] = matrix[ind1][ind2];
                else
                    new_matrix[ind1 - 1][ind2] = matrix[ind1][ind2];
            else if (ind2 > j)
                new_matrix[ind1][ind2 - 1] = matrix[ind1][ind2];
            else
                new_matrix[ind1][ind2] = matrix[ind1][ind2];
        }
    }

    if ((i + j) % 2)
        ans = -det(new_matrix, n - 1, m - 1);
    else
        ans = det(new_matrix, n - 1, m - 1);
    free(new_matrix);

    return ans;
}

int invert(double **matrix, int n, int m, double **result_matrix) {
    double det_m;
    if (!(det_m = det(matrix, n, m))) return 1;

    if (n == 1) return (1 / matrix[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[j][i] = algebraic_complement(matrix, n, m, i, j) / det_m;
        }
    }

    return 0;
}

int create_matrix(double ***mptr, int m, int n) {
    double **values = malloc(n * m * sizeof(double) + m * sizeof(double *));
    if (!values) return 1;
    double *ptr = (double *)(values + m);
    for (int i = 0; i < m; i++) values[i] = ptr + i * n;
    *mptr = values;

    return 0;
}

double det(double **matrix, int n, int m) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        double **new_matrix = NULL;
        create_matrix(&new_matrix, n - 1, m - 1);
        for (int ind1 = 0; ind1 < n; ind1++) {
            if (ind1 == i) continue;
            for (int ind2 = 1; ind2 < m; ind2++) {
                if (ind1 > i)
                    new_matrix[ind1 - 1][ind2 - 1] = matrix[ind1][ind2];
                else
                    new_matrix[ind1][ind2 - 1] = matrix[ind1][ind2];
            }
        }
        if (i % 2)
            ans -= matrix[i][0] * det(new_matrix, n - 1, m - 1);
        else
            ans += matrix[i][0] * det(new_matrix, n - 1, m - 1);
        free(new_matrix);
    }

    return ans;
}

int input_matrix(double **matrix, int r, int c) {
    char ch;
    if (!matrix) return 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%lf", matrix[i] + j) != 1) return 1;
        }
    }
    if (((ch = getchar()) != (int)'\n') && (ch != (int)EOF)) return 1;

    return 0;
}

void output(double **matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((c == 1) && (i < r - 1))
                printf("%.6lf\n", matrix[i][j]);
            else if (c == 1)
                printf("%.6lf", matrix[i][j]);
            else if ((i == r - 1) && (j == c - 1))
                printf(" %.6lf", matrix[i][j]);
            else if (j == c - 1)
                printf(" %.6lf\n", matrix[i][j]);
            else if (j == 0)
                printf("%.6lf", matrix[i][j]);
            else
                printf(" %.6lf", matrix[i][j]);
        }
    }
}