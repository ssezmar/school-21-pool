#ifndef SRC_TOKENIZER_H_
#define SRC_TOKENIZER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token {
    int type;
    char operation;
    double operand;
} token_t;

void shift_skiper(char** copy, const char* temp, int* counter, char*** data);
int operation_type(char* data, char* oper, char** operations, int size);
void detect_negative(token_t** dst, int n);
int tokenizer(token_t** dst, char** data, int n);
void destroyer(char** data, int n);
void get_tokens(char* str, char*** data, int* n);
int get_words(char* str, char*** lexems);
int get_lexors(char* str, int n, char** lexems, char*** data);

#endif
