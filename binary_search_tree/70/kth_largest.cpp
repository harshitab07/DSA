/*
? Question Link : https://www.codingninjas.com/studio/problems/k-th-largest-number_920438?leftPanelTab=1

? Question Title:  Find K-th largest Element in BST
*/

using namespace std;
#include <bits/stdc++.h> 

int solve(TreeNode<int>* root, int k, int &i, int size) {
if(root == NULL) {
    return -1;
}

// L
int left = solve(root -> left, k, i, size);

if (left != -1) return left;

i++;

// N
if (i == (size - k + 1)) return root -> data;

// R
int right = solve(root -> right, k, i, size);
return right;
}

void inOrder(TreeNode<int>* root, vector<int> &tree) {
    if (root == NULL) {
        return;
    }
    inOrder(root -> left, tree);
    tree.push_back(root -> data);
    inOrder(root -> right, tree);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int i = 0;
    vector<int> tree;
    inOrder(root, tree);
    int size = tree.size();
    return solve(root, k, i, size);
}