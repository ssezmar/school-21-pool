#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    printf(Log_prefix);

    time_t curr;
    time(&curr);
    struct tm* local = localtime(&curr);
    printf(" %02d:%02d:%02d ", local->tm_hour, local->tm_min, local->tm_sec);

    for (int i = 0; message[i] != '\0'; i++) print(message[i]);
}
