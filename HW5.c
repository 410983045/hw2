#include <stdio.h>

void flipPieces(int chess[8][8], int x, int y, int color);
int countFlippablePieces(int chess[8][8], int x, int y, int dx, int dy, int color);

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

    int x = 2, y = 3, color = 1;

    flipPieces(chess, x, y, color);

    x = 3, y = 5, color = 2;

    int flippableCount = countFlippablePieces(chess, x, y, 0, 1, color) +
                         countFlippablePieces(chess, x, y, 0, -1, color) +
                         countFlippablePieces(chess, x, y, 1, 0, color) +
                         countFlippablePieces(chess, x, y, -1, 0, color) +
                         countFlippablePieces(chess, x, y, 1, 1, color) +
                         countFlippablePieces(chess, x, y, 1, -1, color) +
                         countFlippablePieces(chess, x, y, -1, 1, color) +
                         countFlippablePieces(chess, x, y, -1, -1, color);

    printf("可翻轉對方的棋子數量: %d\n", flippableCount);

    return 0;
}

void flipPieces(int chess[8][8], int x, int y, int color) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int k = 0; k < 8; ++k) {
        int dx = directions[k][0];
        int dy = directions[k][1];

        int flippableCount = countFlippablePieces(chess, x, y, dx, dy, color);

        for (int i = 1; i <= flippableCount; ++i) {
            chess[x + i * dx][y + i * dy] = color;
        }
    }
}

int countFlippablePieces(int chess[8][8], int x, int y, int dx, int dy, int color) {
    int opponentColor = 3 - color;
    int count = 0;
    int nx = x + dx;
    int ny = y + dy;

    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == opponentColor) {
        count++;
        nx += dx;
        ny += dy;
    }

    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == color) {
        return count;
    }

    return 0;
}
