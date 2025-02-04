#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init_game(int rows, int cols, int grind[rows][cols], int burn[9], int live[9]);

void print_grind(int rows, int cols, int grind[rows][cols]);

int count_live_neighbors(int rows, int cols, int grid[rows][cols], int x, int y);

void update_grid(int rows, int cols, int current[rows][cols], int next[rows][cols], const int burn[9],
                 const int live[9]);

void game_of_life(int rows, int cols, int speed);

int main(int argc, char *argv[]) {
    const int rows = 25;
    const int cols = 80;
    if (argc != 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 100) {
        printf("Использование: ./game_of_life.out <скорость>\nСкорость должна быть от 1 до 100");
    } else {
        int speed = 1000000;
        speed /= atoi(argv[1]);
        game_of_life(rows, cols, speed);
    }

    return 0;
}

void game_of_life(int rows, int cols, int speed) {
    int grind[rows][cols];
    int next[rows][cols];
    int burn[9] = {0};
    int live[9] = {0};

    init_game(rows, cols, grind, burn, live);

    while (1) {
        print_grind(rows, cols, grind);
        update_grid(rows, cols, grind, next, burn, live);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                grind[r][c] = next[r][c];
            }
        }

        usleep(speed);
    }
}

void init_game(int rows, int cols, int grind[rows][cols], int burn[9], int live[9]) {
    // Считывание правил рождения
    for (int i = 0; i < 9; i++) {
        int num = 0;
        scanf("%d", &num);
        burn[num] = 1;
        char last_symbol = getchar();
        if (last_symbol == '\n') break;
    }

    // Считывание правил жизни
    for (int i = 0; i < 9; i++) {
        int num = 0;
        scanf("%d", &num);
        live[num] = 1;
        char last_symbol = getchar();
        if (last_symbol == '\n') break;
    }

    // Считывание для поля
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            scanf("%d", &grind[r][c]);
        }
    }
}

void print_grind(int rows, int cols, int grind[rows][cols]) {
    system("clear");  // очистка экрана
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grind[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

int count_live_neighbors(int rows, int cols, int grind[rows][cols], int x, int y) {
    int live_count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int new_x = ((x + i) % rows) >= 0 ? (x + i) % rows : rows - 1;
            int new_y = ((y + j) % cols) >= 0 ? (y + j) % cols : cols - 1;

            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                if (grind[new_x][new_y] == 1) {
                    live_count++;
                }
            }
        }
    }

    return live_count;
}

void update_grid(int rows, int cols, int current[rows][cols], int next[rows][cols], const int burn[9],
                 const int live[9]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int live_neighbors = count_live_neighbors(rows, cols, current, r, c);

            if (current[r][c] == 1) {
                int is_live = 0;
                for (int i = 0; i < 9; i++) {
                    if (live[i] == 1 && live_neighbors == i) {
                        is_live = 1;
                        break;
                    }
                }
                next[r][c] = is_live ? 1 : 0;
            } else {
                int is_live = 0;
                for (int i = 0; i < 9; i++) {
                    if (burn[i] == 1 && live_neighbors == i) {
                        is_live = 1;
                        break;
                    }
                }
                next[r][c] = is_live ? 1 : 0;
            }
        }
    }
}
