#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<string> q;
        map<string, bool> visited;
        q.push(beginWord);
        q.push("LEVEL_END_TAG");
        visited[beginWord] = true;
        int level = 1;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word != "LEVEL_END_TAG") {
                for (int i = 0; i < word.length(); i++) {
                    string new_word = word;
                    for (int j = 0; j < 26; j++) {
                        new_word[i] = j + 'a';

                        if (new_word == endWord) {
                            level++;
                            return level;
                        }

                        auto it = wordList.find(new_word);
                        if (it != wordList.end() && !visited[new_word]) {
                            q.push(new_word);
                            visited[new_word] = true;
                        }
                    }
                }
            }
            else {
                level++;
                if (!q.empty()) {
                    q.push("LEVEL_END_TAG");
                }
            }
        }

        return 0;
    }
};

int main() {
    unordered_set<string> wordList0 = { "hot", "dot", "dog", "lot", "log" };
    unordered_set<string> wordList1 = { "hot", "dog" } ;

    Solution s;
    assert(s.ladderLength("hit", "cog", wordList0) == 5);
    assert(s.ladderLength("hot", "dog", wordList1) == 0);

    printf("all tests passed!\n");

    return 0;
}
