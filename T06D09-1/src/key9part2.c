#include <stdio.h>

#define LEN 100

int input(int *a, int *n);
void output(int *a, int n);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *flag);

int main() {
    int a[LEN], b[LEN], na = 0, nb = 0, sum_v[LEN + 1], sub_v[LEN], sum_l, sub_l, flag = 1, error = 0;
    if (input(a, &na)) {
        error = 1;
    }

    if (!error) {
        if (input(b, &nb)) {
            error = 1;
        }
    }

    if (!error) {
        sum(a, na, b, nb, sum_v, &sum_l);
        sub(a, na, b, nb, sub_v, &sub_l, &flag);
    }
    if (!error) {
        if (flag == 1) {
            output(sum_v, sum_l);
            output(sub_v, sub_l);
        } else {
            output(sum_v, sum_l);
            printf("n/a");
        }
    }

    if (error) {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    int error = 0;
    int f = 1;
    int sub_n = 0;
    while (!error) {
        int current;

        if (!scanf("%d", &current)) error = 1;
        sub_n++;
        if (current == 0 && f) {
            if (sub_n > 99) error = 1;
            continue;
        }
        f = 0;
        if (!error) {
            if (current > 9 || current < 0) {
                error = 1;
            }
        }

        char next_sym;
        if (!error) {
            next_sym = getchar();
            if (next_sym == '\n') {
                a[*n] = current;
                *n += 1;
                break;
            }
            if (next_sym != ' ') {
                error = 1;
            }
        }
        if (!error) {
            a[*n] = current;
        }

        if (sub_n > 99) error = 1;
        *n += 1;
    }

    return error;
}

void output(int *a, int n) {
    int i = 0;
    while (a[i] == 0) {
        i++;
    }

    printf("%d", a[i]);
    i++;
    for (; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0, i = 0;
    int max_len = len1 > len2 ? len1 : len2;

    for (i = 0; i < max_len || carry; ++i) {
        int digit1 = i < len1 ? buff1[len1 - 1 - i] : 0;
        int digit2 = i < len2 ? buff2[len2 - 1 - i] : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    *result_length = i;
    for (int j = 0; j < *result_length / 2; ++j) {
        int temp = result[j];
        result[j] = result[*result_length - 1 - j];
        result[*result_length - 1 - j] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *flag) {
    if (len2 > len1 || (len2 == len1 && buff2[0] > buff1[0])) {
        *flag = 0;
    } else if (len1 == len2) {
        *flag = 3;
        for (int i = 0; i < len1; i++) {
            if (buff1[i] < buff2[i]) {
                *flag = 0;
                break;
            } else if (buff1[i] > buff2[i]) {
                *flag = 1;
                break;
            }
        }
    }
    if (*flag == 1) {
        int borrow = 0, i = 0;
        for (i = 0; i < len1; ++i) {
            int digit1 = buff1[len1 - 1 - i];
            int digit2 = i < len2 ? buff2[len2 - 1 - i] : 0;

            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result[i] = diff;
        }

        while (i > 1 && result[i - 1] == 0) {
            i--;
        }

        *result_length = i;
        for (int j = 0; j < *result_length / 2; ++j) {
            int temp = result[j];
            result[j] = result[*result_length - 1 - j];
            result[*result_length - 1 - j] = temp;
        }
    }
}
