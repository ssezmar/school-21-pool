#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
    int is_error = 0;
    double *data;
    int n = -1;
    if (is_error == 0) {
        is_error = input(&data, &n);
    }
    if (is_error == 0) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
        free(data);
    } else {
        printf("n/a");
    }
    return 0;
}