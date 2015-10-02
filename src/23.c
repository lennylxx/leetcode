#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * Suppose we have k lists, every list have n nodes.
 * Use a min-heap of which size is k, heapify and take the root of heap.
 * Then fill the next node of the taken node into heap, reheap.
 * If we reach the end of one list, decrease heap size by 1.
 * Repeat until the heap size is 0.
 * Time of reheap is O(logk)
 * We have k*n nodes, so T(n) = k*n*O(logk) = O(n*klogk)
 */

/* Data structures and helper function declarations. */
struct HeapNode {
    struct ListNode *ptr;
    int group; /* no use in this method */
};
void swap(struct HeapNode *a, struct HeapNode *b);
int comp(struct HeapNode a, struct HeapNode b);
void heapify(struct HeapNode *heap, int size); /* min heap */
void siftUp(struct HeapNode *heap, int size);
void reheap(struct HeapNode *heap, int size);
void printheap(struct HeapNode *heap, int size);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) return NULL;

    struct HeapNode *heap
        = (struct HeapNode *)malloc(listsSize * sizeof(struct HeapNode));

    int i;
    for (i = 0; i < listsSize; i++) {
        heap[i].ptr = lists[i];
        heap[i].group = i; /* just initialize, useless */
    }

    heapify(heap, listsSize);

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *p = dummy;
    while (listsSize && p) {
        p->next = heap[0].ptr;
        p = p->next;

        if (heap[0].ptr && heap[0].ptr->next != NULL) {
            heap[0].ptr = heap[0].ptr->next;
        }
        else {
            swap(&heap[0], &heap[listsSize - 1]);
            listsSize--;
        }

        reheap(heap, listsSize);
    }
    if (p)
        p->next = NULL;

    p = dummy->next;
    free(dummy);
    free(heap);

    return p;
}

void swap(struct HeapNode *a, struct HeapNode *b) {
    struct ListNode *t_ptr = a->ptr;
    int t_group = a->group;
    a->group = b->group;
    a->ptr = b->ptr;

    b->group = t_group;
    b->ptr = t_ptr;
}

int comp(struct HeapNode a, struct HeapNode b) {
    if (a.ptr == NULL && b.ptr == NULL) {
        return 0;
    }
    else if (a.ptr && b.ptr == NULL) {
        return -1;
    }
    else if (a.ptr == NULL && b.ptr) {
        return 1;
    }

    if (a.ptr->val == b.ptr->val) {
        return 0;
    }
    else if (a.ptr->val < b.ptr->val) {
        return -1;
    }
    else return 1;
}

void heapify(struct HeapNode *heap, int size) {
    int i;
    for (i = 1; i <= size; i++) {
        siftUp(heap, i);
    }
}

void siftUp(struct HeapNode *heap, int size) {
    int child, parent;
    child = size - 1;
    while (child > 0) {
        parent = (child - 1) / 2;
        if (comp(heap[parent], heap[child]) > 0) {
            swap(&heap[parent], &heap[child]);
        }
        child = parent;
    }
}

void reheap(struct HeapNode *heap, int size) {
    int parent, child, right;
    parent = 0;
    child = 1;
    while (child < size) {
        right = child + 1;
        if (right < size && comp(heap[child], heap[right]) > 0) {
            child = right;
        }
        if (comp(heap[parent], heap[child]) <= 0) break;

        swap(&heap[parent], &heap[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}

void printheap(struct HeapNode *heap, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i].ptr) {
            printf("%d ", heap[i].ptr->val);
        }
        else {
            printf("NIL ");
        }
    }
    printf("\n");
}

/*
 * Suppose we have k lists, every list have n nodes.
 * Make them to k/2 groups, merge two lists in every group.
 * Then group them in k/4, then merge two lists in every group.
 * Repeat until there is one group left.
 * T(n) += 2n + 2n + ... + 2n = (k/2)*2n = kn
 * T(n) += 4n + 4n + ... + 4n = (k/4)*4n = kn
 * ...
 * T(n) += 2 * (k/2)n = kn
 * So, T(n) = kn * logk = O(n*klogk)
 */

struct WorkNode {
    struct ListNode *ptr;
    struct WorkNode *next;
};

struct ListNode* merge2Lists(struct ListNode *headA, struct ListNode *headB);

struct ListNode* mergeKLists0(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) return NULL;

    if (listsSize == 1) return lists[0];

    struct WorkNode *work
        = (struct WorkNode *)calloc(listsSize, sizeof(struct WorkNode));

    int i;
    for (i = 0; i < listsSize; i++) {
        work[i].ptr = lists[i];
        work[i].next = &work[i + 1];
    }
    work[listsSize - 1].next = NULL;

    struct WorkNode *p = work;
    struct WorkNode *tail = &work[listsSize - 1];
    struct WorkNode *first, *second;

    while (p) {
        first = p;
        second = p->next;
        p = p->next;
        if (p) p = p->next;

        first->ptr = merge2Lists(first->ptr, second->ptr);
        first->next = NULL;
        tail->next = first;
        tail = first;
    }

    struct ListNode *final = tail->ptr;

    free(work);

    return final;
}

struct ListNode* merge2Lists(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL) return headB;
    if (headB == NULL) return headA;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *t = dummy;
    struct ListNode *p = headA;
    struct ListNode *q = headB;

    while (p && q) {
        if (p->val <= q->val) {
            t->next = p;
            p = p->next;
        }
        else {
            t->next = q;
            q = q->next;
        }
        t = t->next;
    }

    while (p) {
        t->next = p;
        p = p->next;
        t = t->next;
    }

    while (q) {
        t->next = q;
        q = q->next;
        t = t->next;
    }

    t = dummy->next;
    free(dummy);

    return t;
}

struct ListNode* generateList(int *nums, int size) {
    if (nums == NULL || size == 0) return NULL;

    struct ListNode *list
        = (struct ListNode *)malloc(size * sizeof(struct ListNode));
    struct ListNode **p = &list;

    int i;
    for (i = 0; i < size; i++) {
        (*p)->val = nums[i];
        (*p)->next = *p + 1;
        p = &((*p)->next);
    }
    *p = NULL;

    return list;
}

int main() {
    int k = 7;
    struct ListNode **lists
        = (struct ListNode **)calloc(k, sizeof(struct ListNode*));

    int n0[] = {-10,-9,-9,-3,-1,-1,0};
    int n1[] = {-5};
    int n2[] = {4};
    int n3[] = {-8};
    int n4[] = {};
    int n5[] = {-9,-6,-5,-4,-2,2,3};
    int n6[] = {-3,-3,-2,-1,0};

    lists[0] = generateList(n0, sizeof(n0) / sizeof(int));
    lists[1] = generateList(n1, sizeof(n1) / sizeof(int));
    lists[2] = generateList(n2, sizeof(n2) / sizeof(int));
    lists[3] = generateList(n3, sizeof(n3) / sizeof(int));
    lists[4] = generateList(n4, sizeof(n4) / sizeof(int));
    lists[5] = generateList(n5, sizeof(n5) / sizeof(int));
    lists[6] = generateList(n6, sizeof(n6) / sizeof(int));

    struct ListNode *p;
    int i;

    printf("Lists: \n");
    for (i = 0; i < k; i++) {
        p = lists[i];
        while (p) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("NIL\n");
    }

    p = mergeKLists0(lists, k);

    printf("Merged: \n");
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("NIL\n");

    free(lists);

    return 0;
}
