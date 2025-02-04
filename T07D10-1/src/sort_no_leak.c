#include <stdio.h>
#include <stdlib.h>

int read_array(int *arr, int size);
void sort_array(int *arr, int size);
void print_array(int *arr, int size);

int main() {
    int n;

    int error = 0;

    if (scanf("%d", &n) != 1 || n <= 0) {
        error = 1;
    }

    if (!error) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            error = 1;
        }
        int error = read_array(arr, n);
        if (error) {
            free(arr);
            printf("n/a");
            return 0;
        }

        sort_array(arr, n);

        print_array(arr, n);

        free(arr);
    }
    if (error) {
        printf("n/a");
    }

    return 0;
}

int read_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }
    char last_sym = getchar();
    if (last_sym != '\n' && last_sym != EOF) {
        return 1;
    }
    return 0;
}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}
