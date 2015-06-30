#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct WordDictionary {
    bool end;
    struct WordDictionary *child[26]; /* a - z */
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary *new_node
        = (struct WordDictionary *)malloc(sizeof(struct WordDictionary));

    new_node->end = false;
    memset(new_node->child, 0, sizeof(new_node->child));
    return new_node;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    if (wordDictionary == NULL || word == NULL) return;

    struct WordDictionary *p = wordDictionary;

    while (*word != '\0') {
        if (p->child[*word - 'a'] == NULL) {
            p->child[*word - 'a'] = wordDictionaryCreate();
        }
        p = p->child[*word - 'a'];
        word++;
    }
    p->end = true;
}

/** Returns if the word is in the data structure. A word could
contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
    if (wordDictionary == NULL || word == NULL) return false;

    if (*word == '\0') {
        if (wordDictionary->end) return true;
        else return false;
    }

    int i;
    if (*word == '.') {
        for (i = 0; i < 26; i++) {
            if (wordDictionary->child[i]) {
                bool flag = search(wordDictionary->child[i], word + 1);
                if (flag) return true;
            }
        }
        return false;
    }
    else {
        return search(wordDictionary->child[*word - 'a'], word + 1);
    }
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    if (wordDictionary == NULL) return;

    int i;
    for (i = 0; i < 26; i++) {
        wordDictionaryFree(wordDictionary->child[i]);
    }
    free(wordDictionary);
}

int main() {

    struct WordDictionary* wordDictionary = wordDictionaryCreate();

    addWord(wordDictionary, "bad");
    addWord(wordDictionary, "dad");
    addWord(wordDictionary, "mad");
    addWord(wordDictionary, "dcd");

    assert(search(wordDictionary, "pad") == false);
    assert(search(wordDictionary, "bad") == true);
    assert(search(wordDictionary, ".ad") == true);
    assert(search(wordDictionary, "b..") == true);
    assert(search(wordDictionary, "b.d") == true);
    assert(search(wordDictionary, "b.c") == false);
    assert(search(wordDictionary, ".cd") == true);
    assert(search(wordDictionary, "b") == false);
    assert(search(wordDictionary, ".") == false);
    assert(search(wordDictionary, "badd") == false);

    wordDictionaryFree(wordDictionary);

    printf("all test pased!\n");

    return 0;
}
