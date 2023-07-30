// ? 2 x 2 matrix, {{0, 0, 0}, {1, 0, 0}, {1, 0 ,0}} is given which tells who knows whom; Find out who is celebrity; A celebrity is the one who knows no one but everyone knows celebrity

#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int celebrity(vector<vector<int>> &M, int n) {
    // Step 1. Create stack and Push all people, i.e., 0 to n-1
    stack<int> s;
    for (int i=0; i<n; i++) {
        s.push(i);
    }
    
    /*
    step 2: While s.size is > 1, pop out 2 elements, A and B and compare them;
    If a knoes B, push B; else push A
    */
    while(s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        
        if(M[a][b] == 1) s.push(b); // a knows b
        else s.push(a);
    }
    
    /*
    Step 3: Now only one element is left in stack and it can be a potential candidate.
    To verify :
    All row elements must be 0
    All col elements, except diagonal must be one
    */
    
    int ans = s.top();
    int zero = 0;
    int one = 0;
    
    for(int i=0; i<n; i++) {
        if(M[ans][i] == 0) zero++;
        if(M[i][ans] == 1) one++;
    }
    
    if(zero == n && one == n-1) return ans;
    
    return -1;
}

int main() {
    vector<vector<int>> v = {{0, 0, 0}, {1, 0, 0}, {1, 0 ,0}};
    int ans = celebrity(v, 3);
    
    cout << ans;
    
    return 0;
}