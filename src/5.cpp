#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1; // important, cos a single letter is palindrome
        int i, j, k ;
        for (i = 0; i < n; i++) {
            j = i, k = i + 1; //even length
            while (j >= 0 && k < n) {
                if (s[j] != s[k]) break;
                if (k - j + 1 > maxLen) {
                    start = j;
                    maxLen = k - j + 1;
                }
                j--;
                k++;
            }
            j = i - 1, k = i + 1; // odd length
            while(j >= 0 && k <= n - 1) {
                if (s[j] != s[k]) break;
                if (k - j + 1 > maxLen) {
                    start = j;
                    maxLen = k - j + 1;
                }
                j--;
                k++;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    string str0 = "aabac";
    string str1 = "a";
    Solution s;

    assert(s.longestPalindrome(str0) == "aba");
    assert(s.longestPalindrome(str1) == "a");

    printf("all tests passed!\n");

    return 0;
}
