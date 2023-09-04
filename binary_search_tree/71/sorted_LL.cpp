/*
? Question Link : https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

? Question Title:  Flatten BST To A Sorted List
*/

/*
* Approach 1:
In-order traversal
Store each node in a vector.
Traverse through vector.
For each node, left points to null, right points to next element
For last node, left and right both point to null
* T.C = O(n)
* S.C = O(n)

* Approach 2:
In-order traversal
Store data of each node in a vector.
arr[i] + arr[j] == target, true
Traverse through vector.
For each node, left points to null, right points to next element
For last node, left and right both point to null
* T.C = O(n)
* S.C = O(n)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class Node {
    int data;
    Node* head;

    Node(int x) {
        this -> data = x;
        head = NULL;
    }
};
void inOrder(TreeNode<int>* root, vector<TreeNode<int>*> &in) {
    if(root == NULL) return;

    inOrder(root -> left, in);
    in.push_back(root);
    inOrder(root -> right, in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<TreeNode<int>*> v;
    inOrder(root, v);

    TreeNode<int>* ans = new TreeNode<int>(v[0] -> data);
    TreeNode<int>* LL = ans;

    for(int i = 1; i < v.size(); i++) {
        TreeNode<int>* temp = new TreeNode<int>(v[i] -> data);
        LL -> left = NULL;
        LL -> right = temp;
        LL = temp;
    }

    LL -> left = NULL;
    LL -> right = NULL;

    return ans;
}
