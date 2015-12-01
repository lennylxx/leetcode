#include <stdio.h>
#include <stdlib.h>

/**
    Run time: 28 ms.
    I use a "double" double-linked list.
    A double-linked list to store key value pair, and other two pointers are
    used to implement "Separate chaining" method of hash table.
    Time of insertion and deletion of node are both O(1).

    It's like this one, but all the links between two nodes are two-ways.
    http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
 */

struct node_t {
    int key;
    int value;
    struct node_t *prev;
    struct node_t *next;
    struct node_t *hash_prev;
    struct node_t *hash_next;
};

struct lru_t {
    int size;
    int capacity;
    struct node_t *head;
    struct node_t *tail;
    struct node_t **hash_table;
} m_lru;

int hash(int key) {
    int index = key % m_lru.capacity;
    return index > 0 ? index : (-index);
}

struct node_t* findAndAdjust(int key) {
    int index = hash(key);
    struct node_t *p = m_lru.hash_table[index];
    while (p) {
        if (p->key == key) {
            break;
        }
        p = p->hash_next;
    }

    /* found, take it and insert to the head of double-linked list */
    if (p != NULL) {
        if (m_lru.head != p) { /* p is not head */
            /* take it*/
            p->prev->next = p->next;
            if (p->next != NULL) { /* it's not tail either */
                p->next->prev = p->prev;
            }

            if (m_lru.tail == p) { /* if p is tail */
                m_lru.tail = p->prev;
                m_lru.tail->next = NULL;

                if (m_lru.tail->prev == NULL) {
                    m_lru.tail->prev = p;
                }
            }

            /* make it becomes the new head */
            p->prev = NULL;
            p->next = m_lru.head;
            m_lru.head->prev = p;
            m_lru.head = p;
        }
    }

    return p;
}

void lruCacheInit(int capacity) {
    m_lru.size = 0;
    m_lru.head = m_lru.tail = NULL;

    if (capacity <= 0) {
        m_lru.capacity = 0;
        m_lru.hash_table = NULL;
    }
    else {
        m_lru.capacity = capacity;
        m_lru.hash_table =
            (struct node_t **)calloc(capacity, sizeof(struct node_t *));
    }
}

void lruCacheFree() {
    m_lru.size = 0;
    m_lru.capacity = 0;

    struct node_t *p = NULL;

    while (m_lru.tail) {
        p = m_lru.tail;
        m_lru.tail = p->prev;
        if (m_lru.tail == NULL) {
            break;
        }
        else {
            m_lru.tail->next = NULL;
        }
        free(p);
    }

    free(m_lru.hash_table);

    m_lru.head = m_lru.tail = NULL;
    m_lru.hash_table = NULL;
}

int lruCacheGet(int key) {
    if (m_lru.capacity == 0 || m_lru.hash_table == NULL) return -1;

    struct node_t *p = findAndAdjust(key);

    if (p != NULL) {
        return p->value;
    }
    else {
        return -1;
    }
}

void lruCacheSet(int key, int value) {
    if (m_lru.capacity == 0 || m_lru.hash_table == NULL) return;

    /* check if we already have the value in cache */
    struct node_t *p = findAndAdjust(key);

    if (p != NULL) {
        p->value = value; /* update value */
    }
    else {
        if (m_lru.size == m_lru.capacity) { /* already reaches the capacity */
            if (m_lru.tail != NULL) { /* remove the tail */
                struct node_t *t = m_lru.tail;
                m_lru.tail = m_lru.tail->prev;
                if (m_lru.tail != NULL) {
                    m_lru.tail->next = NULL;
                }

                /* remove old tail's corresponding hash links */
                if (t->hash_prev != NULL) {
                    t->hash_prev->hash_next = t->hash_next;
                    if (t->hash_next != NULL) {
                        t->hash_next->hash_prev = t->hash_prev;
                    }
                }
                else {
                    if (t->hash_next != NULL) {
                        t->hash_next->hash_prev = NULL;
                    }
                    int idx = hash(t->key);
                    m_lru.hash_table[idx] = t->hash_next;
                }

                free(t);
                m_lru.size--;
            }
        }

        struct node_t *new_node =
            (struct node_t *)malloc(sizeof(struct node_t));
        new_node->key = key;
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = m_lru.head;
        new_node->hash_prev = NULL;
        new_node->hash_next = NULL;

        int index = hash(key);

        if (m_lru.size == 0) { /* the list is empty now */
            m_lru.tail = new_node;
        }
        else {
            m_lru.head->prev = new_node;
        }
        m_lru.head = new_node;
        m_lru.size++;

        if (m_lru.hash_table[index]) {
            new_node->hash_next = m_lru.hash_table[index];
            m_lru.hash_table[index]->hash_prev = new_node;
        }
        m_lru.hash_table[index] = new_node;
    }
}

void print() {
    struct node_t *p = m_lru.head;
    while (p) {
        printf("(%d, %d) ", p->key, p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    printf("first test\n");
    lruCacheInit(2);

    lruCacheSet(2, 1);
    print();
    lruCacheSet(1, 1);
    print();

    lruCacheGet(2);
    print();

    lruCacheSet(4, 1);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();

    printf("second test\n");
    lruCacheInit(2);

    lruCacheSet(2, 1);
    print();
    lruCacheSet(1, 1);
    print();

    lruCacheSet(2, 3);
    print();

    lruCacheSet(4, 1);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();

    lruCacheFree();

    printf("third test\n");
    lruCacheInit(3);

    lruCacheSet(1, 1);
    print();
    lruCacheSet(2, 2);
    print();
    lruCacheSet(3, 3);
    print();
    lruCacheSet(4, 4);
    print();

    lruCacheGet(4);
    print();
    lruCacheGet(3);
    print();
    lruCacheGet(2);
    print();
    lruCacheGet(1);
    print();

    lruCacheSet(5, 5);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();
    lruCacheGet(3);
    print();
    lruCacheGet(4);
    print();
    lruCacheGet(5);
    print();

    lruCacheFree();

    printf("all tests passed!\n");

    return 0;
}
