#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> q;
    
    q.push(1);
    
    q.push(15);
    
    cout << "Size of queue : "<< q.size() <<endl;
    
    q.pop();
    
    cout << "Size of queue : "<< q.size() <<endl;
    
    q.pop();
    
    cout << "Is queue empty? "<< q.empty() <<endl;
    
    q.push(16);
    q.push(2);
    q.push(3);
    
    cout << "First element : "<< q.front() <<endl;
    
    q.pop();
    
    cout << "First element : "<< q.front() <<endl;
    
    q.push(19);
    
    cout << "First element : "<< q.front() <<endl;
    return 0;
}
