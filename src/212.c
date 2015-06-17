#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TrieNode {
    char val;
    struct TrieNode *child;   /* most left child */
    struct TrieNode *sibling; /* brothers of the current child*/
};

struct TrieNode* trieCreate() {
    struct TrieNode *dummy = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    dummy->val = '\0';
    dummy->child = NULL;
    dummy->sibling = NULL;

    return dummy;
}

void insert(struct TrieNode* root, char* word) {
    if (root == NULL || word == NULL) return;

    struct TrieNode **p = &(root->child);
    struct TrieNode *new_node = NULL;

    while (*word != '\0') {
        /* get common prefix */
        while (*p) {
            if ((*p)->val == *word) {
                p = &((*p)->child);
                word++;
            }
            else {
                p = &((*p)->sibling);
            }
        }

        new_node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
        new_node->val = *word;
        new_node->child = NULL;
        new_node->sibling = NULL;

        *p = new_node;
        p = &((*p)->child); /* move forward */
        word++;
    }

    /* put the EOL character in the tree */
    new_node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    new_node->val = '\0';
    new_node->child = NULL;
    new_node->sibling = NULL;

    if (*p) {
        p = &((*p)->child);
        *p = new_node;
    }
    else {
        *p = new_node;
    }
}

bool search(struct TrieNode* root, char* word) {
    if (root == NULL || word == NULL) return false;

    if (root->child == NULL) return false;

    struct TrieNode *p = root->child;

    while (p && *word != '\0') {
        if (p->val == *word) {
            p = p->child;
            word++;
        }
        else {
            p = p->sibling;
        }
    }

    /* check if we have an EOL in the siblings */
    while (p) {
        if (p->val == '\0') return true;
        p = p->sibling;
    }

    return false;
}

bool startsWith(struct TrieNode* root, char* prefix) {
    if (root == NULL || prefix == NULL) return false;

    if (root->child == NULL) return false;

    struct TrieNode *p = root->child;

    while (p && *prefix != '\0') {
        if (p->val == *prefix) {
            p = p->child;
            prefix++;
        }
        else {
            p = p->sibling;
        }
    }

    if (p && *prefix == '\0') return true;
    else return false;
}

void trieFree(struct TrieNode* root) {
    if (root == NULL) return;

    /* Post order traversal (recursive) */
    trieFree(root->child);
    trieFree(root->sibling);
    free(root);
}

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

/* 52 ms, a bit slow */
void dfs(char** board, int boardRowSize, int boardColSize,
         bool** visited, int i, int j,
         char* word, int depth,
         struct TrieNode* trie,
         char **ans, int* returnSize) {

    if (i >= 0 && i < boardRowSize && j >= 0 && j < boardColSize && !visited[i][j]) {
        word[depth] = board[i][j];
        word[depth + 1] = '\0';
        visited[i][j] = true;
        if (startsWith(trie, word)) {
            if (search(trie, word)) {
                int k;
                bool flag = false;
                for (k = 0; k < *returnSize; k++) {
                    if (strcmp(ans[k], word) == 0) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) strcpy(ans[(*returnSize)++], word);
            }
            depth++;
            dfs(board, boardRowSize, boardColSize, visited, i, j - 1, word, depth, trie, ans, returnSize); /* left */
            dfs(board, boardRowSize, boardColSize, visited, i, j + 1, word, depth, trie, ans, returnSize); /* right */
            dfs(board, boardRowSize, boardColSize, visited, i - 1, j, word, depth, trie, ans, returnSize); /* up */
            dfs(board, boardRowSize, boardColSize, visited, i + 1, j, word, depth, trie, ans, returnSize); /* down */

        }
        else {
            word[depth] = 0;
        }
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
            buf[0] = board[i][j];
            if (startsWith(trie, buf)) {
                dfs(board, boardRowSize, boardColSize, visited, i, j, buf, 0, trie, ans, returnSize);
                CLEAR2D(visited, boardRowSize, boardColSize);
            }
            memset(buf, 0, bufSize);
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
