#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"

typedef struct Node {
    token_t data;
    struct Node* next;
} node_t;

node_t* peek(node_t** head);
node_t* init(token_t* data);
void push(node_t** head, token_t* data);
node_t* pop(node_t** head);
void destroy(node_t* root);
int count_elems(node_t* root);

#endif
