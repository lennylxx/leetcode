#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> temp;

        combineHelper(1, n, k, temp, ans);

        return ans;
    }

    void combineHelper(int start, int end, int k, vector<int> &temp, vector<vector<int> > &ans) {
        if (k == temp.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= end; i++) {
            temp.push_back(i);
            combineHelper(i + 1, end, k, temp, ans);
            temp.pop_back();
        }
    }
};

int main() {
    int n = 4;
    int k = 2;
    Solution s;
    vector<vector<int> > ans = s.combine(n, k);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
