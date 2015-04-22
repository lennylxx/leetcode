#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidSudoku_1(char board[9][9]) {
    bool flag[9] = { 0 };
    int i, j;

    /* rows */
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '1'; /* digits start with 1 */
                if (flag[n]) return false;
                else flag[n] = true;
            }
        }
        memset(flag, 0, sizeof(flag));
    }

    /* columns */
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '1';
                if (flag[n]) return false;
                else flag[n] = true;
            }
        }
        memset(flag, 0, sizeof(flag));
    }
    
    /* boxes */
    int ii, jj;
    for (ii = 0; ii < 9; ii += 3) {
        for (jj = 0; jj < 9; jj += 3) {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i + ii][j + jj] != '.') {
                        int n = board[i + ii][j + jj] - '1';
                        if (flag[n]) return false;
                        flag[n] = true;
                    }
                }
            }
            memset(flag, 0, sizeof(flag));
        }
    }
    return true;
}

bool isValidSudoku(char board[9][9]) {
    bool row_flag[9][9] = { { 0 } };
    bool col_flag[9][9] = { { 0 } };
    bool box_flag[9][9] = { { 0 } };
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '1'; /* digits start with 1 */
                if (row_flag[i][n]) return false;
                else row_flag[i][n] = true;

                if (col_flag[j][n]) return false;
                else col_flag[j][n] = true;

                if (box_flag[(i / 3) * 3 + j / 3][n]) return false;
                else box_flag[(i / 3) * 3 + j / 3][n] = true;
            }
        }
    }
    return true;
}

int main() {
    char board[9][9] = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    /* should be valid */
    printf("%d\n", isValidSudoku(board));

    return 0;
}
