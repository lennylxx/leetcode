#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* I implement Trie using left-child right-sibling binary tree.              */
/* https://en.wikipedia.org/wiki/Left-child_right-sibling_binary_tree        */
/* It's not an easy way, the code may not be so elegant.                     */
/* We can use an array each node to store the children pointers in easy way. */

struct TrieNode {
    char val;
    struct TrieNode *child;   /* most left child */
    struct TrieNode *sibling; /* brothers of the current child*/
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode *dummy = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    dummy->val = '\0';
    dummy->child = NULL;
    dummy->sibling = NULL;

    return dummy;
}

/**
 *  Iterative Method
 */

/** Inserts a word into the trie. */
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

/** Returns if the word is in the trie. */
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

/** Returns if there is any word in the trie
    that starts with the given prefix. */
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

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if (root == NULL) return;

    /* Post order traversal (recursive) */
    trieFree(root->child);
    trieFree(root->sibling);
    free(root);
}

/**
 *  Recursive Method (insert, search and startWith)
 */

void insert_r(struct TrieNode* root, char* word) {
    if (root == NULL || word == NULL) return;

    if (root->child != NULL) {
        if (root->child->val == *word) {
            if (*word == '\0') return;
            insert_r(root->child, word + 1);
        }
        else {
            /* get most right sibling */
            struct TrieNode **p = &(root->child->sibling);
            while (*p) {
                if ((*p)->val == *word) {
                    if (*word == '\0') return;
                    insert_r(*p, word + 1);
                    return;
                }
                p = &((*p)->sibling);
            }

            struct TrieNode *new_node
                = (struct TrieNode *)malloc(sizeof(struct TrieNode));
            new_node->val = *word;
            new_node->child = NULL;
            new_node->sibling = NULL;

            *p = new_node;

            if (*word == '\0') return;
            insert_r(*p, word + 1);
        }
    }
    else {
        /* if the child is NULL, the sibling must be NULL too */
        /* so we don't need to check that.                    */
        struct TrieNode *new_node
            = (struct TrieNode *)malloc(sizeof(struct TrieNode));
        new_node->val = *word;
        new_node->child = NULL;
        new_node->sibling = NULL;

        root->child = new_node;
        if (*word == '\0') return;
        insert_r(root->child, word + 1);
    }
}

bool search_r(struct TrieNode* root, char* word) {
    if (root == NULL || word == NULL) return false;

    if (root->child == NULL) return false;

    if (root->child->val == *word) {
        if (*word == '\0') return true;
        else return search_r(root->child, word + 1);
    }
    else {
        struct TrieNode *p = root->child->sibling;
        while (p) {
            if (p->val == *word) {
                if (*word == '\0') return true;
                else return search_r(p, word + 1);
            }
            p = p->sibling;
        }
        return false;
    }
}

bool startsWith_r(struct TrieNode* root, char* prefix) {
    if (root == NULL || prefix == NULL) return false;

    if (root->child == NULL) return false;

    if (*prefix == '\0') return true;

    if (root->child->val == *prefix) {
        return startsWith_r(root->child, prefix + 1);
    }
    else {
        struct TrieNode *p = root->child->sibling;
        while (p) {
            if (p->val == *prefix) {
                return startsWith_r(p, prefix + 1);
            }
            p = p->sibling;
        }
        return false;
    }
}

int main() {

    struct TrieNode* node = trieCreate();

    assert(search(node, "some") == false);
    insert(node, "s");
    assert(search(node, "some") == false);
    assert(search(node, "s0") == false);

    insert(node, "some");
    assert(search(node, "some") == true);

    insert(node, "somestring");
    insert(node, "someword");
    insert(node, "word");

    assert(search(node, "word") == true);
    assert(search(node, "somestring") == true);
    assert(search(node, "someword") == true);
    assert(search(node, "somew") == false);
    assert(search(node, "somes") == false);
    assert(search(node, "somex") == false);

    assert(startsWith(node, "some") == true);
    assert(startsWith(node, "somew") == true);
    assert(startsWith(node, "somes") == true);
    assert(startsWith(node, "somex") == false);

    trieFree(node);
    
    printf("all tests passed!\n");

    return 0;
}
