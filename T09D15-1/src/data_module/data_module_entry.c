#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"

int main() {
    int is_error = 0;
    double *data;
    int n = -1;
    if (is_error == 0) {
        is_error = input(&data, &n);
    }
    if (is_error == 0) {
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
        free(data);
    } else {
        printf("n/a");
    }
    return 0;
}