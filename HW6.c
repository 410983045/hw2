#include <stdio.h>

void printChessboard(int chess[8][8]);
void checkNewStepByColor(int chess[8][8], int next[8][8], int color);
void checkNewStep(int chess[8][8], int next[8][8], int x, int y);
int newStep(int chess[8][8], int x, int y, int dx, int dy);
void flipPieces(int chess[8][8], int x, int y, int color);
int countFlippablePieces(int chess[8][8], int x, int y, int dx, int dy, int color);
int checkWinner(int chess[8][8]);

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

    int currentPlayer = 1;

    while (1) {
        printChessboard(chess);

        int i, j;

        printf("Player %d's turn. Enter the row and column (e.g., 3 2): ", currentPlayer);
        scanf("%d %d", &i, &j);

        int next[8][8] = {0};
        checkNewStepByColor(chess, next, currentPlayer);

        if (next[i][j] == 1) {
            flipPieces(chess, i, j, currentPlayer);
            currentPlayer = 3 - currentPlayer;
        } else {
            printf("Invalid move. Try again.\n");
        }

        int winner = checkWinner(chess);

        if (winner != 0) {
            printChessboard(chess);
            printf("Player %d wins!\n", winner);
            break;
        }

        int blackNext[8][8] = {0};
        int whiteNext[8][8] = {0};

        checkNewStepByColor(chess, blackNext, 1);
        checkNewStepByColor(chess, whiteNext, 2);

        int blackCanMove = 0;
        int whiteCanMove = 0;

        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (blackNext[x][y] == 1) {
                    blackCanMove = 1;
                }
                if (whiteNext[x][y] == 1) {
                    whiteCanMove = 1;
                }
            }
        }

        if (!blackCanMove && !whiteCanMove) {
            printChessboard(chess);
            printf("It's a tie!\n");
            break;
        } else if (!blackCanMove) {
            currentPlayer = 2;
        } else if (!whiteCanMove) {
            currentPlayer = 1;
        }
    }

    return 0;
}

void printChessboard(int chess[8][8]) {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ", i);
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == 0) {
                printf(". ");
            } else if (chess[i][j] == 1) {
                printf("B ");
            } else if (chess[i][j] == 2) {
                printf("W ");
            }
        }
        printf("\n");
    }
}

void checkNewStepByColor(int chess[8][8], int next[8][8], int color) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == 0) {
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

        if (newStep(chess, x, y, dx, dy) > 0) {
            next[x][y] = 1;
            break;
        }
    }
}

int newStep(int chess[8][8], int x, int y, int dx, int dy) {
    int opponentColor = 3 - chess[x][y];
    int count = 0;
    int nx = x + dx;
    int ny = y + dy;

    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == opponentColor) {
        count++;
        nx += dx;
        ny += dy;
    }

    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chess[nx][ny] == chess[x][y]) {
        return count;
    }

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

int checkWinner(int chess[8][8]) {
    int blackCount = 0;
    int whiteCount = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == 1) {
                blackCount++;
            } else if (chess[i][j] == 2) {
                whiteCount++;
            }
        }
    }

    if (blackCount > whiteCount) {
        return 1;
    } else if (whiteCount > blackCount) {
        return 2;
    } else {
        return 0;
    }
}
