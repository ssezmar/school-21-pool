#include <stdio.h>

#define SIZE 10

int read_array(int *arr, int size);

void sort_array(int *arr, int size);

void print_array(int *arr, int size);

int main() {
    int arr[SIZE];

    int error = 0;

    if (read_array(arr, SIZE)) {
        error = 1;
    }

    if (!error) {
        sort_array(arr, SIZE);

        print_array(arr, SIZE);
    } else {
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