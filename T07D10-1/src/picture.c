#include <stdio.h>

#define N 15
#define M 13

void transform(int buf[N][M], int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output_matrix(const int r, const int c, int **matrix);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(picture_data, picture, N, M);

    make_picture(picture, N, M);
    output_matrix(N, M, picture);

    return 0;
}

void output_matrix(const int r, const int c, int **matrix) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((c == 1) && (i < r - 1))
                printf("%d\n", matrix[i][j]);
            else if (c == 1)
                printf("%d", matrix[i][j]);
            else if ((i == r - 1) && (j == c - 1))
                printf(" %d", matrix[i][j]);
            else if (j == c - 1)
                printf(" %d\n", matrix[i][j]);
            else if (j == 0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
    }
}

void draw_sun(int **picture, int m, int sun_data[6][5]) {
    int sun_c = m - 1 - 5;
    int sun_r = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[i + sun_r][j + sun_c] = sun_data[i][j];
        }
    }
}

void draw_tree(int **picture, int tree_trunk[4], int tree_foliage[4]) {
    for (int i = 0; i < 4; i++) {
        picture[3][i + 2] = tree_foliage[i];
        picture[4][i + 2] = tree_foliage[i];
        picture[i + 2][3] = tree_foliage[i];
        picture[i + 2][4] = tree_foliage[i];
    }
    for (int i = 0; i < 4; i++) {
        picture[i + 6][3] = tree_trunk[i];
        picture[i + 6][4] = tree_trunk[i];
        picture[10][i + 2] = tree_trunk[i];
    }
}

void draw_window(int **picture, int length_frame_h, int length_frame_w, int *frame_h, int *frame_w) {
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[length_frame_h / 2][i] = frame_w[i];
        picture[length_frame_h - 1][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][length_frame_w / 2] = frame_h[i];
        picture[i][length_frame_w - 1] = frame_h[i];
    }
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    draw_sun(picture, m, sun_data);
    draw_tree(picture, tree_trunk, tree_foliage);
    draw_window(picture, length_frame_h, length_frame_w, frame_h, frame_w);
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int buf[N][M], int **matr, int n, int m) {
    for (int i = 0; i < (m + n - m); i++) {
        matr[i] = (int *)(buf + i);
    }
}
