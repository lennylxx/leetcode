#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 108 ms
class Solution0 {
public:
    struct Trace {
        int i;
        int j;
        int s;
        Trace() : i(0), j(0), s(0) {}
        Trace(int _i, int _j, int _s) : i(_i), j(_j), s(_s) {}
    };

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowFlag(9, vector<bool>(9, false));
        vector<vector<bool>> colFlag(9, vector<bool>(9, false));
        vector<vector<bool>> boxFlag(9, vector<bool>(9, false));
        vector<vector<bool>> occupied(9, vector<bool>(9, false));
        int i, j;
        int remains = 0;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '1';
                    rowFlag[i][k] = true;
                    colFlag[j][k] = true;
                    boxFlag[(i / 3) * 3 + j / 3][k] = true;
                    occupied[i][j] = true;
                }
                else {
                    remains++;
                }
            }
        }

        bool found = false;
        vector<Trace> ans(remains);
        placeNumber(board, found, ans, 0, remains, occupied, rowFlag, colFlag, boxFlag);
    }

    void placeNumber(vector<vector<char>>& board, bool &found,
                     vector<Trace> &ans, int count, int remains,
                     vector<vector<bool>> &occupied, vector<vector<bool>> &rowFlag,
                     vector<vector<bool>> &colFlag, vector<vector<bool>> &boxFlag)
    {
        // suppose we have only one solution, if we found one, no need to continue
        if (found) return;

        int i, j;

        // found one solution! copy answers to the board
        if (count == remains) {
            found = true;
            int k = 0;
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        board[i][j] = ans[k++].s + '1';
                    }
                }
            }
            return;
        }

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (occupied[i][j] == false) {
                    for (int s = 0; s < 9; s++) {
                        // try to place a number
                        ans[count] = Trace(i, j, s);
                        // if it's valid, set flag and place another number
                        if (!rowFlag[i][s] && !colFlag[j][s] && !boxFlag[(i / 3) * 3 + j / 3][s]) {
                            rowFlag[i][s] = true;
                            colFlag[j][s] = true;
                            boxFlag[(i / 3) * 3 + j / 3][s] = true;
                            occupied[i][j] = true;
                            placeNumber(board, found, ans, count + 1, remains, occupied, rowFlag, colFlag, boxFlag);
                        }
                    }
                    // can't find a right number, backtrack
                    // set back the flag to false
                    // be aware to set the previous number, not the current
                    if (count <= 0) return;
                    Trace t = ans[count - 1];
                    rowFlag[t.i][t.s] = false;
                    colFlag[t.j][t.s] = false;
                    boxFlag[(t.i / 3) * 3 + t.j / 3][t.s] = false;
                    occupied[t.i][t.j] = false;
                    return;
                }
            }
        }
    }
};

// 36 ms
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowFlag(10, vector<bool>(10, false));
        vector<vector<bool>> colFlag(10, vector<bool>(10, false));
        vector<vector<bool>> boxFlag(10, vector<bool>(10, false));
        int i, j;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '1';
                    rowFlag[i][k] = true;
                    colFlag[j][k] = true;
                    boxFlag[(i / 3) * 3 + j / 3][k] = true;
                }
            }
        }

        bool found = false;
        placeNumber(board, found, 0, rowFlag, colFlag, boxFlag);
    }

    bool placeNumber(vector<vector<char>>& board, bool &found,
                     int depth,
                     vector<vector<bool>> &rowFlag,
                     vector<vector<bool>> &colFlag, vector<vector<bool>> &boxFlag)
    {
        // suppose we have only one solution, if we found one, no need to continue
        if (found) return true;

        // found one solution! copy answers to the board
        if (depth == 81) {
            found = true;
            return true;
        }

        int i, j;
        i = depth / 9; j = depth % 9;

        if (board[i][j] != '.') {
            return placeNumber(board, found, depth + 1, rowFlag, colFlag, boxFlag);
        }
        else {
            for (int s = 0; s < 9; s++) {
                // if it's valid, set flag and place another number
                if (!rowFlag[i][s] && !colFlag[j][s] && !boxFlag[(i / 3) * 3 + j / 3][s]) {
                    // try to place a number
                    board[i][j] = s + '1';
                    rowFlag[i][s] = true;
                    colFlag[j][s] = true;
                    boxFlag[(i / 3) * 3 + j / 3][s] = true;
                    if (placeNumber(board, found, depth + 1, rowFlag, colFlag, boxFlag)) return true;
                    // backtrack
                    rowFlag[i][s] = false;
                    colFlag[j][s] = false;
                    boxFlag[(i / 3) * 3 + j / 3][s] = false;
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
};

int main() {
    vector<string> board0 = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
    };

    vector<string> board1 = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    vector<vector<char> > board(9, vector<char>(9, 0));
    int i, j;

    // board0
    for (i = 0; i < board0.size(); i++) {
        for (j = 0; j < board0[i].length(); j++) {
            board[i][j] = board0[i][j];
        }
    }

    Solution s;
    s.solveSudoku(board);

    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board[i].size(); j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("-----------------\n");

    // board1
    for (i = 0; i < board1.size(); i++) {
        for (j = 0; j < board1[i].length(); j++) {
            board[i][j] = board1[i][j];
        }
    }

    s.solveSudoku(board);

    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board[i].size(); j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
