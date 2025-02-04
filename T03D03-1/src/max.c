#include <stdio.h>

int max(int a, int b);

int main() {
    int n1, n2;
    char last_symbol;

    if (!(scanf("%d", &n1))) {
        printf("n/a\n");
        return 1;
    }
    if (!(scanf("%d", &n2))) {
        printf("n/a\n");
        return 1;
    }

    last_symbol = getchar();
    if (last_symbol != '\n' && last_symbol != EOF) {
        printf("n/a\n");
        return 1;
    }

    printf("%d \n", max(n1, n2));
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
