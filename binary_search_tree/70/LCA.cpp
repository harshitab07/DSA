/*
? Question Link : https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280?leftPanelTab=0

? Question Title: LCA of Two Nodes In A BST
*/

/*
* Approach :
1. root -> data < n1 and n2, then, both nodes in right node
2. root -> data > n1 and n2, then, both nodes in left node
3. (root -> data < n1 and root -> data > n2)OR (root -> data > n1 and root -> data < n2) then, root is the answer

* T.C : O(n)
* S.C :
1. Recursive = O(H)
2. Iterative = O(1)
*/

using namespace std;
#include <bits/stdc++.h> 

// ! Recursive
TreeNode *LCAinaBST_Recursive(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if (root == NULL) {
        return NULL;
    }

    if((root -> data < P -> data) && (root -> data < Q -> data)) {
        return LCAinaBST_Recursive(root -> right, P, Q);
    }

    if((root -> data > P -> data) && (root -> data > Q -> data)) {
        return LCAinaBST_Recursive(root -> left, P, Q);
    }

    else {
        return root;
    }
}

// ! Iterative
TreeNode *LCAinaBST_Iterative(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if (root == NULL) {
        return NULL;
    }

    while(root != NULL) {
    if((root -> data < P -> data) && (root -> data < Q -> data)) {
        root = root -> right;
    }

    else if((root -> data > P -> data) && (root -> data > Q -> data)) {
        root = root -> left;
    }

    else {
        return root;
    }
    }

}