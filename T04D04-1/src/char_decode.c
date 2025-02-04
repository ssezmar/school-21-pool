#include <stdio.h>

int get_hnum();

void encode();

void decode();

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 1;
    }

    char mode = *argv[1];
    if (!(mode - '0') && !(mode - '1')) {
        printf("n/a");
        return 1;
    }

    if (mode - '0')
        decode();
    else
        encode();

    return 0;
}

void decode() {
    char temp_char;
    int a;

    while (1) {
        a = get_hnum();
        if (a == 256) {
            printf("n/a");
            return;
        }

        printf("%c ", (char)a);

        temp_char = getchar();
        if (temp_char != ' ') {
            if (temp_char != EOF && temp_char != '\n') {
                printf("n/a");
                return;
            }
            if (temp_char == EOF || temp_char == '\n') {
                return;
            }
        }
    }
}

void encode() {
    char temp_char = getchar();
    while (temp_char != EOF && temp_char != '\n') {
        printf("%hhX ", temp_char);

        temp_char = getchar();
        if (temp_char != EOF && temp_char != '\n' && temp_char != ' ') {
            printf("n/a");
            return;
        }

        if (temp_char == ' ') temp_char = getchar();
    }
}

int get_hnum() {
    char c1, c2;

    c1 = (char)getchar();
    c2 = (char)getchar();
    if (('0' <= c1) && (c1 <= '9')) {
        c1 -= '0';
    } else if (('A' <= c1) && (c1 <= 'F')) {
        c1 -= 'A';
        c1 += 10;
    } else {
        return 256;
    }

    if (('0' <= c2) && (c2 <= '9')) {
        c2 -= '0';
    } else if (('A' <= c2) && (c2 <= 'F')) {
        c2 -= 'A';
        c2 += 10;
    } else {
        return 256;
    }

    return (16 * c1 + c2);
}
