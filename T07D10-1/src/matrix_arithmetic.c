#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, const int n, const int m);
void output(int **matrix, int n, int m);
int input_matrix(const int r, const int c, int **matrix);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int n_result, int m_result);
int transpose(int ***matrix, int n, int m);
int create_matrix(int ***ptr, const int m, const int n);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result);
void task1();
void task2();
void task3();

int main() {
    int mode;

    if (scanf("%d", &mode) != 1) {
        printf("n/a");
        return 1;
    }

    switch (mode) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        default:
            printf("n/a");
            break;
    }

    return 0;
}

int input_matrix(const int r, const int c, int **matrix) {
    char ch;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", matrix[i] + j) != 1) {
                return 1;
            }
        }
    }
    if (((ch = getchar()) != (int)'\n') && (ch != (int)EOF)) {
        return 1;
    }

    return 0;
}

void task1() {
    int r1, r2, c1, c2;
    int **m1, **m2, **m3;

    int error = 0;

    if (scanf("%d %d", &r1, &c1) != 2) {
        error += 1;
    }
    if ((create_matrix(&m1, r1, c1) || input_matrix(r1, c1, m1)) && !error) {
        free(m1);
        error += 1;
    }
    if (scanf("%d %d", &r2, &c2) != 2 && !error) {
        error += 1;
    }
    if ((create_matrix(&m2, r2, c2) || input_matrix(r2, c2, m2)) && !error) {
        free(m2);
        error += 1;
    }
    if (create_matrix(&m3, r1, c1) && !error) {
        free(m1);
        free(m2);
        error += 1;
    }

    if (sum(m1, r1, c1, m2, r2, c2, m3, r1, c1) && !error) {
        free(m1);
        free(m2);
        free(m3);
        error += 1;
    }

    if (!error) {
        output(m3, r1, c1);
    } else {
        printf("n/a");
    }
    free(m1);
    free(m2);
    free(m3);
}

void task2() {
    int r1, r2, c1, c2;
    int **m1, **m2, **m3;
    int error = 0;

    if (scanf("%d %d", &r1, &c1) != 2 && !error) {
        error = 1;
    }
    if ((create_matrix(&m1, r1, c1) || input_matrix(r1, c1, m1)) && !error) {
        free(m1);
        error = 1;
    }
    if (scanf("%d %d", &r2, &c2) != 2 && !error) {
        error = 1;
    }
    if ((create_matrix(&m2, r2, c2) || input_matrix(r2, c2, m2)) && !error) {
        free(m2);
        error = 1;
    }
    if (create_matrix(&m3, r1, c2) && !error) {
        free(m1);
        free(m2);
        error = 1;
    }

    if (mul(m1, r1, c1, m2, r2, c2, m3) && !error) {
        free(m1);
        free(m2);
        free(m3);
        error = 1;
    }

    if (!error) {
        output(m3, r1, c2);
    } else {
        printf("n/a");
    }
    free(m1);
    free(m2);
    free(m3);
}

void task3() {
    int r1, c1;
    int **m1;
    int error = 0;

    if (scanf("%d %d", &r1, &c1) != 2 && !error) {
        error = 1;
    }
    if (create_matrix(&m1, r1, c1) && !error) {
        free(m1);
        error = 1;
    }

    if (input_matrix(r1, c1, m1) && !error) {
        error = 1;
    }

    if (transpose(&m1, r1, c1) && !error) {
        free(m1);
        error = 1;
    }

    if (!error) {
        output(m1, c1, r1);
    } else {
        printf("n/a");
    }
    free(m1);
}

void output(int **matrix, const int r, const int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((c == 1) && (i < r - 1))
                printf("%d\n", matrix[i][j]);
            else if (c == 1)
                printf("%d", matrix[i][j]);
            else if ((i == r - 1) && (j == c - 1))
                printf(" %d", matrix[i][j]);
            else if (j == c - 1)
                printf(" %d\n", matrix[i][j]);
            else if (j == 0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
    }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int n_result, int m_result) {
    if ((n_first != n_second) || (m_first != m_second) || (n_first != n_result) || (m_first != m_result))
        return 1;

    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_first; j++) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }

    return 0;
}

int create_matrix(int ***mptr, const int m, const int n) {
    int **values = malloc(n * m * sizeof(int) + m * sizeof(int *));
    if (!values) return 1;
    int *ptr = (int *)(values + m);
    for (int i = 0; i < m; i++) values[i] = ptr + i * n;
    *mptr = values;

    return 0;
}

int transpose(int ***matrix, int m, int n) {
    int **values;
    if (create_matrix(&values, n, m)) return 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            values[j][i] = (*matrix)[i][j];
        }
    }

    free(*matrix);
    *matrix = values;

    return 0;
}

int mul(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second,
        int **matrix_result) {
    if (n_first != m_second) return 1;

    for (int i = 0; i < m_first; i++) {
        for (int j = 0; j < n_second; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < n_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }

    return 0;
}