// Data in left subtree < root node
// data in right subtree > root node
/*
? Delete a node from BST ::
* In order traversal (LNR) of BT gives sorted values
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        this -> data = x;
        this -> right = NULL;
        this -> left = NULL;
    }
};

Node* insertInBst(Node* &root, int data) {
// base case 
if (root == NULL) {
    root = new Node(data);
    return root;
}

if (data > root -> data) {
    root -> right = insertInBst(root -> right, data);
} else {
    root -> left = insertInBst(root -> left, data);
}

return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        insertInBst(root, data);
        cin >> data;
    }
}

int minValue(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp->data;
}

int maxValue(Node* root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp->data;
}

int main() {
    Node *root = NULL;

    cout << "Enter data (enter -1 to stop) :"<< endl;
    takeInput(root);

    cout << "Minimum value: " << minValue(root) << endl;

    cout << "Maximum value: " << maxValue(root) << endl;

    return 0;
}