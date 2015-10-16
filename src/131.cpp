#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partitionHelper(ans, temp, s);
        return ans;
    }

    void partitionHelper(vector<vector<string>> &ans, vector<string> &temp, string s) {
        if (s.length() == 0) {
            ans.push_back(temp);
            return;
        }

        if (s.length() == 1) {
            temp.push_back(s);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if(isPalindrome(s.substr(0, i + 1))) {
                temp.push_back(s.substr(0, i + 1));
                partitionHelper(ans, temp, s.substr(i + 1));
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};

int main() {
    Solution s;
    auto ans = s.partition("aaaba");

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
