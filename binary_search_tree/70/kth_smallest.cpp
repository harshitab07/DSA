/*
? Question Link : https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

? Question Title:  Find K-th smallest Element in BST
*/

/*
* Approach:
In-order traversal of BST, this will give sorted tree values
Then from sorted array return kth smallest value
* Time complexity = O(n)
* Space complexity = O(H) {H -> Height of given BST}
*/

using namespace std;
#include <bits/stdc++.h> 

//! MAIN FUNCTION STARTS 

int solve(BinaryTreeNode<int>* root, int k, int &i) {
if(root == NULL) {
    return -1;
}

// L
int left = solve(root -> left, k, i);

if (left != -1) return left;

i++;

// N
if (i == k) return root -> data;

// R
int right = solve(root -> right, k, i);
return right;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    return solve(root, k, i);
}

//! MAIN FUNCTION ENDS 