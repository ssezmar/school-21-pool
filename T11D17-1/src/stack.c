#include "stack.h"

#include <stdlib.h>

Stack *init() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->first = NULL;
    stack->last = NULL;

    return stack;
}

void push(Stack *stack, int value) {
    StackItem *item = (StackItem *)malloc(sizeof(StackItem));
    item->value = value;
    item->prev = NULL;

    if (stack->first) {
        item->prev = stack->last;
        stack->last = item;
    } else {
        stack->first = item;
        stack->last = item;
    }
}

void pop(Stack *stack) {
    StackItem *item = stack->last;
    if (!item) return;

    if (item == stack->first) {
        stack->last = NULL;
        stack->first = NULL;
    } else {
        stack->last = item->prev;
    }

    free(item);
}

void destroy(Stack *stack) {
    while (stack->last) pop(stack);
    free(stack);
}
