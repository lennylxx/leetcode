#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool isIsomorphic(char* s, char* t) {
    int len = strlen(s); /* same length */

    char hashs[128] = { 0 }; /* for ascii code */
    char hasht[128] = { 0 };
    int i;
    for (i = 0; i < len; i++) {
        int x = s[i];
        if (hashs[x] == 0) {
            hashs[x] = t[i];
        }
        else {
            if (hashs[x] != t[i]) {
                return false;
            }
        }

        int y = t[i];
        if (hasht[y] == 0) {
            hasht[y] = s[i];
        }
        else {
            if (hasht[y] != s[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    assert(isIsomorphic("egg", "add") == true);

    assert(isIsomorphic("foo", "bar") == false);

    assert(isIsomorphic("paper", "title") == true);

    assert(isIsomorphic("bar", "foo") == false);

    assert(isIsomorphic("13", "42") == true);

    printf("success!\n");

    return 0;
}
