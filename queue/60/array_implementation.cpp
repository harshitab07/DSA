#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int size; // size of array
    int qfront;
    int rear;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) cout << "Queue is full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (rear == qfront) return -1;
        
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;

        if(qfront == rear) {
            qfront = 0;
            rear = 0;
        }

        return ans;
    }

    bool isEmpty() {
        if (qfront == rear) {
            return true;
        }

        return false;
    }
};

int main() {
    Queue q(4);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    
    cout << "popped? " << q.dequeue() <<endl;
    
    cout << "empty? " << q.isEmpty() <<endl;
    
    return 0;
}