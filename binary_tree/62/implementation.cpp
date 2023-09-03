/*
Creation 
*/

/*
? Different types of traversals ::
* Level order traversal -> Level by level 
(Node; then left to right for every level)
* In order Traversal -> LNR -> Left Node right
* Pre order traversal -> NLR
* Post order traversal -> LRN
*/
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node *right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree (node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data); // created root node

    if (data == -1) return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data <<endl;
    root->right = buildTree(root->right);

    return;
}

// level order traversal


int main() { 
    node* root = NULL;

    root = buildTree(root);

    return 0;
}

