/*
? Question Link : https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0

? Question Title:  Two Sum IV - Input is a BST
*/

/*
* Approach 1:
For every node, search node with data = ( target - node->data).
* T.C = O(n^2)

* Approach 2:
In-order traversal of tree : TC and SC = O(n)
Two pointer approach i = 0; j <= size - 1
arr[i] + arr[j] == target, true
arr[i] + arr[j] > target, j--
arr[i] + arr[j] < target, i++
*/

#include <bits/stdc++.h> 
// Following is the Binary Tree node structure

class BinaryTreeNode {
    public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

//! MAIN FUNCTION STARTS 

void inOrder(BinaryTreeNode<int>* root, vector<int> &in) {
    if(root == NULL) return;

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> v;
    inOrder(root, v);

    int i = 0;
    int j = v.size() - 1;

    while(i < j) {
        int sum = v[i] + v[j];
        if (sum == target) return true;
        else if (sum > target) j--;
        else i++;
    }

    return false;
}

//! MAIN FUNCTION ENDS