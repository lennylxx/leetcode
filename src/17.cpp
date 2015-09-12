#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int len = digits.length();
        if (len == 0) return ans;

        vector<string> letters(len);
        string temp;

        for (int i = 0; i < digits.length(); i++) {
            switch(digits[i]) {
                case '2':
                    letters[i] = "abc";
                    break;
                case '3':
                    letters[i] = "def";
                    break;
                case '4':
                    letters[i] = "ghi";
                    break;
                case '5':
                    letters[i] = "jkl";
                    break;
                case '6':
                    letters[i] = "mno";
                    break;
                case '7':
                    letters[i] = "pqrs";
                    break;
                case '8':
                    letters[i] = "tuv";
                    break;
                case '9':
                    letters[i] = "wxyz";
                    break;
                default:
                    break;
            }
        }

        letterCombinationsHelper(ans, temp, 0, letters);

        return ans;
    }

    void letterCombinationsHelper(vector<string> &ans, string &temp, int depth, vector<string> letters) {
        if (depth == letters.size()) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < letters[depth].size(); j++) {
            temp.push_back(letters[depth][j]);
            letterCombinationsHelper(ans, temp, depth + 1, letters);
            temp.pop_back();
        }
    }
};

int main() {
    string digits = "23";
    Solution s;
    vector<string> ans = s.letterCombinations(digits);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
