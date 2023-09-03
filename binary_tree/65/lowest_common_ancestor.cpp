/*
? Question Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

? Question Title:  Sum of nodes on the longest path from root to leaf node

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 

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
    //Function to return the lowest common ancestor in a Binary Tree
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       // base case
       if (root == NULL) {
           return NULL;
       }
       
       if(root ->data == n1 || root->data == n2) {
           return root;
       }
       
       Node* leftAns = lca(root -> left, n1, n2);
       Node* rightAns = lca(root -> right, n1, n2);
       
       if(leftAns != NULL && rightAns != NULL) {
           return root;
       }
       
       if(leftAns != NULL && rightAns == NULL) {
           return leftAns;
       }
       
       if(leftAns == NULL && rightAns != NULL) {
           return rightAns;
       }
       
       if(leftAns == NULL && rightAns == NULL) {
           return NULL;
       }
       
    }
};
//! MAIN FUNCTION ENDS 

int main() {
    int a, b, t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "Enter n1 and n2 values: ";
        cin >> a >> b;
        cin.ignore(); // Clear newline character

        cout << "Enter tree values: " << flush;
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        cout << "Lowest common ancestor for " << a << " and " << b << " is: ";
        cout << ob.lca(root, a, b)->data << endl;
    }

    return 0;
}

// } Driver Code Ends