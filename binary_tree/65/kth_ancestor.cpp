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
    void solve(Node *root, int k, int node, vector<int> &path) {
    if (root == NULL) return;
    
    path.push_back(root -> data);
    
    solve(root -> left, k, node, path);
    solve(root -> right, k, node, path);
    
    if(path.back() == node) return;

    path.pop_back();
    }

    int kthAncestor(Node *root, int k, int node)
    {
        vector<int> path;
        solve(root, k, node, path);
        if(path.size() > k) return path[path.size() - 1 - k];
        return -1;
    }
//! MAIN FUNCTION ENDS 

int kthAncestor(Node *root, int k, int node);

int main()
{
  int t;
  cout << "Enter number of test cases: ";
  cin >> t;
  cin.ignore();
    while(t--)
    {
        int k , node;
        cout<< "Enter value for k and node:"<<endl;
        cin >> k;
        cin >> node;
        cin.ignore();
        cout << "Enter tree: ";
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        cout<< "Ancestor is ";
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends