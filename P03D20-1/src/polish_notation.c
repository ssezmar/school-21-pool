#include "polish_notation.h"

#include "stack.h"

// Функция определения приоритета оператора
int precedence(char fc) {
    int res = -1;

    // Словарь для определения приоритетов операторов
    switch (fc) {
        case '(':
        case ')':
            res = 2;
            break;
        case '^':
            res = 10;
            break;
        case 'u':
            res = 9;
            break;
        case 's':
        case 'c':
        case 't':
        case 'g':
        case 'q':
        case 'l':
            res = 8;
            break;
        case '*':
        case '/':
            res = 7;
            break;
        case '+':
        case '-':
            res = 6;
            break;
        default:
            break;
    }

    return res;
}

// Функция выполнения выражения в польской записи
double perform_all(token_t *root, double x, int n) {
    double result;
    void (*funcs[11])(node_t **) = {perform_sin,  perform_cos, perform_tg,  perform_ctg,
                                    perform_base, perform_log, perform_add, perform_sub,
                                    perform_mul,  perform_div, inverse};
    token_t garbage = {-1, '0', 0};
    node_t *perform = init(&garbage);
    for (int i = 0; i < n; i++) {
        if (root[i].type == 1) {
            int h = choose_res(root[i].operation);
            if (h != 13) {
                // Выполняем унарную операцию, если она доступна
                if ((h >= 7 && h <= 11 && count_elems(perform) < 3) ||
                    (h >= 1 && h <= 6 && count_elems(perform) < 2) || (h == 12 && count_elems(perform) < 2)) {
                    break;
                }
                funcs[h - 1](&perform);
            } else {
                // Заменяем значение переменной на заданное значение
                replace(&perform, x);
            }
        } else if (root[i].type == 0) {
            // Добавляем число или переменную в стек для выполнения
            push(&perform, &root[i]);
        }
    }
    result = peek(&perform)->data.operand;
    free(pop(&perform));
    destroy(perform);
    return result;
}

void inverse(node_t **perform) { peek(perform)->data.operand = -(peek(perform)->data.operand); }

void perform_sin(node_t **perform) { peek(perform)->data.operand = sin(peek(perform)->data.operand); }

void perform_cos(node_t **perform) { peek(perform)->data.operand = cos(peek(perform)->data.operand); }

void perform_tg(node_t **perform) { peek(perform)->data.operand = tan(peek(perform)->data.operand); }

void perform_ctg(node_t **perform) { peek(perform)->data.operand = 1.0 / tan(peek(perform)->data.operand); }

void perform_base(node_t **perform) { peek(perform)->data.operand = sqrt(peek(perform)->data.operand); }

void perform_log(node_t **perform) { peek(perform)->data.operand = log(peek(perform)->data.operand); }

void perform_add(node_t **perform) {
    double second_oper = peek(perform)->data.operand;
    free(pop(perform));
    double first_oper = peek(perform)->data.operand;
    free(pop(perform));
    token_t inner;
    inner.type = 0;
    inner.operand = first_oper + second_oper;
    push(perform, &inner);
}

void perform_sub(node_t **perform) {
    double second_oper = peek(perform)->data.operand;
    free(pop(perform));
    double first_oper = peek(perform)->data.operand;
    free(pop(perform));
    token_t inner;
    inner.type = 0;
    inner.operand = first_oper - second_oper;
    push(perform, &inner);
}

void perform_mul(node_t **perform) {
    double second_oper = peek(perform)->data.operand;
    free(pop(perform));
    double first_oper = peek(perform)->data.operand;
    free(pop(perform));
    token_t inner;
    inner.type = 0;
    inner.operand = first_oper * second_oper;
    push(perform, &inner);
}

void perform_div(node_t **perform) {
    double second_oper = peek(perform)->data.operand;
    free(pop(perform));
    double first_oper = peek(perform)->data.operand;
    free(pop(perform));
    token_t inner;
    inner.type = 0;
    inner.operand = first_oper / second_oper;
    push(perform, &inner);
}

// Функция конвертации в польскую запись
node_t *polish_notation(token_t *data, int n) {
    token_t token_tmp = {-1, '0', 0};
    node_t *node_char = init(&token_tmp);
    node_t *node_double = init(&token_tmp);
    int check = 1;
    for (int i = 0; i < n; i++) {
        if (data[i].type == 0 || data[i].operation == 'x') {
            // Добавляем число или переменную в стек чисел
            push(&node_double, &data[i]);
        } else {
            if (data[i].operation == '(') {
                // Добавляем открывающую скобку в стек символов
                push(&node_char, &data[i]);
            } else if (data[i].operation == ')') {
                // Проверяем наличие соответствующей закрывающей скобки и добавляем все элементы из стека
                // символов в стек чисел
                check = push_all(&node_char, &node_double);
            } else if (precedence(data[i].operation) == 8) {
                // Добавляем унарные операторы в стек символов
                push(&node_char, &data[i]);
            } else if (precedence(peek(&node_char)->data.operation) >= precedence(data[i].operation)) {
                // Если текущий оператор имеет больший приоритет, чем следующий оператор в стеке символов,
                // добавляем его в стек чисел
                check = double_stack(&node_double, &node_char, data[i]);
            } else {
                // В противном случае добавляем оператор в стек символов
                push(&node_char, &data[i]);
            }
        }
        if (!check) {
            break;
        }
    }
    if (!check) {
        // Очистка ресурсов при ошибке
        destroy(node_char);
        destroy(node_double);
        node_double = NULL;
    } else {
        // Очистка стека символов и перемещение всех элементов в стек чисел
        clear_node(&node_double, &node_char);
        destroy(node_char);
    }
    return node_double;
}

// Функция для добавления всех элементов из стека символов в стек чисел
int push_all(node_t **node_char, node_t **node_double) {
    int check = 1;
    while ((*node_char != NULL) && peek(node_char)->data.operation != '(') {
        token_t temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
    if (*node_char != NULL) {
        free(pop(node_char));
    } else {
        check = 0;
    }
    return check;
}

int double_stack(node_t **node_double, node_t **node_char, token_t data) {
    int check = 1;
    while ((*node_char == NULL) ||
           (precedence(peek(node_char)->data.operation) == 8 ||
            precedence(peek(node_char)->data.operation) >= precedence(data.operation))) {
        token_t temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
    if (*node_char != NULL) {
        push(node_char, &data);
    } else {
        check = 0;
    }
    return check;
}

// Функция очистки стека символов и перемещения элементов в стек чисел
void clear_node(node_t **node_double, node_t **node_char) {
    while (peek(node_char) != NULL) {
        token_t temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
}

void replace(node_t **perform, double x) {
    token_t inner;
    inner.type = 0;
    inner.operand = x;
    push(perform, &inner);
}

int choose_res(char c) {
    int res = 0;
    res += 1 * (c == 's') + 2 * (c == 'c') + 3 * (c == 't');
    res += 4 * (c == 'g') + 5 * (c == 'q') + 6 * (c == 'l');
    res += 7 * (c == '+') + 8 * (c == '-') + 9 * (c == '*');
    res += 10 * (c == '/') + 11 * (c == '^') + 12 * (c == 'u');
    res += 13 * (c == 'x');
    return res;
}