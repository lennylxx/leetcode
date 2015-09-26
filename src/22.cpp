#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        generateParenthesisHelper(ans, temp, n, n);

        return ans;
    }

    void generateParenthesisHelper(vector<string> &ans, string temp, int left, int right) {
        if (left > right) return;

        if (left == 0 && right == 0) {
            ans.push_back(temp);
            return;
        }

        if (left > 0)
            generateParenthesisHelper(ans, temp + "(", left - 1, right);
        if (right > 0)
            generateParenthesisHelper(ans, temp + ")", left, right - 1);
    }
};

int main() {
    int n = 4;
    Solution s;
    vector<string> ans = s.generateParenthesis(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
