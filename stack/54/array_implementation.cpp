// ? Stack implementation using Array

#include <iostream>
using namespace std;

class Stack {
    public:
    int *arr; int top; int size;
    
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    
    void push(int element) {
        if(size-top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"Stack overflow"<<endl;
        }
    }
    
    void pop() {
        if(top>= 0) {
            top--;
        }
        else {
            cout<<"Stack underflow"<<endl;
        }
    }
    
    int peek() {
        if (top >=0 && top<size)
        return arr[top];
        
        cout<<"Stack empty"<<endl;
    }
    
    bool empty() {
        if(top == -1) return true;
        return false;
    }
    
    void print(int size) {
        int i = top;
        
        while(i>=0) {
            cout<<arr[i]<<" ";
            i--;
        }
    }
};

int main() {
    Stack s(5);
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);
    
    s.print(5);
    
    return 0;
}