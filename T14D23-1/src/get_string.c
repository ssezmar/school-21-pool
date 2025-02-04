#include "get_string.h"

#include <stdio.h>
#include <string.h>

char *read_line() {
    size_t size = INITIAL_SIZE;
    char *buffer = malloc(size);
    if (!buffer) {
        return NULL;
    }

    size_t length = 0;
    int ch;

    while (1) {
        ch = getchar();

        if (ch == '\n' || ch == EOF) {
            break;
        }

        if (length + 1 >= size) {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[length++] = ch;
    }

    buffer[length] = '\0';
    return buffer;
}

char *input_filepath() {
    char *filepath = read_line();
    size_t filepath_len = strlen(filepath);
    char *temp = (char *)malloc(filepath_len + 4 + 1);  // +1 для нуль-терминатора
    strcpy(temp, "../");
    strncat(temp, filepath, filepath_len);  // Копируем только filepath_len байт
    free(filepath);
    return temp;
}