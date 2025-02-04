#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int matrix_scan(int* arr, int size);
void matrix_print(int** matrix, int n, int m);
void init_matrix(int*** matrix, int n, int m);
void matrix_vertical(int** matrix, int* arr, int n, int size);
void matrix_horizontal(int** matrix, int* arr, int n, int size);

int main() {
    int n = 1, m = 1;
    int error = 0;

    if (scanf("%d", &n) != 1 || n <= 0) {
        error = 1;
    }
    if (scanf("%d", &m) != 1 || m <= 0) {
        error = 1;
    }

    int size = n * m;

    int* arr = malloc(sizeof(int) * n * m);

    if (!error) error = matrix_scan(arr, size);

    if (!error) qsort(arr, size, sizeof(int), compare);

    if (!error) {
        int** matrix1 = NULL;
        init_matrix(&matrix1, n, m);
        int** matrix2 = NULL;
        init_matrix(&matrix2, n, m);
        matrix_vertical(matrix1, arr, n, size);
        matrix_horizontal(matrix2, arr, m, size);
        matrix_print(matrix1, n, m);
        printf("\n\n");
        matrix_print(matrix2, n, m);
        for (int i = 0; i < n; i++) {
            free(matrix1[i]);
            free(matrix2[i]);
        }
        free(matrix1);
        free(matrix2);
    }

    if (arr) free(arr);

    if (error) {
        printf("n/a");
    }

    return 0;
}

int compare(const void* a, const void* b) { return (*(int*)a > *(int*)b); }

int matrix_scan(int* arr, int size) {
    int error = 0;
    for (int i = 0; i < size && !error; i++) {
        if (!scanf("%d", &arr[i])) {
            error = 1;
        }
    }
    char ls = getchar();
    if (ls != '\n') {
        error = 1;
    }
    return error;
}

void matrix_print(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) printf(" ");
        }
        if (i != n - 1) printf("\n");
    }
}

void init_matrix(int*** matrix, int n, int m) {
    *matrix = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            (*matrix)[i][j] = 0;
        }
    }
}

void matrix_vertical(int** matrix, int* arr, int n, int size) {
    int z = 0;
    int s = 1;
    int x = 0;
    int y = 0;
    while (z < size) {
        matrix[y][x] = arr[z];
        if (s == 1 && y == n - 1) {
            x++;
            s = -1;
        } else if (s == -1 && y == 0) {
            x++;
            s = 1;
        } else if (s == 1) {
            y++;
        } else if (s == -1) {
            y--;
        }
        z++;
    }
}

void matrix_horizontal(int** matrix, int* arr, int n, int size) {
    int z = 0;
    int s = 1;
    int x = 0;
    int y = 0;
    while (z < size) {
        matrix[x][y] = arr[z];
        if (s == 1 && y == n - 1) {
            x++;
            s = -1;
        } else if (s == -1 && y == 0) {
            x++;
            s = 1;
        } else if (s == 1) {
            y++;
        } else if (s == -1) {
            y--;
        }
        z++;
    }
}