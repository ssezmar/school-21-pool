#include "tokenizer.h"

int tokenizer(token_t** dst, char** data, int n) {
    char* operations[] = {"sin", "cos", "tan", "ctg", "sqrt", "ln", "+", "-", "/", "*", "^", "(", ")", "x"};
    int check = 1;
    *dst = malloc(n * sizeof(token_t));
    for (int i = 0; i < n; i++) {
        double result;
        char operation;
        if (sscanf(data[i], "%lf", &result)) {
            (*dst)[i].type = 0;
            (*dst)[i].operand = result;
        } else if (operation_type(data[i], &operation, operations, sizeof(operations) / sizeof(char*))) {
            (*dst)[i].type = 1;
            (*dst)[i].operation = operation;
        } else {
            check = 0;
            break;
        }
    }
    if (check) {
        detect_negative(dst, n);
    }
    if (!check) {
        free(*dst);
    }
    return check;
}

void detect_negative(token_t** dst, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (i == 0 && (*dst)[i].type && (*dst)[i].operation == '-') {
            (*dst)[i].operation = 'u';  // Присваиваем унарный минус
        } else if (((*dst)[i].type && (*dst)[i].operation == '(') &&
                   ((*dst)[i + 1].type && (*dst)[i + 1].operation == '-')) {
            (*dst)[i + 1].operation = 'u';  // Присваиваем унарный минус
        }
    }
}

int operation_type(char* data, char* oper, char** operations, int size) {
    int check = 0;
    for (int i = 0; i < size; i++) {
        if (!strcmp(operations[i], data)) {
            if (i == 3) {
                *oper = 'g';
            } else if (i == 4) {
                *oper = 'q';
            } else {
                *oper = data[0];
            }
            check = 1;
            break;
        }
    }
    return check;
}

void get_tokens(char* str, char*** data, int* n) {
    int words_count = get_words(str, NULL);
    char** lexems = malloc(words_count * sizeof(char*));
    get_words(str, &lexems);
    *n = get_lexors(str, words_count, lexems, NULL);
    *data = malloc(*n * (sizeof(char*)));
    get_lexors(str, words_count, lexems, data);
    destroyer(lexems, words_count);
}

int get_words(char* str, char*** lexems) {
    int counter = 0;
    char* copy = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(copy, str);
    char* pointer = strtok(copy, "+-*/() ");
    while (pointer != NULL) {
        if (lexems != NULL) {
            (*lexems)[counter] = malloc((strlen(pointer) + 1) * sizeof(char));
            strcpy((*lexems)[counter], pointer);
        }
        counter++;
        pointer = strtok(NULL, "+-*/() ");
    }
    free(copy);
    return counter;
}

int get_lexors(char* str, int n, char** lexems, char*** data) {
    int counter = 0;
    char* copy = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(copy, str);
    char* for_free = copy;
    for (int i = 0; i < n; i++) {
        char* temp = strstr(copy, lexems[i]);
        shift_skiper(&copy, temp, &counter, data);
        if (data != NULL) {
            (*data)[counter] = malloc((strlen(lexems[i]) + 1) * sizeof(char));
            strcpy((*data)[counter], lexems[i]);
        }
        copy += strlen(lexems[i]);
        counter++;
    }
    char* temp = copy + strlen(copy);
    shift_skiper(&copy, temp, &counter, data);
    free(for_free);
    return counter;
}

void destroyer(char** data, int n) {
    for (int i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
}

void shift_skiper(char** copy, const char* temp, int* counter, char*** data) {
    while (*copy != temp) {
        if (**copy != ' ') {
            if (data != NULL) {
                (*data)[*counter] = malloc(2 * sizeof(char));
                (*data)[*counter][0] = **copy;
                (*data)[*counter][1] = '\0';
            }
            (*counter)++;
        }
        (*copy)++;
    }
}
