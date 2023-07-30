/*
Initially, front = rear = -1;

pushFront() ?
-> if Full() return false;
-> 1st element? (front ==- 1) front = rear = 0; arr[front] = value;
-> if (front = 0) front = n-1; arr[front] = value;
-> else, front--; arr[front] = value;

popBack() ?
-> is Empty? return false;
-> Single element? (front==rear) front = rear =-1;
-> if (rear == 0) rear = n-1;
-> else, rear--;
*/

#include <iostream>
using namespace std;

class Deque
{
    int *arr, rear, front, size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // 1. is full?

        if (isFull())
        {
            return false;
        }

        // 2. inserting 1st?
        if (front == -1)
        {
            front = rear = 0;
        }

        // 3. cyclic nature : front == 0?
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }

        else
        {
            front--;
        }

        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // 1. is full?

        if (isFull())
        {
            return false;
        }

        // 2. inserting 1st?
        if (front == -1)
        {
            front = rear = 0;
        }

        // 3. cyclic nature : front == 0?
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // 1. is empty?
        if (front == -1)
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        // 2. only single element present?
        if (front == rear)
        {
            front = rear = -1;
        }

        // 3. cyclic nature?
        else if (front == size - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // 1. is empty?
        if (front == -1)
            return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        // 2. only single element present?
        if (front == rear)
        {
            front = rear = -1;
        }

        // 3. cyclic nature?
        else if (rear == 0)
        {
            rear = size - 1;
        }

        else
        {
            rear--;
        }

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // empty?
        if (front == -1)
            return -1;

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // empty?
        if (front == -1)
            return -1;

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Deque dq(4);
    cout << "Front push? " << dq.pushFront(23) << endl;
    cout << "Back push? " << dq.pushRear(24)  << endl;
    cout << "Front push? " << dq.pushFront(22)  << endl;
    cout << "Back push? " << dq.pushRear(25)  << endl;
    cout << "Back push? " << dq.pushRear(26)  << endl;
    cout << "Front pop? " << dq.popFront()  << endl;
    cout << "Back pop? " << dq.popRear()  << endl;
    cout << "Is empty? " << dq.isEmpty()  << endl;
    cout << "Is full? " << dq.isFull()  << endl;
    cout << "1st? " << dq.getFront()  << endl;
    cout << "Last? " << dq.getRear()  << endl;

    return 0;
}