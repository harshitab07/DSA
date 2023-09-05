/*
? Leaf nodes in CBT lie from (n/2 + 1) to n.

? No need to process leaf nodes, they are Heap in themselves already

? Process nodes from n/2 to 1
* Heapify function
Takes node to its correct index
T.C = O(n)
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

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = (2 * i) + 1;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
};

int main() {
    heap h;

    int arr[6] = { -1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n / 2; i>0; i--) {
        h.heapify(arr, n, i);
    }

    cout << "Printing array after hepifycation: "<< endl;

    for(int i = 1; i <=n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}