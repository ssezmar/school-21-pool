#include "out.h"

void draw(token_t *final_array, int n) {
    int matrix[HEIGHT][WIDTH];
    double x, temp_x, y, temp_y;
    int j, i;
    int count_x = 0;
    int count_y = 0;

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            matrix[j][i] = 0;  // Пустая матрица
        }
    }

    for (x = min_x; x < max_x; x = (x + step_x)) {
        y = perform_all(final_array, x, n);  // Функция

        // Обнуляем переменные для каждого y
        count_x = 0;
        count_y = 0;
        temp_x = x;
        temp_y = y;

        // Считаем координату по x. Это наша координата в матрице от 0 до 80
        while (temp_x >= step_x) {
            temp_x = temp_x - step_x;
            count_x++;
        }

        // Считаем координату по y
        if (temp_y < 0) {
            temp_y = -temp_y;
            while (temp_y >= step_y) {
                temp_y = temp_y - step_y;
                count_y++;
            }
            // если у отрицательно то вычитаем из координаты координату нулевой оси
            if (count_y <= middle) {
                (count_y = count_y - middle);
                count_y = -count_y;
            } else {
                count_y = HEIGHT + 10;  // Если у больше 12 то присваиваем большое
                                        // значение чтобы точно не отрисовалось.
            }
        } else {
            while (temp_y >= step_y) {
                temp_y = temp_y - step_y;
                count_y++;
            }
            // Прибавляем к координате координату нулевой оси
            count_y = count_y + middle;
        }

        // записываем в матрицу "1" если координаты не выходят за размер матрицы
        if (count_x >= 0 && count_x < WIDTH && count_y >= 0 && count_y < HEIGHT) {
            matrix[count_y][count_x] = 1;
        }
    }
    // Рисуем всю матрицу
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (matrix[j][i] == 1)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}