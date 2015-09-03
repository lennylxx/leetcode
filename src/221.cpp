#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int>(cols));

        int i, j;
        int max_edge = 0;

        for (j = 0; j < cols; j++) {
            dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;
            max_edge = max(dp[0][j], max_edge);
        }

        for (i = 0; i < rows; i++) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            max_edge = max(dp[i][0], max_edge);
        }

        for (i = 1; i < rows; i++) {
            for (j = 1; j < cols; j++) {
                if (matrix[i][j] != '1') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1;

                    if (matrix[i - 1][j - 1] == '1' &&
                        matrix[i - 1][j] == '1' &&
                        matrix[i][j - 1] == '1') {
                        dp[i][j] += min(dp[i - 1][j - 1],
                                        min(dp[i - 1][j], dp[i][j - 1]));
                    }

                    max_edge = max(dp[i][j], max_edge);
                }
            }
        }

        return max_edge * max_edge;
    }
};

int main() {
    vector<vector<char> > matrix1{{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '1'}};

    vector<vector<char> > matrix2{{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '1', '1', '1'}};

    Solution s;
    assert(s.maximalSquare(matrix1) == 4);
    assert(s.maximalSquare(matrix2) == 9);

    printf("all tests passed!\n");

    return 0;
}
