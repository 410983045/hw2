#include <stdio.h>

int main(){

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

    int i, j, color;

    scanf("%d %d %d", &i, &j, &color);

    if (chess[i][j] == 0) {
        printf("�ť�\n");

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int x = i + dx;
                int y = j + dy;

                while (x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] == 3 - color) {
                    x += dx;
                    y += dy;
                }

                if (x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] == color) {
                    printf("(%d,%d) �i�H�U %s �l\n", i, j, (color == 1) ? "��" : "��");
                    return 0;
                }
            }
        }

        printf("(%d,%d) ����U %s �l\n", i, j, (color == 1) ? "��" : "��");
    } else {
        printf("(%d,%d) �w�g���Ѥl\n", i, j);
    }

    return 0;
}
