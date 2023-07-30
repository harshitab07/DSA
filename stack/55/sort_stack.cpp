// ? SORT a Stack : 3 -7 9 -2 5

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void sortedInsert(stack<int> &s, int num) {
    // bae case
    if(s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    // recurssive call
    sortedInsert(s, num);
    // once inserted, push back all the elements that were taken out
    s.push(n);
}

void sortStack(stack<int> &s) {
    // base case
    if(s.empty()) {
        return;
    }
    
    int num = s.top();
    s.pop();
    
    // recursive call
    sortStack(s);
    
    // once stack is empty, start filling it in sorted manner
    sortedInsert(s, num);
}

void printStack (stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);
    
    printStack(s);
    
    sortStack(s);
    printStack(s);
    
    return 0;
}
