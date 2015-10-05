#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* use the second bit to store result, keep first bit to calculate neighbors 
   DIE2DIE:   00
   LIVE2DIE:  01
   DIE2LIVE:  10
   LIVE2LIVE: 11
 */
enum { DIE2DIE = 0, LIVE2DIE = 1, DIE2LIVE = 2, LIVE2LIVE = 3 };

int neighbors(int **board, int boardRowSize, int boardColSize, int i, int j) {
    int n = 0;

    if (i - 1 >= 0)
        n += board[i - 1][j] & 0x01; /* N */
    if (i - 1 >= 0 && j + 1 < boardColSize)
        n += board[i - 1][j + 1] & 0x01; /* NE */
    if (j + 1 < boardColSize)
        n += board[i][j + 1] & 0x01; /* E */
    if (i + 1 < boardRowSize && j + 1 < boardColSize)
        n += board[i + 1][j + 1] & 0x01; /* SE */
    if (i + 1 < boardRowSize)
        n += board[i + 1][j] & 0x01; /* S */
    if (i + 1 < boardRowSize && j - 1 >= 0)
        n += board[i + 1][j - 1] & 0x01; /* SW */
    if (j - 1 >= 0)
        n += board[i][j - 1] & 0x01; /* W */
    if (i - 1 >= 0 && j - 1 >= 0)
        n += board[i - 1][j - 1] & 0x01; /* NW */

    return n;
}

void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int i, j;
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            int n = neighbors(board, boardRowSize, boardColSize, i, j);
            if (board[i][j] == 1) {/* live cell */
                if (n < 2 || n > 3) { /* die */
                    board[i][j] = LIVE2DIE;
                }
                else { /* 2 or 3, lives on the next generation */
                    board[i][j] = LIVE2LIVE;
                }
            }
            else if (board[i][j] == 0) {/* dead cell */
                if (n == 3) { /* becomes live */
                    board[i][j] = DIE2LIVE;
                }
                else {
                    board[i][j] = DIE2DIE;
                }
            }
        }
    }

    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            board[i][j] >>= 1; /* translate result */
        }
    }
}

/* Helper functions */
void print(int **board, int boardRowSize, int boardColSize) {
    int i, j;
    for (i = 0; i < boardRowSize; i++ ){
        for (j = 0; j < boardColSize; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ** generateBoard(char **board_ch, int boardRowSize, int boardColSize) {
    int **board_i = (int **)malloc(boardRowSize * sizeof(int *));
    int i, j;
    for (i = 0; i < boardRowSize; i++) {
        board_i[i] = (int *)malloc(boardColSize * sizeof(int));
        for (j = 0; j < boardColSize; j++) {
            board_i[i][j] = board_ch[i][j] - '0';
        }
    }
    return board_i;
}

int main() {
    char *strs[] = {
        "1001",
        "0110",
        "1101",
        "0110"
    };

    int rows = sizeof(strs) / sizeof(strs[0]);
    int cols = strlen(strs[0]);

    int **board = generateBoard(strs, rows, cols);

    printf("Board:\n");
    print(board, rows, cols);

    gameOfLife(board, rows, cols);

    printf("Result:\n");
    print(board, rows, cols);

    return 0;
}
