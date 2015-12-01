#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /* O(n) */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            hash[word].push_back(strs[i]);
        }

        vector<vector<string>> ans(hash.size());
        int k = 0;
        for (auto it = hash.begin(); it != hash.end(); it++, k++) {
            ans[k].swap(it->second);
            sort(ans[k].begin(), ans[k].end());
        }

        return ans;
    }

    /* very slow, will exceed time limit, O(n*n) */
    vector<vector<string>> groupAnagrams0(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<bool> flag(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {
            if (flag[i]) continue;

            flag[i] = true;
            int hash[26] = {0};
            string word = strs[i];
            for (int k = 0; k < word.length(); k++) {
                hash[word[k] - 'a'] += 1;
            }

            temp.push_back(word);

            for (int j = i + 1; j < strs.size(); j++) {
                if (flag[j]) continue;

                int hasht[26] = {0};
                string t = strs[j];
                for (int k = 0; k < t.length(); k++) {
                    hasht[t[k] - 'a'] += 1;
                }

                /* compare hash table */
                int c = 25;
                while (c >= 0 && hash[c] == hasht[c]) {
                    c--;
                }

                if (c == -1) {
                    flag[j] = true;
                    temp.push_back(t);
                }
            }

            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution s;
    auto ans = s.groupAnagrams(strs);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
