#include <stdio.h>

#define SIZE 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length;
    int buffer[SIZE];
    int sum;
    int numbers[SIZE];
    int count;

    int error = 0;

    if (input(buffer, &length)) {
        error = 1;
    }

    if (!error) {
        sum = sum_numbers(buffer, length);
        if (sum == 0) {
            error = 1;
        }
    }

    if (!error) {
        count = find_numbers(buffer, length, sum, numbers);
        if (count == 0) {
            error = 1;
        }
    }

    if (!error) {
        output(numbers, count, sum);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *buffer, int *length) {
    int error = 0;
    if (!scanf("%d", length)) {
        error = 1;
    }
    if (*length <= 0 || *length > SIZE) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < *length; i++) {
            if (!scanf("%d", &buffer[i])) {
                error = 1;
            }
        }
        char last_sym = getchar();
        if (last_sym != '\n' && last_sym != EOF) {
            error = 1;
        }
    }
    return error;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count++] = buffer[i];
        }
    }

    return count;
}

void output(int *buffer, int length, int sum) {
    printf("%d\n", sum);
    printf("%d", buffer[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", buffer[i]);
    }
}