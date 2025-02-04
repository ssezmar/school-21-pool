#include <stdio.h>

int div(int num1, int num2);

int is_prime(int num1);

int main() {
    int num1;
    char last_symbol;

    if (1 != scanf("%d", &num1)) {
        printf("n/num1");
        return 1;
    }
    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/num1");
        return 1;
    }

    if (num1 < 0) num1 = -num1;
    if (num1 <= 1) {
        printf("n/num1");
        return 0;
    }

    for (int num2 = num1; num2 > 1; num2--) {
        int q = div(num1, num2);
        if (q * num2 == num1 && is_prime(num2)) {
            printf("%d", num2);
            return 0;
        }
    }
}

int div(int num1, int num2) {
    int cnt = 1;
    int result = 0;
    while (1) {
        if (cnt == 0) return result;
        if (num2 * cnt < num1) {
            num1 -= num2 * cnt;
            result += cnt;
            cnt++;
        } else if (num2 * cnt == num1) {
            return result + cnt;
        } else {
            cnt--;
        }
    }
}

int is_prime(int num1) {
    int num2 = 2;

    while (num2 * num2 <= num1) {
        if (div(num1, num2) * num2 == num1) {
            return 0;
        }
        num2++;
    }

    return 1;
}
