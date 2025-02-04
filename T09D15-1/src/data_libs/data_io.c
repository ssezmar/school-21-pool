#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    char c;
    int error = 0;
    if (scanf("%d", n) != 1) error++;
    if (!error && (*n <= 0)) error++;
    if (!error) *data = (double *)malloc(sizeof(double) * (*n));
    if (!error && !data) error++;
    for (int ind = 0; (ind < *n) && !error; ind++) {
        if (scanf("%lf", *data + ind) != 1) {
            error++;
            free(*data);
        }
    }
    if ((!error) && (((c = getchar()) != '\n') && (c != EOF))) {
        error++;
        free(*data);
    }

    return error;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) printf(" ");
    }
}