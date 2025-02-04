#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int static_arrayf(int row, int col);
int array(int row, int col);
int dinamic_array(int row, int col);
int hard_array(int row, int col);
int check_last_sym();
int read_matrix(const int r, const int c, int **matrix);
int input(int *mod, int *r, int *c);
void output_matrix(const int r, const int c, int **matrix);

int main() {
    int number, str, col, error = 0;
    if (!scanf("%d", &number)) {
        error = 1;
    }

    if (!error) {
        if (number == 1) {
            if (scanf("%d%d", &str, &col) != 2 || (str <= 0) || (col <= 0) || (str > 100) || (col > 100)) {
                error = 1;
            }
            if (!error) error += static_arrayf(str, col);
        } else if (number == 2) {
            if (scanf("%d%d", &str, &col) != 2 || (str <= 0) || (col <= 0)) {
                error = 1;
            }
            if (!error) error += array(str, col);
        } else if (number == 3) {
            if (scanf("%d%d", &str, &col) != 2 || (str <= 0) || (col <= 0)) {
                error = 1;
            }
            if (!error) error += dinamic_array(str, col);
        } else if (number == 4) {
            if (scanf("%d%d", &str, &col) != 2 || (str <= 0) || (col <= 0)) {
                error = 1;
            }
            if (!error) error += hard_array(str, col);
        } else {
            error = 1;
        }
    }

    if (error != 0) {
        printf("n/a");
    }

    return 0;
}

int static_arrayf(int row, int col) {
    int matrix[MAX][MAX];
    int *matrix_ptr[MAX];
    int error = 0;
    for (int ind = 0; ind < MAX; ind++) matrix_ptr[ind] = matrix[ind];

    if (!((0 < row) && (row <= MAX))) {
        error = 1;
    }
    if (!error) {
        error = read_matrix(row, col, matrix_ptr);
    }

    if (!error) {
        output_matrix(row, col, matrix_ptr);
    }
    return error;
}

int hard_array(int row, int col) {
    int *values = malloc(row * col * sizeof(int));
    int **arr = malloc(row * sizeof(int *));
    int error = 0;

    if (!values || !arr) {
        error = 1;
    }

    if (!error) {
        for (int i = 0; i < row; i++) arr[i] = values + i * col;
        error = read_matrix(row, col, arr);
    }
    if (!error) {
        output_matrix(row, col, arr);
    }

    free(values);
    free(arr);
    return error;
}

int array(int row, int col) {
    int **values = malloc(row * col * sizeof(int) + row * sizeof(int *));
    int error = 0;
    if (!values) {
        error = 1;
    }
    if (!error) {
        int *ptr = (int *)(values + row);
        for (int i = 0; i < row; i++) values[i] = ptr + i * col;
    }

    if (!error) {
        error = read_matrix(row, col, values);
    }

    if (!error) {
        output_matrix(row, col, values);
    }
    free(values);

    return error;
}

int dinamic_array(int row, int col) {
    int **arr = malloc(sizeof(int *) * row);
    int error = 0;
    if (!arr) {
        error = 1;
    }
    if (!error) {
        for (int ind = 0, *ptr; ind < row; ind++) {
            ptr = malloc(sizeof(int) * row);
            if (!ptr) error = 1;
            arr[ind] = ptr;
        }
    }

    if (!error) {
        error = read_matrix(row, col, arr);
    }

    if (!error) {
        output_matrix(row, col, arr);
    }
    for (int ind = 0; ind < col; ind++) free(arr[ind]);
    free(arr);
    return error;
}

int check_last_sym() {
    int error = 0;
    char last_sym = getchar();
    if (last_sym != '\n' && last_sym != EOF) {
        error = 1;
    }
    return error;
}

int read_matrix(const int r, const int c, int **matrix) {
    int error = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", matrix[i] + j) != 1) {
                error = 1;
            }
        }
    }
    error += check_last_sym();
    return error;
}

int input(int *mode, int *r, int *c) {
    char ch;
    int error = 0;
    if (scanf("%d", mode) != 1) error = 1;
    if ((*mode < 1) || (*mode > 4)) error = 1;
    if (scanf("%d %d", r, c) != 2) error = 1;
    if (((ch = getchar()) != (int)('\n')) && (ch != (int)(EOF))) error = 1;
    if ((*r <= 0) || (*c <= 0)) error = 1;
    return error;
}

void output_matrix(const int r, const int c, int **matrix) {
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