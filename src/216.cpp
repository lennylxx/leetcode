#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;

        combinationSum3Helper(1, n, k, temp, ans);

        return ans;
    }

    void combinationSum3Helper(int start, int n, int k, vector<int> &temp, vector<vector<int> > &ans) {
        if (k == temp.size() && n == 0) {
            ans.push_back(temp);
            return;
        }
        else if (temp.size() > k || n < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            combinationSum3Helper(i + 1, n - i, k, temp, ans);
            temp.pop_back();
        }
    }
};

int main() {
    int k = 3;
    int n = 7;
    Solution s;
    vector<vector<int> > ans = s.combinationSum3(k, n);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
