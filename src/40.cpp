#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<bool> flag(candidates.size(), false);
        vector<int> temp;

        combinationSum2Helper(ans, flag, temp, candidates, target);

        return ans;
    }

    /* Very slow, 424 ms. Need to improved. */
    void combinationSum2Helper(vector<vector<int> > &ans, vector<bool> &flag, vector<int> &temp, vector<int> &candidates, int target) {
        if (target == 0) {
            bool found = false;
            for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); it++) {
                if (temp == *it) {
                    found = true;
                    break;
                }
            }
            if (!found)
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
            if (!flag[i] && candidates[i] >= max) {
                flag[i] = true;
                temp.push_back(candidates[i]);
                combinationSum2Helper(ans, flag, temp, candidates, target - candidates[i]);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    vector<vector<int> > ans = s.combinationSum2(candidates, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
