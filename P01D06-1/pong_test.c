#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define WIN_SCORE 21

typedef struct {
    int x, y;
} Ball;

typedef struct {
    int y;
} Paddle;

typedef struct {
    Ball ball;
    Paddle paddle1, paddle2;
    int score1, score2;
} GameState;

void initGame(GameState *game) {
    game->ball.x = WIDTH / 2;
    game->ball.y = HEIGHT / 2;
    game->paddle1.y = HEIGHT / 2 - PADDLE_SIZE / 2;
    game->paddle2.y = HEIGHT / 2 - PADDLE_SIZE / 2;
    game->score1 = 0;
    game->score2 = 0;
}

void draw(GameState *game) {
    printf("\033[H\033[2J\033[3J"); // Очистка экрана
    printf("+");
    for (int i = 1; i < WIDTH + 1; i++) printf("-");
    printf("+\n");
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (x == game->ball.x && y == game->ball.y) {
                printf("O"); // мяч
            } else if ((y >= game->paddle1.y && y < game->paddle1.y + PADDLE_SIZE) && x == 1) {
                printf("|"); // ракетка 1
            } else if ((y >= game->paddle2.y && y < game->paddle2.y + PADDLE_SIZE) && x == WIDTH - 2) {
                printf("|"); // ракетка 2
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 1; i < WIDTH + 1; i++) printf("-");
    printf("+\n");
    printf("Score: Player 1: %d  Player 2: %d\n", game->score1, game->score2);
}

void movePaddles(GameState *game) {
    int ch = getchar();  // Непрерывно считываем символы без ожидания Enter
    switch (ch) {
        case 'A':
        case 'a':
            if (game->paddle1.y > 0) game->paddle1.y--;
            break;
        case 'Z':
        case 'z':
            if (game->paddle1.y < HEIGHT - PADDLE_SIZE) game->paddle1.y++;
            break;
        case 'K':
        case 'k':
            if (game->paddle2.y > 0) game->paddle2.y--;
            break;
        case 'M':
        case 'm':
            if (game->paddle2.y < HEIGHT - PADDLE_SIZE) game->paddle2.y++;
            break;
        default:
            break;  // Игнорируем другие символы
    }
}

void updateBall(GameState *game) {
    static int dx = 1, dy = 1;

    // Логика перемещения мяча
    game->ball.x += dx;
    game->ball.y += dy;

    // Отражение от верхней и нижней границ
    if (game->ball.y == 0 || game->ball.y == HEIGHT - 1) dy = -dy;

    // Отражение от ракеток
    if (game->ball.x == 2 && game->ball.y >= game->paddle1.y && game->ball.y < game->paddle1.y + PADDLE_SIZE) dx = -dx;
    if (game->ball.x == WIDTH - 3 && game->ball.y >= game->paddle2.y && game->ball.y < game->paddle2.y + PADDLE_SIZE) dx = -dx;

    // Проверка на гол
    if (game->ball.x == 0) {
        game->score2++;
        game->ball.x = WIDTH / 2;
        game->ball.y = HEIGHT / 2;
    }
    if (game->ball.x == WIDTH - 1) {
        game->score1++;
        game->ball.x = WIDTH / 2;
        game->ball.y = HEIGHT / 2;
    }
}

int checkWinner(GameState *game) {
    if (game->score1 >= WIN_SCORE) {
        printf("Player 1 wins!\n");
        return 1;
    }
    if (game->score2 >= WIN_SCORE) {
        printf("Player 2 wins!\n");
        return 1;
    }
    return 0;
}

// Функция для настройки терминала в неканонический режим
void setNonCanonicalMode(int enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);           // Сохраняем текущие настройки терминала
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);         // Отключаем канонический режим и вывод ввода
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Применяем изменения
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Восстанавливаем старые настройки
    }
}

// Функция для проверки ввода без ожидания
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;



    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main() {
    GameState game;
    initGame(&game);

    setNonCanonicalMode(1);  // Включаем неканонический режим

    while (!checkWinner(&game)) {
        draw(&game);
        if (kbhit()) {
            movePaddles(&game);
        }
        updateBall(&game);
        usleep(100000);  // Небольшая задержка для видимого движения мяча
    }

    setNonCanonicalMode(0);  // Возвращаем настройки терминала в обычный режим

    return 0;
}