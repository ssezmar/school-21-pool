#ifndef SRC_RPN_H_
#define SRC_RPN_H_

#include <math.h>
#include <stdio.h>

#include "stack.h"
#include "tokenizer.h"

int precedence(char c);

double perform_all(token_t *root, double x, int n);
void inverse(node_t **perform);
void perform_sin(node_t **perform);
void perform_cos(node_t **perform);
void perform_tg(node_t **perform);
void perform_ctg(node_t **perform);
void perform_base(node_t **perform);
void perform_log(node_t **perform);
void perform_add(node_t **perform);
void perform_sub(node_t **perform);
void perform_mul(node_t **perform);
void perform_div(node_t **perform);
void replace(node_t **perform, double x);
int choose_res(char c);

node_t *polish_notation(token_t *data, int n);

int push_all(node_t **node_char, node_t **node_double);
void clear_node(node_t **node_double, node_t **node_char);
int double_stack(node_t **node_double, node_t **node_char, token_t data);

#endif
