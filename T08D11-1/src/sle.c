#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double det);
int input_matrix(double **matrix, int r, int c);
int create_matrix(double ***mptr, int m, int n);
void create_submatrix(double **mptr, int m, int n, int b, double ***mprt_b);

int main() {
    int r1 = 1, c1 = 1;
    double **m1 = NULL;
    int error = 0;

    if (scanf("%d", &r1) != 1) {
        error = 1;
    }
    if (!error) {
        if (scanf("%d", &c1) != 1) {
            error = 1;
        }
    }
    if (!error) {
        if (c1 - r1 != 1) error = 1;
        if (c1 <= 0 || r1 <= 0) error = 1;
    }

    if (!error) {
        error += create_matrix(&m1, r1, c1);
    }

    if (!error) {
        error += input_matrix(m1, r1, c1);
    }

    if (!error) {
        if (det(m1, r1, c1) == 0) {
            error = 1;
        }
    }

    if (!error) {
        for (int i = 0; i < r1; i++) {
            double **m2 = NULL;
            create_matrix(&m2, r1, c1 - 1);
            create_submatrix(m1, r1, c1 - 1, i, &m2);
            printf("%.6lf", det(m2, r1, c1 - 1) / det(m1, r1, c1));
            if (i != r1 - 1) {
                printf(" ");
            }
            free(m2);
        }
    }

    if (m1) free(m1);

    if (error) {
        printf("n/a");
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

void create_submatrix(double **mptr, int m, int n, int b, double ***mptr_b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            (*mptr_b)[i][j] = mptr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        (*mptr_b)[i][b] = mptr[i][m];
    }
}

double det(double **matrix, int n, int m) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        double **new_matrix;
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
