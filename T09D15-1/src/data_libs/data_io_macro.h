#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>
#include <stdlib.h>

#define INPUT(type, format, data, n, flag) { \
        if (scanf("%d", n) != 1) { \
            printf("n/a\n"); \
            *flag = 0; \
        } \
        if (*n < 0) { \
            printf("n/a\n"); \
            *flag = 0; \
        } \
        *data = (type*)malloc(*n * sizeof(type)); \
        if (*data == NULL) { \
            printf("n/a\n"); \
            *flag = 0; \
        } \
        for (int i = 0; i < *n && *flag; i++) { \
            if (scanf("%" #format, &(*data)[i]) != 1) { \
                printf("n/a\n"); \
                *flag = 0; \
            } \
        }  }

#define OUTPUT(type, data, n) { \
        for (int i = 0; i < n; i++) { \
            printf("%.2" #type, data[i]); \
            if (i != n - 1) { \
                printf(" "); \
            } \
        } \
        printf("\n"); \
}

#endif

