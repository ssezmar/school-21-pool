
#include "documentation_module.h"
#include "print_module.h"

void output(const int *availability_mask, int documents_count, ...);

int main() {
#ifdef Q1
    print_log(print_char, Module_load_success_message);
#endif
#ifdef Q2
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output(availability_mask, Documents_count, Documents);
    free(availability_mask);
#endif
    // Output availability for each document....

    return 0;
}

void output(const int *availability_mask, int documents_count, ...) {
    va_list(args);
    va_start(args, documents_count);

    for (int i = 0; i < Documents_count && availability_mask; i++) {
        if (availability_mask[i] == 0) printf("%d. %-15s : unavaliable", i + 1, va_arg(args, char *));
        if (availability_mask[i] == 1) printf("%d. %-15s : avaliable", i + 1, va_arg(args, char *));
        if (i != Documents_count - 1) printf("\n");
    }

    va_end(args);
}
