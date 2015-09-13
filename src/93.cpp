#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        vector<string> ans;

        dfs(s, temp, ans);

        return ans;
    }

    void dfs(string s, vector<string> &temp, vector<string> &ans) {
        if (temp.size() == 4 && s.length() == 0) {
            ans.push_back(temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3]);
            return;
        }
        else if (temp.size() >= 4) {
            return;
        }

        for(int i = 1; i <= 3 && i <= s.length(); i++) {
            string t = s.substr(0, i);
            if (t.length() > 1 && t[0] == '0') break;
            if (stoi(t) > 255) break;
            temp.push_back(t);
            dfs(s.substr(i, s.length() - i), temp, ans);
            temp.pop_back();
        }
    }
};

int main() {
    string str = "010010";
    Solution s;
    vector<string> ret = s.restoreIpAddresses(str);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    return 0;
}
