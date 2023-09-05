/*
? Heap is a Complete Binary Tree (CBT) which comes with heap order properties.
CBT is a type of Binary tree in which each level is completely filled, except the last level.
In this, nodes are added from left.

? Heap Order Property
1. Max Heap
2. Min Heap

-> Max Heap :
Children of each node always lesser than node

-> Min Heap :
Children of each node always greater than node

? Insertion
* T.C = O(log n)

* Left node is at i index, then
Left child of node will be at (2 * i) index.
Right child of the node is at (2 * i) + 1 index.

* Parent of each child is at (i / 2) index.

? Deletion
* T.C = O(log n)

1. Set first node = last node.
2. Remove last node
3. Propagate root node to its correct position
- Keep on swapping with its largest child
*/

#include <iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[size] = val;

        while(index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size) {
            int leftIndex = 2 * i;
            int rightIndex = ( 2 * i ) + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteHeap();
    h.print();

    return 0;
}