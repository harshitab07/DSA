// ? Design a stack such that it can perform pop(), push(), top(), getMin() operations in O(n) time

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    // define data members
    stack<int> s;
    int mini;
    public:
        
    void push(int data) {
        // for first element

        if(s.empty()) {
            s.push(data);
            mini = data;
        }

        else {
            if(data < mini) {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    void pop() {
        // check underflow
        if(s.empty()) return;

        int curr = s.top();
        s.pop();
        int top;
        if(curr > mini) {
            top = curr;
        } else {
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            top = prevMini;
        }
    }

    int top() {
        if(s.empty()) return -1;

        int curr = s.top();

        if(curr< mini) {
            return mini;
        } else {
            return curr;
        }
    }

    int getMin() {
        if(s.empty()) return -1;

        return mini;
    }  
};

int main() {
    SpecialStack s;
    s.push(4);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(9);
    s.push(-2);
    cout << "Top : "<< s.top() << endl;
    cout << "Mini : "<< s.getMin() << endl;
    s.pop();
    cout << "Top : "<< s.top() << endl;
    cout << "Mini : "<< s.getMin() << endl;
    
    return 0;
}