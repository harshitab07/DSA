/*
? Question Link : https://practice.geeksforgeeks.org/problems/k-sum-paths/1

? Question Title:  K Sum Paths

Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//{ Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// } Driver Code Ends

//! MAIN FUNCTION STARTS 
class Solution
{
    public:
      void solve(Node *root, int k, int &count, vector<int> path) {
        if (root == NULL) return;
        
        // add data of current root in path
        path.push_back(root -> data);
        
        // call for left subnode
        solve(root -> left, k, count, path);

        // call for right subnode
        solve(root -> right, k, count, path);
        
        // Once NULL is reached (i.e., path completed)
        // * now data of each node is in vector path
        // * find sum and compare it with k
        int size = path.size();
        int sum = 0;
        for(int i = size - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) count++;
        }
        
        // while going back from a node, keep removing its data from path
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here
        int count = 0;
        vector<int> path;
        
        solve(root, k, count, path);
        
        return count;
    }
};
//! MAIN FUNCTION ENDS 

int main() {
    cout << "Enter number of test cases: ";
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        cout << "Enter tree values: " << flush;
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << "Enter value of k: " << flush;
        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << "kth sum path: ";
        cout << ob.sumK(root, k) << endl;
    }

    return 0;
}

// } Driver Code Ends