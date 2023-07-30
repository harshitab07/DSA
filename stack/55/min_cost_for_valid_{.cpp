// ? Tell minimum cost to make "{}}{}}" a valid string, i.e., "{}{{}}";
// Only one bracket needs to be turned, so cost will be 1
#include <iostream>
#include <stack>
using namespace std;

int minimumBracketCost(string &s) {
    stack <char> st;
    
    if (s.length()%2 != 0) return -1;
    
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '{') {
            st.push(ch);
        }
        else {
            if (!st.empty() && st.top() == '{') st.pop(); // removed valid part
            else st.push(ch);
        }
    }
    
    int a = 0, b = 0;
    
    while(!st.empty()) {
        if(st.top() == '{') a++;
        else b++;
        st.pop();
    }
    
    return (((a+1)/2) + ((b+1)/2));
}

int main() {
    string s = "{}}{}}";
    cout << "Cost for " << s << " to become valid? "<< minimumBracketCost(s);
}