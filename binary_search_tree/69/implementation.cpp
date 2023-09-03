// Data in left subtree < root node
// data in right subtree > root node


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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            } 
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void preOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void postOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);

    cout << root -> data << " ";
}


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

int main() {
    Node *root = NULL;

    cout << "Enter data (enter -1 to stop) :"<< endl;
    takeInput(root);

    cout << "BST Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << "BST Pre Order Traversal: " << endl;
    preOrderTraversal(root);

    cout << endl;

    cout << "BST In Order Traversal: " << endl;
    inOrderTraversal(root);

    cout << endl;

    cout << "BST Post Order Traversal: " << endl;
    postOrderTraversal(root);

    cout << endl;

    return 0;
}