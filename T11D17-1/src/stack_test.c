#include "stack.h"

#include <stdio.h>

int main() {
    int result = 100;
    Stack *stack = init();
    push(stack, 3);
    if (stack->last->value != 3) result = 0;
    push(stack, 2);
    if (stack->last->value != 2) result = 0;
    push(stack, 1);
    if (stack->last->value != 1) result = 0;
    pop(stack);
    if (stack->last->value != 2) result = 0;

    printf(result ? "SUCCESS" : "FAIL");

    destroy(stack);

    return 0;
}
