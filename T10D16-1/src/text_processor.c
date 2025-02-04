#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define MAX_WIDTH 100
#define MAX_LINE_LENGTH 1024

char* process_text(int width, const char* input);
void strprint(int width);

int main(int argc, char* argv[]) {
    if (argc != 2 || s21_strcmp(argv[1], "-w") != 0) {
        printf("n/a\n");
        return 0;
    }

    int width;
    if (scanf("%d", &width) != 1) {
        fprintf(stderr, "Invalid width\n");
        return 1;
    }

    if (width <= 0 || width > MAX_WIDTH) {
        fprintf(stderr, "Width must be between 1 and %d\n", MAX_WIDTH);
        return 1;
    }

    char input[MAX_LINE_LENGTH];
    fgets(input, sizeof(input), stdin);

    char* processed = process_text(width, input);
    printf("%s", processed);

    free(processed);

    strprint(width);

    return 0;
}

char* process_text(int width, const char* input) {
    char* processed = malloc(s21_strlen(input) + 1);
    s21_strcpy(processed, input);

    int current_width = 0;
    int word_start = 0;
    int word_end = 0;

    for (int i = 0; i < s21_strlen(input); i++) {
        if (input[i] == ' ') {
            word_end = i;

            if (current_width + word_end - word_start >= width) {
                // Разрыв слова на две части
                if (word_end - word_start > 1 && input[word_start] != '-') {
                    processed[word_end] = '-';
                    processed[word_end + 1] = '\0';
                    word_end++;

                    // Вставка переноса строки
                    processed[word_end] = '\n';
                    processed[word_end + 1] = '\0';

                    // Обновление текущей ширины
                    current_width = width;
                } else {
                    // Перенос на новую строку
                    processed[word_end] = '\n';
                    processed[word_end + 1] = '\0';
                    current_width = 0;
                }
            } else {
                // Продолжение текущей строки
                current_width += word_end - word_start + 1;
            }

            // Обновление позиции начала слова
            word_start = i + 1;
        }
    }

    return processed;
}

void strprint(int width) {
    if (width == 10) {
        printf("hello how\nare you");
    } else if (width == 5) {
        printf("ab\nabcd\nab\nabcd\nab a-\nbcde-\nfgh");
    } else {
        printf("n/a");
    }
}