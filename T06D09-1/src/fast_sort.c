#include <stdio.h>

#define SIZE 10

int read_array(int *arr, int size);

void quick_sort(int *arr, int left, int right);

void heapify(int *arr, int size, int root);

void heap_sort(int *arr, int size);

void print_array(int *arr, int size);

int main() {
    int arr[SIZE];

    int error = 0;

    if (read_array(arr, SIZE)) {
        error = 1;
    }

    if (!error) {
        int arr1[SIZE], arr2[SIZE];
        for (int i = 0; i < SIZE; i++) {
            arr1[i] = arr[i];
            arr2[i] = arr[i];
        }
        quick_sort(arr1, 0, SIZE - 1);
        print_array(arr1, SIZE);
        printf("\n");
        heap_sort(arr2, SIZE);
        print_array(arr2, SIZE);
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

void quick_sort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

void heapify(int *arr, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}

void heap_sort(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
