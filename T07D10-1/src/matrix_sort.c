#include <stdio.h>
#include <stdlib.h>

void claculate_sum(const int r, const int c, int **matrix, int *row_sum);
void swap(int *a, int *b);
void my_qsort(int a, int b, int *row_sum, int **matrix);
void sort_row(const int r, const int c, int **matrix);
void method2(const int r, const int c);
void method3(const int r, const int c);
void method4(const int r, const int c);
int read_matrix(const int r, const int c, int **matrix);
int input(int *mod, int *r, int *c);
void output_matrix(const int r, const int c, int **matrix);

int main() {
    int mod, r, c;
    if (input(&mod, &r, &c)) {
        printf("n/a");
        return 1;
    }

    switch (mod) {
        case 1:
            method2(r, c);
            break;
        case 2:
            method3(r, c);
            break;
        case 3:
            method4(r, c);
            break;
        default:
            printf("n/a");
            break;
    }

    return 0;
}

void calculate_sum(const int r, const int c, int **matrix, int *row_sum) {
    for (int i = 0; i < r; i++) {
        int current_sum = 0;
        for (int j = 0; j < c; j++) {
            current_sum += matrix[i][j];
        }
        row_sum[i] = current_sum;
    }
}

void swap(int *a, int *b) {
    if (*a == *b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void my_qsort(int a, int b, int *row_sum, int **matrix) {
    int n = b - a + 1;
    if (n <= 1) return;

    int start = a;
    int end = b;
    int piv = row_sum[n / 2];

    while (start <= end) {
        while (row_sum[start] < piv) start++;
        while (row_sum[end] > piv) end--;

        if (start <= end) {
            int *temp_ptr;
            swap(row_sum + start, row_sum + end);
            temp_ptr = matrix[start];
            matrix[start] = matrix[end];
            matrix[end] = temp_ptr;
            start++, end--;
        }
    }

    my_qsort(a, end, row_sum, matrix);
    my_qsort(start, b, row_sum, matrix);
}

void sort_row(const int r, const int c, int **matrix) {
    int *row_sum = malloc(r * sizeof(int));

    calculate_sum(r, c, matrix, row_sum);
    my_qsort(0, r - 1, row_sum, matrix);

    free(row_sum);
}

void method2(const int r, const int c) {
    int **values = malloc(r * c * sizeof(int) + r * sizeof(int *));
    if (!values) {
        printf("n/a");
        return;
    }
    int *ptr = (int *)(values + r);
    for (int i = 0; i < r; i++) values[i] = ptr + i * c;

    if (read_matrix(r, c, values)) return;

    sort_row(r, c, values);
    output_matrix(r, c, values);

    free(values);
}

void method3(const int r, const int c) {
    int **arr = malloc(sizeof(int *) * r);
    if (!arr) {
        printf("n/a");
        return;
    }
    for (int ind = 0, *ptr; ind < r; ind++) {
        ptr = malloc(sizeof(int) * r);
        if (!ptr) {
            printf("n/a");
            return;
        }
        arr[ind] = ptr;
    }

    if (read_matrix(r, c, arr)) return;
    sort_row(r, c, arr);
    output_matrix(r, c, arr);

    for (int ind = 0; ind < c; ind++) free(arr[ind]);
    free(arr);
}

void method4(const int r, const int c) {
    int *values = malloc(r * c * sizeof(int));
    int **arr = malloc(r * sizeof(int *));

    if (!values || !arr) {
        printf("n/a");
        return;
    }

    for (int i = 0; i < r; i++) arr[i] = values + i * c;
    read_matrix(r, c, arr);
    sort_row(r, c, arr);
    output_matrix(r, c, arr);

    free(values);
    free(arr);
}

int input(int *mod, int *r, int *c) {
    char ch;
    if (scanf("%d", mod) != 1) return 1;
    if ((*mod < 1) || (*mod > 4)) return 2;
    if (scanf("%d %d", r, c) != 2) return 3;
    if (((ch = getchar()) != (int)('\n')) && (ch != (int)(EOF))) return 4;
    if ((*r <= 0) || (*c <= 0)) return 5;
    return 0;
}

int read_matrix(const int r, const int c, int **matrix) {
    char ch;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", matrix[i] + j) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }
    if (((ch = getchar()) != (int)'\n') && (ch != (int)EOF)) {
        printf("n/a");
        return 1;
    }

    return 0;
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