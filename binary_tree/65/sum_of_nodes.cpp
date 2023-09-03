/*
? Question Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

? Question Title:  Sum of nodes on the longest path from root to leaf node

Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Input:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
Output: 13
Explanation:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6

The highlighted nodes (4, 2, 1, 6) above are
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13

*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
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

class Solution
{
public:

//! MAIN FUNCTION STARTS 

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    if (root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root -> data;

    solve(root -> left, sum, maxSum, len + 1, maxLen);
    solve(root -> right, sum, maxSum, len + 1, maxLen);
}
int sumOfLongRootToLeafPath(Node *root)
{
        int sum = 0;
        int maxSum = INT_MIN;

        int len = 0;
        int maxLen = 0;

        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
}
};

//! MAIN FUNCTION ENDS

//{ Driver Code Starts.
int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends