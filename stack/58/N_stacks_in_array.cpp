// ? Design a data structure on N stacks in one single array
// * push(x,m) -> pushes elements x in Mth stack and return true if pushed, else false
// * pop(m) -> pops element from Mth stack and return that element, if not popped, returns -1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NStack
{
        int n, s;
        int *arr, *top, *next;
        int freeSpot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.

            n = N; s = S;

            arr = new int[s]; // size of array = s
            top = new int[n]; // number of stacks = n
            next = new int[s];

            for(int i=0; i<n; i++) {
                top[i] = -1;
            }

            for(int i=0; i<s; i++) {
                next[i] = i+1;
            }
            next[s-1] = -1;

            freeSpot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check if overflow
            if(freeSpot == -1) return false;
            // 1. find index
            int index = freeSpot; // 0
            // 2. update freeSpot
            freeSpot = next[index]; // 1
            // 3. insert x in arr at founded index
            arr[index] = x; // arr[0] = x
            // 4. update next
            next[index] = top[m-1]; // next[0] = -1; indicating, if x is removed them stack will be empty
            // 5. update top
            top[m-1] = index; // top[m-1] = 0

            return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Reverse of push

        // check if underflow
        if(top[m-1] == -1) return -1;
        // 1. find index from where to pop, i.e., value of top
        int index = top[m-1];
        // 2. update top
        top[m-1] = next[index];
        // 3. Since element has been removed, update next
        next[index] = freeSpot;
        // 4. update freeSpot
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    NStack s(3, 6);
    cout << s.push(1, 1) << endl;
    cout << s.push(2, 2) << endl;
    cout << s.push(3, 3) << endl;
    cout << s.pop(2) << endl;
}