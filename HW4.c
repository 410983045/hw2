#include <stdio.h>

void checkNewStepByColor(int chess[8][8], int next[8][8], int color);
void checkNewStep(int chess[8][8], int next[8][8], int x, int y);
int newStep(int chess[8][8], int x, int y, int dx, int dy);

int main() {
    int chess[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int next[8][8] = {0};

    checkNewStepByColor(chess, next, 2);

    printf("白子所有可下的步:\n");
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (next[i][j] == 1) {
                printf("(%d,%d), ", i, j);
            }
        }
    }
    printf("\n");

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            next[i][j] = 0;
        }
    }

    checkNewStepByColor(chess, next, 1);

    printf("黑子所有可下的步:\n");
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (next[i][j] == 1) {
                printf("(%d,%d), ", i, j);
            }
        }
    }
    printf("\n");

    return 0;
}

void checkNewStepByColor(int chess[8][8], int next[8][8], int color) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == color) {
                checkNewStep(chess, next, i, j);
            }
        }
    }
}

void checkNewStep(int chess[8][8], int next[8][8], int x, int y) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int k = 0; k < 8; ++k) {
        int dx = directions[k][0];
        int dy = directions[k][1];

        int result = newStep(chess, x, y, dx, dy);

        if (result > 0) {
            int nx = x + result * dx;
            int ny = y + result * dy;
            next[nx][ny] = 1;
        }
    }
}

int newStep(int chess[8][8], int x, int y, int dx, int dy) {
    int color = chess[x][y];
    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || chess[nx][ny] == 0) {
        return 0;
    }

    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == 3 - color) {
        nx += dx;
        ny += dy;
    }

    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == color) {
        return nx - x;
    }

    return 0;
}
