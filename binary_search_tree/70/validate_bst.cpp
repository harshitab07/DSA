/*
? Question Link : https://www.codingninjas.com/studio/problems/validate-bst_799483?leftPanelTab=0

? Question Title:  Partial BST
*/

using namespace std;
#include <bits/stdc++.h> 

//! MAIN FUNCTION STARTS 

bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    /* For BST,
    left subtree must contain values lesser then root
    right subtree must contain values greater then root
    */
    if(root -> data >= min && root->data <= max) {
        /*
        call for left subtree
        values should be lesser then root node, thus ranging from
        minimum value to root value
        */
        bool left = isBST(root->left, min, root->data);

        /*
        call for right subtree
        values should be gretaer then root node, thus ranging from
        root value to maximum value
        */
        bool right = isBST(root->right, root->data, max);

        // return true only when both left and right answers are true
        return left && right;
    } else {
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    /*
    INT_MIN and INT_MAX define the range for the root node, 
    i.e., root node can have any value ranging from -infinity to infinity
    */
    return isBST(root,INT_MIN, INT_MAX);
}

//! MAIN FUNCTION ENDS 

/*
* Time complexity = O(n)
* Space complexity = O(H) {H -> Height of given BST}
*/