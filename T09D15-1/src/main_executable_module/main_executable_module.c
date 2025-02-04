#include <stdio.h>
#include <stdlib.h>

#ifdef MACRO_IO_DOUBLE
#define input(data, n, flag) INPUT(double, lf, data, n, flag)
#define output(data, n) OUTPUT(lf, data, n)
#include "../data_libs/data_io_macro.h"
#elif MACRO_IO_FLOAT
#define input(data, n, flag) INPUT(float, f, data, n, flag)
#define output(data, n) OUTPUT(f, data, n)
#include "../data_libs/data_io_macro.h"
#elif MACRO_IO_CHAR
#define input(data, n, flag) INPUT(char, c, data, n, flag)
#define output(data, n) OUTPUT(c, data, n)
#include "../data_libs/data_io_macro.h"
#elif MACRO_IO_LONG
#define input(data, n, flag) INPUT(long, ld, data, n, flag)
#define output(data, n) OUTPUT(ld, data, n)
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif

#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    int is_error = 0;
    double *data = NULL;
    printf("LOAD DATA...\n");
    int n = -1;
    if (is_error == 0) {
        is_error = input(&data, &n);
    }
    if (is_error == 0) {
        printf("RAW DATA:\n\t");
        output(data, n);
        printf("\nNORMALIZED DATA:\n\t");
        if (!normalization(data, n)) {
            printf("ERROR");
        } else {
            output(data, n);
        }
        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}