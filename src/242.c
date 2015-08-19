#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool isAnagram(char* s, char* t) {
    if (s == NULL || t == NULL) return false;

    int lens = strlen(s);
    int lent = strlen(t);
    if (lens != lent) return false;

    int flag[26] = { 0 };
    int i;
    for (i = 0; i < lens; i++){
        flag[s[i] - 'a']++;
    }

    for (i = 0; i < lent; i++) {
        flag[t[i] - 'a']--;
    }

    for (i = 0; i < 26; i++){
        if (flag[i] != 0) return false;
    }

    return true;
}

int main() {

    assert(isAnagram("anagram", "nagaram") == true);
    assert(isAnagram("rat", "car") == false);
    assert(isAnagram("aba", "aab") == true);
    assert(isAnagram("aba", "ab") == false);

    printf("all tests passed!\n");

    return 0;
}
