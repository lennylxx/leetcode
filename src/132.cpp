#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> dp(n);
        vector<vector<int> > mem(n, vector<int>(n)); // memorization for palindrome

        int i, j, k;
        // build palindrome table
        for (i = 0; i < n; i++) {
            mem[i][i] = 1;
            j = i, k = i + 1; // even length
            while(j >= 0 && k <= n - 1) {
                if (s[j] != s[k]) break;
                mem[j][k] = 1;
                j--;
                k++;
            }
            j = i - 1, k = i + 1; // odd length
            while(j >= 0 && k <= n - 1) {
                if (s[j] != s[k]) break;
                mem[j][k] = 1;
                j--;
                k++;
            }
        }

        // run dynamic programming
        dp[0] = 0;
        for (i = 1; i < n; i++) {
            if (mem[0][i]) {
                dp[i] = 0;
            }
            else {
                int min = dp[i - 1] + 1;
                for (j = 0; j < i; j++) {
                    if (mem[j + 1][i] && dp[j] + 1 < min) {// if right half is palindrome
                        min = dp[j] + 1;
                    }
                }
                dp[i] = min;
            }
        }

        return dp[n - 1];
    }
};

int main() {
    string str0 = "aababa";
    string str1 = "ababa";

    Solution s;

    assert(s.minCut(str0) == 1);
    assert(s.minCut(str1) == 0);

    printf("all tests passed!\n");

    return 0;
}
