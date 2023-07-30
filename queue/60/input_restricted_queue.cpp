/*
? Input restricted queues :
-> Push from one side only
   pushBack(value) // push at rear
-> Pop from both the sides
   popFront() and popBack()

? Output restricted queues :
-> Pop from one side only
   popFront(value) // pop from front
-> Push from both the sides
   pushFront() and pushBack()

? Doubly ended queue :
-> Push and pop from both sides
   pushBack(value) & pushFront(value)
   popBack() & popFront()

-> Can be used to implement both queue and stack.
-> Basic application of queue => CPU scheduling, Process scheduling
-> STL ::  dequeue<int> dq;
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(12);
    dq.push_back(13);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.pop_front();
    cout << dq.front() << endl;

return 0;
}