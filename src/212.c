#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CALLOC2D(array, type, rowSize, colSize)                      \
    do {                                                             \
        array = (type **)calloc(rowSize, sizeof(type *));            \
        int _i;                                                      \
        for (_i = 0; _i < rowSize; _i++) {                           \
            array[_i] = (type *)calloc(colSize, sizeof(type));       \
        }                                                            \
    } while (0)                                    

#define CLEAR2D(array, rowSize, colSize)                             \
    do {                                                             \
        int _i;                                                      \
        for (_i = 0; _i < rowSize; _i++) {                           \
            memset(array[_i], 0, colSize);                           \
        }                                                            \
    } while (0)                                    

#define FREE2D(array, rowSize)                                       \
    do {                                                             \
        int _i;                                                      \
        for (_i = 0; _i < rowSize; _i++) {                           \
            free(array[_i]);                                         \
        }                                                            \
    } while (0)

struct TrieNode {
    bool end;
    struct TrieNode *next[26]; /* a-z */
};

struct TrieNode* trieCreate() {
    struct TrieNode* dummy = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    dummy->end = false;
    memset(dummy->next, 0, sizeof(dummy->next));
    return dummy;
}

void insert(struct TrieNode* root, char* word) {
    if (root == NULL || word == NULL) return;

    struct TrieNode* p = root;
    while (*word != '\0') {
        if (p->next[*word - 'a'] == NULL) {
            p->next[*word - 'a'] = trieCreate();
        }
        p = p->next[*word - 'a'];
        word++;
    }
    p->end = true;
}

void trieFree(struct TrieNode* root) {
    if (root == NULL) return;

    int i;
    for (i = 0; i < 26; i++) {
        trieFree(root->next[i]);
    }
    free(root);
}

/* 44 ms, a bit slow */
void dfs(char** board, int boardRowSize, int boardColSize,
         bool** visited, int i, int j,
         char* word, int depth,
         struct TrieNode* node,
         char **ans, int* returnSize) {

    if (i >= 0 && i < boardRowSize && j >= 0 && j < boardColSize && !visited[i][j]) {
        word[depth] = board[i][j];
        visited[i][j] = true;

        struct TrieNode* next_node = node->next[board[i][j] - 'a'];
        if (next_node) {
            if (next_node->end) {
                strcpy(ans[(*returnSize)++], word);
                next_node->end = false;
            }
            depth++;
            dfs(board, boardRowSize, boardColSize, visited, i, j - 1, word, depth, next_node, ans, returnSize); /* left */
            dfs(board, boardRowSize, boardColSize, visited, i, j + 1, word, depth, next_node, ans, returnSize); /* right */
            dfs(board, boardRowSize, boardColSize, visited, i - 1, j, word, depth, next_node, ans, returnSize); /* up */
            dfs(board, boardRowSize, boardColSize, visited, i + 1, j, word, depth, next_node, ans, returnSize); /* down */
        }

        word[depth] = 0;
        visited[i][j] = false; /* restore */
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {

    int bufSize = 128;
    char *buf = (char *)calloc(bufSize, sizeof(char));

    /* returned array */
    char **ans;
    CALLOC2D(ans, char, wordsSize, bufSize);

    bool **visited;
    CALLOC2D(visited, bool, boardRowSize, boardColSize);

    int i, j;
    /* insert all words into Trie */
    struct TrieNode* trie = trieCreate();
    for (i = 0; i < wordsSize; i++) {
        insert(trie, words[i]);
    }

    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            dfs(board, boardRowSize, boardColSize, visited, i, j, buf, 0, trie, ans, returnSize);
        }
    }

    trieFree(trie);
    free(buf);
    FREE2D(visited, boardRowSize);

    return ans;
}

int main() {

    //char *board[5] = { "ab", "aa" }; // 2 2 
    //char *words[20] = { "aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba" }; // 7
    
    char *board[7] = { "baabab", "abaaaa", "abaaab", "ababba", "aabbab", "aabbba", "aabaab" }; // 7 6
    char *words[30] = {
        "bbaabaabaaaaabaababaaaaababb", 
        "aabbaaabaaabaabaaaaaabbaaaba", 
        "babaababbbbbbbaabaababaabaaa", 
        "bbbaaabaabbaaababababbbbbaaa", 
        "babbabbbbaabbabaaaaaabbbaaab",
        "bbbababbbbbbbababbabbbbbabaa", 
        "babababbababaabbbbabbbbabbba", 
        "abbbbbbaabaaabaaababaabbabba", 
        "aabaabababbbbbbababbbababbaa", 
        "aabbbbabbaababaaaabababbaaba", //
        "ababaababaaabbabbaabbaabbaba", //
        "abaabbbaaaaababbbaaaaabbbaab", //
        "aabbabaabaabbabababaaabbbaab", 
        "baaabaaaabbabaaabaabababaaaa", 
        "aaabbabaaaababbabbaabbaabbaa",
        "aaabaaaaabaabbabaabbbbaabaaa", 
        "abbaabbaaaabbaababababbaabbb", 
        "baabaababbbbaaaabaaabbababbb", 
        "aabaababbaababbaaabaabababab", 
        "abbaaabbaabaabaabbbbaabbbbbb", 
        "aaababaabbaaabbbaaabbabbabab", 
        "bbababbbabbbbabbbbabbbbbabaa", 
        "abbbaabbbaaababbbababbababba",
        "bbbbbbbabbbababbabaabababaab", 
        "aaaababaabbbbabaaaaabaaaaabb", 
        "bbaaabbbbabbaaabbaabbabbaaba", 
        "aabaabbbbaabaabbabaabababaaa", 
        "abbababbbaababaabbababababbb", 
        "aabbbabbaaaababbbbabbababbbb", 
        "babbbaabababbbbbbbbbaabbabaa" }; // 30

    int size = 0;
    char **ans = findWords(board, 7, 6, words, 30, &size);

    int i;
    for (i = 0; i < size; i++) {
        printf("%s\n", ans[i]);
    }
    printf("Total: %d\n", size);

    return 0;
}
