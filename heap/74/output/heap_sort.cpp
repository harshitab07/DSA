/*
Lets say given heap is max heap;

1. Swap root with last
2. size--
3. Take root node to its correct position
4. Repeat 1 - 3 while size != 0
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

        if (left <= n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
    int size = n;

    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
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

    cout << "Before Sorting: ";

    for(int i = 1; i <=n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "After Sorting: ";

    h.heapSort(arr, n);
    for(int i = 1; i <=n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}