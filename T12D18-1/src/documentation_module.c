#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int *array = NULL, flag = 1;
    if (document_count > 16) {
        printf("n/a");
        flag = 0;
    }
    if (flag) {
        va_list args;
        va_start(args, document_count);
        array = (int*)malloc(document_count * sizeof(int));
        for (int i = 0; i < document_count; i++) {
            array[i] = validate(va_arg(args, char*));
        }

        va_end(args);
    }
    return array;
}
