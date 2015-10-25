#include <iostream>

using namespace std;

class MedianFinder {
    static const int MAXN = 102400;
    int maxHeap[MAXN]; // store the smaller half
    int minHeap[MAXN]; // store the bigger half
    int max_heap_size = 0;
    int min_heap_size = 0;
    double medium = 0;

    void addheap(int *heap, int &size, int data) {
        if (size < MAXN - 1) {
            heap[size] = data;
            size++;
        }
    }

    void siftUpMax() {
        int parent, child;
        child = max_heap_size - 1;
        while (child > 0) {
            parent = (child - 1) / 2;
            if (maxHeap[parent] < maxHeap[child])
                swap(maxHeap[parent], maxHeap[child]);
            child = parent;
        }
    }

    void siftDownMax() {
        int parent, child;
        parent = 0; child = 1;
        while (child < max_heap_size) {
            if (child + 1 < max_heap_size && maxHeap[child] < maxHeap[child + 1])
                child = child + 1;

            if (maxHeap[parent] >= maxHeap[child]) break;
            swap(maxHeap[parent], maxHeap[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }

    void siftUpMin() {
        int parent, child;
        child = min_heap_size - 1;
        while (child > 0) {
            parent = (child - 1) / 2;
            if (minHeap[parent] > minHeap[child])
                swap(minHeap[parent], minHeap[child]);
            child = parent;
        }
    }

    void siftDownMin() {
        int parent, child;
        parent = 0; child = 1;
        while (child < min_heap_size) {
            if (child + 1< min_heap_size && minHeap[child] > minHeap[child + 1])
                child = child + 1;

            if (minHeap[parent] <= minHeap[child]) break;
            swap(minHeap[parent], minHeap[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (max_heap_size == min_heap_size) {
            if (num > medium) {
                addheap(minHeap, min_heap_size, num);
                siftUpMin();
                medium = minHeap[0];
            }
            else {
                addheap(maxHeap, max_heap_size, num);
                siftUpMax();
                medium = maxHeap[0];
            }
        }
        else {
            if (num > minHeap[0]) {
                addheap(minHeap, min_heap_size, num);
                siftUpMin();
                if (min_heap_size >= max_heap_size + 2) {
                    addheap(maxHeap, max_heap_size, minHeap[0]);
                    siftUpMax();
                    swap(minHeap[0], minHeap[min_heap_size - 1]);
                    min_heap_size--;
                    siftDownMin();
                }
            }
            else {
                addheap(maxHeap, max_heap_size, num);
                siftUpMax();
                if (max_heap_size >= min_heap_size + 2) {
                    addheap(minHeap, min_heap_size, maxHeap[0]);
                    siftUpMin();
                    swap(maxHeap[0], maxHeap[max_heap_size - 1]);
                    max_heap_size--;
                    siftDownMax();
                }
            }
            medium = maxHeap[0] + (minHeap[0] - maxHeap[0]) / 2.0;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return medium;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    cout << mf.findMedian() << endl;
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    mf.addNum(4);
    cout << mf.findMedian() << endl;
    mf.addNum(5);
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(7);
    cout << mf.findMedian() << endl;
    mf.addNum(8);
    cout << mf.findMedian() << endl;
    mf.addNum(9);
    cout << mf.findMedian() << endl;
    mf.addNum(10);
    cout << mf.findMedian() << endl;

    return 0;
}
