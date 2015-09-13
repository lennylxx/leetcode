#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (k == 0) return "";
        string ans;
        vector<int> nums(n); /* numbers from 1 to n */
        vector<bool> flag(n, false);

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        getPermutationHelper(ans, nums, flag, n, k);

        return ans;
    }

    void getPermutationHelper(string &ans, vector<int> nums, vector<bool> &flag, int n, int k) {
        if (n == 0) return;

        int fact = 1; /* factorial of (n - 1) */
        for (int i = 1; i <= n - 1; i++) {
            fact *= i;
        }

        int first = 0; /* pick the first available number as head of permutation */
        while (flag[first]) { /* skip unavailable numbers */
            first++;
        }

        while (k > fact) {
            first++;
            while (flag[first]) { /* skip unavailable numbers */
                first++;
            }
            k -= fact;
        }

        flag[first] = true;
        ans.push_back(nums[first] + '0');

        getPermutationHelper(ans, nums, flag, n - 1, k);
    }
};

int main() {
    int n = 3;
    int factN = 1;
    for (int i = 1; i <= n; i++) {
        factN *= i;
    }

    Solution s;

    for (int k = 1; k <= factN; k++) {
        cout << s.getPermutation(n, k) << endl;
    }

    return 0;
}
