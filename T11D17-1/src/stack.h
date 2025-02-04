#ifndef STACK_H
#define STACK_H

typedef struct StackItem {
    struct StackItem *prev;
    int value;
} StackItem;

typedef struct Stack {
    StackItem *first;
    StackItem *last;
} Stack;

Stack *init();
void push(Stack *stack, int value);
void pop(Stack *stack);
void destroy(Stack *stack);

#endif
