#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;

        combinationSumHelper(ans, temp, candidates, target);

        return ans;
    }

    void combinationSumHelper(vector<vector<int> > &ans, vector<int> &temp, vector<int> &candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        else if (target < 0) {
            return;
        }

        int max = 0;
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] > max)
                max = temp[k];
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] >= max) {
                temp.push_back(candidates[i]);
                combinationSumHelper(ans, temp, candidates, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution s;
    vector<vector<int> > ans = s.combinationSum(candidates, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
