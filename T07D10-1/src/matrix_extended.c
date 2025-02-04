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
void output_matrix(const int r, const int c, int **matrix, int *max, int *min);
void search_max(int **matrix, int *max, int row, int col);
void search_min(int **matrix, int *max, int row, int col);
void output_matrix_static(const int M, const int N, int m[MAX][MAX], int max[MAX], int min[MAX]);
void search_max_s(int matrix[MAX][MAX], int *min, int row, int col);
void search_min_s(int matrix[MAX][MAX], int *min, int row, int col);

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
    int m[MAX][MAX], max[MAX], min[MAX];

    int error = 0;
    if (!((0 < row) && (row <= MAX))) {
        error = 1;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                error = 1;
                break;
            }
        }
        if (error) break;
    }

    if (!error) {
        search_max_s(m, max, row, col);
        search_min_s(m, min, row, col);
    }
    if (!error) {
        output_matrix_static(row, col, m, max, min);
    }
    return error;
}

int hard_array(int row, int col) {
    int max[MAX], min[MAX];
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
        search_max(arr, max, row, col);
        search_min(arr, min, row, col);
    }
    if (!error) {
        output_matrix(row, col, arr, max, min);
    }

    free(values);
    free(arr);
    return error;
}

int array(int row, int col) {
    int **values = malloc(row * col * sizeof(int) + row * sizeof(int *));
    int max[MAX], min[MAX];
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
        search_max(values, max, row, col);
        search_min(values, min, row, col);
    }
    if (!error) {
        output_matrix(row, col, values, max, min);
    }

    free(values);

    return error;
}

int dinamic_array(int row, int col) {
    int **arr = malloc(sizeof(int *) * row);
    int max[MAX], min[MAX];
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
        search_max(arr, max, row, col);
        search_min(arr, min, row, col);
    }
    if (!error) {
        output_matrix(row, col, arr, max, min);
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

void output_matrix(const int r, const int c, int **matrix, int *max, int *min) {
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
    printf("\n%d", max[0]);
    for (int i = 1; i < r; i++) {
        printf(" %d", max[i]);
    }
    printf("\n");
    printf("%d", min[c - 1]);
    for (int i = c - 2; i >= 0; i--) {
        printf(" %d", min[i]);
    }
}

void search_max(int **matrix, int *max, int row, int col) {
    for (int r = 0; r < row; r++) {
        int cur_max = matrix[r][0];
        for (int c = 0; c < col; c++) {
            if (cur_max < matrix[r][c]) {
                cur_max = matrix[r][c];
            }
        }
        max[r] = cur_max;
    }
}
void search_min(int **m, int *min, int row, int col) {
    for (int i = 0; i < row; i++) {
        int min_v = m[i][0];
        for (int j = 1; j < col; j++) {
            if (m[i][j] < min_v) min_v = m[i][j];
        }
        min[i] = min_v;
    }
}

void search_min_s(int m[MAX][MAX], int *min, int row, int col) {
    for (int i = 0; i < row; i++) {
        int min_v = m[i][0];
        for (int j = 1; j < col; j++) {
            if (m[i][j] < min_v) min_v = m[i][j];
        }
        min[i] = min_v;
    }
}

void search_max_s(int matrix[MAX][MAX], int *min, int row, int col) {
    for (int r = 0; r < col; r++) {
        int cur_max = matrix[r][0];
        for (int c = 0; c < row; c++) {
            if (cur_max < matrix[r][c]) {
                cur_max = matrix[r][c];
            }
        }
        min[r] = cur_max;
    }
}

void output_matrix_static(const int M, const int N, int m[MAX][MAX], int max[MAX], int min[MAX]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j != N - 1)
                printf("%d ", m[i][j]);
            else
                printf("%d", m[i][j]);
        }
        if (i != M - 1) printf("\n");
    }
    printf("\n%d", max[0]);
    for (int i = 1; i < M; i++) {
        printf(" %d", max[i]);
    }
    printf("\n%d", min[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        printf(" %d", min[i]);
    }
}
