#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> possible(len, 0);

        for (int i = 0; i < len; i++) {
             if (dict.find(s.substr(0, i + 1)) != dict.end())
                possible[i] = true;

            for (int j = 0; j < i; j++) {
                if (possible[j] &&
                        dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                    possible[i] = true;
                    break;
                }
            }
        }
        /*
        for (vector<bool>::iterator it = possible.begin();
            it != possible.end(); it++)
            cout << *it << endl;
        */
        return possible[len - 1];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    unordered_set<string> dict = { "leet", "code" };
    cout << solution.wordBreak(s, dict) << endl;
    return 0;
}
