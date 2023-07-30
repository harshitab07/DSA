// ? If redundant brackets are present in the string of a valid mathematical expression : ( a + (b * c) ), return true, else false;

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string redundantBrackets(string &s) {
    stack <char> st;
    
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            if (ch == ')') {
                string redundancy = "true";
                while(st.top() != '(') {
                    char c = st.top();
                    if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/') redundancy = "false";
                    st.pop();
                }
                if (redundancy == "true") return "true";
                st.pop();
            }
        }
    }
    return "false";
}

int main() {
    string s = "( a + (b * c) )";
    cout << "String " << s << " is redundant? "<< redundantBrackets(s);
}