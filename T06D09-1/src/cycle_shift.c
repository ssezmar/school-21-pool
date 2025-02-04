#include <stdio.h>

#define SIZE 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void cycle_shift(int *buffer, int length, int shift);

int main() {
    int length;
    int buffer[SIZE];
    int shift;
    int error = 0;

    if (input(buffer, &length, &shift)) {
        error = 1;
    }

    if (length <= 0 || length > SIZE) {
        error = 1;
    }

    if (!error) {
        cycle_shift(buffer, length, shift);
    }

    if (!error) {
        output(buffer, length);
    }

    if (error) {
        printf("n/a");
    }

    return 0;
}

int input(int *buffer, int *length, int *shift) {
    int error = 0;
    if (!scanf("%d", length)) {
        error = 1;
    }
    if (!error) {
        if (*length > SIZE || *length <= 0) {
            error = 1;
        }
    }

    if (!error) {
        for (int i = 0; i < *length; i++) {
            if (!scanf("%d", &buffer[i])) {
                error = 1;
            }
        }
    }

    if (!error) {
        if (!scanf("%d", shift)) {
            error = 1;
        }
    }

    if (!error) {
        char last_sym = getchar();
        if (last_sym != '\n' && last_sym != EOF) {
            error = 1;
        }
    }

    return error;
}

void cycle_shift(int *buffer, int length, int shift) {
    if (length == 0) return;

    shift = shift % length;
    if (shift < 0) {
        shift += length;
    }

    int temp[SIZE];

    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i + shift) % length];
    }

    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}

void output(int *buffer, int length) {
    printf("%d", buffer[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", buffer[i]);
    }
}
