#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        map<string, char> word2pattern;
        map<char, string> pattern2word;

        int i, prev = 0;
        for (i = 0; i <= str.length(); i++) {
            if (str[i] == ' ' || str[i] == '\0') {
                words.push_back(str.substr(prev, i - prev));
                prev = i + 1;
            }
        }

        if (pattern.length() != words.size()) return false;

        for (i = 0; i < words.size(); i++) {
            if (word2pattern.find(words[i]) == word2pattern.end() &&
                pattern2word.find(pattern[i]) == pattern2word.end()) {
                word2pattern[words[i]] = pattern[i];
                pattern2word[pattern[i]] = words[i];
            }
            else {
                if (word2pattern[words[i]] != pattern[i] ||
                    pattern2word[pattern[i]] != words[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {

    Solution s;
    assert(s.wordPattern("abba", "dog cat cat dog") == true);
    assert(s.wordPattern("abba", "dog cat cat fish") == false);
    assert(s.wordPattern("aaaa", "dog cat cat dog") == false);
    assert(s.wordPattern("abba", "dog dog dog dog") == false);

    printf("all tests passed!\n");

    return 0;
}
