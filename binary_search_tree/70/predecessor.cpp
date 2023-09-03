/*
? Question Link : https://www.codingninjas.com/studio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

? Question Title:  Predecessor And Successor In BST
*/

/*
* Approach :
In-order traversal to find key
Predecessor -> Max. value in left subtree
Successor -> Min. value in right subtree
*/

using namespace std;
#include <bits/stdc++.h> 

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // find key
    TreeNode *temp = root;
    int predecessor = -1;
    int successor = -1;

    while(temp) {
        if(temp -> data == key) break;

        if (temp -> data > key) {
            successor = temp -> data;
            temp = temp -> left;
        } else {
            predecessor = temp -> data;
            temp = temp -> right;
        }
    }

    if(temp != NULL) {
    TreeNode *leftTree = temp -> left;
    while(leftTree != NULL) {
        predecessor = leftTree -> data;
        leftTree = leftTree -> right;
    }
    }

    if(temp != NULL) {
    TreeNode *rightTree = temp -> right;
    while(rightTree != NULL) {
        successor = rightTree -> data;
        rightTree = rightTree -> left;
    }
    }

    pair<int, int> ans = make_pair(predecessor, successor);
    
    return ans;
}