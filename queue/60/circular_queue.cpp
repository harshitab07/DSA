/*
initially, front = rear = -1

push :
1. if (full) queue is full full -> (front == 0 && rear = size-1) || (rear == (front-1)%(size-1));
2. if (front == -1) queue is empty -> inserting 1st element, so front++; rear++; arr[front] = data;
3. if(rear == -1 && front != 0) rear = 0; arr[rear] = data;
4. Else, rear++; arr[rear] = data;

pop:
1. Empty? front == -1
2. Single element? (front == rear) -> front=rear=-1
3. Front at last (front == n-1) -> front = 0
4. Else, front++;
*/

#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {

        // 1. is full?
        bool isFull = (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
        if (isFull)
            return false;

        // 2. Adding 1st element?
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        // 3. Rear at end?? But queue not full
        else if (rear == (size - 1) && front != 0)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // 1. empty?
        if (front == -1)
            return -1;

        int ans = arr[front];
        arr[front] = -1;
        // 2. Single element?
        if (front == rear)
        {
            front = rear = -1;
        }

        // 3. Front at end?
        else if (front == (size - 1))
        {
            front = 0;
        }

        else
        {
            front++;
        }

        return ans;
    }
};

int main()
{

    CircularQueue q(5);

    cout << "Pushed? " << q.enqueue(7) << endl;

    cout << "Pushed? " << q.enqueue(8) << endl;

    cout << "Pushed? " << q.enqueue(9) << endl;

    cout << "Pushed? " << q.enqueue(6) << endl;

    cout << "Pushed? " << q.enqueue(5) << endl;

    cout << "Pushed? " << q.enqueue(4) << endl;

    cout << "Popped value? " << q.dequeue() << endl;

    cout << "Pushed? " << q.enqueue(2) << endl;

    cout << "Popped value? " << q.dequeue() << endl;

    return 0;
}