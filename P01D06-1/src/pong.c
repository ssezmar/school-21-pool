#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define WIN_SCORE 21

void initGame(int *ball_x, int *ball_y, int *paddle_1_y, int *paddle_2_y, int *score1, int *score2) {
    *ball_x = WIDTH / 2;
    *ball_y = HEIGHT / 2;
    *paddle_1_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    *paddle_2_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    *score1 = 0;
    *score2 = 0;
}

void draw(int *ball_x, int *ball_y, int *paddle_1_y, int *paddle_2_y, int *score1, int *score2) {
    printf("\033[H\033[2J\033[3J");  // Очистка экрана
    printf("+");
    for (int i = 1; i < WIDTH + 1; i++) printf("-");
    printf("+\n");
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (x == *ball_x && y == *ball_y) {
                printf("O");  // мяч
            } else if (x == 19 && y == 6) {
                printf("%d", *score1 / 10);
            } else if (x == WIDTH - 20 && y == 6) {
                printf("%d", *score2 / 10);
            } else if (x == WIDTH - 19 && y == 6) {
                printf("%d", *score2 % 10);
            } else if (x == 20 && y == 6) {
                printf("%d", *score1 % 10);
            } else if (x == WIDTH / 2 && !(x == *ball_x && y == *ball_y)) {
                printf("|");
            } else if ((y >= *paddle_1_y && y < *paddle_1_y + PADDLE_SIZE) && x == 1) {
                printf("|");  // ракетка 1
            } else if ((y >= *paddle_2_y && y < *paddle_2_y + PADDLE_SIZE) && x == WIDTH - 2) {
                printf("|");  // ракетка 2
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 1; i < WIDTH + 1; i++) printf("-");
    printf("+\n");
    printf("Score: Player 1: %d  Player 2: %d\n", *score1, *score2);
}

void movePaddles(int *paddle_1_y, int *paddle_2_y) {
    char input;
    printf("Enter move for Player 1 (A/Z) or Player 2 (K/M), or space to skip: ");
    input = getchar();  // Чтение одного символа

    switch (input) {
        case 'A':
        case 'a':
            if (*paddle_1_y > 0) *paddle_1_y -= 1;
            break;
        case 'Z':
        case 'z':
            if (*paddle_1_y < HEIGHT - PADDLE_SIZE) *paddle_1_y += 1;
            break;
        case 'K':
        case 'k':
            if (*paddle_2_y > 0) *paddle_2_y -= 1;
            break;
        case 'm':
            if (*paddle_2_y < HEIGHT - PADDLE_SIZE) *paddle_2_y += 1;
            break;
        default:
            printf("Step skipped!\n");
            break;
    }
}

void updateBall(int *ball_x, int *ball_y, int *paddle_1_y, int *paddle_2_y, int *score1, int *score2) {
    static int dx = 1, dy = 1;

    // Логика перемещения мяча
    *ball_x += dx;
    *ball_y += dy;

    // Отражение от верхней и нижней границ
    if (*ball_y == 0 || *ball_y == HEIGHT - 1) dy = -dy;

    // Отражение от ракеток
    if (*ball_x == 2 && *ball_y >= *paddle_1_y && *ball_y < *paddle_1_y + PADDLE_SIZE) dx = -dx;
    if (*ball_x == WIDTH - 3 && *ball_y >= *paddle_2_y && *ball_y < *paddle_2_y + PADDLE_SIZE) dx = -dx;

    // Проверка на гол
    if (*ball_x == 0) {
        *score2 += 1;
        *ball_x = WIDTH / 2;
        *ball_y = HEIGHT / 2;
    }
    if (*ball_x == WIDTH - 1) {
        *score1 += 1;
        *ball_x = WIDTH / 2;
        *ball_y = HEIGHT / 2;
    }
}

int checkWinner(int *score1, int *score2) {
    printf("\033[H\033[2J\033[3J");  // Очистка экрана
    if (*score1 >= WIN_SCORE) {
        printf(
            "*    ###      ##                         ##                        ###                          "
            "                                   ##                ##       ##       ## \t*\n"
            "*   ## ##                                ##                         ##                          "
            "                                                    ####     ####     #### \t*\n"
            "*    #       ###     ######    #####    #####            ######     ##      ####    ##  ##    "
            "####    ######            ##   ##   ###     #####     ####     ####     #### \t*\n"

            "*  ####       ##      ##  ##  ##         ##               ##  ##    ##         ##   ##  ##   ## "
            " ##    ##  ##           ## # ##    ##     ##  ##     ##       ##       ## \t*\n"
            "*   ##        ##      ##       #####     ##               ##  ##    ##      #####   ##  ##   "
            "######    ##               #######    ##     ##  ##     ##       ##       ## \t*\n"
            "*   ##        ##      ##           ##    ## ##            #####     ##     ##  ##    #####   ## "
            "       ##               #######    ##     ##  ## \t*\n"
            "*  ####      ####    ####     ######      ###             ##       ####     #####       ##    "
            "#####   ####               ## ##    ####    ##  ##     ##       ##       ## \t*\n"
            "                                                        ####                       ##### \t*\n");
        return 1;
    }
    if (*score2 >= WIN_SCORE) {
        printf(
            "*                                                  ###                      ###                 "
            "                                            ##                ##       ##       ## \t*\n"
            "*                                                   ##                       ##                 "
            "                                                             ####     ####     #### \t*\n"
            "*   #####    ####     ####     ####    #####        ##            ######     ##      ####    ## "
            " ##    ####    ######            ##   ##   ###     #####     ####     ####     #### \t*\n"
            "*  ##       ##  ##   ##  ##   ##  ##   ##  ##    #####             ##  ##    ##         ##   ## "
            " ##   ##  ##    ##  ##           ## # ##    ##     ##  ##     ##       ##       ## \t*\n"
            "*   #####   ######   ##       ##  ##   ##  ##   ##  ##             ##  ##    ##      #####   ## "
            " ##   ######    ##               #######    ##     ##  ##     ##       ##       ## \t*\n"
            "*       ##  ##       ##  ##   ##  ##   ##  ##   ##  ##             #####     ##     ##  ##    "
            "#####   ##        ##               #######    ##     ##  ## \t*\n"
            "*  ######    #####    ####     ####    ##  ##    ######            ##       ####     #####      "
            " ##    #####   ####               ## ##    ####    ##  ##     ##       ##       ## \t*\n"
            "*                                                                 ####                       "
            "##### \t*\n");
        return 1;
    }
    return 0;
}
int main() {
    int ball_x;
    int ball_y;
    int paddle_1_y;
    int paddle_2_y;
    int score1, score2;

    initGame(&ball_x, &ball_y, &paddle_1_y, &paddle_2_y, &score1, &score2);

    printf("\033[H\033[2J\033[3J");

    while (!checkWinner(&score1, &score2)) {
        draw(&ball_x, &ball_y, &paddle_1_y, &paddle_2_y, &score1, &score2);
        movePaddles(&paddle_1_y, &paddle_2_y);
        updateBall(&ball_x, &ball_y, &paddle_1_y, &paddle_2_y, &score1, &score2);
        printf("\033[H\033[2J\033[3J");
    }

    return 0;
}