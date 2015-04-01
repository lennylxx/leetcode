#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isValid(vector<int> &columns, int row) {
        for (int i = 0; i < row; i++) {
            if (columns[i] == columns[row]
                || abs(columns[i] - columns[row]) == (row - i)) {
                return false;
            }
        }
        return true;
    }

    void placeQueens(vector<vector<string> > &ret, vector<int> &columns, int row) {
        int n = columns.size();

        for (int j = 0; j < n; j++) {
            if (row == n) { /* found one solution! */
                vector<string> solution;
                /* build solution vector */
                for (int i = 0; i < n; i++) {
                    string line(n, '.');
                    line[columns[i]] = 'Q';
                    solution.push_back(line);
                }
                ret.push_back(solution);

                return;
            }
            /* try to place a queen in this row */
            columns[row] = j;
            /* put another queen in next row if this row's position is valid */
            if (isValid(columns, row)) {
                placeQueens(ret, columns, row + 1);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        vector<int> columns(n, 0);

        placeQueens(ret, columns, 0);

        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<string> > ret;
    ret = s.solveNQueens(4);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[0].size(); j++) {
            cout << ret[i][j] << endl;
        }
        cout << "----" << endl;
    }

    ret = s.solveNQueens(5);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[0].size(); j++) {
            cout << ret[i][j] << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}
