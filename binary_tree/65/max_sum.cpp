/*
? Question Link : https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
? Question Title:  Maximum sum of Non-adjacent nodes

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/

#include <bits/stdc++.h>
using namespace std;

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

//! MAIN FUNCTION STARTS 
class Solution{
    private:
    pair<int, int> solve(Node *root) {
        if(root == NULL) {
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> leftAns = solve(root -> left);
        pair<int, int> rightAns = solve(root -> right);
        
        pair<int, int> result;
        result.first = root->data + leftAns.second + rightAns.second;
        result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return result;
    }
  public:
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};
//! MAIN FUNCTION ENDS 

int main()
{
  int t;
  cout << "Enter number of test cases: ";
  cin >> t;
  cin.ignore();

  while (t--)
  {
    cout << "Enter tree: ";
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    cout << "Max sum of non adjacent nodes is ";
    cout << ob.getMaxSum(root) << endl;
  }
  return 0;
}